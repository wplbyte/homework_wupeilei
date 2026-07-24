#include "GameManage.h"
#include "SmallFish.h"
#include "MidFish.h"
#include "BigFish.h"
#include <graphics.h>
#include <ctime>
#include <math.h>
#define PI 3.1415926
using namespace std;

GameManage::GameManage()
{
    cannon = nullptr;
    score = 0;
    lastTime = 0;
    frameCount = 0;
    srand((unsigned int)time(NULL));
    fireCount = 0; 
    isStartScene = true; 
}

GameManage::~GameManage()
{
    delete cannon;
    for (auto fish : fishes)
        delete fish;
    fishes.clear();
    for (auto bullet : bullets)
        delete bullet;
    bullets.clear();
    for (auto coin : coins)
        delete coin;
    coins.clear();
}

void GameManage::Init()
{
    cannon = new Cannon();
    score = 0;
    lastTime = GetTickCount();
    fireCount = 0;
    BeginBatchDraw();
}

void GameManage::spawnFish()
{
    DWORD currentTime = GetTickCount();
    if (currentTime - lastTime < INTERVAL)
        return;
    if ((int)fishes.size() >= MAX_FISH)
        return;
    lastTime = currentTime;
    int type = rand() % 3;
    Fish* fish = nullptr;
    switch (type)
    {
    case 0:
        fish = new SmallFish();
        break;
    case 1:
        fish = new MidFish();
        break;
    case 2:
        fish = new BigFish();
        break;
    }
    if (fish)
    {
        fish->setX(-fish->getW());
        int newY = 0;
        bool ok = false;
        int tryCount = 0;
        while (!ok && tryCount < 10)
        {
            newY = rand() % (WINDOW_HEIGHT - 300);
            ok = true;
            for (auto f : fishes)
            {
                int diffX = abs(f->getX() - fish->getX());
                int diffY = abs(f->getY() - newY);
                if (diffX < MIN_FISH_GAP || diffY < MIN_FISH_GAP)
                {
                    ok = false;
                    break;
                }
            }
            tryCount++;
        }
        fish->setY(newY);
        fishes.push_back(fish);
    }
}

void GameManage::processInput()
{
    ExMessage msg;
    while (peekmessage(&msg))
    {
        if (msg.message == WM_MOUSEMOVE)
        {
            cannon->aimAt(msg.x, msg.y);
        }
        else if (msg.message == WM_LBUTTONDOWN)
        {
            if (fireCount < MAX_BULLET_ALL)
            {
                int cx = cannon->getX() + cannon->getW() / 2;
                int cy = cannon->getY() + cannon->getH() / 2;
                double degree = cannon->getDegree();
                double rad = degree * PI / 180.0;
                int len = 55;
                int bx = cx + (int)(cos(rad) * len);
                int by = cy + (int)(sin(rad) * len);
                bullets.push_back(new Bullet(bx, by, degree));
                fireCount++;
            }
            
        }
    }
}   

void GameManage::checkCollisions()
{
    for (auto bullet : bullets)
    {
        for (auto fish : fishes)
        {
            if (fish->getIsLiving() && collision.isCollision(*bullet, *fish))
            {
                fish->hurt(5);
                if (!fish->getIsLiving())
                {
                    coins.push_back(new Coin(fish->getX(), fish->getY(), fish->getValue()));
                    score += fish->getValue();
                }
                bullet->setNum(0);
                break;
            }
        }
    }
}

void GameManage::cleanupObjects()
{
    for (auto it = fishes.begin(); it != fishes.end();)
    {
        if (!(*it)->getIsLiving())
        {
            delete *it;
            it = fishes.erase(it);
        }
        else
        {
            ++it;
        }
    }
    for (auto it = bullets.begin(); it != bullets.end();)
    {
        if ((*it)->isOut() || (*it)->getNum() == 0)
        {
            delete *it;
            it = bullets.erase(it);
        }
        else
        {
            ++it;
        }
    }
    for (auto it = coins.begin(); it != coins.end();)
    {
        if ((*it)->isOut())
        {
            delete *it;
            it = coins.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void GameManage::Update()
{
    frameCount++;
    cannon->Update();
    processInput();
    spawnFish();
    if (frameCount % FISH_UPDATE_SKIP == 0)
    {
        for (auto fish : fishes)
            fish->Update();
    }
    for (auto bullet : bullets)
        bullet->Update();
    for (auto coin : coins)
        coin->Update();
    checkCollisions();
    cleanupObjects();
}

void GameManage::Draw()
{
    cleardevice();
    setfillcolor(RGB(30, 80, 120));
    solidrectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    for (auto fish : fishes)
        fish->Draw();
    for (auto bullet : bullets)
        bullet->Draw();
    for (auto coin : coins)
        coin->Draw();
    cannon->Draw();
    settextcolor(WHITE);
    settextstyle(20, 0, _T("黑体"));
    TCHAR scoreText[20];
    _stprintf_s(scoreText, _T("得分: %d"), score);
    outtextxy(10, 10, scoreText);
    TCHAR bulletText[30];
    int remainBullet = MAX_BULLET_ALL - fireCount;
    _stprintf_s(bulletText, _T("炮弹: %d / %d"), remainBullet, MAX_BULLET_ALL);
    outtextxy(10, 40, bulletText);
}

void GameManage::Run()
{
    BeginBatchDraw();
    while (true)
    {
        if (isStartScene)
        {
            startUI.Draw();

            ExMessage msg;
            while (peekmessage(&msg))
            {
                if (msg.message == WM_LBUTTONDOWN)
                {
                    int mx = msg.x;
                    int my = msg.y;
                    if (mx >= WINDOW_WIDTH / 2 - 100 && mx <= WINDOW_WIDTH / 2 + 100
                        && my >= 320 && my <= 400)
                    {
                        HWND hWnd = GetHWnd();
                        TCHAR ruleStr[] = _T("捕鱼游戏规则\n1.鼠标移动控制炮台瞄准\n2.左键发射子弹消耗次数\n3.击杀小鱼/中鱼/大鱼获得分数\n4.子弹全部用完游戏结束\n5.鱼游出屏幕无得分");
                        MessageBox(hWnd, ruleStr, _T("游戏规则"), MB_OK | MB_ICONINFORMATION);
                    }
                    else if (mx >= WINDOW_WIDTH / 2 - 100 && mx <= WINDOW_WIDTH / 2 + 100
                        && my >= 400 && my <= 480)
                    {
                        isStartScene = false;
                        Init(); // 重置fireCount、score
                    }
                }
            }

            FlushBatchDraw();
        }
        else
        {
            Update();
            Draw();
            FlushBatchDraw();
            //炮弹用尽退出，游戏结束
            if (fireCount >= MAX_BULLET_ALL)
            {
                HWND hWnd = GetHWnd();
                TCHAR msgBuffer[256];
                wsprintf(msgBuffer, _T("游戏结束！\n本次得分：%d"), score);
                MessageBox(hWnd, msgBuffer, _T("游戏结束"), MB_OK | MB_ICONERROR);
                isStartScene = true;
                delete cannon;
                cannon = nullptr;
                cleanupObjects(); 
            }
            //ecs退出
            if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
            {
                isStartScene = true;
                delete cannon;
                cannon = nullptr;
                cleanupObjects();
            }
        }
    }
}
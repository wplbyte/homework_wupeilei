#include "StartScene.h"
#include "extern.h"
StartScene::StartScene()
{
    loadimage(&background, _T("images\\background.png"), WINDOW_WIDTH, WINDOW_HEIGHT);
    Click = false;
}
StartScene::~StartScene()
{

}
void StartScene::Draw()
{
    cleardevice();
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    settextcolor(WHITE);
    settextstyle(60, 0, _T("黑体"));
    TCHAR title[] = _T("捕鱼游戏");
    outtextxy(WINDOW_WIDTH / 2 - 120, 150, title);
    //游戏规则按钮
    setfillcolor(RGB(30, 120, 200));
    solidrectangle(WINDOW_WIDTH / 2 - 100, 320, WINDOW_WIDTH / 2 + 100, 400);
    settextcolor(WHITE);
    settextstyle(30, 0, _T("宋体"));
    outtextxy(WINDOW_WIDTH / 2 - 75, 345, _T("游戏规则"));
    // 开始按钮
    setfillcolor(GREEN);
    solidrectangle(WINDOW_WIDTH / 2 - 100, 400, WINDOW_WIDTH / 2 + 100, 480);
    settextcolor(WHITE);
    settextstyle(30, 0, _T("黑体"));
    TCHAR btnText[] = _T("点击开始游戏");
    outtextxy(WINDOW_WIDTH / 2 - 85, 420, btnText);
    Click = false;
}
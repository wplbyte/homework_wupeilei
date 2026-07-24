#ifndef GAMEMANAGE_H
#define GAMEMANAGE_H
#pragma comment(lib, "MSIMG32.LIB")
#include <graphics.h>
#include<vector>
#include "Fish.h"
#include "Bullet.h"
#include "Coin.h"
#include "Collision.h"
#include "Cannon.h"
#include "extern.h"
#include "StartScene.h"
using namespace std;
class GameManage
{
private:
	Cannon* cannon;
	vector<Fish*>fishes;
	vector<Bullet*>bullets;
	vector<Coin*>coins;
	Collision collision;
	int score;
	DWORD lastTime;
	int frameCount;                       // 帧计数器
	static const int FISH_UPDATE_SKIP = 6;    // 鱼每3帧更新一次，降低移动速度
	static const int MAX_FISH = 5;           // 最大鱼数量，避免画面拥挤
	static const int MIN_FISH_GAP = 200;       // 鱼之间最小Y间距，避免重叠
	int fireCount;    // 已发射子弹计数
	const int MAX_BULLET_ALL = 30; // 总炮弹上限10发
	bool isStartScene; // 标记当前是否是开始界面
	StartScene startUI; // 首页对象
public:
	GameManage();
	~GameManage();
	void Init();
	void Update();
	void Draw();
	void Run();
private:
	void spawnFish();
	void processInput();
	void checkCollisions();
	void cleanupObjects();
};
#endif
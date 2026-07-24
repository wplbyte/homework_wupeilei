#ifndef COIN_H
#define COIN_H
#pragma comment(lib, "MSIMG32.LIB")
#include <graphics.h>
#include "GameObject.h"
class Coin :public GameObject
{
private:
	int score;
	IMAGE imgCoin;
	DWORD startTime; // 金币开始生成的时间
	const int LIVE_TIME = 5000; // 金币出现5s后自动消失
public:
	Coin(int x0,int y0,int s);
	virtual void Update();
	virtual void Draw();
	int getScore();
	bool isOut();
};
#endif
#include "Coin.h"
#include<graphics.h>
#include "extern.h"
Coin::Coin(int x0, int y0,int s)
{
	x = x0;
	y = y0;
	w = 20;
	h = 20;
	score = s;
	loadimage(&imgCoin, _T("coin.png"), w, h);
	startTime = GetTickCount();
}
void Coin::Update(){}
void Coin::Draw()
{
	AlphaBlend(GetImageHDC(NULL), x, y, w, h, GetImageHDC(&imgCoin), 0, 0, w, h, {AC_SRC_OVER, 0, 255, AC_SRC_ALPHA });
}
int Coin::getScore()
{
	return score;
}
bool Coin::isOut()
{
	if (x > WINDOW_WIDTH || x < 0 || y<0 || y>WINDOW_HEIGHT)
		return true;
	if (GetTickCount() - startTime > LIVE_TIME)
		return true;
	return false;
}
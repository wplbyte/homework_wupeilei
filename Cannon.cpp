#include "Cannon.h"
#include<graphics.h>
#include<math.h>
#include "extern.h"
#define PI 3.1415926
Cannon::Cannon()
{
	w = 40;
	h = 40;
	x = WINDOW_WIDTH / 2 - w / 2;
	y = WINDOW_HEIGHT - h;
	degree = -90;//初始默认炮口朝上
}
void Cannon::Update()
{
}
void Cannon::aimAt(int mx, int my)
{
	int cx = x + w / 2;
	int cy = y + h / 2;
	double dx = mx - cx;
	double dy = my - cy;
	degree = atan2(dy, dx) * 180 / PI;
}
//用原型表示底座，矩形表示炮管，炮管的数学计算个人认为有一定难度
void Cannon::Draw()
{
	int cx = x + w/ 2;
	int cy = y + h/ 2;

	//圆形底座
	setfillcolor(RGB(60, 60, 60));
	fillcircle(cx, cy, 35);

	double rad = degree * PI / 180.0;
	int len = 55;// 炮管长度
	int thick = 12;// 炮管粗细

	// 矩形四个顶点计算
	POINT p[4] = {
		{ (int)(cx + cos(rad) * len), (int)(cy + sin(rad) * len) },
		{ (int)(cx + cos(rad + PI / 2) * thick / 2), (int)(cy + sin(rad + PI / 2) * thick / 2) },
		{ (int)(cx + cos(rad - PI) * len), (int)(cy + sin(rad - PI) * len) },
		{ (int)(cx + cos(rad - PI / 2) * thick / 2), (int)(cy + sin(rad - PI / 2) * thick / 2) }
	};
	setfillcolor(RGB(80, 80, 80));
	fillpolygon(p, 4);
}
void Cannon::setDegree(double theta)
{
	degree = theta;
}
double Cannon::getDegree()
{
	return degree;
}
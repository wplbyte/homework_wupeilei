#include "Bullet.h"
#include "extern.h"
#include<math.h>
#include<graphics.h>
#define PI 3.1415926
Bullet::Bullet(int x0, int y0, double degree0)
{
	w = 5;
	h = 5;
	x = x0;
	y = y0;
	degree = degree0;
	vb = 8;
	hurt = 5;
	num = 1;
}
void Bullet::Update()
{
	double rad = degree * PI / 180.0;
	x += vb * cos(rad);
	y += vb * sin(rad);
}
void Bullet::Draw()
{
	setfillcolor(RGB(255, 220, 0));
	fillcircle(x, y, 8);
	setfillcolor(WHITE);
	fillcircle(x, y, 4);
}
int Bullet::getNum()
{
	return num;
}
void Bullet::setNum(int n)
{
	num = n;
}
bool Bullet::isOut()
{
	if (x > WINDOW_WIDTH || x < 0 || y<0 || y>WINDOW_HEIGHT)
		return true;
	else return false;
}
#ifndef BULLET_H
#define BULLET_H
#pragma comment(lib, "MSIMG32.LIB")
#include <graphics.h>
#include "GameObject.h"
class Bullet:public GameObject
{
private:
	double degree;
	int vb;//子弹的速度
	int hurt;
	int num;
public:
	Bullet(int x0,int y0,double degree0);
	virtual void Update();
	virtual void Draw();
	int getNum();
	void setNum(int n);
	bool isOut();
};
#endif
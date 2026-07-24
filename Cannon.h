#ifndef CANNON_H
#define CANNON_H
#pragma comment(lib, "MSIMG32.LIB")
#include <graphics.h>
#include "GameObject.h"
class Cannon:public GameObject
{
private:
	double degree;//ÅÚµ¯·¢Éä½Ç¶È
public:
	Cannon();
	virtual void Update();
	virtual void Draw();
	void aimAt(int mx, int my);
	double getDegree();
	void setDegree(double theta);
};
#endif
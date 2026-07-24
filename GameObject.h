#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <graphics.h>
class GameObject
{
protected:
	int x;
	int y;
	int w;
	int h;
public:
	GameObject() {};
	virtual ~GameObject() {};
	virtual void Update() = 0;
	virtual void Draw() = 0;
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	int getW()
	{
		return w;
	}
	int getH()
	{
		return h;
	}
	void setX(int x0)
	{
		x = x0;
	}
	void setY(int y0)
	{
		y = y0;
	}
};
#endif

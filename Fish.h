#ifndef FISH_H
#define FISH_H
#pragma comment(lib, "MSIMG32.LIB")
#include <graphics.h>
#include "GameObject.h"
class Fish:public GameObject
{
protected:
	int v;//速度
	int life;//血量
	int value;//得分
	bool isLiving;//是否存活
	static const int FRAME_INTERVAL = 15;   // ֡帧切换频率
	int animIndex;
	int animTimer;
public:
	Fish() {};
	Fish(int x, int y);
	virtual ~Fish() {};
	void Die();
	void putimage_alpha(int x, int y, IMAGE* img);
	virtual void Update() = 0;
	virtual void Draw() = 0;
	void hurt(int damage);
	int getValue()
	{
		return value;
	}
	bool getIsLiving()
	{
		return isLiving;
	}
};
#endif
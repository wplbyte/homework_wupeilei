#ifndef SMALLFISH_H
#define SMALLFISH_H
#pragma comment(lib, "MSIMG32.LIB")
#include <graphics.h>
#include "Fish.h"
class SmallFish:public Fish
{
protected:
	static const int IMAGE_NUM = 1;
	IMAGE fishAnimFrames[IMAGE_NUM];
public:
	SmallFish();
	void Update();
	void Draw();
};
#endif
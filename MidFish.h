#ifndef MIDFISH_H
#define MIDFISH_H
#pragma comment(lib, "MSIMG32.LIB")
#include <graphics.h>
#include "Fish.h"
class MidFish :public Fish
{
private:
	static const int IMAGE_NUM = 1;
	IMAGE fishAnimFrames[IMAGE_NUM];
public:
	MidFish();
	void Update();
	void Draw();
};
#endif
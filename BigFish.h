#ifndef BIGFISH_H
#define BIGFISH_H
#pragma comment(lib, "MSIMG32.LIB")
#include <graphics.h>
#include "Fish.h"
class BigFish :public Fish
{
private:
	static const int IMAGE_NUM = 1;
	IMAGE fishAnimFrames[IMAGE_NUM];
public:
	BigFish();
	void Update();
	void Draw();
};
#endif
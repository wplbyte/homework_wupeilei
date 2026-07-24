#include "Fish.h"
void Fish::Die()
{
	isLiving = false;
}
void Fish::putimage_alpha(int x, int y, IMAGE* img)
{
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h, GetImageHDC(img), 0, 0, w, h, {
   AC_SRC_OVER, 0, 255, AC_SRC_ALPHA });
}
void Fish::hurt(int damage)
{
	life -= damage;
	if (life <= 0)
		Die();
}
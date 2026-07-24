#include "SmallFish.h"
#include "extern.h"
SmallFish::SmallFish()
{
	w = 40;
	h = 40;
	v = 1;
	value = 5;//小鱼死得分为5
	life = 5;//小鱼血量为5
	isLiving = true;
	animIndex = 0;
	animTimer = 0;
	TCHAR imgPath[256]; //动画图片文件路径
	for (int i = 0; i < IMAGE_NUM; i++) //加载动画图片
	{
		_stprintf_s(imgPath, _T("images\\small\\%d.png"), i + 1); //动画图片路径（格式转换）
		loadimage(&fishAnimFrames[i], imgPath); //加载动画图片
	}
}
void SmallFish::Update()
{
	if (!isLiving) return;
	// 小鱼持续向右平移
	x += v;
	// 边界循环：移出屏幕右侧，从左侧重新进入
	if (x > WINDOW_WIDTH)
		x = -w;
	// 2. 帧动画切换逻辑（完全复刻范例计时器逻辑）
	animTimer += 5;
	if (animTimer >= FRAME_INTERVAL)
	{
		animIndex = (animIndex + 1) % IMAGE_NUM;
		animTimer = 0;
	}
}
void SmallFish::Draw()
{
	if (!isLiving) return;
	// 绘制当前动画帧（透明渲染，无黑边）
	putimage_alpha(x, y, &fishAnimFrames[animIndex]);
}

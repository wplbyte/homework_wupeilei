#include "Collision.h"
bool Collision::isCollision(GameObject& a, GameObject& b)
{
	bool h = (a.getX() <= b.getX() + b.getW()) && (b.getX() <= a.getX() + a.getW());//判断水平方向是否发生碰撞
	bool v = (a.getY() <= b.getY() + b.getH()) && (b.getY() <= a.getY() + a.getH());//判断垂直方向是否发生碰撞
	return h && v;//水平竖直同时有接触才算碰撞
}
#ifndef COLLISION_H
#define COLLISION_H
#pragma comment(lib, "MSIMG32.LIB")
#include <graphics.h>
#include "GameObject.h"
class Collision
{
public:
	bool isCollision(GameObject& a, GameObject& b);
};
#endif

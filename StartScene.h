#ifndef STARTSCENE_H
#define STARTSCENE_H
#pragma comment(lib, "MSIMG32.LIB")
#include <graphics.h>
class StartScene
{
private:
    IMAGE background;
    bool Click;
public:
    StartScene();
    ~StartScene();
    void Draw();
};
#endif
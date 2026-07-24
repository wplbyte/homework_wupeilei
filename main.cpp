#include <graphics.h>
#pragma comment(lib, "MSIMG32.LIB")
#include "extern.h"
#include "GameManage.h"
#pragma comment(lib, "winmm.lib")

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);
    mciSendString(_T("open D:\\VS_projects\\xiaoxueqihomework\\fish2\\audio\\bgm.mp3 alias BGM"), NULL, 0, NULL);
    mciSendString(_T("play BGM repeat"), NULL, 0, NULL);
    GameManage game;
    game.Init();
    game.Run();
    mciSendString(_T("close BGM"), NULL, 0, NULL);
    closegraph();
    return 0;
}
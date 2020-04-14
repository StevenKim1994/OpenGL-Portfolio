#pragma once

#include "../resource.h"
#include "iGraphics.h"


#if _DEBUG
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console") // 디버그모드 콘솔창 나오게하기
#define xprintf printf
#else
#define xprintf(...) (void)0
#endif

#define DEVSIZE_WIDTH 960
#define DEVSIZE_HEIGHT 480

extern int monitorSizeW, monitorSizeH; // 이헤더를 포함하는 외부소스에 이변수 알려줌 .. 전역변수로 쓰기 위함


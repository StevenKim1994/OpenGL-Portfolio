#pragma once
#include <windows.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment(lib, "Gdiplus.lib")

ULONG_PTR startGdiplus();
void endGdiplus(ULONG_PTR gpToken);
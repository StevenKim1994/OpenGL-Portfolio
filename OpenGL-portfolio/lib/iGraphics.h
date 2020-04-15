#pragma once
#include <windows.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment(lib, "Gdiplus.lib")

#include "iType.h"

ULONG_PTR startGdiplus();
void endGdiplus(ULONG_PTR gpToken);

wchar_t* utf8_to_utf16(const char* szFornat, ...);
char* utf16_to_utf8(const wchar_t* str);

typedef Image igImage;

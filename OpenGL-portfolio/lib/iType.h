#pragma once

// 이 iType은 선언만 있음 정의따로 구현안함 (cpp X)

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "iPoint.h"
#include "iSize.h"
#include "iRect.h"
#include "iColor.h"

#include "iArray.h"
#include "iString.h"

typedef signed char int8;
typedef unsigned char uint8;
typedef signed short int16;
typedef unsigned short uint16;
typedef signed int int32;
typedef unsigned int uint32;

enum iKeyState
{
	iKeyStateBegan = 0,
	iKeyStateMoved,
	iKeyStateEnded
};

#define keyboard_left	1
#define keyboard_right	2
#define keyboard_up		4
#define keyboard_down	8
#define keyboard_enter	16
#define keyboard_space	32

#define keyboard_num1	64
#define keyboard_num2	128
#define keyboard_num3	256




struct Texture
{
	uint32 texID;
	float width, height;
	float potWidth, potHeight; // OpenGL의 특성때문에 2의 승수로 텍스처를 불러오기 때문에 실제 width, height를 2의 승수로 만든 값
	int retainCount; // 참조횟수 자체적인 GarbageCollector 구현을 위함
};

enum TextureWrap
{
	CLAMP = 0,
	REPEAT,
};

enum TextureFilter
{
	LINEAR = 0,
	NEAREST,
	MIPMAP,
};

#define	TOP		1
#define	VCENTER	2
#define	BOTTOM	4

#define	LEFT	0
#define HCENTER	16
#define	RIGHT	32

#define	REVERSE_NONE	0
#define REVERSE_WIDTH	1
#define REVERSE_HEIGHT	2

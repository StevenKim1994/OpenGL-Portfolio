#pragma once
#include "iStd.h"


#define _zoomDt 1.0f

void shakeCamera(int range, float duration = 0.5f);// 카메라 진동
void zoomCamera(iPoint point, float _zoomRate); // 카메라 확대
void slowCamera(float time); // 속도 느리게
void showCamera(Texture* tex, float dt);
#pragma once
#include "cameraFunc.h"



iPoint shakePosition;
float _shakeDt;
float shakeDt = _shakeDt;

void shakeCamera(int range, float duration)
{
	int x = random() % range;
		if (random() % 2) 
			x *= -1;

	int y = random() % range;
		if (random() % 2)
			y *= -1;
		shakePosition = iPointMake(x, y);
		
		_shakeDt = duration;
		shakeDt = 0.0f;

}

iPoint zoomPosition;
float zoomRate;
float zoomDt = _zoomDt;

void zoomCamera(iPoint point, float _zoomRate)
{
	zoomPosition = point;
	zoomRate = _zoomRate;
	zoomDt = 0.0f;
}

void slowCamera(float time)
{
}

void showCamera(Texture* tex, float dt)
{
	if (zoomDt < _zoomDt || shakeDt < _shakeDt)
	{
		iPoint c = iPointMake(devSize.width / 2, devSize.height / 2);
		float r = 1.0f;

		if (zoomDt < _zoomDt)
		{
			r = 1.0f + (zoomRate - 1.0f) * _sin(180 * zoomDt / _zoomDt);
			zoomDt += dt;
			iPoint dp = zoomPosition - c;
			iPoint rp = dp * r;
			c -= rp - dp;
		}

		if (shakeDt < _shakeDt)
		{
			float r = shakeDt / _shakeDt;
			if (r < 1.0f / 1.75f)
				c += shakePosition * _sin(180 * r / (1.0f / 1.75f));

			else if (r < 1.5 / 1.75f)
				c += shakePosition * 0.5f * _sin(180 * (r - 1.0f / 1.75f) / (0.5f / 1.75f));

			else
				c += shakePosition * 0.25f * _sin(180 * (r - 1.5f / 1.75f) / (0.25f / 1.75f));

			shakeDt += dt;
		}

		drawImage(tex, c.x, c.y, 0, 0, tex->width, tex->height, VCENTER | HCENTER, r, r, 2, 0, REVERSE_HEIGHT);

	}
	else
	{
		drawImage(tex, 0, 0, 0, 0, tex->width, tex->height, TOP | LEFT, 1.0f, 1.0f, 2, 0, REVERSE_HEIGHT);
	}
}

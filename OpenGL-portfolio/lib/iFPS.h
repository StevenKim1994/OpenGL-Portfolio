#pragma once

#define iFPS_delta 0.5f

struct iFPS {
	int frames = 0;
	float delta = 0.0f;
	int fps = 0;

	int update(float dt)
	{
		frames++;
		if (delta >= iFPS_delta)
		{
			fps = frames / iFPS_delta;
			delta -= iFPS_delta;
			frames = fps * delta * iFPS_delta;// 0;
		}
		return fps;
	}
};


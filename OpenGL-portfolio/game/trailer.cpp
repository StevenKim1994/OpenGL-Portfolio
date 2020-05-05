#pragma once

#include "iStd.h"
#include "trailer.h"
#include "iVideo.h"
#include "sceneManager.h"

#include "intro.h"

void loadTrailer()
{
	playVideo("assets/trailer/video/trailer.mp4");

}

void freeTrailer()
{
}

void drawTrailer(float dt)
{
	
	if (getKeyDown() & keyboard_enter)
	{
		printf("to Enter\n");
		//stopVideo
		//playVideo(NULL);
		//
		stopVideo();
		setLoading(gs_intro, freeIntro, loadIntro);
	}

}

void keyTrailer(iKeyState stat, iPoint point)
{
	
}

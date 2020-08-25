#pragma once

#include "Thunder.h"
#include "../PlayerCharacter/Player.h"

static iImage** imgThunder = NULL;
extern Player* hero;


Thunder::Thunder()
{
	if (imgThunder == NULL)
	{
		ObjInfo _oi[1] =
		{
			{"assets/stage/props/thunder/Thunder (%d).png", 13, 1.0f, {0, -200}},
		};

		iGraphics* g = iGraphics::instance();
		iSize size;

		imgThunder = (iImage**)malloc(sizeof(iImage*) * 1);

		for (int i = 0; i < 1; i++)
		{
			ObjInfo* oi = &_oi[i];
			iImage* img = new iImage();
			for (int j = 0; j < oi->num; j++)
			{
				Texture* tex = createImage(oi->path, j + 1);
				tex->height *= oi->sizeRate;
				tex->potHeight *= oi->sizeRate;
				tex->potWidth *= oi->sizeRate;
				tex->width *= oi->sizeRate;
				img->addObject(tex);
				freeImage(tex);
			}

			switch (i)
			{
			case 0:
				img->_repeatNum = 1;
				break;
			}

			img->_aniDt = 0.075f;
			img->position = oi->p;
			imgThunder[i] = img;
		}
	}

	imgs = (iImage**)malloc(sizeof(iImage*) * 1);
	for (int i = 0; i< 1; i++)
		imgs[i] = imgThunder[i]->copy();

	img = imgs[0];
	img->startAnimation(cbBehave, this);
	size = iSizeMake(50, 100);

	_delay = 2.5f;
	delay = 0.0f;
}

Thunder::~Thunder()
{
	if (imgThunder)
	{

	}

	for (int i = 0; i < 1; i++)
		delete imgs[i];

	free(imgs);
}

void Thunder::paint(float dt, iPoint offset)
{
	
	if (img->animation == false)
	{
		delay += dt;
		if (delay > _delay)
		{
			delay = 0.0f;
			img->startAnimation(cbBehave, this);
		}
	}
	else
		img->paint(dt, position + offset);

	




}

void Thunder::cbBehave(void* parm)
{
	Thunder* t = (Thunder*)parm;
}

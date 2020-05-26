#pragma once

#include "Fire.h"

static iImage** imgFire = NULL;

Fire::Fire()
{
	if (imgFire == NULL)
	{
		ObjInfo _oi[1] = {
			{"assets/stage/props/fire/tile%03d.png",61, 2.0f, {-100,-100}} ,
		};

		iGraphics* g = iGraphics::instance();
		iSize size;
		
		imgFire = (iImage**)malloc(sizeof(iImage*) * 1);

		for(int i = 0; i<1; i++)
		{ 
			ObjInfo* oi = &_oi[i];
			iImage* img = new iImage();
			for (int j = 0; j < oi->num; j++)
			{
				Texture* tex = createImage(oi->path, j);
				tex->height*= oi->sizeRate;
				tex->potHeight*= oi->sizeRate;
				tex->potWidth*= oi->sizeRate;
				tex->width *= oi->sizeRate;
				img->addObject(tex);
				freeImage(tex);
			}
			switch (i)
			{
			case 0:
				img->_repeatNum = 0;
				break;

			}
			img->_aniDt = 0.01f;
			img->position = oi->p;
			imgFire[i] = img;
		}
	}

	imgs = (iImage**)malloc(sizeof(iImage*) * 1);
	for (int i = 0; i < 1; i++)
		imgs[i] = imgFire[i]->copy();

	img = imgs[0];
	img->startAnimation();
	size = iSizeMake(50, 100);

}

Fire::~Fire()
{
	if (imgFire)
	{
	
	}

	for(int i = 0; i<1; i++)
		delete imgs[i];

	free(imgs);

}

void Fire::paint(float dt, iPoint offset)
{
	img->paint(dt, position + offset);
}

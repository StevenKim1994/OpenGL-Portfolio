#pragma once

#include "Flyeye.h"

static iImage** imgFlyeye = NULL;

Flyeye::Flyeye()
{
	type = 2;
	if (imgFlyeye == NULL)
	{

		ObjInfo _oi[1] = {
			"assets/intro/flyeye/tile%03d.png",8, 1.5f, {0, 0},
		}; // 0: idle

		iGraphics* g = iGraphics::instance();
		iSize size;

		imgFlyeye = (iImage**)malloc(sizeof(iImage*) * 1);

		for (int i = 0; i < 1; i++)
		{

			iImage* img = new iImage();
			ObjInfo* oi = &_oi[i];

			for (int j = 0; j < oi->num; j++)
			{
				igImage* ig = g->createIgImage(oi->path, j);
				size = iSizeMake(g->getIgImageWidth(ig) * oi->sizeRate,
					g->getIgImageHeight(ig) * oi->sizeRate);

				g->init(size);
				g->drawImage(ig, 0, 0, oi->sizeRate, oi->sizeRate, TOP | LEFT);
				g->freeIgImage(ig);

				Texture* tex = g->getTexture();
				img->addObject(tex);
				freeImage(tex);
			}


			switch (i)
			{
			case 0:
				img->_repeatNum = 0;
				break;

			default:
				img->_repeatNum = 1;

				break;
			}

			img->_aniDt = 0.1f;
			img->position = oi->p * 2;

			imgFlyeye[i] = img;
		}
	}

	imgs = (iImage**)malloc(sizeof(iImage*) * 1);
	for (int i = 0; i < 1; i++)
		imgs[i] = imgFlyeye[i]->copy();

	img = imgs[0];

	behave = ObjectBehave::ObjectBehave_NULL;
	setBehave(ObjectBehave::ObjectBehave_idle, 0);
	movement = 100;
	direction = 0;
	
}
Flyeye::~Flyeye()
{
	if(imgFlyeye)
	{
		for (int i = 0; i < 1; i++)
			delete imgFlyeye[i];

		free(imgFlyeye);
		imgFlyeye = NULL;
	}
	
	for (int i = 0; i < 1; i++)
		delete imgs[i];

	free(imgs);
}

void Flyeye::cbBehave(void* cb)
{
	iImage* i = (iImage*)cb;
}


void Flyeye::setBehave(ObjectBehave be, int direction)
{
	if(behave != be || direction != direction)
	{
		behave = be;
		img = imgs[(int)be];
		if (be == ObjectBehave::ObjectBehave_idle)
			img->startAnimation(cbBehave, img);

		this->direction = direction;
		
	}
}


void Flyeye::paint(float dt, iPoint offset)
{
	iPoint flyeyeMovement = iPointMake(0, 0) * powGravity * dt; // 애는 날고있으므로 중력 적용 X

	img->leftRight = direction;
	img->paint(dt, position + offset);
}

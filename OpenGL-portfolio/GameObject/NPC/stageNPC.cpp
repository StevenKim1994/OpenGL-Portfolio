#pragma once

#include "stageNPC.h"

static iImage** imgstageNPC = NULL;

stageNPC::stageNPC()
{
	if(imgstageNPC == NULL)
	{
		NPCInfo _ni[1] = {
			
				"assets/stage/stageNPC/stageNPC (%d).png", 8, 1.5f, {-16,-42},
			
		};

		iGraphics* g = iGraphics::instance();
		iSize size;

		imgstageNPC = (iImage**)malloc(sizeof(iImage*) * 1);
		
		for (int i = 0; i < 1; i++)
		{

			iImage* img = new iImage();
			NPCInfo* ni = &_ni[i];
			for (int j = 0; j < ni->num; j++)
			{
				igImage* ig = g->createIgImage(ni->path, j + 1);
				size = iSizeMake(g->getIgImageWidth(ig) * ni->sizeRate, g->getIgImageHeight(ig) * ni->sizeRate);
				g->init(size);
				g->drawImage(ig, 0, 0, ni->sizeRate, ni->sizeRate, TOP | LEFT);

				Texture* tex = g->getTexture();
				img->addObject(tex);
				freeImage(tex);
			}
			switch (i)
			{
			case 0:
				img->_repeatNum = 0; // infinity
				break;
			}
			img->_aniDt = 0.15f;
			img->position = ni->p;
			imgstageNPC[i] = img;
		}
	}

	imgs = (iImage**)malloc(sizeof(iImage*) * 1);
	for (int i = 0; i < 1; i++)
		imgs[i] = imgstageNPC[i]->copy();

	img = imgs[0];

	behave = NPCBehave::NPCBehave_NULL;
	direction = 1;
	setBehave(NPCBehave::NPCBehave_idle, direction);

}

stageNPC::~stageNPC()
{
	if (imgstageNPC)
	{
		for (int i = 0; i < 1; i++)
			delete imgstageNPC[i];
	}
	
	for (int i = 0; i < (int)NPCBehave::NPCBehave_num; i++)
		delete imgs[i];
	free(imgs);

}

void stageNPC::cbBehave(void* cb)
{
}

void stageNPC::cbSkill(void* cb)
{
}

void stageNPC::setBehave(NPCBehave be, int dir)
{
	if (behave != be || direction != dir)
	{
		behave = be;
		img = imgs[(int)be];
		img->startAnimation(cbBehave);
		direction = dir;
	}
}

void stageNPC::paint(float dt, iPoint offset)
{
	img->paint(dt, position + offset, direction);
}

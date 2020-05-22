#pragma once

#include "stageNPC.h"

stageNPC::stageNPC()
{
	

	NPCInfo _ni[1] = {
		
			"assets/stage/stageNPC/stageNPC (%d).png", 8, 1.5f, {0,-42},
		
	};

	iGraphics* g = iGraphics::instance();
	iSize size;

	imgs = (iImage**)malloc(sizeof(iImage*) * 1);
	
	for (int i = 0; i < 1; i++)
	{
		NPCInfo* ni = &_ni[i];

		iImage* img = new iImage();

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
		img->_aniDt = 0.15f;

		switch (i)
		{
		case 0:
			img->_repeatNum = 0; // infinity
			break;
		}
		
		img->position = ni->p;
		imgs[i] = img;
	}

	behave = (NPCBehave)-1;
	direction = 1;
	setBehave(NPCBehave_idle, direction);

	
}

stageNPC::~stageNPC()
{
	for (int i = 0; i < NPCBehave_num; i++)
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
		img = imgs[be];
		img->startAnimation(cbBehave);
		direction = dir;
	}
}

void stageNPC::paint(float dt, iPoint offset)
{
	img->paint(dt, position + offset, direction);
}

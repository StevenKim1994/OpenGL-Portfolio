#pragma once

#include "stageNPC.h"

stageNPC::stageNPC()
{
	iGraphics* g = iGraphics::instance();
	iSize size;

	NPCInfo _ni[NPCBehave_num] = {
		{"assets/stage/stageNPC/stageNPC (%d).png", 9, 1.0f, {iPointZero}},
	};

	for (int i = 0; i < NPCBehave_num; i++)
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
		img->_aniDt = 0.05f;

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
	setBehave(NPCBehave_idle, 0);
	direction = 0;

	
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

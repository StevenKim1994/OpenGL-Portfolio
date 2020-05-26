#include "Mushroom.h"

#include "GameUI.h"

#define Mush_HP 50
#define Mush_MP 100
#define Mush_Staminia 100

#define Mush_Width 10
#define Mush_Height 10

#define Mush_Speed 6.0

static iImage** imgMush = NULL;

Mushroom::Mushroom(int number)
{
	if (imgMush == NULL)
	{
		ObjInfo _oi[6] = {
			"assets/stage/mushroom/Idle (%d).png", 4, 2.5f, {-75,-100},
			"assets/stage/mushroom/Attack (%d).png", 8, 2.5f, {-75,-100},
			"assets/stage/mushroom/Idle (%d).png", 4, 2.5f, {-75, -75},
			"assets/stage/mushroom/Idle (%d).png", 4, 2.5f, {-75, -75},
			"assets/stage/mushroom/Idle (%d).png", 4, 2.5f, {-75, -75},
			"assets/stage/mushroom/Idle (%d).png", 4, 2.5f, {-75, -75},
		};

		iGraphics* g = iGraphics::instance();
		iSize size;

		imgMush = (iImage**)malloc(sizeof(iImage*) * 6);

		for (int i = 0; i < 6; i++)
		{
			iImage* img = new iImage();
			ObjInfo* oi = &_oi[i];
			for (int j = 0; j < oi->num; j++)
			{
				Texture* tex = createImage(oi->path, j + 1);
				tex->width *= oi->sizeRate;
				tex->height *= oi->sizeRate;
				tex->potWidth *= oi->sizeRate;
				tex->potHeight *= oi->sizeRate;
				img->addObject(tex);
				freeImage(tex);
		
			}

			switch (i)
			{
			//case 0:
			//	img->_repeatNum = 0;
			//	break;
				
			default:
				img->_repeatNum = 0;
				break;
			}
			img->_aniDt = 0.1f;
			img->position = oi->p * oi->sizeRate;
			imgMush[i] = img;
		}
	}

	mush_number = number;
	this->size = iSizeMake(16, 16);

	imgs = (iImage**)malloc(sizeof(iImage*) * 6);
	for (int i = 0; i < 6; i++)
		imgs[i] = imgMush[i]->copy();
	img = imgs[0];

	HP = Mush_HP;
	MP = Mush_MP;
	
	direction = 0;

	behave = EnermyBehave::EnermyBehave_NULL;
	setBehave(EnermyBehave::EnermyBehave_meleeAttack, direction);
}

Mushroom::~Mushroom()
{
	if (imgMush)
	{
		for (int i = 0; i < 6; i++)
			delete imgMush[i];

		free(imgMush);
		imgMush = NULL;

	}

	for (int i = 0; i < 6; i++)
		delete imgs[i];
	free(imgs);
}

void Mushroom::paint(float dt, iPoint offset, MapTile* tile, int NumX, int NumY)
{
	iPoint mushMovement = iPointMake(0, 1) * powGravity * dt;
	move(v + mushMovement, tile, NumX, NumY);
	img->paint(dt, position + offset, direction);
}

void Mushroom::setBehave(EnermyBehave be, int direction)
{
	if (behave != be || direction != direction)
	{
		behave = be;
		img = imgs[(int)be];
		
		if (be == EnermyBehave::EnermyBehave_idle)
			img->startAnimation(cbBehave, this);

		else if (be == EnermyBehave::EnermyBehave_meleeAttack)
			img->startAnimation(cbBehave, this);
			
	
		this->direction = direction;
	}
}

void Mushroom::Skill1()
{
}

void Mushroom::setDmg(float dmg)
{
}

void Mushroom::cbDeath(void* cb)
{
}

void Mushroom::cbHurt(void* cb)
{
}

void Mushroom::cbBehave(void* cb)
{
}

void Mushroom::setDetected_Player(bool check)
{
}

void Mushroom::setTarget(Object* obj)
{
}

bool Mushroom::getDetected_Player()
{
	return false;
}

Object* Mushroom::getTarget()
{
	return nullptr;
}

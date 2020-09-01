#include "GhostWarrior.h"
#include "GameUI.h"
#include "GameEffect.h"
#include "CoinFactory.h"

#define GhostWarrior_HP 200
#define GhostWarrior_MP 100
#define GhostWarrior_Stamina 100

#define GhostWarrior_Width 100
#define GhostWarrior_Height 100

static iImage** imgGhostWarrior = NULL;

GhostWarrior::GhostWarrior(int number)
{
	type = 2;
	if (imgGhostWarrior == NULL)
	{
		ObjInfo _oi[(int)ObjectBehave::ObjectBehave_num] = {
			"assets/stage/ghostwarrior/idle/"
		};

		iGraphics* g = iGraphics::instance();
		iSize size;

		imgGhostWarrior = (iImage**)malloc(sizeof(iImage*) * (int)ObjectBehave::ObjectBehave_num);

		for (int i = 0; i < (int)ObjectBehave::ObjectBehave_num; i++)
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
			case 0:
				break;

			default:
				break;
			}

			img->_aniDt = 0.1f;
			img->position = oi->p * oi->sizeRate;
			imgGhostWarrior[i] = img;

		}
	}

	//ghostwarrior_Num = number;
	
	this->size = iSizeMake(32, 32); //나중에 이건 바꿔야함

	imgs = (iImage**)malloc(sizeof(iImage*) * (int)ObjectBehave::ObjectBehave_num);

	for (int i = 0; i < (int)ObjectBehave::ObjectBehave_num; i++)
		imgs[i] = imgGhostWarrior[i]->copy();
	img = imgs[0];

	HP = GhostWarrior_HP;
	MP = GhostWarrior_MP;

	direction = 0;

	_speed = 10; // 나중에 이건 바꿔야함

	behave = ObjectBehave::ObjectBehave_NULL;
	setBehave(ObjectBehave::ObjectBehave_idle, direction);


}

GhostWarrior::~GhostWarrior()
{
}

void GhostWarrior::paint(float dt, iPoint offset, MapTile* tile, int NumX, int NumY)
{
}

void GhostWarrior::setBehave(ObjectBehave be, int direction)
{
}

void GhostWarrior::Skill1()
{
}

void GhostWarrior::Skill2()
{
}

void GhostWarrior::setDmg(float dmg)
{
}

void GhostWarrior::cbDeath(void* cb)
{
}

void GhostWarrior::cbBehave(void* cb)
{
}

void GhostWarrior::cbSkill(void* cb)
{
}

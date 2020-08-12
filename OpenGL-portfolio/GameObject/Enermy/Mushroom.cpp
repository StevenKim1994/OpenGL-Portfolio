#include "Mushroom.h"

#include "GameUI.h"
#include "../PlayerCharacter/Player.h"
#include "../GameObject/Prop/coin.h"
#include "GameEffect.h"
extern Object** coins;
extern int coinNum;

#define Mush_HP 50
#define Mush_MP 100
#define Mush_Staminia 100

#define Mush_Width 10
#define Mush_Height 10

#define Mush_Speed 1.0

static iImage** imgMush = NULL;

extern Object** heros;
extern Player* hero;

Mushroom::Mushroom(int number)
{
	type = 2;
	if (imgMush == NULL)
	{
		ObjInfo _oi[(int)ObjectBehave::ObjectBehave_num] = {
			"assets/stage/mushroom/Idle (%d).png", 4, 2.5f, {-75,-100},
			"assets/stage/mushroom/Attack (%d).png", 8, 2.5f, {-75,-100},
			"assets/stage/mushroom/Idle (%d).png", 4, 2.5f, {-75, -75},
			"assets/stage/mushroom/Idle (%d).png", 4, 2.5f, {-75, -75},
			"assets/stage/mushroom/Hurt (%d).png", 4, 2.5f, {-75, -100},
			"assets/stage/mushroom/Idle (%d).png", 4, 2.5f, {-75, -75},
			"assets/stage/mushroom/Hurt (%d).png", 4, 2.5f, {-75, -100},
		};

		iGraphics* g = iGraphics::instance();
		iSize size;

		imgMush = (iImage**)malloc(sizeof(iImage*) * (int)ObjectBehave::ObjectBehave_num);

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
				img->_repeatNum = 0;
				break;

			default:
				img->_repeatNum = 1;
				break;
			}
			img->_aniDt = 0.1f;
			img->position = oi->p * oi->sizeRate;
			imgMush[i] = img;
		}
	}

	mush_number = number;
	this->size = iSizeMake(16, 16);

	imgs = (iImage**)malloc(sizeof(iImage*) * (int)ObjectBehave::ObjectBehave_num);
	for (int i = 0; i < (int)ObjectBehave::ObjectBehave_num; i++)
		imgs[i] = imgMush[i]->copy();
	img = imgs[0];

	HP = Mush_HP;
	MP = Mush_MP;

	direction = 0;

	_speed = Mush_Speed;

	behave = ObjectBehave::ObjectBehave_NULL;
	setBehave(ObjectBehave::ObjectBehave_idle, direction);

	
}



Mushroom::~Mushroom()
{
	if (imgMush)
	{
		for (int i = 0; i < (int)ObjectBehave::ObjectBehave_num; i++)
			delete imgMush[i];

		free(imgMush);
		imgMush = NULL;

	}

	for (int i = 0; i < (int)ObjectBehave::ObjectBehave_num; i++)
		delete imgs[i];
	free(imgs);
}

void Mushroom::paint(float dt, iPoint offset, MapTile* tile, int NumX, int NumY)
{
	iPoint mushMovement = iPointMake(0, 1) * powGravity * dt;
	move(v + mushMovement, tile, NumX, NumY);
	img->paint(dt, position + offset);
	img->leftRight = direction;

	if (hero->getPosition().x > position.x) 
		direction = 1;

	else
		direction = 0;


	if (iPointLength(hero->getPosition() - position) < 150)
	{
		if (detected_Player == false)
		{

			int sx = position.x;
			sx /= MapTileWidth;

			int sy = position.y;
			sy /= MapTileHeight;

			int ex = hero->getPosition().x;
			ex /= MapTileWidth;

			int ey = hero->getPosition().y;
			ey /= MapTileHeight;

			detected_Player = true;

		}
	

		if (detected_Player)
		{
			speed += 0.05f;
			if (speed > _speed)
			{
				setBehave(ObjectBehave::ObjectBehave_meleeAttack1, direction);
				speed = 0.0f;
			}
		

		}

	}
	else
	{
	
		detected_Player = false;
		if (behave != ObjectBehave::ObjectBehave_hurt && behave != ObjectBehave::ObjectBehave_death)
			setBehave(ObjectBehave::ObjectBehave_idle, direction);
	}
	
}

void Mushroom::setBehave(ObjectBehave be, int dir)
{
	if (behave != be || direction != dir)
	{
		behave = be;
		img = imgs[(int)be];

		if (be == ObjectBehave::ObjectBehave_death)
			img->startAnimation(cbDeath, this);

		else if (be == ObjectBehave::ObjectBehave_meleeAttack1)
			img->startAnimation(cbSkill, this);

		else if (be == ObjectBehave::ObjectBehave_hurt)
			img->startAnimation(cbHurt, this);

		else
			img->startAnimation(cbBehave, this);

		direction = dir;
	}
}


void Mushroom::cbSkill(void* cb)
{
	printf("cbSkill1\n");
	Mushroom* o = (Mushroom*)cb;
	o->Skill1();
	o->setBehave(ObjectBehave::ObjectBehave_idle, o->direction);
	
}
void Mushroom::Skill1()
{
	if (this->direction)
	{
		// 플레이어의 1번 스킬처럼 몬스터도 똑같이 구현하기
	}
	else
	{

	}

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


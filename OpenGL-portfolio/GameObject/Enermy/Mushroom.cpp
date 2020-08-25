#include "Mushroom.h"

#include "GameUI.h"
#include "../PlayerCharacter/Player.h"
#include "../GameObject/Prop/coin.h"
#include "GameEffect.h"
extern Object** coins;
extern int coinNum;

#define Mush_HP 20
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
			"assets/stage/mushroom/Death/Death (%d).png", 4, 2.5f, {-75,-100},
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
	alive = true;

	// 스킬 1 로드
	iImage* imgS = new iImage();
	{
		for (int i = 1; i <= 22; i++)
		{
			iGraphics* g = iGraphics::instance();
			setRGBA(1, 1, 1, 1);
			Texture* tex = createImage("assets/stage/mushroom/Skill1/Projectile (%d).png", i);
			imgS->addObject(tex);
			freeImage(tex);
		}
		imgS->position = iPointMake(-300, -300);
		imgS->aniDt = 0.0f;
		imgS->_aniDt = 0.01f;
		imgS->_repeatNum = 1;
	

		imgSkill1 = imgS;
		setRGBA(1, 1, 1, 1);
	}
	
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

	if (imgSkill1->animation)
	{
		imgSkill1->leftRight = direction;
		imgSkill1->paint(dt, offset);
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
	float cool = 0.0f;
	bool collision = false;
	iPoint targetPos;
	printf("%f %f\n", position.x, position.y);
	if (direction == 0)
		targetPos = iPointMake(position.x - 376, position.y - 230);
	else
		targetPos = iPointMake(position.x , position.y - 230);


	imgSkill1->position = targetPos;
	imgSkill1->startAnimation();

	if (collision == false)
	{
		if (containPoint(hero->getPosition(), imgSkill1->touchRect()))
		{
			collision = true;
			hero->setHP(hero->getHp() - 10.0);
			hero-> setBehave(ObjectBehave::ObjectBehave_hurt, hero->direction);
			extern iStrTex* hpIndicator;
			hpIndicator->setString("%f", hero->getHp());

			if (hero->getHp() < 1)
				hero->alive = false;
		}
	}

	while (cool >= 10.0f)
		cool += 0.01f;

	printf("end\n");

}
void Mushroom::setDmg(float dmg)
{
	printf("%f\n", HP);
	ObjectBehave be = behave;
	int dir = direction;

	if (HP > 0)
	{
		HP -= dmg;
		be = ObjectBehave::ObjectBehave_hurt;
	}
	else
	{
		HP = 0;
		be = ObjectBehave::ObjectBehave_death;
	}
	setBehave(be, dir);
	addNumber(dmg, position + iPointMake(0, -50));
}

#include "../PlayerCharacter/Player.h"
#include "../GameObject/Prop/coin.h"
#include "../GameObject/CoinFactory.h"
extern Object** coins;
extern int coinNum;


void Mushroom::cbDeath(void* cb)
{
	Object* o = (Object*)cb;
	o->alive = false;

	hero->setExp(hero->getExp() + 10.0f);
//	addCoin(o->position, 300);
}

void Mushroom::cbHurt(void* cb)
{
}

void Mushroom::cbBehave(void* cb)
{
	iImage* i = (iImage*)cb;
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


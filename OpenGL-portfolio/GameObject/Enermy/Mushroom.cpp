#include "Mushroom.h"

#include "GameUI.h"
#include "../PlayerCharacter/Player.h"
#include "../GameObject/Prop/coin.h"
extern Object** coins;
extern int coinNum;

#define Mush_HP 50
#define Mush_MP 100
#define Mush_Staminia 100

#define Mush_Width 10
#define Mush_Height 10

#define Mush_Speed 6.0

static iImage** imgMush = NULL;

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
			"assets/stage/mushroom/Idle (%d).png", 4, 2.5f, {-75, -75},
			"assets/stage/mushroom/Idle (%d).png", 4, 2.5f, {-75, -75},
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

	imgs = (iImage**)malloc(sizeof(iImage*) * (int)ObjectBehave::ObjectBehave_num);
	for (int i = 0; i < (int)ObjectBehave::ObjectBehave_num; i++)
		imgs[i] = imgMush[i]->copy();
	img = imgs[0];

	HP = Mush_HP;
	MP = Mush_MP;
	
	direction = 0;

	behave = ObjectBehave::ObjectBehave_NULL;
	setBehave(ObjectBehave::ObjectBehave_idle, direction);

	iImage* img = new iImage();
	{ // 스클 불러오는 부분
		for (int i = 0; i < 22; i++)
		{

			iGraphics* g = iGraphics::instance();
			Texture* tex = createImage("assets/stage/mushroom/Skill1/Projectile (%d).png", i + 1);
	
			img->addObject(tex);
			freeImage(tex);
		}
	}

	img->aniDt = 0.0f;
	img->_aniDt = 0.15f;
	img->repeatNum = 1;

	imgSkill1 = img;
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

	if (iPointLength(hero->getPosition() - position) < 150) // 플레이어가 사정거리에 들어왔을시 투사체 발사
	{
		if (behave != ObjectBehave::ObjectBehave_hurt && behave != ObjectBehave::ObjectBehave_death)
		{ 
			setBehave(ObjectBehave::ObjectBehave_meleeAttack1, direction);
			
		}
	}
	else
	{
		if (behave != ObjectBehave::ObjectBehave_hurt && behave != ObjectBehave::ObjectBehave_death)
			setBehave(ObjectBehave::ObjectBehave_idle, direction);
	}
}

void Mushroom::setBehave(ObjectBehave be, int direction)
{
	if (behave != be || direction != direction)
	{
		behave = be;
		img = imgs[(int)be];
		
		if (be == ObjectBehave::ObjectBehave_idle)
			img->startAnimation(cbBehave, this);

		else if (be == ObjectBehave::ObjectBehave_meleeAttack1)
		{
			
			
			
		}
			
		this->direction = direction;
	}
	if(!img->animation)
		img->startAnimation(cbSkill1,this);
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

void Mushroom::cbSkill1(void* cb)
{
	printf("!!usb!\n");
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

void Mushroom::SKill1()
{


}

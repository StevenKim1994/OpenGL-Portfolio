#include "Orc.h"

#include "GameUI.h"

#define Orc_HP 20
#define Orc_MP 100
#define Orc_Stamina 100

#define Orc_Width 10
#define Orc_Height 10

#define Orc_Speed 3.0

static iImage** imgOrc = NULL;

Orc::Orc(int number)
{
	if (imgOrc == NULL)
	{
		struct OrcInfo
		{
			const char* path;
			int num;
			float sizeRate;
			iPoint p; // 축 조절하는 거

		};

		OrcInfo _oi[6] = {
			"assets/stage/goblin/goblin idle (%d).png", 4, 2.0f, {-75, -90} ,
			"assets/stage/goblin/goblin attack (%d).png", 8, 2.0f, {-75,-90},
			"assets/stage/goblin/goblin move (%d).png", 8, 2.0f, {-75, -90},
			"assets/stage/goblin/goblin move (%d).png", 8, 2.0f, {-75, -90},
			"assets/stage/goblin/goblin hurt (%d).png", 4, 2.0f, {-75, -90},
			"assets/stage/goblin/goblin death (%d).png", 4, 2.0f, {-75, -90},

		};
		iGraphics* g = iGraphics::instance();
		iSize size;

		imgOrc = (iImage**)malloc(sizeof(iImage*) * 6);
		for (int i = 0; i < 6; i++)
		{
			iImage* img = new iImage();
			OrcInfo* oi = &_oi[i];
			for (int j = 0; j < oi->num; j++)
			{
				Texture* tex = createImage(oi->path, j+1);
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
			case 2:
				img->_repeatNum = 0; // 무한반복
				break;

			default:
				img->_repeatNum = 1;
				break;
			}
			img->_aniDt = 0.1f;
			img->position = oi->p * 2;
			imgOrc[i] = img;
		}
	}

	orc_number = number;
	imgs = (iImage**)malloc(sizeof(iImage*) * 6);
	for (int i = 0; i < 6; i++)
		imgs[i] = imgOrc[i]->copy();
	img = imgs[0];

	float ai[5] = orcAiTime;
	aiTime = _aiTime = ai[number];

	// super class
	this->size = iSizeMake(Orc_Width, Orc_Height);

	HP = Orc_HP;
	MP = Orc_MP;

	Stamina = Orc_Stamina;
	speed = 0.0;
	_speed = Orc_Speed;

	movement = 100;

	direction = 0;
	jumpNum = 0;
	_jumpNum = 2;


	behave = EnermyBehave::EnermyBehave_NULL;
	setBehave(EnermyBehave::EnermyBehave_idle, 0);
}

Orc::~Orc()
{
	if (imgOrc)
	{
		for (int i = 0; i < 6; i++)
			delete imgOrc[i];
		free(imgOrc);
		imgOrc = NULL;
	}

	for (int i = 0; i < 6; i++)
		delete imgs[i];
	free(imgs);


}

#include "../PlayerCharacter/Player.h"
void Orc::cbDeath(void* cb)
{
	Orc* o = (Orc*)cb;
	o->alive = false;

	hero->kill++;
}

void Orc::cbHurt(void* cb)
{
	Orc* o = (Orc*)cb;
	o->setBehave(EnermyBehave::EnermyBehave_idle, o->direction);

}

void Orc::cbBehave(void* cb)
{
	iImage* i = (iImage*)cb;

}

void Orc::cbSkill(void* cb)
{
	Orc* o = (Orc*)cb;
	o->Skill1();
	o->setBehave(EnermyBehave::EnermyBehave_idle, o->direction);



}

#include "../game/stage.h"
void Orc::setDmg(float dmg)
{
	EnermyBehave be = behave;
	int dir = direction;

	HP -= dmg;
	if (HP > 0)
	{
		be = EnermyBehave::EnermyBehave_hurt;
	}
	else
	{
		HP = 0;
		be = EnermyBehave::EnermyBehave_death;
	}
	setBehave(be, dir);

	addNumber(dmg, position + iPointMake(0, -50));

}
void Orc::setBehave(EnermyBehave be, int dir)
{
	if (behave != be || direction != dir)
	{
		behave = be;
		img = imgs[(int)be];
		if (be == EnermyBehave::EnermyBehave_death)
			img->startAnimation(cbDeath, this);
		else if (be == EnermyBehave::EnermyBehave_hurt)
			img->startAnimation(cbHurt, this);
		else if (be == EnermyBehave::EnermyBehave_meleeAttack)
			img->startAnimation(cbSkill, this);
		else
			img->startAnimation(cbBehave, img);
		direction = dir;
	}
}

#include "stageTileInfo.h"

extern iShortestPath* sp;

void Orc::paint(float dt, iPoint offset, MapTile* tile, int NumX, int NumY)
{
	iPoint orcMovement = iPointMake(0, 1) * powGravity * dt;
	move(v + orcMovement, tile, NumX, NumY);

	img->paint(dt, position + offset, direction);

	direction = (position.x < targetPosition.x);

	// 플레이어 발견 했을때!
	if (iPointLength(hero->getPosition() - position) < 150)
	{
		if (detected_Player == false)
		{
			printf("orcs[%d] player detected!\n", orc_number);

			int sx = position.x;
			sx /= MapTileWidth;

			int sy = position.y;
			sy /= MapTileHeight;

			int ex = hero->getPosition().x;
			ex /= MapTileWidth;

			int ey = hero->getPosition().y;
			ey /= MapTileHeight;


			if (sy == ey) //세로 위치가 같을떄만 !
			{
				sp->dijkstra(sy * NumX + sx, ey * NumX + ex, path, pathNum);
				sp->removeDuplicate(path, pathNum);


				targetPosition = position;
				pathIndex = 1;
				detected_Player = true;
			}
		}


		if (detected_Player)
		{
			if (speed > _speed)
			{
				setBehave(EnermyBehave::EnermyBehave_meleeAttack, direction);
				speed = 0;
			}
			speed += 0.05f;

		}

		moveForMouse(dt, NumX, NumY);

	}
	else // 발견하지 못하였을때 또는 멀어졌을떄
	{

		pathNum = pathIndex;
		targetPosition = iPointZero;
		detected_Player = false;

		r += rValue * (1 + orc_number); // 오크인덱스

		float rateOrcV = _sin(r);
		float orcDir;


		v = iPointMake(rateOrcV, 0);

		if (v.x > 0)
			direction = 1;

		else
			direction = 0;

		setBehave(EnermyBehave::EnermyBehave_move, direction);

	}
}

void Orc::Skill1()
{

	extern Player* hero;

	if (hero->getPosition().x > position.x)
		hero->setPosition(hero->getPosition() - iPointMake(-10, 0)); // 넉백


	else
		hero->setPosition(hero->getPosition() - iPointMake(+10, 0));

	//zoomCamera(hero->getPosition(), 1.3);
	shakeCamera(25, 0.5);
	hero->setHP(hero->getHp() - 5.0);
	extern iStrTex* hpIndicator;
	hpIndicator->setString("%f", hero->getHp());

	if (hero->getHp() < 1)
		hero->alive = false;
}

void Orc::Skill2()
{
}

void Orc::setDetected_Player(bool check)
{
	detected_Player = check;
}

void Orc::setTarget(Object* obj)
{
	Target = obj;
	Target_Pos = obj->getPosition();
}

bool Orc::getDetected_Player()
{
	return detected_Player;
}

Object* Orc::getTarget()
{
	return Target;
}

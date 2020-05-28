#include "Goblin.h"

#include "GameUI.h"
#include "GameEffect.h"

#define Orc_HP 20
#define Orc_MP 100
#define Orc_Stamina 100

#define Orc_Width 10
#define Orc_Height 10

#define Orc_Speed 3.0

static iImage** imgOrc = NULL;

Goblin::Goblin(int number)
{
	type = 2;
	if (imgOrc == NULL)
	{
		struct OrcInfo
		{
			const char* path;
			int num;
			float sizeRate;
			iPoint p; // 축 조절하는 거

		};

		OrcInfo _oi[(int)ObjectBehave::ObjectBehave_num] = {
			"assets/stage/goblin/goblin idle (%d).png", 4, 2.0f, {-75, -90} ,
			"assets/stage/goblin/goblin attack (%d).png", 8, 2.0f, {-75,-90},
			"assets/stage/goblin/goblin attack (%d).png", 8, 2.0f, {-75,-90},
			"assets/stage/goblin/goblin move (%d).png", 8, 2.0f, {-75, -90},
			"assets/stage/goblin/goblin move (%d).png", 8, 2.0f, {-75, -90},
			"assets/stage/goblin/goblin move (%d).png", 8, 2.0f, {-75, -90},
			"assets/stage/goblin/goblin hurt (%d).png", 4, 2.0f, {-75, -90},
			"assets/stage/goblin/goblin death (%d).png", 4, 2.0f, {-75, -90},

		};
		iGraphics* g = iGraphics::instance();
		iSize size;

		imgOrc = (iImage**)malloc(sizeof(iImage*) * (int)ObjectBehave::ObjectBehave_num);
		for (int i = 0; i < (int)ObjectBehave::ObjectBehave_num; i++)
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
			case 3:
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

	goblin_number = number;
	imgs = (iImage**)malloc(sizeof(iImage*) * (int)ObjectBehave::ObjectBehave_num);
	for (int i = 0; i < (int)ObjectBehave::ObjectBehave_num; i++)
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


	behave = ObjectBehave::ObjectBehave_idle;
	setBehave(behave, 0);
}

Goblin::~Goblin()
{
	if (imgOrc)
	{
		for (int i = 0; i < (int)ObjectBehave::ObjectBehave_num; i++)
			delete imgOrc[i];
		free(imgOrc);
		imgOrc = NULL;
	}

	for (int i = 0; i < (int)ObjectBehave::ObjectBehave_num; i++)
		delete imgs[i];
	free(imgs);


}



#include "../PlayerCharacter/Player.h"
#include "../GameObject/Prop/coin.h"
extern Object** coins;
extern int coinNum;

void Goblin::cbDeath(void* cb)
{
	Object* o = (Object*)cb;
	o->alive = false;

	hero->setExp(hero->getExp() + 5.0f);
	addCoin(o->position, 100);	
}

void Goblin::cbBehave(void* cb)
{
	iImage* i = (iImage*)cb;

}

void Goblin::cbSkill(void* cb)
{
	
	Goblin* o = (Goblin*)cb;
	o->Skill1();
	o->setBehave(ObjectBehave::ObjectBehave_idle, o->direction);



}

#include "../game/stage.h"

void Goblin::setDmg(float dmg)
{
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
		hero->setExp(hero->getExp() + 5.0f);
		be = ObjectBehave::ObjectBehave_death;
	}
	setBehave(be, dir);
	addNumber(dmg, position + iPointMake(0, -50));

}
void Goblin::setBehave(ObjectBehave be, int dir)
{
	if (behave != be || direction != dir)
	{
		behave = be;
		img = imgs[(int)be];
		if (be == ObjectBehave::ObjectBehave_death)
			img->startAnimation(cbDeath, this);
		else if (be == ObjectBehave::ObjectBehave_hurt)
			img->startAnimation(cbHurt, this);
		else if (be == ObjectBehave::ObjectBehave_meleeAttack1)
			img->startAnimation(cbSkill, this);
		else
			img->startAnimation(cbBehave, img);
		direction = dir;
	}
}

#include "stageTileInfo.h"

extern iShortestPath* sp;

void Goblin::paint(float dt, iPoint offset, MapTile* tile, int NumX, int NumY)
{
	iPoint orcMovement = iPointMake(0, 1) * powGravity * dt;
	move(v + orcMovement, tile, NumX, NumY);

	img->paint(dt, position + offset);
	img->leftRight = direction;

	direction = (position.x < targetPosition.x);

	// 플레이어 발견 했을때!
	if (iPointLength(hero->getPosition() - position) < 150)
	{
		if (detected_Player == false)
		{
			printf("orcs[%d] player detected!\n",goblin_number);

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
				setBehave(ObjectBehave::ObjectBehave_meleeAttack1, direction);
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

		r += rValue * (1 + goblin_number); // 고블린인덱스

		float rateOrcV = _sin(r);
		float orcDir;


		v = iPointMake(rateOrcV, 0);

		if (v.x > 0)
			direction = 1;

		else
			direction = 0;

		if(behave != ObjectBehave::ObjectBehave_hurt && behave != ObjectBehave::ObjectBehave_death)
			setBehave(ObjectBehave::ObjectBehave_move, direction);

	}
}

void Goblin::Skill1()
{

	extern Player* hero;

	if (hero->getPosition().x > position.x)
		hero->setPosition(hero->getPosition() - iPointMake(-10, 0)); // 넉백


	else
		hero->setPosition(hero->getPosition() - iPointMake(+10, 0));

	//zoomCamera(hero->getPosition(), 1.3);
	shakeCamera(25, 0.5);
	audioPlay(5);
	hero->setHP(hero->getHp() - 5.0);
	hero->setBehave(ObjectBehave::ObjectBehave_hurt, hero->direction);
	extern iStrTex* hpIndicator;
	hpIndicator->setString("%f", hero->getHp());

	if (hero->getHp() < 1)
		hero->alive = false;
}

void Goblin::Skill2()
{
}

void Goblin::setDetected_Player(bool check)
{
	detected_Player = check;
}

void Goblin::setTarget(Object* obj)
{
	Target = obj;
	Target_Pos = obj->getPosition();
}

bool Goblin::getDetected_Player()
{
	return detected_Player;
}

Object* Goblin::getTarget()
{
	return Target;
}

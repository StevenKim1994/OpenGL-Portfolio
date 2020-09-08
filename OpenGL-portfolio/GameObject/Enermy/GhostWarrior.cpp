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
			"assets/stage/ghostwarrior/Idle/idle%d.png", 5, 2.0f, {-150, -270},
			"assets/stage/ghostwarrior/Attack/Attack%d.png", 11, 2.0f, {-150, -270},
			"assets/stage/ghostwarrior/Attack/Attack%d.png", 11, 2.0f, {-150, -270},
			"assets/stage/ghostwarrior/Fly/fly%d.png", 5, 2.0f, {-150,-270},
			"assets/stage/ghostwarrior/Fly/fly%d.png", 5, 2.0f, {-150,-270},
			"assets/stage/ghostwarrior/Fly/fly%d.png", 5, 2.0f, {-150,-270},
			"assets/stage/ghostwarrior/Hit/hit%d.png", 6, 2.0f, {-150,-270},
			"assets/stage/ghostwarrior/Death/death%d.png",8, 2.0f, {-150,-270},
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
				img->_repeatNum = 0;
				break;

			default:
				img->_repeatNum = 0; // 테스트용 설정 나중에 1로 바꿔야함
				break;
			}

			img->_aniDt = 0.1f;
			img->position = oi->p * oi->sizeRate;
			imgGhostWarrior[i] = img;

		}
	}

	//ghostwarrior_Num = number;
	
	this->size = iSizeMake(16,16); //나중에 이건 바꿔야함

	imgs = (iImage**)malloc(sizeof(iImage*) * (int)ObjectBehave::ObjectBehave_num);

	for (int i = 0; i < (int)ObjectBehave::ObjectBehave_num; i++)
		imgs[i] = imgGhostWarrior[i]->copy();
	img = imgs[0];

	HP = GhostWarrior_HP;
	MP = GhostWarrior_MP;

	direction = 0;

	speed = 0.0;
	_speed = 10; // 나중에 이건 바꿔야함

	movement = 100;
	behave = ObjectBehave::ObjectBehave_NULL;
	setBehave(ObjectBehave::ObjectBehave_idle, direction);


}

GhostWarrior::~GhostWarrior()
{
	if (imgGhostWarrior)
	{
		for (int i = 0; i < (int)ObjectBehave::ObjectBehave_num; i++)
			delete imgGhostWarrior[i];

		free(imgGhostWarrior);
		imgGhostWarrior = NULL;
	}

	for (int i = 0; i < (int)ObjectBehave::ObjectBehave_num; i++)
		delete imgs[i];
	free(imgs);
}

extern iShortestPath* sp;

void GhostWarrior::paint(float dt, iPoint offset, MapTile* tile, int NumX, int NumY)
{
	iPoint gwMovement = iPointMake(0, 1) * powGravity * dt;
	
	move(v + gwMovement, tile, NumX, NumY);

	img->paint(dt, position + offset);

	// 플레이어 발견 했을때!
	if (iPointLength(hero->getPosition() - position) < 150)
	{
		if (detected_Player == false)
		{
			printf("Player Detected!\n");

			detected_Player = true;
		}
		
	}

	if (detected_Player)
	{

		int sx = position.x;
		sx /= MapTileWidth;

		int sy = position.y;
		sy /= MapTileHeight;

		int ex = hero->getPosition().x;
		ex /= MapTileWidth;

		int ey = hero->getPosition().y;
		ey /= MapTileHeight;

		sp->dijkstra(sy * NumX + sx, ey * NumX + ex, path, pathNum);
		sp->removeDuplicate(path, pathNum);
		

		targetPosition = position;

		pathIndex = 1;
	
		if (targetPosition != position)
			setBehave(ObjectBehave::ObjectBehave_move, direction);

		moveForMouse(dt, NumX, NumY);
	}


	img->leftRight = direction;

	direction = (position.x > targetPosition.x);

}

void GhostWarrior::setBehave(ObjectBehave be, int dir)
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

void GhostWarrior::Skill1()
{
	extern Player* hero;

	if (hero->getPosition().x > position.x)
		hero->setPosition(hero->getPosition() - iPointMake(-10, 0));

	else
		hero->setPosition(hero->getPosition() - iPointMake(+10, 0));

	shakeCamera(25, 0.5);
	audioPlay(5);
	hero->setHP(hero->getHp() - 5.0);
	hero->setBehave(ObjectBehave::ObjectBehave_hurt, hero->direction);
	extern iStrTex* hpIndicator;
	hpIndicator->setString("%f", hero->getHp());

	if (hero->getHp() < 1)
		hero->alive = false;

}

void GhostWarrior::Skill2()
{
}

void GhostWarrior::setDmg(float dmg)
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
		be = ObjectBehave::ObjectBehave_death;
	}

	setBehave(be, dir);
	addNumber(dmg, position + iPointMake(0, -50));
}

void GhostWarrior::cbDeath(void* cb)
{
	Object* o = (Object*)cb;
	o->alive = false;

	hero->setExp(hero->getExp() + 100.0f);
	addCoin(o->position, 1000);

}

void GhostWarrior::cbBehave(void* cb)
{
	iImage* i = (iImage*)cb;

}

void GhostWarrior::cbSkill(void* cb)
{
	GhostWarrior* o = (GhostWarrior*)cb;
	o->Skill1();
	o->setBehave(ObjectBehave::ObjectBehave_idle, o->direction);
}

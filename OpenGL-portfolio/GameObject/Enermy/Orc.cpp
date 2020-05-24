#include "Orc.h"

#include "GameUI.h"

#define Orc_HP 20
#define Orc_MP 100
#define Orc_Stamina 100

#define Orc_Width 10
#define Orc_Height 10

#define Orc_Speed 3.0


Orc::Orc(int number)
{
	hitEffect = new iImage();
	orc_number = number;
	
	HP = Orc_HP;
	MP = Orc_MP;
	
	Stamina = Orc_Stamina;
	speed = 0.0;
	_speed = Orc_Speed;

	size = iSizeMake(Orc_Width, Orc_Height);
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

	imgs = (iImage**)malloc(sizeof(iImage*) * 6);

	for (int i = 0; i < 6; i++)
	{
		OrcInfo* oi = &_oi[i];

		iImage* img = new iImage();

		for (int j = 0; j < oi->num; j++)
		{
			igImage* ig = g->createIgImage(oi->path, j + 1);
			size = iSizeMake(g->getIgImageWidth(ig) * oi->sizeRate,
				g->getIgImageHeight(ig) * oi->sizeRate);

			g->init(size);
			g->drawImage(ig, 0, 0, oi->sizeRate, oi->sizeRate, TOP | LEFT);

			Texture* tex = g->getTexture();
			img->addObject(tex);
			freeImage(tex);
		}

		img->_aniDt = 0.1f;

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

		img->position = oi->p * 2;

		imgs[i] = img;

		movement = 100;
	}

	behave = (EnermyBehave)-1;
	setBehave(EnermyBehave_idle, 0);
	direction = 0;
	jumpNum = 0;
	_jumpNum = 2;

	
	iImage* imgHit = new iImage();

}

Orc::~Orc()
{
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
	o->hitEffect->position = o->position;
	o->hitEffect->startAnimation();
	o->setBehave(EnermyBehave_idle, o->direction);

}

void Orc::cbBehave(void* cb)
{
	iImage* i = (iImage*)cb;
		
}

void Orc::cbSkill(void* cb)
{
	Orc* o = (Orc*)cb;
	o->Skill1();
	o->setBehave(EnermyBehave_idle, o -> direction);

	
	
}

#include "../game/stage.h"
void Orc::setDmg(float dmg)
{
	hitEffect->startAnimation();
	EnermyBehave be = behave;
	int dir = direction;

	HP -= dmg;
	if (HP > 0)
	{
		be = EnermyBehave_hurt;
	}
	else
	{
		HP = 0;
		be = EnermyBehave_death;
	}
	setBehave(be, dir);

	addNumber(dmg, position + iPointMake(0, -50));
}
void Orc::setBehave(EnermyBehave be, int dir)
{
	if (behave != be || direction != dir)
	{
		behave = be;
		img = imgs[be];
		if (be == EnermyBehave_death)
			img->startAnimation(cbDeath, this);
		else if (be == EnermyBehave_hurt)
		{
			hitEffect->startAnimation();
			img->startAnimation(cbHurt, this);
		}
		else if (be == EnermyBehave_meleeAttack)
			img->startAnimation(cbSkill, this);
		else
			img->startAnimation(cbBehave, img);
		direction = dir;
	}
}

#include "stageTileInfo.h"
extern MapTile* maptile;

extern iShortestPath* sp;

void Orc::paint(float dt, iPoint offset)
{
	iPoint orcMovement = iPointMake(0, 1) * powGravity * dt;
	move(v + orcMovement, maptile);

	img->paint(dt, position + offset, direction);

	direction = (position.x < targetPosition.x);

	// 플레이어 발견 했을때!
	if (iPointLength(hero->getPosition() -position) < 150)
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
				sp->dijkstra(sy * MapTileNumX + sx, ey * MapTileNumX + ex, path, pathNum);
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
				setBehave(EnermyBehave_meleeAttack, direction);
				speed = 0;
			}
			speed += 0.05f;

		}
		
		moveForMouse(dt);

	}
	else // 발견하지 못하였을때 또는 멀어졌을떄
	{

		pathNum = pathIndex;
		//setBehave(EnermyBehave_idle, direction);
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
		
		setBehave(EnermyBehave_move, direction);

	}

	if(hitEffect->animation && hitEffect != NULL)
	{
		hitEffect->paint(dt, offset, direction);
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

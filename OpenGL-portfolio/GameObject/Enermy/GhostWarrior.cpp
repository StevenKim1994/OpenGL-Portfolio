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
extern iShortestPath* sp;
extern int Vilegetiles[40 * 22];
GhostWarrior::GhostWarrior(int number)
{
	movement = 2;
	oldPosition = position;
	
	sp->init(Vilegetiles, vilegeTileNumX, vilegeTileNumY);
	type = 2;
	if (imgGhostWarrior == NULL)
	{
		ObjInfo _oi[(int)ObjectBehave::ObjectBehave_num] = {
			"assets/stage/ghostwarrior/Idle/idle%d.png", 5, 2.0f, {-150, -270},
			"assets/stage/ghostwarrior/Attack/Attack%d.png", 11, 2.0f, {-150, -270},
			"assets/stage/ghostwarrior/Attack/Attack%d.png", 11, 2.0f, {-150, -270},
			"assets/stage/ghostwarrior/Fly/fly%d.png", 5, 2.0f, {-150,-270},
			"assets/stage/ghostwarrior/Fly/fly%6d.png", 5, 2.0f, {-150,-270},
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

			case 3:
			case 4:
			case 5:
				img->_repeatNum = 0;
				break;

			default:
				img->_repeatNum = 1; // 테스트용 설정 나중에 1로 바꿔야함
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

	movement = 225;
	behave = ObjectBehave::ObjectBehave_NULL;
	setBehave(ObjectBehave::ObjectBehave_idle, direction);

	_aiTime = 2.0f;


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


/*
보스의 알고리즘 패턴

플레이어와 거리 차가 500 이면 플레이어를 발견함 이때 부터 1페이즈 시작


보스의 상태
state (체력 + 시간)
1페이즈 초반(50% 체력까지, 페이즈 진입후 2분 초과시 바로 2페이즈 진입)      맵을 로밍하면서 플레이어 방향으로 큰 범위공격
2페이즈 중반(20% 체력까지, 페이즈 진입후 1분 초과시 바로 3페이즈 진입)      플레이어 주위에 지역범위 스킬(번개같은거 사용)
3페이즈 막반(무제한)                     다시 체력 100%
*/


void GhostWarrior::paint(float dt, iPoint offset, MapTile* tile, int NumX, int NumY)
{
	iPoint gwMovement = iPointMake(0, 1) * powGravity * dt ;
	iPoint mp = v * (movement * dt);

	if(action == false)
	move(mp  + gwMovement, tile, NumX, NumY);

	img->paint(dt, position + offset);

	// 플레이어 발견 했을때!
	if (iPointLength(hero->getPosition() - position) < 500 && detected_Player == false)
	{
		detected_Player = true;
		targetPosition = iPointMake(300, position.y);
		printf("Player Detected!\n");
	}
	
//	iPointMake(MapTileWidth * 35, MapTileHeight * 13)
	if (detected_Player)
	{
		Parse = 1;
	}
	
	if (Parse == 1)
	{
		parseDt += 0.01f;
		
		if (position != targetPosition)
		{
			setBehave(ObjectBehave::ObjectBehave_move, direction);
			moveForMouse(dt, NumX, NumY);
			
		}
		
		else
		{
			
			//v = iPointZero;
			
			if (aiTime >= _aiTime)
			{
			
				img->leftRight = direction;
				setBehave(ObjectBehave::ObjectBehave_meleeAttack1, direction);
				//공격이 끝나면 콜백함수로 aiTime = 0.0f; 해주기 
			}
			else
				setBehave(ObjectBehave::ObjectBehave_idle, direction);

			aiTime += 0.01f;
		}



		if (parseDt >= 120.0f || HP <= getMaxHp() * 0.5)
		{
			Parse = 2;
			parseDt = 0.0f;
		}
	}
	else if (Parse == 2)
	{

	}
	else if (Parse == 3)
	{
		setHP(getMaxHp()); // 다시 체력 100%로
		
		// 페이즈 1처럼 행동
	}

	
}

void GhostWarrior::setBehave(ObjectBehave be, int dir)
{
	if (behave != be || direction != dir)
	{
		direction = dir;
		behave = be;
		img = imgs[(int)be];
		if (be == ObjectBehave::ObjectBehave_death)
			img->startAnimation(cbDeath, this);
		else if (be == ObjectBehave::ObjectBehave_hurt)
			img->startAnimation(cbHurt, this);
		else if (be == ObjectBehave::ObjectBehave_meleeAttack1)
			img->startAnimation(cbMeleeAttack, this);
		else
			img->startAnimation(cbBehave, this);
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

void GhostWarrior::cbMeleeAttack(void* cb)
{
	GhostWarrior* o = (GhostWarrior*)cb;
	
	o->aiTime = 0.0f;

}

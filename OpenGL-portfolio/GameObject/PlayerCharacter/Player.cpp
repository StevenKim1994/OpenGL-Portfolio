#pragma once
#include "Player.h"
#include "Monster.h"
#include "GameUI.h"
#include "GameEffect.h"

#define Player_HP 100
#define Player_MP 100
#define Player_Stamina 100

Player::Player()
{
	memset(path, 0x00, sizeof(int) * 1024);
	pathIndex = pathNum;
	HP = Player_HP;
	MP = Player_MP;
	Stamina = Player_Stamina;

	ObjInfo _pi[(int)ObjectBehave::ObjectBehave_num] = {
		{"assets/stage/hero/Knight/hero idle (%d).png", 11, 1.5f, {-75, -80} },
		{"assets/stage/hero/Knight/hero melee2 (%d).png", 7, 1.5f, {-72, -80}},
		{"assets/stage/hero/Knight/hero melee1 (%d).png", 7, 1.5f, {-72, -80}},
		{"assets/stage/hero/Knight/hero move (%d).png",8, 1.5f, {-60, -80}},
		{"assets/stage/hero/Knight/hero jump (%d).png", 3, 1.5f, {-72, -80}},
		{"assets/stage/hero/Knight/hero fall (%d).png", 3, 1.5f, {-72, -80}},
		{"assets/stage/hero/Knight/hero takeHit (%d).png", 4, 1.5f, {-72, -80}},
		{"assets/stage/hero/Knight/hero death (%d).png", 11 , 1.5f, {-72, -80}},
	};
	iGraphics* g = iGraphics::instance();
	iSize size;

	iImage* img;
	Texture* tex;

	imgs = (iImage**)malloc(sizeof(iImage*) * 8);
	for (int i = 0; i < (int)ObjectBehave::ObjectBehave_num; i++)
	{
		ObjInfo* pi = &_pi[i];

		img = new iImage();
		for (int j = 0; j < pi->num; j++)
		{
			tex = createImage(pi->path, j + 1);
			tex->width *= pi->sizeRate;
			tex->height *= pi->sizeRate;
			tex->potWidth *= pi->sizeRate;
			tex->potHeight *= pi->sizeRate;
			img->addObject(tex);
			freeImage(tex);
		}
		img->_aniDt =  0.05f;

		switch (i)
		{
		case 0: 
		case 3:
			img->_repeatNum = 0;
			break;

		default:
			img->_repeatNum = 1;
		
			break;
		}


		img->position = pi->p*2;
	
		imgs[i] = img;
	}
	
	behave = ObjectBehave::ObjectBehave_NULL;
	setBehave(ObjectBehave::ObjectBehave_idle, 0);
	direction = 0;
	jumpNum = 0;
	_jumpNum = 2;

	iImage* ii[4];

	ObjInfo oi[4] = {
		// 근거리 스킬 불러오는 부분
		{"assets/stage/hero/Knight/skill/skill1 (%d).png", 4, 0.25, {-128, -128}, 0.15, 1},
		//근거리 타격이펙트 (Monster 오브젝트에 copy용)
		{"assets/stage/hero/knight/skill/hit/tile%03d.png", 31, 1.0, {0,0}, 0.01, 1},
		//버프스킬
		{"assets/stage/hero/knight/skill3/tile%03d.png", 61, 2.0, {-30, -100}, 0.01, 0, {1, 0, 0, 1}},
		// 원거리 스킬 불러오는 부분
		{"assets/stage/hero/Knight/skill2/tile%03d.png", 61, 2.0, {-30, -100}, 0.01, 0, }
	};
	for (int j = 0; j < 4; j++)
	{
		img = new iImage();
		int n = (j == 0 ? 1 : 0 );

		ObjInfo* o = &oi[j];
		for (int i = 0; i < o->num; i++)
		{
			//if (o->color == iColor4fMake(1, 1, 1, 1))
			//	tex = createImage(o->path, i + n);
			//else
				tex = createColorImage(o->color, o->path, i + n);
			tex->width     *= o->sizeRate;
			tex->height    *= o->sizeRate;
			tex->potHeight *= o->sizeRate;
			tex->potWidth  *= o->sizeRate;
			img->addObject(tex);
			freeImage(tex);
		}
		img->_aniDt = o->aniDt;
		img->_repeatNum = o->repeatNum;
		ii[j] = img;
	}
	imgSkill = ii[0];
	imgSKillHit = ii[1];
	imgBuff = ii[2];
	imgRange = ii[3];

	_CoolDown_SK1 = CoolDown_SK1 = 2;
	_CoolDown_SK2 = CoolDown_SK2 = 5;
	_CoolDown_SK3 = CoolDown_SK3 = 0;
}

Player::~Player()
{
	for (int i = 0; i < (int)ObjectBehave::ObjectBehave_num; i++)
		delete imgs[i];
	free(imgs);

	delete imgSkill;
	delete imgSKillHit;
	delete imgBuff;
	delete imgRange;
}

void Player::cbBehave(void* cb)
{

	printf("End Animation!\n");
	extern Player* hero;
	if(hero->behave != ObjectBehave::ObjectBehave_idle)
		hero->setBehave(ObjectBehave::ObjectBehave_idle, hero->direction);


}

void Player::setBehave(ObjectBehave be, int dir)
{
	
	if (behave != be || direction != dir)
	{
		printf("income\n");
		behave = be;
		img = imgs[(int)be];
		img->startAnimation(cbBehave);
		direction = dir;
	}
}

void Player::paint(float dt, iPoint offset)
{
	if(imgBuff->animation)
	{
		imgBuff->leftRight = direction;
		imgBuff->paint(dt, iPointMake(position.x -55, position.y -50)+ offset);
	}
	if (direction == 0 && behave == ObjectBehave::ObjectBehave_jump)
	{
		printf("left direction Jumping!\n");
		img->leftRight = direction;
		img->paint(dt, (position + offset) - iPointMake(0,0));
	}

	else
	{
		img->leftRight = direction;
		img->paint(dt, position + offset);
	}
	if (imgSkill->animation)
	{
		imgSkill->leftRight = direction;
		imgSkill->paint(dt, offset);
	}

	if(imgSKillHit->animation)
	{
		imgSKillHit->leftRight = direction;
		imgSKillHit->paint(dt, offset);
	}


}


void Player::cbSkill1(void* cb)
{

}

void Player::cbSkill2(void* cb)
{
}

void Player::cbSkill3(void* cb)
{
}


void Player::Skill1()
{
	if (MP < 5)
	{
		printf("MP enough\n");
		return;
	}
	if (CoolDown_SK1 < _CoolDown_SK1)
		return;

	MP -= 5;
	CoolDown_SK1 = 0.0f;

	printf("skill1! on!\n");
		
	audioPlay(4);
	iPoint targetPos = iPointZero;
	if (direction == 1)
		targetPos = iPointMake(position.x + 10, position.y - 100);
	else if (direction == 0)
		targetPos = iPointMake(position.x - 128, position.y - 100);
	imgSkill->position = targetPos;
	imgSkill->startAnimation();
}

extern Object** goblins;
extern int goblinNum;

void Player::Skill2()
{
	if (MP < 10 && (hero->CoolDown_SK2 - hero->_CoolDown_SK2 != 0))
	{
		printf("MP enough\n");
		return;
	}
	if (CoolDown_SK2 < _CoolDown_SK2)
		return;

	MP -= 10;
	CoolDown_SK2 = 0.0f;

	printf("skill2! on!\n");

	audioPlay(8);
	addProjectile(0, hero->getPosition(), hero->direction, 10, (Object**)goblins, goblinNum);

}

void Player::Skill3()
{
	if (MP >= 1)
	{
		printf("skill3! on!\n");
		
		//imgBuff->position = iPointMake(position.x -50, position.y-50);
		if (imgBuff->animation)
		{
			imgBuff->animation = false;
			damage -= 5.0f;
		}
		else
		{
			printf("mana use!\n");
			imgBuff->startAnimation();
			damage += 5.0f;
			//MP--;
		}
	}
}

//Override
bool Player::moveForMouse(float dt, int NumX, int NumY)
{
	
	if (position.x < targetPosition.x)
		setBehave(ObjectBehave::ObjectBehave_move, 1);

	else
		setBehave(ObjectBehave::ObjectBehave_move, 0);
	

	
	if (position != targetPosition)
	{
		if (position.x < targetPosition.x)
		{
			position.x += movement * dt;
			if (position.x > targetPosition.x)
				position.x = targetPosition.x;


		}
		else if (position.x > targetPosition.x)
		{
			position.x -= movement * dt;
			if (position.x < targetPosition.x)
				position.x = targetPosition.x;
		}

		if (position.y < targetPosition.y)
		{
			position.y += movement * dt;
			if (position.y > targetPosition.y)
				position.y = targetPosition.y;
		}
		else if (position.y > targetPosition.y)
		{
			position.y -= movement * dt;
			if (position.y < targetPosition.y)
				position.y = targetPosition.y;
		}
	}
	else
	{
		if (pathIndex < pathNum)
		{
			int index = path[pathIndex];
			targetPosition.x = MapTileWidth * (index % NumX) + MapTileWidth / 2;
			targetPosition.y = MapTileHeight * (index / NumX) + MapTileHeight / 2;
			pathIndex++;
		}
		else
			return true;
	}
	return false;

}
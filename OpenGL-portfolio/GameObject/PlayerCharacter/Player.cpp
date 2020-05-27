#pragma once
#include "Player.h"
#include "Monster.h"

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
	
	struct PlayerInfo
	{
		const char* path;
		int num;
		float sizeRate;
		iPoint p;
	};

	PlayerInfo _pi[8] = {
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
	

	imgs = (iImage**)malloc(sizeof(iImage*) * 8);
	for (int i = 0; i < 8; i++)
	{
		PlayerInfo* pi = &_pi[i];

		iImage* img = new iImage();
		for (int j = 0; j < pi->num; j++)
		{
			Texture* tex = createImage(pi->path, j + 1);
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

	iImage* img = new iImage();

	{// 근거리 스킬 불러오는 부분

		for (int i = 0; i < 4; i++)
		{
			iGraphics* g = iGraphics::instance();
			Texture* tex = createImage("assets/stage/hero/Knight/skill/skill1 (%d).png", i + 1);
			tex->width *= 0.25;
			tex->height *= 0.25;
			tex->potHeight *= 0.25;
			tex->potWidth *= 0.25;
			img->addObject(tex);
			freeImage(tex);
		}
		img->aniDt = 0.0f;
		img->_aniDt = 0.15f;
		img->_repeatNum = 1;

		iPoint p = iPointMake(-128, -128);
		img->position = p;

		imgSkill = img;
	}

	
	//근거리 타격이펙트 (Monster 오브젝트에 copy용)
	iImage* img2 = new iImage();
	{
		for(int i = 0; i<31; i++)
		{
			iGraphics* g = iGraphics::instance();
			setRGBA(1, 0, 0, 1);
			Texture* tex = createImage("assets/stage/hero/knight/skill/hit/tile%03d.png", i);
			img2->addObject(tex);
			freeImage(tex);
		}
		img2->aniDt = 0.0f;
		img2->_aniDt = 0.01f;
		img2->_repeatNum = 1;
		

		imgSKillHit = img2;
		setRGBA(1, 1, 1, 1);	
	}


	//버프스킬
	iImage* img3 = new iImage();
	{
		for (int i = 0; i < 61; i++)
		{
			iGraphics* g = iGraphics::instance();
	
			//Texture* tex = createImage("assets/stage/hero/knight/skill2/tile%03d.png", i);
			Texture* tex = createColorImage(iColor4fMake(1, 0, 0, 1), "assets/stage/hero/knight/skill3/tile%03d.png", i);
			tex->width *= 2.0;
			tex->potWidth *= 2.0f;
			tex->height *= 2.0f;
			tex->potHeight *= 2.0f;

			
			/*
			igImage* ig = g->createIgImage("assets/stage/hero/knight/skill2/tile%03d.png", i);
			iSize skillsize = iSizeMake(g->getIgImageWidth(ig) * 2.0, g->getIgImageHeight(ig) * 2.0);
			g->init(skillsize);
			g->drawImage(ig, 0, 0, 2.0, 2.0, TOP | LEFT);

			tex = g->getTexture();
			*/
			img3->addObject(tex);
			freeImage(tex);
		}
		img3->aniDt = 0.0f;
		img3->_aniDt = 0.01f;
		img3->_repeatNum = 0; // on / off skill임
		img3->position = iPointMake(-30, -100);
		imgBuff = img3;

		setRGBA(1, 1, 1, 1);
	}

	
	iImage* img4 = new iImage();
	{// 원거리 스킬 불러오는 부분
		for (int i = 0; i < 61; i++)
		{
			Texture* tex = createImage("assets/stage/hero/Knight/skill2/tile%03d.png", i);
			tex->width *= 2.0;
			tex->potWidth *= 2.0;
			tex->height *= 2.0;
			tex->potHeight *= 2.0;

			img4->addObject(tex);
			freeImage(tex);

		}
		img4->_aniDt = 0.01f;
		img4->repeatNum = 0;
		img4->position = iPointMake(-30, -100);
		imgRange = img4;
		
		
	}
	
	
}

Player::~Player()
{
	for (int i = 0; i < 4; i++)
		delete imgs[i];
	free(imgs);

	delete imgSkill;
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

//iImage* skill;// = new iImage();

void Player::cbSkill(void* cb)
{



}





void Player::Skill1()
{
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

void Player::Skill2()
{
	printf("skill2! on!\n");


}

void Player::Skill3()
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
		imgBuff->startAnimation();
		damage += 5.0f;
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
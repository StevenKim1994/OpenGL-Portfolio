#include "Player.h"


#define Player_HP 100
#define Player_MP 100
#define Player_Stamina 100

Player::Player()
{
	memset(path, 0x00, sizeof(int) * MapTileNumX * MapTileNumY);
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

	PlayerInfo _pi[4] = {
		{"assets/stage/hero/Knight/hero_idle (%d).png", 15, 2.0f, {-30, -38} },
		{"assets/stage/hero/Knight/hero_melee (%d).png", 22, 2.0f, {-72, -38}},
		{"assets/stage/hero/Knight/hero_move (%d).png",8, 2.0f, {-48, -38}},
		{"assets/stage/hero/Knight/hero_jumpAndFall (%d).png", 14, 2.0f, {-48, -38}}
	};
	iGraphics* g = iGraphics::instance();
	iSize size;
	

	imgs = (iImage**)malloc(sizeof(iImage*) * 4);
	for (int i = 0; i < 4; i++)
	{
		PlayerInfo* pi = &_pi[i];

		iImage* img = new iImage();
		for (int j = 0; j < pi->num; j++)
		{
			igImage* ig = g->createIgImage(pi->path, j + 1);
			size = iSizeMake(	g->getIgImageWidth(ig) * pi->sizeRate,
								g->getIgImageHeight(ig) * pi->sizeRate);
			g->init(size);
			g->drawImage(ig, 0, 0, pi->sizeRate, pi->sizeRate, TOP | LEFT);

			Texture* tex = g->getTexture();
			img->addObject(tex);
			freeImage(tex);
		}
		img->_aniDt =  0.05f;

		switch (i)
		{
		case 0: 
		case 2:
			img->_repeatNum = 0;
			break;

		default:
			img->_repeatNum = 1;
		
			break;
		}


		img->position = pi->p*2;
	
		imgs[i] = img;
	}
	
	behave = (Behave)-1;
	setBehave(Behave_idle, 0);
	direction = 0;
	jumpNum = 0;
	_jumpNum = 2;

	iImage* img = new iImage();

	{// 근거리 스킬 불러오는 부분
		
		for (int i = 0; i < 4; i++) 
		{
			iGraphics* g = iGraphics::instance();
			//Texture* tex = createImage("assets/stage/hero/Knight/skill/skill1 (%d).png", i + 1);
			igImage* ig = g->createIgImage("assets/stage/hero/Knight/skill/skill1 (%d).png", i + 1);
			iSize skillsize = iSizeMake(g->getIgImageWidth(ig) * 0.25, g->getIgImageHeight(ig) * 0.25);
			g->init(skillsize);
			g->drawImage(ig, 0, 0, 0.25, 0.25, TOP | LEFT);
			tex = g->getTexture();


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

	{// 원거리 스킬 불러오는 부분
		

		
	}
	
	
}

Player::~Player()
{
	for (int i = 0; i < 4; i++)
		delete imgs[i];
	free(imgs);

	delete imgSkill;
}

void Player::cbBehave(iImage* me)
{

	printf("End Animation!\n");
	extern Player* hero;
	if(hero->behave != Behave_idle)
		hero->setBehave(Behave_idle, hero->direction);
}

void Player::setBehave(Behave be, int dir)
{
	
	if (behave != be || direction != dir)
	{
		printf("income\n");
		behave = be;
		img = imgs[be];
		img->startAnimation(cbBehave);
		direction = dir;
	}
}

void Player::paint(float dt, iPoint offset)
{
	if (direction == 0 && behave == Behave_jumpAndFall)
	{
		printf("left direction Jumping!\n");
		img->paint(dt, (position + offset) - iPointMake(100,0), direction);
	}

	else
		img->paint(dt, position + offset, direction);
	if (imgSkill->animation)
	{
		imgSkill->paint(dt, offset, direction);
	}
}

//iImage* skill;// = new iImage();

void Player::cbSkill(iImage* me)
{
//	printf("end skill!\n");
//	delete skill;

}



void Player::Skill1()
{
	printf("skill1! on!\n");
	iPoint targetPos;
	if (direction == 1)
		targetPos = iPointMake(position.x + 10, position.y - 100);
	else if (direction == 0)
		targetPos = iPointMake(position.x - 128, position.y - 100);
	imgSkill->position = targetPos;
	imgSkill->startAnimation();
}

void Player::Skill2()
{
}

void Player::Skill3()
{
}




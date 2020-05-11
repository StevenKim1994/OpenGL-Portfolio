#include "Player.h"


Player::Player()
{
	struct PlayerInfo
	{
		const char* path;
		int num;
		float sizeRate;
		iPoint p;
	};

	PlayerInfo _pi[4] = {
		{"assets/stage/hero/Knight/hero_idle (%d).png", 15, 2.0f, {-32, -38} },
		{"assets/stage/hero/Knight/hero_melee (%d).png", 22, 2.0f, {-72, -32}},
		{"assets/stage/hero/Knight/hero_move (%d).png",8, 2.0f, {-48, -38}},
		{"assets/stage/hero/Knight/hero_jumpAndFall (%d).png", 14, 2.0f, {-75, -32}}
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
		img->_aniDt =  0.1f;
		//img->repeatNum =  (i % 2 == 0 ? 0 : 1);
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
}

Player::~Player()
{
	for (int i = 0; i < 4; i++)
		delete imgs[i];
	free(imgs);
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
	// direct;
	switch (direction)
	{
	case 1:
		break;

	case 2:
		break;
	}

		img->paint(dt,offset);
}




void Player::Skill1()
{
}

void Player::Skill2()
{
}

void Player::Skill3()
{
}




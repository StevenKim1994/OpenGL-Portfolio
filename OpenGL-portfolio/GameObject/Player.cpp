#include "Player.h"


Player::Player()
{
	struct PlayerInfo
	{
		const char* path;
		int num;
		float sizeRate;
	};

	PlayerInfo _pi[4] = {
		{"assets/stage/hero/Knight/hero_idle (%d).png", 15, 3.0f },
		{"assets/stage/hero/Knight/hero_melee (%d).png", 22, 3.0f},
		{"assets/stage/hero/Knight/hero_move (%d).png",8, 3.0f},
		{"assets/stage/hero/Knight/hero_jumpAndFall (%d).png", 14, 3.0f}
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
		img->repeatNum =  (i % 2 == 0 ? 0 : 1);
	
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
	//for(int i=0; i< Behave_num; i++)
	//{
	//	
	//	if (me == hero->imgs[i])
	//	{
	//		if( i%2==1)
	//		return;
	//	}
	//}
	extern Player* hero;
	hero->setBehave(Behave_idle, hero->direction);
}

void Player::setBehave(Behave be, int dir)
{
	if (behave != be || direction != dir)
	{
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

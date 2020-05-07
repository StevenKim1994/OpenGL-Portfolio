#include "Player.h"

Player::Player()
{

	
	idle = new iImage();
	meleeAttack = new iImage();
	moving = new iImage();
	jumping = new iImage();
	hurt = new iImage();
	fall = new iImage();
	jumpAndFall = new iImage();

	float sizeRate = 3.0f;

	iGraphics* g = iGraphics::instance();
	iSize size;



	// IDLE ANIMATION
	for (int i = 0; i < idle_aniNum; i++)
	{
		Texture* tex;
		igImage* ig = g->createIgImage("assets/stage/hero/Knight/hero_idle (%d).png", i + 1);
		size = iSizeMake(g->getIgImageWidth(ig) * sizeRate, g->getIgImageHeight(ig) * sizeRate);
		g->init(size);
		g->drawImage(ig, 0, 0, sizeRate, sizeRate, TOP | LEFT);

		tex = g->getTexture();

		idle->addObject(tex);
		freeImage(tex);
	}

	idle->_aniDt = 0.1f; 
	idle->repeatNum = 0; 
	idle->animation = true;

	// MELEEATTACK ANIMATION
	for (int i = 0; i < meleeAttack_aniNum; i++)
	{
		Texture* tex;
		igImage* ig = g->createIgImage("assets/stage/hero/Knight/hero_melee (%d).png", i + 1);
		size = iSizeMake(g->getIgImageWidth(ig) * sizeRate, g->getIgImageHeight(ig)*sizeRate);
		g->init(size);
		g->drawImage(ig, 0, 0, sizeRate, sizeRate, TOP | LEFT);

		tex = g->getTexture();

		meleeAttack->addObject(tex);
		freeImage(tex);
	}

	meleeAttack->_aniDt = 0.1f;
	meleeAttack->repeatNum = 1;
	meleeAttack->animation = true;


	// MOVE ANIAMATION
	for (int i = 0; i < move_aniNum; i++)
	{
		Texture* tex;
		igImage* ig = g->createIgImage("assets/stage/hero/Knight/hero_move (%d).png", i + 1);
		size = iSizeMake(g->getIgImageWidth(ig) * sizeRate, g->getIgImageHeight(ig) * sizeRate);
		g->init(size);
		g->drawImage(ig, 0, 0, sizeRate, sizeRate, TOP | LEFT);

		tex = g->getTexture();

		moving->addObject(tex);
		freeImage(tex);
	}

	moving->_aniDt = 0.1f;
	moving->repeatNum = 0;
	moving->animation = true;

	// JUMP AND FALL ANIMATION;
	for (int i = 0; i < jumpAndFall_aniNum; i++)
	{
		Texture* tex;
		igImage* ig = g->createIgImage("assets/stage/hero/Knight/hero_jumpAndFall (%d).png", i + 1);
		size = iSizeMake(g->getIgImageWidth(ig) * sizeRate, g->getIgImageHeight(ig) * sizeRate);
		g->init(size);
		g->drawImage(ig, 0, 0, sizeRate, sizeRate, TOP | LEFT);

		tex = g->getTexture();

		jumpAndFall->addObject(tex);
		freeImage(tex);
	}

	jumpAndFall->_aniDt = 0.1f;
	jumpAndFall->repeatNum = 1;
	jumpAndFall->animation = true;

	// HURT ANIAMTION
	for (int i = 0; i < hurt_aniNum; i++)
	{
		Texture* tex;
		igImage* ig = g->createIgImage("assets/stage/hero/Knight/hero_hurt (%d).png", i + 1);
		size = iSizeMake(g->getIgImageWidth(ig) * sizeRate, g->getIgImageHeight(ig) * sizeRate);
		g->init(size);
		g->drawImage(ig, 0, 0, sizeRate, sizeRate, TOP | LEFT);

		tex = g->getTexture();

		hurt->addObject(tex);
		freeImage(tex);

	}
		


	



}

Player::~Player()
{
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

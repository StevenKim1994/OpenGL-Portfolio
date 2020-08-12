#pragma once

#include "GameEffect.h"
#include "../game/sceneManager.h"
#include "Goblin.h"

struct Damage
{
	iStrTex* stDamage;
	iPoint p;
	float delta;

	bool paint(float dt, iPoint off);
};
#define Damage_delta 1.0f

Damage* _damage;
Damage** damage;
int damageNum;
#define _damageNum 100

Texture* methodStDamage(const char* str);

void loadNumber()
{
	_damage = (Damage*)malloc(sizeof(Damage) * _damageNum);
	for (int i = 0; i < _damageNum; i++)
	{
		Damage* d = &_damage[i];
		d->stDamage = new iStrTex(methodStDamage);
		d->p = iPointZero;
		d->delta = Damage_delta;
	}

	damage = (Damage**)malloc(sizeof(Damage*) * _damageNum);
	damageNum = 0;
}

void freeNumber()
{
	for (int i = 0; i < _damageNum; i++)
		delete _damage[i].stDamage;
	free(_damage);
	free(damage);
}
void drawNumber(float dt, iPoint off)
{
	for (int i = 0; i < damageNum; i++)
	{
		if (damage[i]->paint(dt, off))
		{
			damageNum--;
			for (int j = i; j < damageNum; j++)
				damage[j] = damage[1 + j];
			i--;
		}

	}
}
void addNumber(int dmg, iPoint position)
{
	for (int i = 0; i < _damageNum; i++)
	{
		Damage* d = &_damage[i];
		if (d->delta >= Damage_delta)
		{
			d->stDamage->setString("%d", dmg);
			d->p = position;
			d->delta = 0.0f;

			damage[damageNum] = d;
			damageNum++;
			return;
		}
	}
}

struct EffectHit
{
	iImage* img;
	iPoint p;
	int dir;

	bool paint(float dt, iPoint off)
	{
		img->paint(dt, p + off);
		img->leftRight = dir;
		if (img->animation)
			return false;
		return true;
	}
};
EffectHit** _ehEffectHit;
EffectHit** ehEffectHit;
int ehNum;
#define _ehNum 100

void loadEffectHit()
{
	int i;

	_ehEffectHit = (EffectHit**)malloc(sizeof(EffectHit*) * 1);

	iImage* img = new iImage();
	for (i = 0; i < 31; i++)
	{
		Texture* tex = createImage("assets/stage/hero/Knight/skill/hit/tile%d.png", i);
		img->addObject(tex);
		freeImage(tex);
	}
	img->position = iPointMake(-48, -48);
	img->_aniDt = 0.001f;
	img->_repeatNum = 1;

	_ehEffectHit[0] = (EffectHit*)malloc(sizeof(EffectHit) * _ehNum);
	for (i = 0; i < _ehNum; i++)
		_ehEffectHit[0][i].img = img->copy();

	delete img;

	ehEffectHit = (EffectHit**)malloc(sizeof(EffectHit*) * 1 * _ehNum);
	ehNum = 0;
}

void freeEffectHit()
{
	for (int j = 0; j < 1; j++)
	{
		for (int i = 0; i < _ehNum; i++)
			delete _ehEffectHit[j][i].img;
		free(_ehEffectHit[j]);
	}
	free(_ehEffectHit);
	free(ehEffectHit);
}

void drawEffectHit(float dt, iPoint off)
{
	setRGBA(1, 0, 0, 1);
	for (int i = 0; i < ehNum; i++)
	{
		if (ehEffectHit[i]->paint(dt, off))
		{
			ehNum--;
			for (int j = i; j < ehNum; j++)
				ehEffectHit[j] = ehEffectHit[1 + j];
		}
	}
	setRGBA(1, 1, 1, 1);
}

void addEffectHit(int index, iPoint p)
{
	for (int i = 0; i < _ehNum; i++)
	{
		EffectHit* eh = &_ehEffectHit[index][i];
		if (eh->img->animation == false)
		{
			eh->p = p;
			eh->dir = 0;
			eh->img->startAnimation();

			ehEffectHit[ehNum] = eh;
			ehNum++;
			return;
		}
	}
}

extern Object** orcs;
struct Projectile
{
	iImage* img;
	iPoint p;
	int dir;
	int speed;
	//int targetNum;
	iSize rectSize = iSizeMake(32, 32);
	//Object** target;
	int shooter; // 0 : player , 1: enermy;
	float damage;

	bool paint(float dt, iPoint off)
	{

		if (dir == 1)
			p += iPointMake(1, 0) * speed;
		else
			p += iPointMake(-1, 0) * speed;
		img->paint(dt, p + off);
		img->leftRight = dir;

		/*
		extern int gameState;

		
			for (int i = 0; i < targetNum; i++)
			{

				if (gameState == 1)
				{
					if (containPoint(iPointMake(p.x, p.y + 32), iRectMake(target[i]->position.x, target[i]->position.y, 64, 64)))
					{

						if (((Monster*)target[i])->type == 2)
						{
							((Goblin*)target[i])->setDmg(7);
							addEffectHit(0, target[i]->position);
							//zoomCamera(target[i]->position, 1.5);
							return true;
						}

					}
				}
			}
		*/
		

		if (img->animation)
			return false;


		return true;

	}
};

Projectile** _projectile;
Projectile** projectile;
int projectNum;
#define _projectNum 100

void loadProjectile()
{
	int i;
	_projectile = (Projectile**)malloc(sizeof(Projectile*) * 2); // 0 : 플레이어 2 번스킬 , 1 : Mushroom 투사체

	iImage* img = new iImage();
	for (int i = 0; i < 61; i++)
	{
		Texture* tex = createImage("assets/stage/hero/Knight/skill2/tile%03d.png", i);
		img->addObject(tex);
		freeImage(tex);
	}
	img->position = iPointMake(-60, -60);
	img->_aniDt = 0.01f;
	img->_repeatNum = 0;

	_projectile[0] = (Projectile*)malloc(sizeof(Projectile) * _projectNum);
	for (i = 0; i < _projectNum; i++)
		_projectile[0][i].img = img->copy();

	delete img;

	img = new iImage();
	for (int i = 0; i < 22; i++)
	{
		Texture* tex = createImage("assets/stage/mushroom/Skill1/Projectile (%d).png", i + 1);
		img->addObject(tex);
		freeImage(tex);
	}

	img->position = iPointMake(-188, -188);
	img->_aniDt = 0.03f;
	img->_repeatNum = 1;

	_projectile[1] = (Projectile*)malloc(sizeof(Projectile) * _projectNum);

	for (i = 0; i < _projectNum; i++)
		_projectile[1][i].img = img->copy();

	delete img;



	projectile = (Projectile**)malloc(sizeof(Projectile*) * 2 * _projectNum);
	projectNum = 0;




}

void freeProjectile()
{
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < _projectNum; i++)
			delete _projectile[j][i].img;

		free(_projectile[j]);
	}
	free(_projectile);
	free(projectile);
}

#include "Player.h"
extern Player* hero;
extern Object** goblins;
extern Monster** mushrooms;
extern int goblinNum;
extern int mushNum;


void drawProjectile(float dt, iPoint off)
{
	for (int i = 0; i < projectNum; i++)
	{
		//printf("%f ,%f shot \n", projectile[i]->p.x, projectile[i]->p.y);
		if (projectile[i]->paint(dt, off))
		{
			projectNum--;
			for (int j = i; j < projectNum; j++)
				projectile[j] = projectile[1 + j];
		}
		if (projectile[i]->shooter == 0) // 발사한 오브젝트가 player 일때
		{
			if (goblinNum > 0) // 고블린이 살아 있으면
			{
				for (int j = 0; j < goblin_Num; j++)
				{
			

					if (containPoint(projectile[i]->p, iRectMake(goblins[j]->position.x - 16, goblins[j]->position.y - 16, 32, 32)))
					{
						// 데미지 주는곳
						goblins[j]->setBehave(ObjectBehave::ObjectBehave_hurt, goblins[j]->direction);
					}

				}
			}
			
			if (mushNum > 0 ) // 버섯이 살아있으면
			{
				for (int j = 0; j < mush_Num; j++)
				{
					//printf("projectile %f %f\n", projectile[i]->p.x, projectile[i]->p.y);
					//printf("mush %f %f\n", mushrooms[j]->position.x, mushrooms[j]->position.y);
					
					if (containPoint(projectile[i]->p, iRectMake(mushrooms[j]->position.x -55, mushrooms[j]->position.y - 35 , 110 ,70)))
					{
						printf("mushrooms[%d] hit!\n", j);
					}

				}
			}
		}
		else if (projectile[i]->shooter == 1) // 발사한 오브젝트가 enermy 일때
		{
			if (containRect(projectile[i]->img->touchRect(), hero->img->touchRect())) // 적이 쏜 투사체와 플레이어가 충돌하였을때
			{
				printf("player hit!\n");
			}
		}

	}
}

void addProjectile(int index, iPoint p, int direction, int speed, int shooter)// Object** ObjTarget, int TargetNum)
{
	for (int i = 0; i < _projectNum; i++)
	{
		Projectile* pj = &_projectile[index][i];
		if (pj->img->animation == false)
		{
			pj->p = p;
			pj->dir = direction;
			pj->speed = speed;
			pj->img->startAnimation();
			//pj->target = ObjTarget;
			//pj->targetNum = TargetNum;
			pj->shooter = shooter;

			projectile[projectNum] = pj;
			projectNum++;
			return;
		}

	}
}



bool Damage::paint(float dt, iPoint off)
{
	float r = delta / Damage_delta;
	iPoint pp = p + off + iPointMake(0, -easeIn(r, 0, 200));
	float a = 1.0f - r;
	setRGBA(1, 1, 1, a);
	stDamage->paint(pp.x, pp.y, VCENTER | HCENTER);
	setRGBA(1, 1, 1, 1);

	delta += dt;
	if (delta < Damage_delta)
		return false;
	return true;
}


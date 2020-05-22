#pragma once

#include "iStd.h"
#include "drawObject.h"
#include "Player.h"
#include "Orc.h"
#include "sceneManager.h"

extern iPoint offMt;
extern Texture* tileset[1521];
extern Texture* endStageTileset[1521];
extern MapTile* maptile;
extern Player* hero;
extern bool mouseMove;

extern Monster** orcs;
extern int orcNum;
extern iStrTex* killIndicator;



void drawMapTile(float dt)
{
	int i, num = MapTileNumX * MapTileNumY;

	setRGBA(1, 1, 1, 1);
	{ // MapTilePaint

		for (i = 0; i < num; i++) // layer 0
		{
			MapTile* t = &maptile[i];

			float x = offMt.x + MapTileWidth * (i % MapTileNumX);
			float y = offMt.y + MapTileHeight * (i / MapTileNumX);

			if (i > 879)
			{
				setRGBA(1, 1, 1, 1);
				drawImage(tileset[i - 880], x, y, TOP | LEFT);
			}
			else
			{
				setRGBA(0.63137, 0.94901, 0.92549, 1);
				fillRect(x, y, 32, 32);
			}

#if _DEBUG // tileHitbox
			switch (t->attr)
			{
				//case canMove: break;
				//case canNotMove: setRGBA(0, 1, 1, 1); drawRect(x, y, MapTileWidth, MapTileHeight); break;
				//case deadZone:	setRGBA(1, 0, 0, 1); drawRect(x, y, MapTileWidth, MapTileHeight); break;
				//case nextStagePortal: setRGBA(0, 1, 1, 1); drawRect(x, y, MapTileWidth, MapTileHeight); break;
			}
#endif

		}

	}

}

void drawHero(float dt)
{
	uint32 keyStat = 0;
	uint32 keyDown = 0;

	iPoint movement = iPointMake(0, 1) * powGravity * dt;
	hero->applyJump(movement, dt);

	if (getKeyDown() & keyboard_space) // 윗점프
	{
		if (hero->getStamina() > 50.0f)
		{
			hero->setStamina(hero->getStamina() - 50.0f);
			hero->jump();

			if (hero->behave != PlayerBehave_meleeAttack)
			{
				keyStat = getKeyStat();
				keyDown = getKeyDown();
			}
			iPoint v = iPointZero;
			PlayerBehave be;
			if (keyStat & keyboard_left) v.x = -1;
			else if (keyStat & keyboard_right) v.x = 1;
			//if (keyStat & keyboard_up) v.y = -1;
			else if (keyStat & keyboard_down) v.y = 1;
		}
	}

	if (getKeyDown() & keyboard_down) // 아래점프 아래바닥보다 한칸밑이 갈수 있는곳이면 아랫점프를 시도함!
	{

		int sx = hero->getPosition().x;
		sx /= MapTileWidth;

		int sy = hero->getPosition().y;
		sy /= MapTileHeight;
		sy += 2;// 아랫칸인덱스

		if (tiles[sy * MapTileNumX + sx] == canMove)
		{
			iPoint jumpVector = iPointMake(hero->getPosition().x, hero->getPosition().y + 1);
			hero->setPosition(jumpVector);
		}
	}

	if (hero->behave != PlayerBehave_meleeAttack)
	{
		keyStat = getKeyStat();
		keyDown = getKeyDown();
	}
	iPoint v = iPointZero;
	PlayerBehave be;
	if (keyStat & keyboard_left) v.x = -1;
	else if (keyStat & keyboard_right) v.x = 1;
	//if (keyStat & keyboard_up) v.y = -1;
	else if (keyStat & keyboard_down) v.y = 1;




	if (hero->alive)
	{

		if (mouseMove) // 마우스 입력이 있을때
		{
			if (hero->moveForMouse(dt))
				mouseMove = false;

			if (v != iPointZero)
			{
				mouseMove = false;
				hero->setTargetPosition(hero->getPosition());
				hero->pathNum = hero->pathIndex;
			}
		}
		else // 키보드 입력일때
		{

			if (keyDown & keyboard_num1)
			{
				be = PlayerBehave_meleeAttack;

				hero->Skill1();

				zoomCamera(hero->getPosition() + offMt, 1.5);
				shakeCamera(30);

				extern int gameState;
				//printf("%f %f \n", imgSkill->touchRect().origin.x, imgSkill->touchRect().origin.y); // 스킬 출력 위치
				switch (gameState)
				{
				case gs_stage:
					for (int i = 0; i < orc_Num; i++)
					{
						//printf("orc %d : x: %f, y : %f\n",i, enermy[i]->getPosition().x, enermy[i]->getPosition().y); // 몬스터 충돌 위치
						if (containPoint(orcs[i]->getPosition(), hero->imgSkill->touchRect()))
						{
							((Orc*)orcs[i])->setDmg(5.f);
						}
					}
					break;

				case gs_endStage:

					break;
				}
			}


			else if (keyDown & keyboard_space)
				be = PlayerBehave_jumpAndFall;
			else if (keyDown & keyboard_down)
				be = PlayerBehave_idle;
			else if (keyDown & keyboard_up)
				be = PlayerBehave_jumpAndFall;
			else
				be = (v == iPointZero ? PlayerBehave_idle : PlayerBehave_move);
			int dir = hero->direction;


			if (v.x < 0) dir = 0;
			else if (v.x > 0) dir = 1;

			if (hero->behave != PlayerBehave_meleeAttack && hero->behave != PlayerBehave_jumpAndFall)
				hero->setBehave(be, dir);
			float minX, maxX, minY, maxY;

			if (v != iPointZero)
			{
				v /= iPointLength(v);
				iPoint mp = v * (hero->getMovement() * dt);
				hero->move(mp + movement, maptile);

				minX = devSize.width * 0.333333f;
				maxX = devSize.width * 0.666667f;
				minY = devSize.height * 0.333333f;
				maxY = devSize.height * 0.666667f;
			}
			else// if(v == iPointZero)
			{
				hero->move(movement * 3, maptile);

				minX = devSize.width / 2;
				maxX = devSize.width / 2;
				minY = devSize.height / 2;
				maxY = devSize.height / 2;
			}


			iPoint vp = offMt + hero->getPosition();
			if (vp.x < minX)
			{
				// 왼쪽으로 넘어갔을 경우

				offMt.x += (minX - vp.x) * dt;
				if (offMt.x > 0)
					offMt.x = 0;
			}
			else if (vp.x > maxX)
			{

				// 오른쪽으로 넘어갔을 경우
				offMt.x += (maxX - vp.x) * dt;
				if (offMt.x < devSize.width - MapTileWidth * MapTileNumX)
					offMt.x = devSize.width - MapTileWidth * MapTileNumX;
			}
			if (vp.y < minY)
			{
				// 위로 넘어갔을 경우
				offMt.y += (minY - vp.y) * dt;
				if (offMt.y > 0)
					offMt.y = 0;
			}
			else if (vp.y > maxY)
			{
				// 아래로 넘어갔을 경우
				offMt.y += (maxY - vp.y) * dt;
				if (offMt.y < devSize.height - MapTileHeight * MapTileNumY)
					offMt.y = devSize.height - MapTileHeight * MapTileNumY;
			}
		}
	}

	setRGBA(1, 1, 1, 1);
	hero->paint(dt, offMt);
	setRGBA(1, 1, 1, 1);

	//printf("%f %f || ", offMt.x, offMt.y);
	//printf("%f %f\n", hero->getPosition().x - offMt.x, hero->getPosition().y - offMt.y);
}

void drawOrc(float dt)
{ // paint Orc
	for (int i = 0; i < orcNum; i++)
	{
		if (orcs[i]->alive == false)
		{
			orcNum--;
			delete orcs[i];
			orcs[i] = orcs[orcNum];
			continue;
		}
		orcs[i]->paint(dt, offMt);
	}

	killIndicator->setString("%d", hero->kill);
}

#if _DEBUG
void debugHitbox(float dt)
{
	//hitbox orc
	for (int i = 0; i < orcNum; i++)
		drawRect((orcs[i]->getPosition().x - orcs[i]->getSize().width / 2) + offMt.x, (orcs[i]->getPosition().y - orcs[i]->getSize().height) + offMt.y, orcs[i]->getSize().width, orcs[i]->getSize().height);

	//hitbox player
	drawRect((hero->getPosition().x - hero->getSize().width / 2) + offMt.x,
		(hero->getPosition().y - hero->getSize().height) + offMt.y, hero->getSize().width, hero->getSize().height);
}

#endif

extern int endStagetiles[MapTileNumX * MapTileNumY];
void drawEndStageMapTile(float dt)
{

	int i, num = MapTileNumX * MapTileNumY;

	setRGBA(1, 1, 1, 1);
	{ // MapTilePaint

		for (i = 0; i < num; i++) // layer 0
		{
			MapTile* t = &maptile[i];
			t->attr = endStagetiles[i];
			float x = offMt.x + MapTileWidth * (i % MapTileNumX);
			float y = offMt.y + MapTileHeight * (i / MapTileNumX);

			if (i > 879)
			{
				setRGBA(1, 1, 1, 1);
				drawImage(endStageTileset[i - 880], x, y, TOP | LEFT);
			}
			else
			{
				setRGBA(0.63137, 0.94901, 0.92549, 1);
				fillRect(x, y, 32, 32);
			}

#if _DEBUG // tileHitbox
			switch (t->attr)
			{
				case canMove: break;
				case canNotMove: setRGBA(0, 1, 1, 1); drawRect(x, y, MapTileWidth, MapTileHeight); break;
				case deadZone:	setRGBA(1, 0, 0, 1); drawRect(x, y, MapTileWidth, MapTileHeight); break;
				
			}
#endif

		}

	}



}

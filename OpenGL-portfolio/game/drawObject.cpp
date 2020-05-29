#pragma once


#include "drawObject.h"


extern iPoint offMt;

extern MapTile* maptile;
extern Player* hero;
extern bool mouseMove;

extern Object** goblins;
extern int goblinNum;
extern iStrTex* killIndicator;

extern iStrTex* hpIndicator;
extern iStrTex* mpIndicator;
extern iStrTex* staminaIndicator;
extern iStrTex* expIndicator;
extern iStrTex* skillIndicator[3];
extern int gameState;

void drawMapTile(float dt, int* tiledata,MapTile* tileInfo,Texture** tileset, int NumX, int NumY)
{
	int i, num = NumX * NumY;

	setRGBA(1, 1, 1, 1);
	{ // MapTilePaint

		for (i = 0; i < num; i++) // layer 0
		{
			MapTile* t = &tileInfo[i];

			float x = offMt.x + MapTileWidth * (i % NumX);
			float y = offMt.y + MapTileHeight * (i / NumX);

			if (gameState < gs_villege)
			{
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
			}
			else
			{
				setRGBA(1, 1, 1, 1);
				drawImage(tileset[i], x, y, TOP | LEFT);
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

void drawMinimapTile(float dt, int* tiledata, MapTile* tileInfo, Texture** tileset, int NumX, int NumY)
{
	int i, num = NumX * NumY;

	setRGBA(1, 1, 1, 1);
	{ // MapTilePaint

		for (i = 0; i < num; i++) // layer 0
		{
			MapTile* t = &tileInfo[i];

			float x = offMt.x + MapTileWidth * (i % NumX);
			float y = offMt.y + MapTileHeight * (i / NumX);

			
				setRGBA(0, 0, 0, 1);
				fillRect(x, y, 32, 32);
			

#if _DEBUG // tileHitbox
			switch (t->attr)
			{
			case canMove: break;
			case canNotMove: setRGBA(1, 1, 1, 1); drawRect(x, y, MapTileWidth, MapTileHeight); break;
			case deadZone:	setRGBA(1, 1, 1, 1); drawRect(x, y, MapTileWidth, MapTileHeight); break;
			case nextStagePortal: setRGBA(1, 1, 1, 1); drawRect(x, y, MapTileWidth, MapTileHeight); break;
			}
#endif

		}

	}
}

extern Player* minimapHero;

void drawMinimapHero(float dt, int* tiledata, MapTile* tile, int NumX, int NumY)
{
		minimapHero->direction = hero->direction;
		minimapHero->position = hero->position;
		uint32 keyStat = 0;
		uint32 keyDown = 0;

		iPoint movement = iPointMake(0, 1) * powGravity * dt;
		minimapHero->applyJump(movement, dt);

		if (getKeyDown() & keyboard_space) // 윗점프
		{
			if (minimapHero->getStamina() > 50.0f)
			{
				minimapHero->setStamina(minimapHero->getStamina() - 50.0f);
				minimapHero->jump();
				

				if (minimapHero->behave != ObjectBehave::ObjectBehave_meleeAttack1)
				{
					keyStat = getKeyStat();
					keyDown = getKeyDown();
				}
				iPoint v = iPointZero;
				ObjectBehave be;
				if (keyStat & keyboard_left) v.x = -1;
				else if (keyStat & keyboard_right) v.x = 1;
				//if (keyStat & keyboard_up) v.y = -1;
				else if (keyStat & keyboard_down) v.y = 1;
			}
		}

		if (getKeyDown() & keyboard_down) // 아래점프 아래바닥보다 한칸밑이 갈수 있는곳이면 아랫점프를 시도함!
		{

			int sx = minimapHero->getPosition().x;
			sx /= MapTileWidth;

			int sy = minimapHero->getPosition().y;
			sy /= MapTileHeight;
			sy += 2;// 아랫칸인덱스

			if (tiledata[sy * NumX + sx] == canMove)
			{
				iPoint jumpVector = iPointMake(minimapHero->getPosition().x, minimapHero->getPosition().y + 1);
				minimapHero->setPosition(jumpVector);
			}
		}

		if (minimapHero->behave != ObjectBehave::ObjectBehave_meleeAttack1)
		{
			keyStat = getKeyStat();
			keyDown = getKeyDown();
		}
		iPoint v = iPointZero;
		ObjectBehave be;
		if (keyStat & keyboard_left) v.x = -1;
		else if (keyStat & keyboard_right) v.x = 1;
		//if (keyStat & keyboard_up) v.y = -1;
		else if (keyStat & keyboard_down) v.y = 1;




		if (minimapHero->alive)
		{

			if (mouseMove) // 마우스 입력이 있을때
			{
				if (minimapHero->moveForMouse(dt, NumX, NumY))
					mouseMove = false;

				if (v != iPointZero)
				{
					mouseMove = false;
					minimapHero->setTargetPosition(minimapHero->getPosition());
					minimapHero->pathNum = minimapHero->pathIndex;
				}
			}
			else // 키보드 입력일때
			{

				if (keyDown & keyboard_space)
					be = ObjectBehave::ObjectBehave_jump;
				else if (keyDown & keyboard_down)
					be = ObjectBehave::ObjectBehave_idle;

				else
					be = (v == iPointZero ? ObjectBehave::ObjectBehave_idle : ObjectBehave::ObjectBehave_move);
				int dir = minimapHero->direction;


				if (v.x < 0) dir = 0;
				else if (v.x > 0) dir = 1;

				if (minimapHero->behave != ObjectBehave::ObjectBehave_meleeAttack1 && minimapHero->behave != ObjectBehave::ObjectBehave_meleeAttack2 && hero->behave != ObjectBehave::ObjectBehave_jump && hero->behave != ObjectBehave::ObjectBehave_hurt)
					minimapHero->setBehave(be, dir);
				float minX, maxX, minY, maxY;

				if (v != iPointZero)
				{
					v /= iPointLength(v);
					iPoint mp = v * (minimapHero->getMovement() * dt);
					minimapHero->move(mp + movement, tile, NumX, NumY);

					minX = devSize.width * 0.333333f;
					maxX = devSize.width * 0.666667f;
					minY = devSize.height * 0.333333f;
					maxY = devSize.height * 0.666667f;
				}
				else// if(v == iPointZero)
				{
					minimapHero->move(movement * 3, tile, NumX, NumY);

					minX = devSize.width / 2;
					maxX = devSize.width / 2;
					minY = devSize.height / 2;
					maxY = devSize.height / 2;
				}


				iPoint vp = offMt + minimapHero->getPosition();
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
					if (offMt.x < devSize.width - MapTileWidth * NumX)
						offMt.x = devSize.width - MapTileWidth * NumX;
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
					if (offMt.y < devSize.height - MapTileHeight * NumY)
						offMt.y = devSize.height - MapTileHeight * NumY;
				}
			}
		}

		setRGBA(1, 1, 1, 1);
		fillRect(minimapHero->getPosition().x+offMt.x, minimapHero->getPosition().y+offMt.y, 32, 32);
		setRGBA(1, 1, 1, 1);

	
}

void meleeAttackCb()
{
	ObjectBehave be = ObjectBehave::ObjectBehave_meleeAttack2;
	hero->setBehave(be, hero->direction);
}

void drawHero(float dt, int* tiledata, MapTile* tile, int NumX, int NumY)
{
	void* playercb = NULL;
	uint32 keyStat = 0;
	uint32 keyDown = 0;

	iPoint movement = iPointMake(0, 1) * powGravity * dt;
	
	hero->applyJump(movement, dt);


	if (getKeyDown() & keyboard_space) // 윗점프
	{
		if (hero->getStamina() > 50.0f)
		{
			hero->setStamina(hero->getStamina() - 50.0f);
			ObjectBehave be;
			be = ObjectBehave::ObjectBehave_jump;
			hero->setBehave(be, hero->direction);
			hero->jump();


			if (hero->behave != ObjectBehave::ObjectBehave_meleeAttack1)
			{
				keyStat = getKeyStat();
				keyDown = getKeyDown();
			}
			iPoint v = iPointZero;
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

		if (tiledata[sy * NumX + sx] == canMove)
		{
			iPoint jumpVector = iPointMake(hero->getPosition().x, hero->getPosition().y + 1);
			hero->setPosition(jumpVector);
		}
	}

	if (hero->behave != ObjectBehave::ObjectBehave_meleeAttack1)
	{
		keyStat = getKeyStat();
		keyDown = getKeyDown();
	}
	iPoint v = iPointZero;
	ObjectBehave be;
	if (keyStat & keyboard_left) v.x = -1;
	else if (keyStat & keyboard_right) v.x = 1;
	//if (keyStat & keyboard_up) v.y = -1;
	else if (keyStat & keyboard_down) v.y = 1;




	if (hero->alive)
	{

		if (mouseMove) // 마우스 입력이 있을때
		{
			if (hero->moveForMouse(dt, NumX, NumY))
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
				
				be = ObjectBehave::ObjectBehave_meleeAttack1;

				hero->Skill1();
				//hero->setMP(hero->getMp() - 5.0f);
				zoomCamera(hero->getPosition() + offMt, 1.5);
				shakeCamera(30);

				extern int gameState;
			
				switch (gameState)
				{
				case gs_stage:
					for (int i = 0; i < goblin_Num; i++)
					{
				
						if (containPoint(goblins[i]->getPosition(), hero->imgSkill->touchRect()))
						{
							Goblin* goblin = (Goblin*)goblins[i];
							goblin->setDmg(hero->getDamage());
							addEffectHit(0, goblin->getPosition());
						}
					}
					break;

				case gs_endStage:

					break;
				}
			}
			else if (keyDown & keyboard_num2)
			{
				be = ObjectBehave::ObjectBehave_meleeAttack2;
				hero->Skill2();
				
			}
			else if (keyDown & keyboard_num3)
			{
				be = ObjectBehave::ObjectBehave_idle;
				hero->Skill3();
				
			
			}


			else if (keyDown & keyboard_space && hero->getStamina() > 49)
				be = ObjectBehave::ObjectBehave_jump;
			else if (keyDown & keyboard_down)
				be = ObjectBehave::ObjectBehave_idle;
			else
				be = (v == iPointZero ? ObjectBehave::ObjectBehave_idle : ObjectBehave::ObjectBehave_move);

			
			int dir = hero->direction;


			if (v.x < 0) dir = 0;
			else if (v.x > 0) dir = 1;

			if (hero->behave != ObjectBehave::ObjectBehave_meleeAttack1 &&hero->behave != ObjectBehave::ObjectBehave_meleeAttack2 && hero->behave != ObjectBehave::ObjectBehave_jump && hero->behave != ObjectBehave::ObjectBehave_hurt)
				hero->setBehave(be, dir);
			float minX, maxX, minY, maxY;

			if (v != iPointZero)
			{
				v /= iPointLength(v);
				iPoint mp = v * (hero->getMovement() * dt);
				hero->move(mp + movement, tile, NumX, NumY);

				minX = devSize.width * 0.333333f;
				maxX = devSize.width * 0.666667f;
				minY = devSize.height * 0.333333f;
				maxY = devSize.height * 0.666667f;
			}
			else// if(v == iPointZero)
			{
				hero->move(movement * 3, tile, NumX, NumY);

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
				if (offMt.x < devSize.width - MapTileWidth * NumX)
					offMt.x = devSize.width - MapTileWidth * NumX;
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
				if (offMt.y < devSize.height - MapTileHeight * NumY)
					offMt.y = devSize.height - MapTileHeight * NumY;
			}
		}
	}

	setRGBA(1, 1, 1, 1);
	hero->paint(dt, offMt);
	setRGBA(1, 1, 1, 1);

	if(hero->imgBuff->animation)
	{
		hero->setMP(hero->getMp() - 0.25f);

		if (hero->getMp() < 1)
		{
			hero->imgBuff->animation = false;
			hero->setDamage(hero->getDamage() - 5.0f);
		}
	}


	//MP charge
	if (hero->getMp() != hero->getMaxMP())
	{
		hero->setMP(hero->getMp() + 0.1f);
		mpIndicator->setString("%0.1f", (hero->getMp()));

		if (hero->getMp() > hero->getMaxMP())
			hero->setMP(hero->getMaxMP());
	}


	//stamina charge
	if (hero->getStamina() != hero->getMaxStamina())
	{
		hero->setStamina(hero->getStamina() + 0.1f);
		staminaIndicator->setString("%f", (hero->getStamina()));

		if (hero->getStamina() > hero->getMaxStamina())
			hero->setStamina(hero->getMaxStamina());
	}

	
	hero->CoolDown_SK1 += dt;
	if (hero->CoolDown_SK1 > hero->_CoolDown_SK1)
	{
		hero->CoolDown_SK1 = hero->_CoolDown_SK1;
	}

	hero->CoolDown_SK2 += dt;
	if (hero->CoolDown_SK2 > hero->_CoolDown_SK2)
	{
		hero->CoolDown_SK2 = hero->_CoolDown_SK2;
	}

	hero->CoolDown_SK3 += dt;
	if (hero->CoolDown_SK3 > hero->_CoolDown_SK3)
	{
		hero->CoolDown_SK3 = hero->_CoolDown_SK3;
	}

	if (hero->_CoolDown_SK1 - hero->CoolDown_SK1 > 0)
	{
		skillIndicator[0]->setString("%1.0f", hero->_CoolDown_SK1 - hero->CoolDown_SK1);
	}
	else
	{
		skillIndicator[0]->setString("On!");
	}

	if (hero->_CoolDown_SK2 - hero->CoolDown_SK2 > 0)
	{
		skillIndicator[1]->setString("%1.0f", hero->_CoolDown_SK2 - hero->CoolDown_SK2);
	}
	else
	{
		skillIndicator[1]->setString("On!");
	}

	if (hero->_CoolDown_SK3 - hero->CoolDown_SK3 > 0)
	{
		skillIndicator[2]->setString("%1.0f", hero->_CoolDown_SK3 - hero->CoolDown_SK3);
	}
	else
	{
		skillIndicator[2]->setString("On!");
	}


	expIndicator->setString("%f", (hero->getExp()));
}

void drawGoblin(float dt, int* tiledata ,MapTile* tile, int NumX, int NumY)
{ // paint Orc
	for (int i = 0; i < goblinNum; i++)
	{
		if (goblins[i]->alive == false)
		{
			
			goblinNum--;
			delete goblins[i];
			goblins[i] = goblins[goblinNum];
			continue;
		}
		((Goblin*)goblins[i])->paint(dt, offMt, tile, NumX, NumY);
	}

	killIndicator->setString("%d", hero->kill);
	
}



#if _DEBUG
void debugHitbox(float dt, int* tiledata, MapTile* tile, int NumX, int NumY)
{


	//hitbox orc
	if(goblins != NULL)
	for (int i = 0; i < goblinNum; i++)
		drawRect((goblins[i]->getPosition().x - goblins[i]->getSize().width / 2) + offMt.x, (goblins[i]->getPosition().y - goblins[i]->getSize().height) + offMt.y, goblins[i]->getSize().width, goblins[i]->getSize().height);

	//hitbox player
	if(hero != NULL)
	drawRect((hero->getPosition().x - hero->getSize().width / 2) + offMt.x,
		(hero->getPosition().y - hero->getSize().height) + offMt.y, hero->getSize().width, hero->getSize().height);
}



#endif

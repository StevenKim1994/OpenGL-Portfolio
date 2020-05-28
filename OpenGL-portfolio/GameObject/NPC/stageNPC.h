#pragma once

#include "iStd.h"
#include "NPC.h"


class stageNPC : public NPC
{
private:



public:
	stageNPC();
	virtual ~stageNPC();

	iImage** imgs;
	iImage* img;


	int direction;

	static void cbBehave(void* cb);
	static void cbSkill(void* cb);


	void setBehave(ObjectBehave be, int dir);
	void paint(float dt, iPoint offset);




};
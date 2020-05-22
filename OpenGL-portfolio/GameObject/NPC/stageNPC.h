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

	NPCBehave behave;
	int direction;

	static void cbBehave(void* cb);
	static void cbSkill(void* cb);


	void setBehave(NPCBehave be, int dir);
	void paint(float dt, iPoint offset);




};
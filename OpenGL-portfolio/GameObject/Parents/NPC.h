#pragma once
#include "Object.h"

struct NPCInfo
{
	const char* path;
	int num;
	float sizeRate;
	iPoint p;
};


enum class NPCBehave
{
	NPCBehave_NULL = -1,
	NPCBehave_idle = 0,
	NPCBehave_num,
};

class NPC : public Object
{
public:
	NPC();
	virtual ~NPC();


	void setBehave(NPCBehave be, int direction);
	void paint(float dt, iPoint offset);

	
};
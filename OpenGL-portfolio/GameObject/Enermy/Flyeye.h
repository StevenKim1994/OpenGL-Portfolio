#pragma once

#include "iStd.h"

#include "Monster.h"

class Flyeye : public Monster
{
public:
	Flyeye();
	virtual ~Flyeye();

	static void cbBehave(void* cb);

private:
	



public:
	void setBehave(EnermyBehave be, int direction);
	void paint(float dt, iPoint offset);


	
};
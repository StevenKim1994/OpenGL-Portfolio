#pragma once
#include "CanNotMove.h"

class Thunder : public CanNotMove
{
public:
	Thunder();
	virtual ~Thunder();

	iImage* img;
	iImage** imgs;

	void paint(float dt, iPoint offset);

	static void cbBehave(void* parm);

	float delay, _delay;
};


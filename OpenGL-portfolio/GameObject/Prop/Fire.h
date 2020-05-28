#pragma once
#include "CanNotMove.h"

class Fire : public CanNotMove
{
public:
	Fire();
	virtual ~Fire();

	iImage* img;
	iImage** imgs;

	void paint(float dt, iPoint offset);

};
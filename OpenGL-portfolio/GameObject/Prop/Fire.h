#pragma once

#include "iStd.h"
#include "Object.h"

class Fire : public Object
{
public:
	Fire();
	virtual ~Fire();

	iImage* img;
	iImage** imgs;

	void paint(float dt, iPoint offset);

};
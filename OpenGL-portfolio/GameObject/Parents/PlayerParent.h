#pragma once
#include "Object.h"

enum PlayerBehave
{
	PlayerBehave_idle = 0,
	PlayerBehave_meleeAttack,
	PlayerBehave_move,
	PlayerBehave_jumpAndFall,

	PlayerBehave_num,
};


class PlayerParent : public Object
{
public:
	PlayerParent();
	 virtual ~PlayerParent();

	

	
};
#pragma once
#include "Object.h"

enum class PlayerBehave
{
	PlayerBehave_NULL = -1,
	PlayerBehave_idle = 0,
	PlayerBehave_meleeAttack1,
	PlayerBehave_meleeAttack2,
	PlayerBehave_move,
	PlayerBehave_jump,
	PlayerBehave_fall,
	PlayerBehave_takeHit,
	PlayerBehave_death,


	PlayerBehave_num,
};


class PlayerParent : public Object
{
public:
	PlayerParent();
	 virtual ~PlayerParent();

	

	
};
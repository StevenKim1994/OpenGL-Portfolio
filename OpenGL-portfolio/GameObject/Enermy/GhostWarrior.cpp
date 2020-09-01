#include "GhostWarrior.h"
#include "GameUI.h"
#include "GameEffect.h"
#include "CoinFactory.h"

#define GhostWarrior_HP 200
#define GhostWarrior_MP 100
#define GhostWarrior_Stamina 100

#define GhostWarrior_Width 100
#define GhostWarrior_Height 100

static iImage** imgGhostWarrior = NULL;

GhostWarrior::GhostWarrior(int number)
{
	type = 2;
	if (imgGhostWarrior == NULL)
	{
		struct GhostWarriorInfo
		{
			const char* path;
			int num;
			float sizeRate;
			iPoint p;

		};
	}
}
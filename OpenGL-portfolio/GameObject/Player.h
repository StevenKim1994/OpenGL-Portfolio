#pragma once
#include "iStd.h"
#include "Object.h"



class Player : public Object
{
private: Player(); // Player는 싱글톤 객체로 사용할 예정임 왜냐하면 게임에서 플레이어는 나 혼자뿐이니까.
		virtual ~Player();
		static Player* instance;

public:
	static Player* GetInstance()
	{
		if (instance == NULL)
		{
			instance = new Player();
		}

		return instance;
	}



public : 
	void Skill1(); // 아직 어떤 스킬을 넣을지 결정하진 않았음.
	void Skill2();
	void Skill3(); 
	
	

};


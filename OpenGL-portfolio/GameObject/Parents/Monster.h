#pragma once
#include "Object.h"

class Monster : public Object // 모든 몬스터(ex, 오크, 아처 들은 이 부모클래스를 상속받음)
{
public: Monster();
	  virtual ~Monster();


protected:
	float r = 0.0f; 
	float rValue = 1.0f; 
	
	bool detected_Player;
	iPoint Target_Pos;
	Object* Target;

	float aiTime = 0.0f;
	float _aiTime;


public:


	//setter;
	void setDetected_Player(bool check);
	void setTarget(Object* obj);

	//getter;
	bool getDetected_Player();
	Object* getTarget();






};
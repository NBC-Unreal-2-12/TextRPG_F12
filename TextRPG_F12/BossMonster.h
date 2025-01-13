#pragma once
#include "Monster.h"

class BossMonster : public Monster
{
public:
	BossMonster(const std::string& name) // 만약 보스를 두 마리 이상 만들면 인자가 필요해 질 것.
		: Monster(name)
	{ 
	}
};
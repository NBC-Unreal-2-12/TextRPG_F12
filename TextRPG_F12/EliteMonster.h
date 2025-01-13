#pragma once
#include "Monster.h"

class EliteMonster : public Monster
{
public:
	EliteMonster(const std::string& name)
		: Monster(name)
	{
	}
};

class EliteSlime : public EliteMonster
{
public:
	EliteSlime() : EliteMonster("EliteSlime")
	{

	}
};

class EliteOrc : public EliteMonster
{
public:
	EliteOrc() : EliteMonster("EliteOrc")
	{

	}
};

class EliteGoblin : public EliteMonster
{
public:
	EliteGoblin() : EliteMonster("EliteGoblin")
	{

	}
};
#pragma once
#include "Monster.h"

class SpecialMonster : public Monster
{
public:
	SpecialMonster(const std::string& name)
		: Monster(name) 
	{
	}
};

class Dragon : public SpecialMonster
{
public:
	Dragon() : SpecialMonster("Dragon")
	{
	}
};

class Balrog : public SpecialMonster
{
public:
	Balrog() : SpecialMonster("Balrog")
	{
	}
};

class Kraken : public SpecialMonster
{
public:
	Kraken() : SpecialMonster("Kraken")
	{
	}
};
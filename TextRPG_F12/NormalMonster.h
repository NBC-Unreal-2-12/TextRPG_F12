#pragma once
#include "Monster.h"

class NormalMonster : public Monster
{
public:
    NormalMonster(const std::string& name)
        : Monster(name) 
    {
    }
};

class Slime : public NormalMonster 
{
public:
    Slime() : NormalMonster("Slime") 
    {
    }
};

class Orc : public NormalMonster 
{
public:
    Orc() : NormalMonster("Orc") 
    {
    }
};

class Goblin : public NormalMonster
{
public:
    Goblin() : NormalMonster("Goblin")
    {
    }
};


#ifndef ARCHER_SKILL_H
#define ARCHER_SKILL_H
#pragma once

#include "Skill.h"

class Fusillade : public Skill
{
public:
    Fusillade() : Skill("연속 사격", 30, 1.8, SkillType::Normal) {}

    string getSkillName() const override
    {
        return "연속 사격";
    }
};

class RainOfArrows : public Skill
{
public:
    RainOfArrows() : Skill("화살비", 50, 1.4, SkillType::AreaOfEffect) {}

    string getSkillName() const override
    {
        return "화살비";
    }
};

class  PreciseShot : public Skill
{
public:
    PreciseShot() : Skill("정밀 사격", 80, 2.5, SkillType::Normal) {}
    string getSkillName() const override
    {
        return "정밀 사격";
    }
};



#endif
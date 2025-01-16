#ifndef MAGE_SKILL_H
#define MAGE_SKILL_H
#pragma once

#include "Skill.h"

class FireBall : public Skill
{
public:
    FireBall() : Skill("화염구", 40, 2.0, SkillType::Normal) {}

    string getSkillName() const override {
        return "화염구";
    }
};

class Blizzard : public Skill
{
public:
    Blizzard() : Skill("눈보라", 60, 2.0, SkillType::AreaOfEffect) {}

    string getSkillName() const override {
        return "눈보라";
    }
};

class IceBlock : public Skill
{
public:
    IceBlock() : Skill("얼음 방패", 60, 0, SkillType::Buff) {}

    string getSkillName() const override {
        return "얼음 방패";
    }
};


#endif
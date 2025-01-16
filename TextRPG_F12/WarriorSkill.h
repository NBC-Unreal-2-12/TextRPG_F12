﻿#ifndef WARRIOR_SKILL_H
#define WARRIOR_SKILL_H
#pragma once

#include "Skill.h"

// 전사의 강타 스킬
class Smite : public Skill
{
public:
    Smite() : Skill("강타", 40, 2.1, SkillType::Normal) {}

    string getSkillName() const override {
        return "강타";
    }
};

// 회전 베기 스킬
class Whirlwind : public Skill
{
public:
    Whirlwind() : Skill("회전 베기", 60, 1.9, SkillType::AreaOfEffect) {}

    string getSkillName() const override {
        return "회전 베기";
    }
};

// 방어 자세 스킬
class SwordDance : public Skill
{
public:
    SwordDance() : Skill("검의 춤", 90, 3.0, SkillType::Normal) {}

    string getSkillName() const override {
        return "검의 춤";
    }
};

#endif
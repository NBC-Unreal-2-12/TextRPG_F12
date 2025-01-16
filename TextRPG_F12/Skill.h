#ifndef SKILL_H
#define SKILL_H
#pragma once

#include <string>
#include <iostream>

using namespace std;

// 스킬 인터페이스
class Skill 
{
protected:
	const string skillName; // 스킬 이름
    const int manaCost;          // MP 소모량
    const double damageFactor;    // 스킬 데미지 배율
public:
    Skill(const string& name, int manaCost, double damageFactor)
        : skillName(name), manaCost(manaCost), damageFactor(damageFactor) {
    }
    virtual string getSkillName() const = 0; // 스킬 이름
    virtual ~Skill(){}
	int getManaCost() const
	{
		return manaCost;
	}
	double getDamageFactor() const
	{
		return damageFactor;
	}
};


class WarriorSkill : public Skill 
{
public:
    WarriorSkill()
        : Skill("전사의 강타", 40, 2.0) {
    } // 이름, 고정 MP 소모, 고정 데미지 배율

    string getSkillName() const override 
    {
        return "전사의 강타";
    }
};

class MageSkill : public Skill 
{
public:
	MageSkill()
		: Skill("마법사의 화염구", 50, 2.5) {
	} // 이름, 고정 MP 소모, 고정 데미지 배율


    string getSkillName() const override 
    {
        return "마법사의 화염구";
    }
};

class ArcherSkill : public Skill
{
public:
	ArcherSkill()
		: Skill("궁수의 연속 사격", 30, 1.8) {
	} // 이름, 고정 MP 소모, 고정 데미지 배율

    string getSkillName() const override
    {
        return "궁수의 연속 사격";
    }
};

#endif
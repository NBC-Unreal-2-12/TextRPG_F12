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

#endif
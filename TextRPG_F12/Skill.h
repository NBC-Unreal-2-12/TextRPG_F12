#ifndef SKILL_H
#define SKILL_H
#pragma once

#include <string>
#include <iostream>

using namespace std;

enum class SkillType {
    Normal,      // 일반 스킬
    Counter,     // 반격 스킬
    Healing,     // 치유 스킬
    Buff,        // 버프 스킬
    Debuff,      // 디버프 스킬
    AreaOfEffect // 범위 공격 스킬
};

// 스킬 인터페이스
class Skill 
{
protected:
	const string skillName; // 스킬 이름
    const int manaCost;          // MP 소모량
    const double damageFactor;    // 스킬 데미지 배율
    SkillType type;
public:
    Skill(const string& name, int manaCost, double damageFactor, SkillType skillType)
        : skillName(name), manaCost(manaCost), damageFactor(damageFactor), type(skillType) {
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
    // 스킬 타입 getter함수
    SkillType getSkillType() const {
        return type;
    }

};

#endif
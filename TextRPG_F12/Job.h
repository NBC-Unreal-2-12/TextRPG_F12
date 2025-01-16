#ifndef JOB_H
#define JOB_H
#pragma once

#include <string>
#include <iostream>
#include "Skill.h"

using namespace std;

// 직업 인터페이스
class Job 
{
protected:
    unique_ptr<Skill> skill; // unique_ptr로 변경
    int jobIndex;
    int healthGrowth;
	int manaGrowth;
	int attackGrowth;
	int attackSpeedGrowth;
	double evasionGrowth;
	double accuracyGrowth;
public:
    virtual string getJobName() const = 0;
    Job(int jobIndex, int health, int mana, int attack, int attackSpeed, double evasion, double accuracy)
        :jobIndex(jobIndex), healthGrowth(health), manaGrowth(mana), attackGrowth(attack),
        attackSpeedGrowth(attackSpeed), evasionGrowth(evasion), accuracyGrowth(accuracy) {}
    virtual ~Job() {}
    virtual void applyJobEffect(double& attack, int& maxHelth, int& attackspeed, double& evasion, double& accuracy, int& maxMp) const = 0;
    virtual Skill* getSkill() const = 0; // 스킬 반환
        
    // Getter 메서드
    int getHealthGrowth() const { return healthGrowth; }
    int getManaGrowth() const { return manaGrowth; }
    int getAttackGrowth() const { return attackGrowth; }
    int getAttackSpeedGrowth() const { return attackSpeedGrowth; }
    double getEvasionGrowth() const { return evasionGrowth; }
    double getAccuracyGrowth() const { return accuracyGrowth; }
    int getJobIndex() const { return jobIndex; }
    int getManaCost()
    {

        return skill->getManaCost();
    }
    string getSkillName()
    {
        return skill->getSkillName();
    }
};

// 전사 직업 클래스
class Warrior : public Job 
{    
public:
	Warrior() : Job(0, 50, 20, 30, 1, 0.1, 5) 
    {
        skill = make_unique<WarriorSkill>();
    } // 전사식별번호 전사 레벨업 증가량, 체력, 마나, 공격력, 속도, 회피, 명중
    string getJobName() const override 
    {
        return "전사";
    }

    void applyJobEffect(double& attack, int& maxHealth, int& attackspeed,
        double& evasion, double& accuracy, int& maxMp) const override 
    {
        attack += 10;
        maxHealth += 100;
        attackspeed += 2;
    }


    Skill* getSkill() const override 
    {
        return skill.get();
    }
};

// 마법사 직업 클래스
class Mage : public Job 
{
public:
    Mage() : Job(1, 30, 50, 50, 1, 0.1, 5) 
    {
        skill = make_unique<MageSkill>();
    } // 마법사식별번호 마법사 레벨업 증가량, 체력, 마나, 공격력, 속도, 회피, 명중

    string getJobName() const override
    {
        return "마법사";
    }

    void applyJobEffect(double& attack, int& maxHealth, int& attackspeed, 
        double& evasion, double& accuracy, int& maxMp) const override 
    {
        attack += 10;
        maxHealth += 20;
        maxMp += 50;
        attackspeed += 1;
    }

    Skill* getSkill() const override 
    {
        return skill.get();
    }
};

// 궁수 직업 클래스
class Archer : public Job 
{
public:
    Archer() : Job(2, 30, 20, 30, 2, 0.2, 10) 
    {
        skill = make_unique<ArcherSkill>();
    } // 궁수식별번호 궁수 마법사 증가량, 체력, 마나, 공격력, 속도, 회피, 명중

    string getJobName() const override
    {
        return "궁수";
    }

    void applyJobEffect(double& attack, int& maxHealth, int& attackspeed,
        double& evasion, double& accuracy, int& maxMp) const override 
    {
        attack += 10;
        maxHealth += 50;
        evasion += 0.1;
        attackspeed += 3;
        accuracy += 10;
    }

    Skill* getSkill() const override 
    {
        return skill.get();
    }
};

#endif
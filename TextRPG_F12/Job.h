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
};

// 전사 직업 클래스
class Warrior : public Job 
{
private:
    Skill* skill = new WarriorSkill();
public:
	Warrior() : Job(0, 50, 20, 30, 1, 0.1, 5) {} // 전사식별번호 전사 레벨업 증가량, 체력, 마나, 공격력, 속도, 회피, 명중
    string getJobName() const override 
    {
        return "전사";
    }

    void applyJobEffect(double& attack, int& maxHealth, int& attackspeed,
        double& evasion, double& accuracy, int& maxMp) const override 
    {
        attack += 30;
        maxHealth += 70;
        attackspeed += 10;
    }

    ~Warrior() override { delete skill; }

    Skill* getSkill() const override 
    {
        return skill;
    }
};

// 마법사 직업 클래스
class Mage : public Job 
{
private:
    Skill* skill = new MageSkill();
public:
    Mage() : Job(1, 30, 50, 50, 1, 0.1, 5) {} // 마법사식별번호 마법사 레벨업 증가량, 체력, 마나, 공격력, 속도, 회피, 명중

    string getJobName() const override
    {
        return "마법사";
    }

    void applyJobEffect(double& attack, int& maxHealth, int& attackspeed, 
        double& evasion, double& accuracy, int& maxMp) const override 
    {
        attack += 25;
        maxHealth += 20;
        maxMp += 50;
        attackspeed += 5;
    }

	~Mage() override { delete skill; }

    Skill* getSkill() const override 
    {
        return skill;
    }
};

// 궁수 직업 클래스
class Archer : public Job 
{
private:
    Skill* skill = new ArcherSkill();
public:
    Archer() : Job(2, 30, 20, 30, 2, 0.2, 10) {} // 궁수식별번호 궁수 마법사 증가량, 체력, 마나, 공격력, 속도, 회피, 명중

    string getJobName() const override
    {
        return "궁수";
    }

    void applyJobEffect(double& attack, int& maxHealth, int& attackspeed,
        double& evasion, double& accuracy, int& maxMp) const override 
    {
        attack += 20;
        maxHealth += 30;
        evasion += 0.1;
        attackspeed += 20;
        accuracy += 10;
    }

	~Archer() override { delete skill; }

    Skill* getSkill() const override 
    {
        return skill;
    }
};

#endif
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
    int healthGrowth;
	int manaGrowth;
	int attackGrowth;
	int attackSpeedGrowth;
	double evasionGrowth;
	double accuracyGrowth;
public:
    virtual string getJobName() const = 0;
    Job(int health, int mana, int attack, int attackSpeed, double evasion, double accuracy)
        : healthGrowth(health), manaGrowth(mana), attackGrowth(attack),
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
};

// 전사 직업 클래스
class Warrior : public Job 
{
private:
    Skill* skill = new WarriorSkill();
public:
	Warrior() : Job(70, 20, 30, 0, 0.05, 0.02) {}
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
    Mage() : Job(30, 50, 20, 0, 0.03, 0.01) {}

    string getJobName() const override
    {
        return "마법사";
    }

    void applyJobEffect(double& attack, int& maxHelth, int& attackspeed, 
        double& evasion, double& accuracy, int& maxMp) const override 
    {
        attack += 25;
        maxHelth += 20;
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
    Archer() : Job(50, 30, 25, 0, 0.1, 0.05) {}

    string getJobName() const override
    {
        return "궁수";
    }

    void applyJobEffect(double& attack, int& maxHelth, int& attackspeed,
        double& evasion, double& accuracy, int& maxMp) const override 
    {
        attack += 20;
        maxHelth += 30;
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
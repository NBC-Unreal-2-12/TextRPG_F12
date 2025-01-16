#ifndef JOB_H
#define JOB_H
#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "Skill.h"
#include "WarriorSkill.h"
#include "ArcherSkill.h"
#include "MageSkill.h"

using namespace std;

// 직업 인터페이스
class Job 
{
protected:
    vector<unique_ptr<Skill>> skills; // 스킬 목록
    int jobIndex;
    int healthGrowth;
	int manaGrowth;
	int attackGrowth;
	int attackSpeedGrowth;
	double evasionGrowth;
	double accuracyGrowth;
public:
    virtual string getJobName() const = 0;
    virtual const Skill* getSkill(size_t index) const = 0;
    Job(int jobIndex, int health, int mana, int attack, int attackSpeed, double evasion, double accuracy)
        :jobIndex(jobIndex), healthGrowth(health), manaGrowth(mana), attackGrowth(attack),
        attackSpeedGrowth(attackSpeed), evasionGrowth(evasion), accuracyGrowth(accuracy) {}
    virtual ~Job() {}
    virtual void applyJobEffect(double& attack, int& maxHelth, int& attackspeed, double& evasion, double& accuracy, int& maxMp) const = 0;

    // 스킬 추가 메서드
    void addSkill(std::unique_ptr<Skill> skill) {
        skills.push_back(std::move(skill));
    }

    // 외부에서 skills에 접근할 수 있는 getter 메서드 추가
    const vector<unique_ptr<Skill>>& getSkills() const {
        return skills;
    }

    // 모든 스킬 출력
    void displaySkills() const {
        for (size_t i = 0; i < skills.size(); ++i) {
            std::cout << "[" << i + 1 << "] " << skills[i]->getSkillName()
                << " (마나 소모: " << skills[i]->getManaCost()
                << ", 데미지 배율: " << skills[i]->getDamageFactor() << ")\n";
        }
    }
        
    // Getter 메서드
    int getHealthGrowth() const { return healthGrowth; }
    int getManaGrowth() const { return manaGrowth; }
    int getAttackGrowth() const { return attackGrowth; }
    int getAttackSpeedGrowth() const { return attackSpeedGrowth; }
    double getEvasionGrowth() const { return evasionGrowth; }
    double getAccuracyGrowth() const { return accuracyGrowth; }
    int getJobIndex() const { return jobIndex; }

    int getManaCost(int index)
    {
        return skills[index]->getManaCost();
    }

    string getSkillName(int index) 
    {
        return skills[index]->getSkillName();
    }

    double getDamageFactor(int index) 
    {
        return skills[index]->getDamageFactor();
    }
};

// 전사 직업 클래스
class Warrior : public Job 
{    
public:
	Warrior() : Job(0, 50, 20, 30, 1, 0.1, 5) 
    {
        addSkill(make_unique<Smite>());           // 강타 스킬 추가
        addSkill(make_unique<Whirlwind>());       // 회전 베기 스킬 추가
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
    // getSkill() 메서드 구현
    Skill* getSkill(size_t index) const override {
        return skills.empty() ? nullptr : skills[index].get();
    }

};

// 마법사 직업 클래스
class Mage : public Job 
{
public:
    Mage() : Job(1, 30, 50, 50, 1, 0.1, 5) 
    {
        addSkill(make_unique<FireBall>());     // 화염구 스킬 추가
        addSkill(make_unique<Blizzard>());          // 눈보라 스킬 추가
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
    // getSkill() 메서드 구현
    Skill* getSkill(size_t index) const override {
        return skills.empty() ? nullptr : skills[index].get();
    }
};

// 궁수 직업 클래스
class Archer : public Job 
{
public:
    Archer() : Job(2, 30, 20, 30, 2, 0.2, 10)   // 궁수식별번호 궁수 마법사 증가량, 체력, 마나, 공격력, 속도, 회피, 명중
    {
        addSkill(make_unique<Fusillade>());         // 연속 사격 스킬 추가
        addSkill(make_unique<RainOfArrows>());      // 화살비 스킬 추가
    } 

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
    Skill* getSkill(size_t index) const override {
        return skills.empty() ? nullptr : skills[index].get();
    }

};

#endif
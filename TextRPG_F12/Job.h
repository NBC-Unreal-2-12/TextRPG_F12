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
    // Job 클래스의 생성자
    Job(int jobIndex, int health, int mana, int attack, int attackSpeed, double evasion, double accuracy)
        : jobIndex(jobIndex), healthGrowth(health), manaGrowth(mana), attackGrowth(attack),
        attackSpeedGrowth(attackSpeed), evasionGrowth(evasion), accuracyGrowth(accuracy) {
    }

    virtual ~Job() {}

    // 직업의 이름 반환
    virtual string getJobName() const = 0;
    // 스킬 반환
    virtual const Skill* getSkill(size_t index) const = 0;

    // 직업의 효과 적용
    virtual void applyJobEffect(double& attack, int& maxHealth, int& attackspeed, double& evasion, double& accuracy, int& maxMp) const = 0;

    // 스킬 추가 메서드
    void addSkill(std::unique_ptr<Skill> skill) {
        skills.push_back(std::move(skill));
    }

    // 외부에서 skills에 접근할 수 있는 getter 메서드
    const vector<unique_ptr<Skill>>& getSkills() const {
        return skills;
    }

    // 모든 스킬 출력
    void displaySkills(double playerAttack) const {
        for (size_t i = 0; i < skills.size(); ++i) {
            // 스킬 타입에 맞는 문자열을 출력하기 위한 switch문
            string skillTypeStr;
            switch (skills[i]->getSkillType()) {
            case SkillType::Normal:
                skillTypeStr = "일반 공격";
                break;
            case SkillType::AreaOfEffect:
                skillTypeStr = "광역 공격";
                break;
            case SkillType::Buff:
                skillTypeStr = "버프";
                break;
            case SkillType::Debuff:
                skillTypeStr = "디버프";
                break;
            default:
                skillTypeStr = "알 수 없음";
                break;
            }
            std::cout << "[" << i + 1 << "] " << skills[i]->getSkillName()
                << " (타입: " << skillTypeStr
                << ", 마나 소모: " << skills[i]->getManaCost()
                << ", 데미지: " << skills[i]->getDamageFactor() * playerAttack << ")\n";
        }
    }

    string getSkillTypeName(int index) {
        string skillTypeStr;
        switch (skills[index]->getSkillType()) {
        case SkillType::Normal:
            skillTypeStr = "일반 공격";
            break;
        case SkillType::AreaOfEffect:
            skillTypeStr = "광역 공격";
            break;
        case SkillType::Buff:
            skillTypeStr = "버프";
            break;
        case SkillType::Debuff:
            skillTypeStr = "디버프";
            break;
        default:
            skillTypeStr = "알 수 없음";
            break;
        }
        return skillTypeStr;
    }

    // Getter 메서드
    int getHealthGrowth() const { return healthGrowth; }
    int getManaGrowth() const { return manaGrowth; }
    int getAttackGrowth() const { return attackGrowth; }
    int getAttackSpeedGrowth() const { return attackSpeedGrowth; }
    double getEvasionGrowth() const { return evasionGrowth; }
    double getAccuracyGrowth() const { return accuracyGrowth; }
    int getJobIndex() const { return jobIndex; }
    int getManaCost(int index) {
        return skills[index]->getManaCost();
    }

    SkillType getSkillType(size_t index)
    {
        return skills[index]->getSkillType();
    }

    string getSkillName(int index) {
        return skills[index]->getSkillName();
    }

    double getDamageFactor(int index) {
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
    }
    string getJobName() const override {
        return "전사";
    }

    void applyJobEffect(double& attack, int& maxHealth, int& attackspeed,
        double& evasion, double& accuracy, int& maxMp) const override {
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
    }
    string getJobName() const override {
        return "마법사";
    }

    void applyJobEffect(double& attack, int& maxHealth, int& attackspeed,
        double& evasion, double& accuracy, int& maxMp) const override {
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

    string getJobName() const override {
        return "궁수";
    }

    void applyJobEffect(double& attack, int& maxHealth, int& attackspeed,
        double& evasion, double& accuracy, int& maxMp) const override {
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
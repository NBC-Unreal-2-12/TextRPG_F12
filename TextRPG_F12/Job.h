#ifndef JOB_H
#define JOB_H
#pragma once

#include <string>
#include <iostream>
#include "Skill.h"

using namespace std;

// 직업 인터페이스
class Job {
public:
    virtual string getJobName() const = 0;
    virtual ~Job() {}
    virtual void applyJobEffect(double& attack, int& maxHelth, int& attackspeed, double& evasion, double& accuracy, int& maxMp) const = 0;
    virtual Skill* getSkill() const = 0; // 스킬 반환
};

// 전사 직업 클래스
class Warrior : public Job {
private:
    Skill* skill = new WarriorSkill();
public:
    string getJobName() const override {
        return "Warrior";
    }

    void applyJobEffect(double& attack, int& maxHelth, int& attackspeed, double& evasion, double& accuracy, int& maxMp) const override {
        attack += 30;
        maxHelth += 70;
        attackspeed += 10;
    }

    Skill* getSkill() const override {
        return skill;
    }
};

// 마법사 직업 클래스
class Mage : public Job {
private:
    Skill* skill = new MageSkill();
public:
    string getJobName() const override {
        return "Mage";
    }

    void applyJobEffect(double& attack, int& maxHelth, int& attackspeed, double& evasion, double& accuracy, int& maxMp) const override {
        attack += 25;
        maxHelth += 20;
        maxMp += 50;
        attackspeed += 5;
    }

    Skill* getSkill() const override {
        return skill;
    }
};

// 궁수 직업 클래스
class Archer : public Job {
private:
    Skill* skill = new ArcherSkill();
public:
    string getJobName() const override {
        return "Archer";
    }

    void applyJobEffect(double& attack, int& maxHelth, int& attackspeed, double& evasion, double& accuracy, int& maxMp) const override {
        attack += 20;
        maxHelth += 30;
        evasion += 0.1;
        attackspeed += 20;
        accuracy += 10;
    }

    Skill* getSkill() const override {
        return skill;
    }
};

#endif
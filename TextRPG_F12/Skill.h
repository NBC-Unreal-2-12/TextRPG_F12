#ifndef SKILL_H
#define SKILL_H
#pragma once

#include <string>
#include <iostream>

using namespace std;

// 스킬 인터페이스
class Skill {
public:
    virtual void useSkill() const = 0; // 스킬 사용
    virtual string getSkillName() const = 0; // 스킬 이름
    virtual ~Skill() {}
};


class WarriorSkill : public Skill {
public:
    void useSkill() const override {
        cout << "전사의 강타를 사용합니다!" << endl;
    }

    string getSkillName() const override {
        return "전사의 강타";
    }
};

class MageSkill : public Skill {
public:
    void useSkill() const override {
        cout << "마법사의 화염구를 사용합니다!" << endl;
    }

    string getSkillName() const override {
        return "마법사의 화염구";
    }
};

class ArcherSkill : public Skill {
public:
    void useSkill() const override {
        cout << "궁수의 연속 사격을 사용합니다!" << endl;
    }
    string getSkillName() const override {
        return "궁수의 연속 사격";
    }
};

#endif
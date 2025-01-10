#ifndef SKILL_H
#define SKILL_H
#pragma once

#include <string>
#include <iostream>

using namespace std;

// ��ų �������̽�
class Skill {
public:
    virtual void useSkill() const = 0; // ��ų ���
    virtual string getSkillName() const = 0; // ��ų �̸�
    virtual ~Skill() {}
};


class WarriorSkill : public Skill {
public:
    void useSkill() const override {
        cout << "������ ��Ÿ�� ����մϴ�!" << endl;
    }

    string getSkillName() const override {
        return "������ ��Ÿ";
    }
};

class MageSkill : public Skill {
public:
    void useSkill() const override {
        cout << "�������� ȭ������ ����մϴ�!" << endl;
    }

    string getSkillName() const override {
        return "�������� ȭ����";
    }
};

class ArcherSkill : public Skill { 
public:
	void useSkill() const override {
        cout << "�ü��� ���� ����� ����մϴ�!" << endl;
	}
	string getSkillName() const override {
		return "�ü��� ���� ���";
	}
};

#endif
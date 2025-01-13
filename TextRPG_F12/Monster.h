#ifndef MONSTERS_H
#define MONSTERS_H

#include <iostream>
#include <string>
#include "Item.h"
#include "Inventory.h"
#include "Character.h"

using namespace std;

class Monster {
public:
    virtual ~Monster() = default;

    string getName() {
        return this->name;
    }

    int getHealth() {
        return this->mobHealth;
    }

    int getAttack() {
        return this->mobAttack;
    }

    int getMana() {
        return this->mobMana;
    }

    int getMaxMana() {
        return this->mobMaxMana;
    }

    int getSpeed() {
        return this->mobSpeed;
    }

    int getAccuracy() {
        return this->mobAccuracy;
    }

    double getEvasion() {
        return this->mobEvasion;
    }

    virtual int getSkill() = 0;

    int useAttack() { // 몬스터가 공격할 때
        if (mobMana < mobMaxMana) { // mobMaxMana만큼 Attack
            mobMana++; // 공격할 때 마다 마나++
            return mobAttack;
        }
        else {
            mobMana = 0; // 마나 초기화
            return getSkill(); // 스킬 호출
        }
    }

    bool isMonsterDie() {
        return this->mobHealth <= 0;
    }

    void takeDamage(int damage) { // 몬스터가 공격 받을 때
        this->mobHealth -= damage;
        if (this->mobHealth <= 0) {
            this->mobHealth = 0;
        }
        cout << this->name << " 이 " << damage << " 데미지 받음. 남은 체력 : " << this->mobHealth << endl;
    }

    void getInterface() {
        cout << "이름 : " << this->name << endl;
        cout << "체력 : " << this->mobHealth << endl;
        cout << "공격력 : " << this->mobAttack << endl;
        cout << "현재 마나 : " << this->mobMana << endl;
        cout << "최대 마나 : " << this->mobMaxMana << endl;
        cout << "속도 : " << this->mobSpeed << endl;
        cout << "명중률 : " << this->mobAccuracy << endl;
        cout << "회피율 : " << this->mobEvasion << endl;
    }


protected:
    string name = "Unknown";
    int mobHealth = 99;
    int mobAttack = 99;
    int mobMana = 99;
    int mobMaxMana = 99;
    int mobSpeed = 99;
    int mobAccuracy = 99;
    double mobEvasion = 99;
};





class Goblin : public Monster { //고블린

public:
    Goblin(int level) {
        name = "Goblin";
        mobHealth = level * 20;
        mobAttack = (level * 10);
        mobMana = 0;
        mobMaxMana = 3;
        mobSpeed = level;
        mobAccuracy = 50 + (level * 20);
        mobEvasion = 1 + (level * 0.05f);
    }

    int useSkill() override {
        return mobAttack * 2;
    }
};

class Orc : public Monster { // 오크

public:
    Orc(int level) {
        name = "Orc";
        mobHealth = level * 20;
        mobAttack = (level * 10);
        mobMana = 0;
        mobMaxMana = 3;
        mobSpeed = level;
        mobAccuracy = 50 + (level * 20);
        mobEvasion = 1 + (level * 0.05f);
    }

    int useSkill() override {
        return mobAttack * 2;
    }
};

class Slime : public Monster { // 슬라임

public:
    Slime(int level) {
        name = "Slime";
        mobHealth = level * 20;
        mobAttack = (level * 10);
        mobMana = 0;
        mobMaxMana = 3;
        mobSpeed = level;
        mobAccuracy = 50 + (level * 20);
        mobEvasion = 1 + (level * 0.05f);
    }


    int useSkill() override {
        return mobAttack * 2;
    }
};

class BossMonster : public Monster { // 보스

public:
    BossMonster(int level) {
        name = "BossMonster";
        mobHealth = level * 20;
        mobAttack = (level * 10);
        mobMana = 0;
        mobMaxMana = 3;
        mobSpeed = level;
        mobAccuracy = 50 + (level * 20);
        mobEvasion = 1 + (level * 0.05f);
    }

    int useSkill() override {
        return mobAttack * 2;
    }
};

#endif // MONSTERS_H
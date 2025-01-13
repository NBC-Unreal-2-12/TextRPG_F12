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

    string getMobName() {
        return this->mobName;
    }

    int getMobHealth() {
        return this->mobHealth;
    }

    int getMobAttack() {
        return this->mobAttack;
    }

    int getMobMana() {
        return this->mobMana;
    }

    int getMobMaxMana() {
        return this->mobMaxMana;
    }

    int getMobAttackSpeed() {
        return this->mobAttackSpeed;
    }

    int getMobAccuracy() {
        return this->mobAccuracy;
    }

    double getMobEvasion() {
        return this->mobEvasion;
    }

    bool isMobDead() {
        return this->mobHealth <= 0;
    }

    virtual int useMobSkill() = 0;

    int useMobAttack() { // 몬스터가 공격할 때
        if (mobMana < mobMaxMana) { // mobMaxMana만큼 Attack
            mobMana++; // 공격할 때 마다 마나++
            return mobAttack;
        }
        else {
            mobMana = 0; // 마나 초기화
            return useMobSkill(); // 스킬 호출
        }
    }



    void takeMobDamage(int damage) { // 몬스터가 공격 받을 때
        this->mobHealth -= damage;
        if (this->mobHealth <= 0) {
            this->mobHealth = 0;
        }
        cout << this->mobName << " 이 " << damage << " 데미지 받음. 남은 체력 : " << this->mobHealth << endl;
    }

    void getMobInterface() {
        cout << "이름 : " << this->mobName << endl;
        cout << "체력 : " << this->mobHealth << endl;
        cout << "공격력 : " << this->mobAttack << endl;
        cout << "현재 마나 : " << this->mobMana << endl;
        cout << "최대 마나 : " << this->mobMaxMana << endl;
        cout << "속도 : " << this->mobAttackSpeed << endl;
        cout << "명중률 : " << this->mobAccuracy << endl;
        cout << "회피율 : " << this->mobEvasion << endl;
    }


protected:
    string mobName = "Unknown";
    int mobHealth = 99;
    int mobAttack = 99;
    int mobMana = 99;
    int mobMaxMana = 99;
    int mobAttackSpeed = 99;
    int mobAccuracy = 99;
    double mobEvasion = 99;
};





class Goblin : public Monster { //고블린

public:
    Goblin() {
        mobName = "Goblin";
        mobHealth = 20;
        mobAttack = 10;
        mobMana = 0;
        mobMaxMana = 3;
        mobAttackSpeed = 1;
        mobAccuracy = 50 + 20;
        mobEvasion = 1;
    }

    int useMobSkill() override {
        return mobAttack * 2;
    }
};

class Orc : public Monster { // 오크

public:
    Orc() {
        mobName = "Orc";
        mobHealth = 20;
        mobAttack = 10;
        mobMana = 0;
        mobMaxMana = 3;
        mobAttackSpeed = 1;
        mobAccuracy = 50 + 20;
        mobEvasion = 1;
    }

    int useMobSkill() override {
        return mobAttack * 2;
    }
};

class Slime : public Monster { // 슬라임

public:
    Slime() {
        mobName = "Slime";
        mobHealth = 20;
        mobAttack = 10;
        mobMana = 0;
        mobMaxMana = 3;
        mobAttackSpeed = 1;
        mobAccuracy = 50 + 20;
        mobEvasion = 1;
    }


    int useMobSkill() override {
        return mobAttack * 2;
    }
};

class BossMonster : public Monster { // 보스

public:
    BossMonster() {
        mobName = "BossMonster";
        mobHealth = 20;
        mobAttack = 10;
        mobMana = 0;
        mobMaxMana = 3;
        mobAttackSpeed = 1;
        mobAccuracy = 50 + 20;
        mobEvasion = 1;
    }

    int useMobSkill() override {
        return mobAttack * 2;
    }
};

#endif // MONSTERS_H
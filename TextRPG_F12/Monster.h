#ifndef MONSTERS_H
#define MONSTERS_H

#include <iostream>
#include <string>
#include "Item.h"
#include "Inventory.h"
#include "Character.h"

using namespace std;

class Monster 
{
public:
    virtual ~Monster() = default;

    string getName() 
    {
        return this->mobName;
    }

    int getHealth() 
    {
        return this->mobHealth;
    }

    int getMana()
    {
        return this->mobMana;
    }

    int getMaxMana() 
    {
        return this->mobMaxMana;
    }

    int getSpeed() 
    {
        return this->mobSpeed;
    }

    int getAccuracy() 
    {
        return this->mobAccuracy;
    }

    float getEvasion() {
        return this->mobEvasion;
    }

    bool isMobDead() {
        return this->mobHealth <= 0;
    }

    int getAttack() {
        if (mobMana < mobMaxMana) { // mobMaxMana만큼 Attack
            mobMana++; // 공격할 때 마다 마나++
            return mobAttack;
        }
        else 
        {
            mobMana = 0; // 마나 초기화
            // 스킬 호출 useMobSkill();
            return 0;
        }
    }

    bool isMonsterDie() 
    {
        return this->mobHealth <= 0;
    }

    void takeDamage(int damage) 
    {
        this->mobHealth -= damage;
        if (this->mobHealth <= 0) 
        {
            this->mobHealth = 0;
        }
        cout << this->mobName << " 이 " << damage << " 데미지 받음. 남은 체력 : " << this->mobHealth << endl;
    }

    void getInterface() 
    {
        cout << "이름 : " << this->mobName << endl;
        cout << "체력 : " << this->mobHealth << endl;
        cout << "공격력 : " << this->mobAttack << endl;
        cout << "현재 마나 : " << this->mobMana << endl;
        cout << "최대 마나 : " << this->mobMaxMana << endl;
        cout << "속도 : " << this->mobAttackSpeed << endl;
        cout << "명중률 : " << this->mobAccuracy << endl;
        cout << "회피율 : " << this->mobEvasion << endl;
    }

    int getSkill()
    {
        return mobAttack * 2;
    }


protected:
    string mobName = "Unknown";
    int mobHealth = 99;
    int mobAttack = 99;
    int mobSpeed = 99;
    int mobMana = 99;
    int mobMaxMana = 99;
    int mobAttackSpeed = 99;
    int mobAccuracy = 99;
    double mobEvasion = 99;
};

class Goblin : public Monster 
{ //고블린

public:
    Goblin(int level) 
    {
        mobName = "Goblin";
        mobHealth = level * 20;
        mobAttack = (level * 10);
        mobMana = 0;
        mobMaxMana = 3;
        mobAttackSpeed = 1;
        mobAccuracy = 50 + 20;
        mobEvasion = 1;
    }
};

class Orc : public Monster
{ // 오크

public:
    Orc(int level)
    {
        mobName = "Orc";
        mobHealth = level * 20;
        mobAttack = (level * 10);
        mobMana = 0;
        mobMaxMana = 3;
        mobAttackSpeed = 1;
        mobAccuracy = 50 + 20;
        mobEvasion = 1;
    }
};

class Slime : public Monster 
{ // 슬라임

public:
    Slime(int level) 
    {
        mobName = "Slime";
        mobHealth = level * 20;
        mobAttack = (level * 10);
        mobMana = 0;
        mobMaxMana = 3;
        mobAttackSpeed = 1;
        mobAccuracy = 50 + 20;
        mobEvasion = 1;
    }

};

class BossMonster : public Monster 
{ // 보스

public:
    BossMonster(int level)
    {
        mobName = "BossMonster";
        mobHealth = level * 20;
        mobAttack = (level * 10);
        mobMana = 0;
        mobMaxMana = 3;
        mobAttackSpeed = 1;
        mobAccuracy = 50 + 20;
        mobEvasion = 1;
    }

};

#endif // MONSTERS_H
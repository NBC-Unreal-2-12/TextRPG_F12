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

<<<<<<< Updated upstream
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
=======
    string getName() 
    {
        return this->name;
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

    float getEvasion() 
    {
>>>>>>> Stashed changes
        return this->mobEvasion;
    }

    bool isMobDead() {
        return this->mobHealth <= 0;
    }

<<<<<<< Updated upstream
    virtual int useMobSkill() = 0;

    int useMobAttack() { // 몬스터가 공격할 때
        if (mobMana < mobMaxMana) { // mobMaxMana만큼 Attack
=======
    int getAttack() 
    {
        if (mobMana < mobMaxMana)
        { // mobMaxMana만큼 Attack
>>>>>>> Stashed changes
            mobMana++; // 공격할 때 마다 마나++
            return mobAttack;
        }
        else 
        {
            mobMana = 0; // 마나 초기화
            return useMobSkill(); // 스킬 호출
        }
    }

<<<<<<< Updated upstream


    void takeMobDamage(int damage) { // 몬스터가 공격 받을 때
=======
    bool isMonsterDie() 
    {
        return this->mobHealth <= 0;
    }

    void takeDamage(int damage)
    {
>>>>>>> Stashed changes
        this->mobHealth -= damage;
        if (this->mobHealth <= 0) 
        {
            this->mobHealth = 0;
        }
        cout << this->mobName << " 이 " << damage << " 데미지 받음. 남은 체력 : " << this->mobHealth << endl;
    }

<<<<<<< Updated upstream
    void getMobInterface() {
        cout << "이름 : " << this->mobName << endl;
=======
    void getInterface()
    {
        cout << "이름 : " << this->name << endl;
>>>>>>> Stashed changes
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





class Goblin : public Monster 
{ //고블린

public:
<<<<<<< Updated upstream
    Goblin() {
        mobName = "Goblin";
        mobHealth = 20;
        mobAttack = 10;
=======
    Goblin(int level) 
    {
        name = "Goblin";
        mobHealth = level * 20;
        mobAttack = (level * 10);
>>>>>>> Stashed changes
        mobMana = 0;
        mobMaxMana = 3;
        mobAttackSpeed = 1;
        mobAccuracy = 50 + 20;
        mobEvasion = 1;
    }

<<<<<<< Updated upstream
    int useMobSkill() override {
=======
    int getSkill() override
    {
>>>>>>> Stashed changes
        return mobAttack * 2;
    }
};

class Orc : public Monster { // 오크

public:
<<<<<<< Updated upstream
    Orc() {
        mobName = "Orc";
        mobHealth = 20;
        mobAttack = 10;
=======
    Orc(int level) 
    {
        name = "Orc";
        mobHealth = level * 20;
        mobAttack = (level * 10);
>>>>>>> Stashed changes
        mobMana = 0;
        mobMaxMana = 3;
        mobAttackSpeed = 1;
        mobAccuracy = 50 + 20;
        mobEvasion = 1;
    }

<<<<<<< Updated upstream
    int useMobSkill() override {
=======
    int getSkill() override 
    {
>>>>>>> Stashed changes
        return mobAttack * 2;
    }
};

class Slime : public Monster 
{ // 슬라임

public:
<<<<<<< Updated upstream
    Slime() {
        mobName = "Slime";
        mobHealth = 20;
        mobAttack = 10;
=======
    Slime(int level)
    {
        name = "Slime";
        mobHealth = level * 20;
        mobAttack = (level * 10);
>>>>>>> Stashed changes
        mobMana = 0;
        mobMaxMana = 3;
        mobAttackSpeed = 1;
        mobAccuracy = 50 + 20;
        mobEvasion = 1;
    }


<<<<<<< Updated upstream
    int useMobSkill() override {
=======
    int getSkill() override 
    {
>>>>>>> Stashed changes
        return mobAttack * 2;
    }
};

class BossMonster : public Monster 
{ // 보스

public:
<<<<<<< Updated upstream
    BossMonster() {
        mobName = "BossMonster";
        mobHealth = 20;
        mobAttack = 10;
=======
    BossMonster(int level)
    {
        name = "BossMonster";
        mobHealth = level * 20;
        mobAttack = (level * 10);
>>>>>>> Stashed changes
        mobMana = 0;
        mobMaxMana = 3;
        mobAttackSpeed = 1;
        mobAccuracy = 50 + 20;
        mobEvasion = 1;
    }

<<<<<<< Updated upstream
    int useMobSkill() override {
=======
    int getSkill() override 
    {
>>>>>>> Stashed changes
        return mobAttack * 2;
    }
};

#endif // MONSTERS_H
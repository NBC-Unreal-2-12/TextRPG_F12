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
    virtual string getName() = 0;
    virtual int getHealth() = 0;
    virtual int getAttack() = 0;
    virtual int getSkill() = 0;

    bool isMonsterDie() {
        if (this->health <= 0) {
            return true;
        }
        else {
            return false;
        }
    }

    void takeDamage(int damage)  {
        this->health -= damage;
        if (this->health <= 0) {
            this->health = 0;
        }
        cout << this->name << " 이 " << damage << " 데미지 받음. 남은 체력 : " << this->health << endl;
    }

protected:
    string name = "Unknown";
    int health = 99;
    int attack = 99;
    int mana = 99;
    int maxMana = 99;
    int speed = 99;
    int accuracy = 99;
    float avoid = 99;
};

class Goblin : public Monster {

public:
    Goblin(int level) {
        name = "Goblin";
        health = level * 20;
        attack = (level * 10);
        mana = 0;
        maxMana = 3;
        speed = level;
        accuracy = 50 + (level * 20);
        avoid = 1 + (level * 0.05f);
    }

    string getName() override {
        return name;
    }

    int getHealth() override {
        return health;
    }

    int getAttack() override {
        if (mana < maxMana) { // maxMana만큼 Attack
            mana++; // 공격할 때 마다 마나++
            return attack;
        }
        else {
            mana = 0; // 마나 초기화
            return getSkill(); // 스킬 호출
        }
    }

    int getSkill() override {
        return attack * 2;
    }
};

class Orc : public Monster {

public:
    Orc(int level) {
        name = "Orc";
        health = level * 20;
        attack = (level * 10);
        mana = 0;
        maxMana = 3;
        speed = level;
        accuracy = 50 + (level * 20);
        avoid = 1 + (level * 0.05f);
    }

    string getName() override {
        return name;
    }

    int getHealth() override {
        return health;
    }

    int getAttack() override {
        if (mana < maxMana) { // maxMana만큼 Attack
            mana++; // 공격할 때 마다 마나++
            return attack;
        }
        else {
            mana = 0; // 마나 초기화
            return getSkill(); // 스킬 호출
        }
    }

    int getSkill() override {
        return attack * 2;
    }
};

class Slime : public Monster {

public:
    Slime(int level) {
        name = "Slime";
        health = level * 20;
        attack = (level * 10);
        mana = 0;
        maxMana = 3;
        speed = level;
        accuracy = 50 + (level * 20);
        avoid = 1 + (level * 0.05f);
    }

    string getName() override {
        return name;
    }

    int getHealth() override {
        return health;
    }

    int getAttack() override {
        if (mana < maxMana) { // maxMana만큼 Attack
            mana++; // 공격할 때 마다 마나++
            return attack;
        }
        else {
            mana = 0; // 마나 초기화
            return getSkill(); // 스킬 호출
        }
    }

    int getSkill() override {
        return attack * 2;
    }
};

class BossMonster : public Monster {

public:
    BossMonster(int level) {
        name = "BossMonster";
        health = level * 20;
        attack = (level * 10);
        mana = 0;
        maxMana = 3;
        speed = level;
        accuracy = 50 + (level * 20);
        avoid = 1 + (level * 0.05f);
    }

    string getName() override {
        return name;
    }

    int getHealth() override {
        return health;
    }

    int getAttack() override {
        if (mana < maxMana) { // maxMana만큼 Attack
            mana++; // 공격할 때#ifndef MONSTERS_H
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
    virtual string getName() = 0;
    virtual int getHealth() = 0;
    virtual int getAttack() = 0;
    virtual int getSkill() = 0;

    bool isMonsterDie() {
        if (this->health <= 0) {
            return true;
        }
        else {
            return false;
        }
    }

    void takeDamage(int this->damage)  {
        this->health -= this->damage;
        if (this->health <= 0) {
            this->health = 0;
        }
        cout << this->name << " 이 " << this->damage << " 데미지 받음. 남은 체력 : " << this->health << endl;
    }

protected:
    string name = "Unknown";
    int health = 99;
    int attack = 99;
    int mana = 99;
    int maxMana = 99;
    int speed = 99;
    int accuracy = 99;
    float avoid = 99;
};

class Goblin : public Monster { //고블린

public:
    Goblin(int level) {
        name = "Goblin";
        health = level * 20;
        attack = (level * 10);
        mana = 0;
        maxMana = 3;
        speed = level;
        accuracy = 50 + (level * 20);
        avoid = 1 + (level * 0.05f);
    }

    string getName() override {
        return name;
    }

    int getHealth() override {
        return health;
    }

    int getAttack() override {
        if (mana < maxMana) { // maxMana만큼 Attack
            mana++; // 공격할 때 마다 마나++
            return attack;
        }
        else {
            mana = 0; // 마나 초기화
            return getSkill(); // 스킬 호출
        }
    }

    int getSkill() override {
        return attack * 2;
    }
};

class Orc : public Monster { // 오크

public:
    Orc(int level) {
        name = "Orc";
        health = level * 20;
        attack = (level * 10);
        mana = 0;
        maxMana = 3;
        speed = level;
        accuracy = 50 + (level * 20);
        avoid = 1 + (level * 0.05f);
    }

    string getName() override {
        return name;
    }

    int getHealth() override {
        return health;
    }

    int getAttack() override {
        if (mana < maxMana) { // maxMana만큼 Attack
            mana++; // 공격할 때 마다 마나++
            return attack;
        }
        else {
            mana = 0; // 마나 초기화
            return getSkill(); // 스킬 호출
        }
    }

    int getSkill() override {
        return attack * 2;
    }
};

class Slime : public Monster { // 슬라임

public:
    Slime(int level) {
        name = "Slime";
        health = level * 20;
        attack = (level * 10);
        mana = 0;
        maxMana = 3;
        speed = level;
        accuracy = 50 + (level * 20);
        avoid = 1 + (level * 0.05f);
    }

    string getName() override {
        return name;
    }

    int getHealth() override {
        return health;
    }

    int getAttack() override {
        if (mana < maxMana) { // maxMana만큼 Attack
            mana++; // 공격할 때 마다 마나++
            return attack;
        }
        else {
            mana = 0; // 마나 초기화
            return getSkill(); // 스킬 호출
        }
    }

    int getSkill() override {
        return attack * 2;
    }
};

class BossMonster : public Monster { // 보스

public:
    BossMonster(int level) {
        name = "BossMonster";
        health = level * 20;
        attack = (level * 10);
        mana = 0;
        maxMana = 3;
        speed = level;
        accuracy = 50 + (level * 20);
        avoid = 1 + (level * 0.05f);
    }

    string getName() override {
        return name;
    }

    int getHealth() override {
        return health;
    }

    int getAttack() override {
        if (mana < maxMana) { // maxMana만큼 Attack
            mana++; // 공격할 때 마다 마나++
            return attack;
        }
        else {
            mana = 0; // 마나 초기화
            return getSkill(); // 스킬 호출
        }
    }

    int getSkill() override {
        return attack * 2;
    }
};

#endif // MONSTERS_H 마다 마나++
            return attack;
        }
        else {
            mana = 0; // 마나 초기화
            return getSkill(); // 스킬 호출
        }
    }

    int getSkill() override {
        return attack * 2;
    }
};

#endif // MONSTERS_H
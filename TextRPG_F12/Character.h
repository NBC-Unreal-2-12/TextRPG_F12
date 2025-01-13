#ifndef CHARACTER_H
#define CHARACTER_H
#pragma once

#include <string>
#include "Job.h"
#include "Inventory.h"
#include "Item.h"

using namespace std;


class Character
{
private:
    string name;
    int level;
    int health;
    int maxHealth;
    int mp;
    int maxMp;
    double attack;
    int experience;
    int gold;
    int attackSpeed;
    double accuracy;
    double evasion;
    Job* job;
    bool isDead;
    static Character* instance;
    Character(string userName, Job* characterJob);
    Inventory inventory;

public:
    Character(const Character&) = delete;
    Character& operator=(const Character&) = delete;
    static Character* getInstance(string userName, Job* characterJob);
    void displayStatus();
    void levelUp();
    void useItem(Item* item);
    void addItemToInventory(Item* item);
    void removeItemFromInventory(Item* item);
    void displayInventory();

    // 추가
    int getGold();
    void setGold(int sellPrice);

    // 추가
    string setName();
};

#endif
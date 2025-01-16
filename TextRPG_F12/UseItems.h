#pragma once

#include "Item.h"
#include "Character.h"

// 회복 포션
// 체력 회복 소모성 아이템
class HealthPotion : public Item
{
private:
    int healthRestore; // 회복량

public:
    HealthPotion(const string& itemName, int itemPrice, int restoreAmount)
        : Item(itemName, itemPrice), healthRestore(restoreAmount)
    {
    }

    void use(Character* character)
    {
        character->setHealth(character->getHealth() + character->getMaxHealth() * healthRestore / 100);
    }

};

//마나포션
//마나 회복 소모성 아이템
class ManaPotion : public Item
{
private:
    int manaRestore; // 마나 회복량

public:
    ManaPotion(const string& itemName, int itemPrice, int restoreAmount)
        : Item(itemName, itemPrice), manaRestore(restoreAmount)
    {
    }

    void use(Character* character) override
    {
        character->setMP(character->getMP() + character->getMaxHealth() * manaRestore / 100);
    }
};
//어택부스트
//공격력 증가 소모성 아이템
class AttackBoost : public Item
{
private:
    int attackIncrease; // 공격력 증가량

public:
    AttackBoost(const string& itemName, int itemPrice, int increaseAmount)
        : Item(itemName, itemPrice), attackIncrease(increaseAmount)
    {
    }

    void use(Character* character) override
    {
        character->setAttack(character->getAttack() + attackIncrease);
    }
};

//진흙단 -> 캐릭터 회피율 증가 포션으로 변경
class EvasionBoost : public Item
{
private:
	int evasionIncrease; // 회피율 증가량

public:
    EvasionBoost(const string& itemName, int itemPrice, int reductionAmount)
        : Item(itemName, itemPrice), evasionIncrease(reductionAmount)
    {
    }

    void use(Character* character) override
    {
        character->setEvation(character->getEvasion() + evasionIncrease);
    }
};

class AttackSpeedBoost : public Item
{
private:
    int attackSpeedIncrease; // 공격속도 증가량

public:
    AttackSpeedBoost(const string& itemName, int itemPrice, int increaseAmount)
        : Item(itemName, itemPrice), attackSpeedIncrease(increaseAmount)
    {
    }

    void use(Character* character) override
    {
        character->setAttackSpeed(character->getAttackSpeed() + attackSpeedIncrease);
    }
};
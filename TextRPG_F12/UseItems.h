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
        int prevHP = character->getHealth();
        character->setHealth(character->getHealth() + character->getMaxHealth() * healthRestore / 100);
        cout << "\n체력이 " << character->getHealth() - prevHP << "만큼 회복되었습니다! (현재 체력 : " << character->getHealth() << ")" << endl;
        delay(500);
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
        int prevMP = character->getMP();
        character->setMP(character->getMP() + character->getMaxHealth() * manaRestore / 100);
        cout << "\n마나가 " << character->getMP() - prevMP << "만큼 회복되었습니다! (현재 체력 : " << character->getMP() << ")" << endl;
        delay(500);
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
        int prevAttack = character->getAttack();
        character->setAttack(character->getAttack() + attackIncrease);
        cout << "\n공격력이 " << character->getAttack() - prevAttack << "만큼 증가하였습니다! (현재 공격력 : " << character->getAttack() << ")" << endl;
        delay(500);
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
        int prevEvasion = character->getEvasion();
        character->setEvation(character->getEvasion() + evasionIncrease);
        cout << "\n회피율이 " << character->getEvasion() - prevEvasion << "만큼 증가하였습니다! (현재 회피율 : " << character->getEvasion() << ")" << endl;
        delay(500);
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
        int prevAttackSpeed = character->getAttackSpeed();
        character->setAttackSpeed(character->getAttackSpeed() + attackSpeedIncrease);
        cout << "\n공격 속도가 " << character->getAttackSpeed() - prevAttackSpeed << "만큼 증가하였습니다! (현재 공격 속도 : " << character->getAttackSpeed() << ")" << endl;
        delay(500);
    }
};
#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Character;

class Item 
{
protected:
    string name; // 아이템 이름
    int price; // 아이템 가격

public:
    Item(const string& itemName, int itemPrice)
        : name(itemName), price(itemPrice) 
    {
    }

    virtual ~Item() = default;

    string getName() const 
    {
        return name;
    }
    int getPrice() const 
    {
        return price; 
    }

    virtual void use(Character* character) = 0;
};
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

    void use(Character* character) override {}
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
    }
};

//진흙단
//명중률 감소 소모성 아이템
class MudBall : public Item
{
private:
    int accuracyReduction; // 명중률 감소량

public:
    MudBall(const string& itemName, int itemPrice, int reductionAmount)
        : Item(itemName, itemPrice), accuracyReduction(reductionAmount)
    {
    }

    void use(Character* character) override
    {
    }
};

//스피드업
//속도 증가 소모성 아이템
class SpeedPotion : public Item
{
private:
    int speedIncrease; // 속도 증가량

public:
    SpeedPotion(const string& itemName, int itemPrice, int increaseAmount)
        : Item(itemName, itemPrice), speedIncrease(increaseAmount)
    {
    }

    void use(Character* character) override
	{
	}
};

//드랍 아이템 확률 매우낮음 
//1회 부활아이템 사용시 소멸
class ReviveItem : public Item
{
private:
    int reviveHealth; // 부활시 줄 체력

public:
    ReviveItem(const string& itemName, int itemPrice, int health)
        : Item(itemName, itemPrice), reviveHealth(health)
    {
    }

    void use(Character* character) override
	{
	}
};

//몬스터 드랍 아이템
class MonsterLoot : public Item
{
public:
    MonsterLoot(const string& itemName, int itemPrice)
        : Item(itemName, itemPrice)
    {
    }

    void use(Character* character) override
    {
    }
};

#endif // ITEM_H

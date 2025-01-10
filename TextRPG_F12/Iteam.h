#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std; 

class Character;

class Item {
protected:
    int index; // Item의 인덱스
    string name; // 아이템 이름
    int price; // 아이템 가격

public:
    Item(int idx, const string& itemName, int itemPrice)
        : index(idx), name(itemName), price(itemPrice) {
    }

    virtual ~Item() = default;

    int getIndex() const { return index; }
    string getName() const { return name; }
    int getPrice() const { return price; }

    virtual void use(Character* character) = 0;
};

class HealthPotion : public Item {
private:
    int healthRestore; // 회복량

public:
    HealthPotion(int idx, const string& itemName, int itemPrice, int restoreAmount)
        : Item(idx, itemName, itemPrice), healthRestore(restoreAmount) {
    }

    void use(Character* character) override;
};

class ManaPotion : public Item {
private:
    int manaRestore; // 마나 회복량

public:
    ManaPotion(int idx, const string& itemName, int itemPrice, int restoreAmount)
        : Item(idx, itemName, itemPrice), manaRestore(restoreAmount) {
    }

    void use(Character* character) override;
};

class AttackBoost : public Item {
private:
    int attackIncrease; // 공격력 증가량

public:
    AttackBoost(int idx, const string& itemName, int itemPrice, int increaseAmount)
        : Item(idx, itemName, itemPrice), attackIncrease(increaseAmount) {
    }

    void use(Character* character) override;
};

#endif // ITEM_H

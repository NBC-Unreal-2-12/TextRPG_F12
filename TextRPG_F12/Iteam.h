#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std; 

class Character;

class Item {
protected:
    int index; // Item�� �ε���
    string name; // ������ �̸�
    int price; // ������ ����

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
    int healthRestore; // ȸ����

public:
    HealthPotion(int idx, const string& itemName, int itemPrice, int restoreAmount)
        : Item(idx, itemName, itemPrice), healthRestore(restoreAmount) {
    }

    void use(Character* character) override;
};

class ManaPotion : public Item {
private:
    int manaRestore; // ���� ȸ����

public:
    ManaPotion(int idx, const string& itemName, int itemPrice, int restoreAmount)
        : Item(idx, itemName, itemPrice), manaRestore(restoreAmount) {
    }

    void use(Character* character) override;
};

class AttackBoost : public Item {
private:
    int attackIncrease; // ���ݷ� ������

public:
    AttackBoost(int idx, const string& itemName, int itemPrice, int increaseAmount)
        : Item(idx, itemName, itemPrice), attackIncrease(increaseAmount) {
    }

    void use(Character* character) override;
};

#endif // ITEM_H

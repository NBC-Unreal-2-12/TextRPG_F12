#ifndef ITEM_H
#define ITEM_H

#include <string>

void delay(int milliseconds);

using namespace std;

class Character;

class Item 
{
protected:
    std::string name; // 아이템 이름
    int price; // 아이템 가격

public:
    Item(const std::string& itemName, int itemPrice)
        : name(itemName), price(itemPrice) 
    {
    }

    virtual ~Item() = default;

    std::string getName() const
    {
        return name;
    }
    int getPrice() const 
    {
        return price; 
    }

    virtual std::string getEffect() const = 0;

    virtual void use(Character* character) = 0;
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

    std::string getEffect() const
    {
        return "사망 시 부활";
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
        cout << "아.. 저거 상점에 팔면 " << this->getPrice()*0.6 <<"골드 짜리였는데.." << endl;
        delay(1000);
    }

    std::string getEffect() const
    {
        return "판매 가격 : " + to_string(static_cast<int>(price * 0.6)) + "골드";
    }
};

#endif // ITEM_H

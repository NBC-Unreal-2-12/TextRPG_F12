#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "Item.h"

using namespace std;

class Inventory 
{
private:
    vector<Item*> inventory;
    unordered_map<Item*, int> counts;

    // 싱글톤 인스턴스
    static Inventory* instance;

    // 생성자를 private으로 선언하여 외부에서 인스턴스를 생성하지 못하도록 제한
    Inventory() {}
    
    friend class Character; // Character 클래스가 private 멤버에 접근 가능하도록 설정

public:
    // 복사 생성자와 대입 연산자를 삭제하여 복사 방지
    Inventory(const Inventory&) = delete;
    Inventory& operator=(const Inventory&) = delete;

    // 싱글톤 인스턴스를 반환하는 정적 메서드
    static Inventory* getInstance();

    void addItem(Item* item);

    Item* findItem(int index);

    void sellItem(int index);

    void useItem(int index, Character* player);

    void listItem();

    vector<Item*> getInventory();

    bool isInventoryEmpty();

    int numberOfItems(Item* item);
};

#endif // INVENTORY_H
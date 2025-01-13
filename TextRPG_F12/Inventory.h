#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Item.h"

using namespace std;

class Inventory 
{
private:
    vector<Item*> inventory;

public:
    void addItem(Item* item) 
    {
        inventory.push_back(item);
        cout << "인벤토리에 " << item->getName() << "이(가) 추가되었습니다." << endl;
    }

    bool hasItem(Item* item) 
    {
        auto it = find(inventory.begin(), inventory.end(), item);

        if (it != inventory.end()) {
            return true;
        }
        else {
            return false;
        }
    }

    void removeItem(Item* item) 
    {
        auto it = find(inventory.begin(), inventory.end(), item);

        if (it != inventory.end()) 
        {
            inventory.erase(it);
            cout << item->getName() << " 제거됨." << endl;
        }
        else 
        {
            cout << item->getName() << " 이(가) 없습니다." << endl;
        }
    }

    void listItem() 
    {
        for (auto it : inventory) 
        {
            cout << it->getName() << endl;
        }
    }


};

#endif // INVENTORY_H
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

public:
    void addItem(Item* item) 
    {
        if (counts[item] == 0)
        {
            inventory.push_back(item);
        }
        counts[item]++;
        cout << "인벤토리에 " << item->getName() << "이(가) 추가되었습니다.\n" << endl;
    }

    Item* findItem(int index) 
    {
        if (index < 0 || index >= inventory.size())
        {
            return nullptr;
        }

        Item* item = inventory[index];
        if (counts.find(item) != counts.end() && counts[item] > 0)
        {
            return item;
        }
        return nullptr;
    }

    void sellItem(int index) 
    {
        Item* item = findItem(index);
        if (item == nullptr)
        {
            cout << "잘못된 입력입니다." << endl;
            return;
        }

        if (--counts[item] == 0)
        {
            counts.erase(item);
            inventory.erase(remove(inventory.begin(), inventory.end(), item), inventory.end());
            cout << item->getName() << "이(가) 판매되었습니다. 남은 개수 : 0개" << endl;
        }
        else
        {
            cout << item->getName() << "이(가) 판매되었습니다. 남은 개수 : " << counts[item] << endl;
        }
    }

    void useItem(int index, Character* player)
    {
        Item* item = findItem(index);
        if (item == nullptr)
        {
            cout << "잘못된 입력입니다." << endl;
            return;
        }

        if (counts[item] > 0)
        {
            item->use(player);
            if (--counts[item] == 0)
            {
                counts.erase(item);
                inventory.erase(remove(inventory.begin(), inventory.end(), item), inventory.end());
                cout << item->getName() << "이(가) 사용되었습니다. 남은 개수 : 0개" << endl;
            }
            else
            {
                cout << item->getName() << "이(가) 사용되었습니다. 남은 개수 : " << counts[item] << endl;
            }
        }
        else
        {
            cout << item->getName() << " 이(가) 없습니다." << endl;
        }
    }

    void listItem() 
    {
        cout << "======== ( Inventory ) ========" << endl;
        for (int idx = 0; idx < inventory.size();idx++)
        {
            Item* item = inventory[idx];
            cout << "[" << idx << "] " << item->getName() << " (개수: " << counts[item] << ")" << endl;
        }
    }

    vector<Item*> getInventory()
    {
        return inventory;
    }

};

#endif // INVENTORY_H
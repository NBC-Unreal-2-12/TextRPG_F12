#include "inventory.h"

// 싱글톤 인스턴스 초기화
Inventory* Inventory::instance = nullptr;

// 싱글톤 인스턴스를 반환하는 정적 메서드
Inventory* Inventory::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Inventory();
    }
    return instance;
}

void Inventory::addItem(Item* item)
{
    if (counts[item] == 0)
    {
        inventory.push_back(item);
    }
    counts[item]++;
    cout << "인벤토리에 " << item->getName() << "이(가) 추가되었습니다.\n" << endl;
}

Item* Inventory::findItem(int index)
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

void Inventory::sellItem(int index)
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

void Inventory::useItem(int index, Character* player)
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

void Inventory::listItem()
{
    cout << "======== ( Inventory ) ========" << endl;
    for (int idx = 0; idx < inventory.size();idx++)
    {
        Item* item = inventory[idx];
        cout << "[" << idx << "] " << item->getName() << " (개수: " << counts[item] << ")" << endl;
    }
    if (inventory.empty()) cout << "인벤토리가 비어 있습니다.\n";
}

vector<Item*> Inventory::getInventory()
{
    return inventory;
}
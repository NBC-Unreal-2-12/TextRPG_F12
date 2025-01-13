#include "ItemManager.h"

void ItemManager::registerItem(int index, Item* item)
{
	itemList[index] = item;
}

Item* ItemManager::getItemByIndex(int index) const
{
	auto iter = itemList.find(index);
	if (iter != itemList.end())
	{
		return iter->second;
	}
	return nullptr;
}

void ItemManager::initializeDefaultItems()
{
	// 아이템 리스트 초기화
	registerItem(1, new HealthPotion("Small Health Potion", 50, 20));
	registerItem(2, new HealthPotion("Large Health Potion", 150, 50));
	registerItem(3, new ManaPotion("Small Mana Potion", 50, 20));
	registerItem(4, new ManaPotion("Small Mana Potion", 150, 50));
	registerItem(5, new AttackBoost("Adrenaline", 100, 5));
}


// 모든 아이템 반환 (참조)
const std::map<int, Item*>& ItemManager::getAllItems() const
{
	return itemList;
}
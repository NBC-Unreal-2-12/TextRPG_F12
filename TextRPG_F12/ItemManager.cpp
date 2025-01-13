#include "ItemManager.h"

void ItemManager::registerItem(int index, Item* item)
{
	itemList[index] = item;
}

void ItemManager::registerLoot(int index, Item* item)
{
	lootLIst[index] = item;
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

// 모든 아이템 반환 (참조)
const std::map<int, Item*>& ItemManager::getAllItems() const
{
	return itemList;
}

// 모든 전리품 반환 (참조)
const std::map<int, Item*>& ItemManager::getAlILoots() const
{
	return lootLIst;
}

void ItemManager::initializeDefaultItems()
{
	// 아이템 리스트 초기화
	registerItem(1, new HealthPotion("Small Health Potion", 50, 20));
	registerItem(2, new HealthPotion("Large Health Potion", 150, 50));
	registerItem(3, new ManaPotion("Small Mana Potion", 50, 20));
	registerItem(4, new ManaPotion("Small Mana Potion", 150, 50));
	registerItem(5, new AttackBoost("Adrenaline", 100, 5));

	// 전리품 아이템 리스트 초기화
	registerLoot(101, new MonsterLoot("고블린의 작은 동전", 20));
	registerLoot(103, new MonsterLoot("오크의 부서진 검", 20));
	registerLoot(104, new MonsterLoot("슬라임 젤리", 20));
	registerLoot(105, new MonsterLoot("고블린 대장의 반지", 45));
	registerLoot(106, new MonsterLoot("오크 대왕의 검", 45));
	registerLoot(107, new MonsterLoot("슬라임 왕관", 45));
	registerLoot(108, new MonsterLoot("드래곤의 비늘", 75));
	registerLoot(109, new MonsterLoot("발록의 재", 75));
	registerLoot(110, new MonsterLoot("크라켄의 심장", 75));
	registerLoot(111, new MonsterLoot("가시고기의 갈비뼈", 125));
}

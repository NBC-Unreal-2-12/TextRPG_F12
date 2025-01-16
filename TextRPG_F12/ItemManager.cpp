#include "ItemManager.h"

// 싱글톤 인스턴스 초기화
ItemManager* ItemManager::instance = nullptr;

// 싱글톤 인스턴스를 반환하는 정적 메서드
ItemManager* ItemManager::getInstance()
{
	if (instance == nullptr)
	{
		instance = new ItemManager();
	}
	return instance;
}

// 소비 아이템 등록
void ItemManager::registerItem(int index, Item* item)
{
	itemList[index] = item;
}

// 전리품 등록
void ItemManager::registerLoot(int index, Item* item)
{
	lootLIst[index] = item;
}

// 인덱스로 아이템 접근
Item* ItemManager::getItemByIndex(int index) const
{
	auto iter = itemList.find(index);
	if (iter != itemList.end())
	{
		return iter->second;
	}
	return nullptr;
}

// 인덱스로 아이템 접근
Item* ItemManager::getLootByIndex(int index) const
{
	auto iter = lootLIst.find(index);
	if (iter != lootLIst.end())
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
	registerItem(1, new HealthPotion("회복포션(소)", 50, 10));
	registerItem(2, new HealthPotion("회복포션(대)", 150, 30));
	registerItem(3, new HealthPotion("회복포션(특대)", 300, 70));
	registerItem(4, new ManaPotion("마나포션(소)", 50, 10));
	registerItem(5, new ManaPotion("마나포션(대)", 150, 30));
	registerItem(6, new ManaPotion("마나포션(특대)", 300, 70));
	registerItem(7, new AttackBoost("데미지 부스터", 100, 5));
	registerItem(8, new AttackSpeedBoost("공격 속도 부스트", 100, 5));
    registerItem(9, new EvasionBoost("투명망토", 80, 5));

	// 전리품 아이템 리스트 초기화
	registerLoot(101, new MonsterLoot("고블린의 작은 동전", 20));
	registerLoot(102, new MonsterLoot("오크의 부서진 검", 20));
	registerLoot(103, new MonsterLoot("슬라임 젤리", 20));
	registerLoot(104, new MonsterLoot("고블린 대장의 반지", 45));
	registerLoot(105, new MonsterLoot("오크 대왕의 검", 45));
	registerLoot(106, new MonsterLoot("슬라임 왕관", 45));
	registerLoot(107, new MonsterLoot("드래곤의 비늘", 75));
	registerLoot(108, new MonsterLoot("발록의 재", 75));
	registerLoot(109, new MonsterLoot("크라켄의 심장", 75));
	registerLoot(110, new MonsterLoot("가시고기의 갈비뼈", 125));
	registerLoot(999, new ReviveItem("부활의 토템", 300, 100));
}

// 몬스터 수에 따른 골드 획득 기대값
// 1라운드 100:1 
// + 50
// 2라운드 70:2 30 : 3
// + 230
// 3라운드 70 : 2 30 : 3
// + 345
// 4라운드 70 : 2 30 : 3
// + 460
// 5라운드 70 : 2 30 : 3
// + 575
// 6라운드 50 : 1 50 : 2
// + 450
// 7라운드 50 : 1 50 : 2
// + 525
// 8라운드 50 : 1 50 : 2
// + 600
// 9라운드 50 : 1 50 : 2
// + 675
// 10라운드 50 : 1 50 : 2
// + 750
// 11라운드 40 : 1 60 : 2
// + 880
// 12라운드 40 : 1 60 : 2
// + 960
// 13라운드 40 : 1 60 : 2
// + 1040
// 14라운드 40 : 1 60 : 2
// + 1120
// 15라운드 100 : 1
// + 750

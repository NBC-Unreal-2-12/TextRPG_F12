#pragma once

#include "GameManager.h"
#include "UseItems.h"
#include <map>

class ItemManager
{
private:
	std::map<int, Item*> itemList;  // 플레이어가 사용하는 소비 아이템
	std::map<int, Item*> lootLIst;  // 몬스터 처치 후 전리품

	// 싱글톤 인스턴스
	static ItemManager* instance;

	// 생성자를 private으로 선언하여 외부에서 인스턴스를 생성하지 못하도록 제한
	ItemManager() {}

public:
	~ItemManager()
	{
		for (auto& pair : itemList)
		{
			delete pair.second;
		}
	}

	// 싱글톤 인스턴스를 반환하는 정적 메서드
	static ItemManager* getInstance();

	void registerItem(int index, Item* item);	// 소비 아이템 등록
	void registerLoot(int index, Item* item);	// 전리품 등록
	Item* getItemByIndex(int index) const;		// 아이템 인덱스로 접근
	Item* getLootByIndex(int index) const;		// 전리품 인덱스로 접근
	void initializeDefaultItems();				// 아이템 목록 초기화 (상점 방문시 사용)
	const map<int, Item*>& getAllItems() const; // 모든 소비 아이템 목록
	const map<int, Item*>& getAlILoots() const; // 모든 전리품 목록

	int getItemListSize() const  // 아이템 리스트 사이즈 반환
	{
		return itemList.size();
	}
};
﻿#pragma once

#include "GameManager.h"
#include <map>

class ItemManager
{
private:
	std::map<int, Item*> itemList;  // 플레이어가 사용하는 소비 아이템
	std::map<int, Item*> lootLIst;  // 몬스터 처치 후 전리품


public:
	~ItemManager()
	{
		for (auto& pair : itemList)
		{
			delete pair.second;
		}
	}

	void registerItem(int index, Item* item);	// 소비 아이템 등록
	void registerLoot(int index, Item* item);	// 전리품 등록
	Item* getItemByIndex(int index) const;		// 아이템 인덱스로 접근
	void initializeDefaultItems();				// 아이템 목록 초기화 (상점 방문시 사용)
	const map<int, Item*>& getAllItems() const; // 모든 소비 아이템 목록
	const map<int, Item*>& getAlILoots() const; // 모든 전리품 목록
};
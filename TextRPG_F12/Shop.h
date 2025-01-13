#pragma once

#include "GameManager.h"
#include <vector>
#include <algorithm>
#include <iostream>

class ItemManager;

class Shop 
{
private:
	struct StockItem
	{
		int index;
		Item* item;   // 아이템 포인터
		int quantity; // 재고 수량

		StockItem(int index, Item* _item, int _quantity = 5);
	};

	std::vector<StockItem> stock;
	bool isValidIndex(int index) const;	// 인덱스 접근 유효성 검사

public:
	~Shop() = default;

	Shop(ItemManager& itemManager);  // 상점 생성자

	void displayItems();		// 아이템 목록 확인
	void buyItem(int index, Character* player);  // 아이템 구매
	void sellItem(int index, Character* player); // 아이템 판매

};

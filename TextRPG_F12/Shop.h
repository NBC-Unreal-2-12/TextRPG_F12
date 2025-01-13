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
	bool isValidIndex(int index) const;

public:
	~Shop() = default;

	Shop(ItemManager& itemManager);

	void displayItems();
	void buyItem(int index, Character* player);
	void sellItem(int index, Character* player);

};

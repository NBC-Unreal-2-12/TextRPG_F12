#pragma once

#include "GameManager.h"
#include <vector>
#include <algorithm>
#include <iostream>

class Shop 
{
private:
	struct StockItem
	{
		Item* item;   // 아이템 포인터
		int quantity; // 재고 수량

		StockItem(Item* _item, int _quantity = 5);
	};

	std::vector<StockItem> stock;

public:
	Shop() 
	{
	}
	~Shop() = default;

	void displayItems();
	void buyItem(int index, Character* player);
	void sellItem(int index, Character* player);

};

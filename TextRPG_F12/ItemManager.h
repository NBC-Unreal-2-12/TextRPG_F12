#pragma once

#include "GameManager.h"
#include <map>

class ItemManager
{
private:
	std::map<int, Item*> itemList;

public:
	~ItemManager()
	{
		for (auto& pair : itemList)
		{
			delete pair.second;
		}
	}

	void registerItem(int index, Item* item);
	Item* getItemByIndex(int index) const;
	void initializeDefaultItems();
	const map<int, Item*>& getAllItems() const;
};
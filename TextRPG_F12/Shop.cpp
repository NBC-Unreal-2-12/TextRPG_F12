#include "Shop.h"

#include <set>

// StockItem 생성자
Shop::StockItem::StockItem(int index, Item* _item, int _quantity, bool isLoot)
	: index(index), item(_item), quantity(_quantity), isLoot(isLoot)
{
}

Shop::Shop(ItemManager* itemManager)
{
	// 상점에 초기 재고 랜덤 추가
	std::set<int> randomIndex;
	while(randomIndex.size() < stockMaxSize)
	{
		randomIndex.insert(std::rand() % itemManager->getItemListSize());
	}

	for (const auto& pair : itemManager->getAllItems())
	{
		int index = pair.first;
		Item* item = pair.second;

		if (find(randomIndex.begin(), randomIndex.end(), index) != randomIndex.end())
		{
			stock.emplace_back(index, item, 5, false);
		}
	}

	// 상점에 초기 전리품 추가
	for (const auto& pair : itemManager->getAlILoots())
	{
		int index = pair.first;
		Item* item = pair.second;

		if (item)
		{
			stock.emplace_back(index, item, 5, true);
		}
	}

}

// 인덱스 아이템 접근 유효성 검사
bool Shop::isValidIndex(int index) const
{
	if (index < 0 || index > stock.size()) return false;
	return true;
}

// 상점 아이템 리스트 출력
void Shop::displayItems()
{
	system("cls");
	std::cout << R"(
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣄⣠⣄⣤⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣾⣿⣿⣿⠿⠟⠛⠋⠉⠉⠉⠉⠉⠉⠉⠉⠉⠛⠛⠿⢿⣿⣿⣿⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣠⣄⣤⣠⣾⣿⣿⠟⠋⢀⣠⣀⠀⢀⣀⠀⢀⣀⠀⠀⣀⣄⡀⠀⠀⣀⣀⣈⠙⢿⣿⣿⣦⣄⣤⣀⡀⠀⠀⠀⠀
⠀⠀⠀⣰⣿⣿⣿⣿⣿⣿⠃⠀⠀⢿⣥⣙⠀⠸⣯⣀⣼⡷⠀⣾⠋⠈⢻⡆⠘⣿⢉⣹⡇⠀⢹⣿⣿⣿⣿⣿⣿⡀⠀⠀⠀
⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⣤⣌⣿⠆⢸⣟⠈⢸⡷⠀⢻⣇⣀⣿⠃⢈⣿⠉⠉⠀⢀⣼⣿⣿⣿⣿⣿⣿⣇⠀⠀⠀
⠀⠀⣸⣿⣿⣿⣿⣿⣿⣿⣿⣷⣤⣀⠉⠀⠀⠀⠀⠀⠀⠁⠀⠀⠈⠉⠀⠀⠀⠀⢀⣠⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⡀⠀⠀
⠀⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣤⣤⣤⣠⣀⣄⣠⣄⣤⣤⣴⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀
⠀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀
⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀
⢾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆
⠙⠛⠟⠻⠻⣿⣿⣿⠛⠟⠻⠛⠟⠻⠛⠟⠻⠛⠟⠻⠛⠟⠻⠛⠟⠻⠛⠟⠻⠛⠟⠻⠛⠟⠻⠛⠿⣿⣿⣿⠛⠟⠻⠛⠁
⠀⠀⠀⠀⢀⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣤⣤⣤⣀⠀⠀⠀⠀⢘⣿⣿⡷⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿⣿⣿⣷⡄⠀⠀⢘⣿⣿⣟⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣿⣿⣿⠀⠀⠀⠀⣀⣀⣀⣀⣀⣀⣀⣀⠀⠀⠀⢸⣿⣿⡟⠁⣻⡇⠙⣿⣿⣿⠀⠀⢨⣿⣿⣯⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠠⣿⣿⣿⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⢸⣿⣿⡇⠀⣻⡇⠀⣿⣿⣿⠀⠀⢰⣿⣿⡷⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠐⣿⣿⣿⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⢸⣿⣿⡿⠟⣿⡿⠿⣿⣿⣿⠀⠀⢰⣿⣿⣟⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣿⣿⣿⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⢸⣿⣿⡇⠀⣽⡇⠀⣿⣿⣿⠀⠀⠰⣿⣿⣯⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠈⣿⣿⣿⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⢘⣿⣿⡷⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠈⣿⣿⣿⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠈⠛⠛⠛⠛⠛⠛⠛⠛⠛⠋⠀⠀⢘⣿⣿⣟⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠈⣿⣿⣿⠀⠀⠀⢀⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⢨⣿⣿⣯⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡷⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠙⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠁⠀⠀⠀⠀⠀
             )" << endl;

	int index = 1;
	for (const auto& it : stock)
	{
		if (it.isLoot == false)
		{
			std::cout << index++ << ". " << it.item->getName()
				<< " (가격: " << it.item->getPrice() << " 골드, 재고 수량: " << it.quantity << "개)\n";
		}
	}

	// 아이템이 하나도 없을 경우 (재고와 무관)
	if (stock.empty())
	{
		std::cout << "상점에 물건이 없습니다.\n";
	}


}

// 아이템 구매
void Shop::buyItem(int index, int itemCount, Character* player)
{
	// 아이템 유효성 검사
	if (!isValidIndex(index))
	{
		std::cout << "해당 아이템을 찾을 수 없습니다.\n";
		return;
	}

	// 해당 아이템 찾기
	auto& stockItem = stock[index - 1];

	int count = 0;

	Item* managedItem = ItemManager::getInstance()->getItemByIndex(stockItem.index);
	while (itemCount--)
	{
		// 재고가 없을 경우
		if (stockItem.quantity <= 0)
		{
			std::cout << stockItem.item->getName() << " 재고가 없습니다!\n";
			return;
		}

		// 잔고 부족
		if (player->getGold() < stockItem.item->getPrice())
		{
			std::cout << stockItem.item->getName() << ": 골드가 부족합니다. 보유 금액 " << player->getGold() << "골드\n";
			return;
		}

		// 구매 처리
		player->setGold(-stockItem.item->getPrice());
		player->addItemToInventory(managedItem);
		count++;

		// 재고 업데이트
		stockItem.quantity--;
	}
	std::cout << managedItem->getName() << "을(를) " << count << " 개 구매 했습니다. (잔고 : " << player->getGold() << ")\n";
}

// 아이템 판매
void Shop::sellItem(int index, int itemCount, Character* player)
{
	// 유효성 검사
	Item* item = player->findItemFromInventory(index);
	if (item == nullptr)
	{
		std::cout << "해당 아이템을 소지하고 있지 않습니다.\n";
		return;
	}

	// 해당 아이템 찾기
	auto& stockItem = *std::find_if(stock.begin(), stock.end(),
		[item](const StockItem& stockItem)
		{
			return stockItem.item->getName() == item->getName();
		});

	int count = 0;

	while (itemCount-- && Inventory::getInstance()->numberOfItems(item) > 0)
	{
		// 판매 처리
		int sellPrice = static_cast<int>(stockItem.item->getPrice() * 0.6);
		player->setGold(sellPrice);
		player->sellItemFromInventory(index);
		count++;

		// 재고 업데이트
		stockItem.quantity++;

	}
		std::cout << item->getName() << "을(를) " << count << " 개 판매 했습니다. (잔고 : " << player->getGold() << ")\n";
}
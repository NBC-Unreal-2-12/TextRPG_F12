#include "Shop.h"

// StockItem 생성자
Shop::StockItem::StockItem(Item* _item, int _quantity) : item(_item), quantity(_quantity) {}

// 상점 아이템 리스트 출력
void Shop::displayItems()
{
	std::cout << "\n======== ( Item Shop ) ========\n";
	for (const auto& it : stock)
	{
		std::cout << it.item->getIndex() << ". " << it.item->getName() << " (가격: " << it.item->getPrice() << " 골드, 재고 수량: " << it.quantity << "개)\n";
	}

	// 아이템이 하나도 없을 경우 (재고와 무관)
	if (stock.empty())
	{
		std::cout << "상점에 물건이 없습니다.\n";
	}
}

// 아이템 구매
void Shop::buyItem(int index, Character* player)
{
	// 아이템 유효성 검사
	if (index < 0 || index >= static_cast<int>(stock.size()))
	{
		std::cout << "잘못된 선택입니다.\n";
		return;
	}

	auto& stockItem = stock[index];

	// 재고가 없을 경우
	if (stockItem.quantity <= 0)
	{
		std::cout << stockItem.item->getName() << " 재고가 없습니다!\n";
		return;
	}

	// 잔고 부족
	if (player->getGold() < stockItem.item->getPrice())
	{
		std::cout << "골드가 부족합니다. 보유 금액 " << player->getGold() << "골드\n";
		return;
	}

	// 구매 처리
	player->setGold(-stockItem.item->getPrice());
	player->addItemToInventory(stockItem.item);

	// 재고 업데이트
	stock[index].quantity--;

	std::cout << stockItem.item->getName() << "을(를) 구매하였습니다. (잔고 : " << player->getGold() << ")\n";
}

// 아이템 판매
void Shop::sellItem(int index, Character* player)
{

	// 인벤토리 내에서 아이템 찾기
	/*
	Item* item = player->inven(item);
	if (!item)
	{
		std::cout << "해당 아이템을 소지하지 않고 있습니다.\n";
		return;
	}
	*/

	auto& stockItem = stock[index];
	auto item = stockItem.item;

	// 판매 처리
	int sellPrice = static_cast<int>(item->getPrice() * 0.6);
	player->setGold(sellPrice);
	player->removeItemFromInventory(item);

	// 재고 업데이트
	auto iter = find_if(stock.begin(), stock.end(),
		[&item](const StockItem& stockItem) { return stockItem.item->getName() == item->getName(); });

	if (iter != stock.end())
	{
		++iter->quantity;
	}
	else
	{
		stock.emplace_back(item, 1);
	}

	std::cout << item->getName() << "을 판매하였습니다. (잔고 : " << player->getGold() << ")\n";
}
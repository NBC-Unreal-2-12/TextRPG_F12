#include "GameManager.h"

// 정적 멤버 변수 정의
GameManager* GameManager::instance = nullptr;

// 상점 방문
void GameManager::visitShop(Character* player)
{
	Shop shop;
	shop.displayItems();

	int choice;
	cout << "아이템 구매 : 1 , 아이템 판매 : 2 >> ";
	cin >> choice;

	if (choice == 1)
	{
		int index;
		cout << "몇 번 아이템을 구매하시겠습니까? >> ";
		cin >> index;
		shop.buyItem(index, player);
	}
	else if (choice == 2)
	{
		int index;
		cout << "몇 번 아이템을 판매하시겠습니까? >> ";
		cin >> index;
		shop.sellItem(index, player);
	}
	else
	{
		cout << "부적절한 입력입니다." << endl;
	}
}

// 인벤토리 출력
void GameManager::displayInventory(Inventory inventory)
{
	cout << "======현재 소지한 아이템======" << endl;
	inventory.listItem();
	cout << "==============================." << endl;
}
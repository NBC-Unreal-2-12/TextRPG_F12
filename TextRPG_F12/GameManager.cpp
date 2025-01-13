﻿#include "GameManager.h"

// 정적 멤버 변수 정의
GameManager* GameManager::instance = nullptr;

// 상점 방문
void GameManager::visitShop(Character* player)
{
	// 아이템 리스트 초기화
	ItemManager itemManager;
	itemManager.initializeDefaultItems();

	Shop shop(itemManager);
	shop.displayItems();

	int choice = -1;

	while (choice != 0)
	{
		cout << "구매 : 1, 판매 : 2,  나가기 : 0 >> ";
		cin >> choice;

		if (choice == 0)
		{
			return; // 나가기
		}
		else if (choice == 1)
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
			cout << "부적절한 입력입니다. 다시 입력해주세요." << endl;
		}
	}
}

// 인벤토리 출력
void GameManager::displayInventory(Inventory inventory)
{
	cout << "======현재 소지한 아이템======" << endl;
	inventory.listItem();
	cout << "==============================." << endl;
}
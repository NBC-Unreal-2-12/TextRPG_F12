#include "GameManager.h"

// ���� �湮
void GameManager::visitShop(Character* player)
{
	Shop shop;
	shop.displayItems();

	int choice;
	cout << "������ ���� : 1 , ������ �Ǹ� : 2 >> ";
	cin >> choice;

	if (choice == 1)
	{
		int index;
		cout << "�� �� �������� �����Ͻðڽ��ϱ�? >> ";
		cin >> index;
		shop.buyItem(index, player);
	}
	else if (choice == 2)
	{
		int index;
		cout << "�� �� �������� �Ǹ��Ͻðڽ��ϱ�? >> ";
		cin >> index;
		shop.sellItem(index, player);
	}
	else
	{
		cout << "�������� �Է��Դϴ�." << endl;
	}
}

// �κ��丮 ǥ��
void GameManager::displayInventory(Inventory inventory)
{
	cout << "======���� ������ ������======" << endl;
	inventory.listItem();
	cout << "==============================." << endl;
}
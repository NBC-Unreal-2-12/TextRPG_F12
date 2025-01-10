#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Character.h"
#include "Shop.h"
#include "Inventory.h"

using namespace std;

// Text RPG���� GameManager�� �� �ϳ��� �����ؾ� �ϹǷ� �̱��� ���
class GameManager
{
private:
	// ���� ��� ������ �̱��� �ν��Ͻ��� ����
	static GameManager* instance;

	GameManager()
	{
	};

	~GameManager()
	{
	};

	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager) = delete;


public:
	// �̱��� �ν��Ͻ� ���� �޼���
	static GameManager* getInstance()
	{
		if (instance == nullptr)
		{
			instance = new GameManager();
		}
		return instance;
	}

	// ���� �湮
	void visitShop(Character* player)
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
	void displayInventory(Inventory inventory)
	{
		Inventory inventory;
		cout << "======���� ������ ������======" << endl;
		inventory.listItem();
		cout << "==============================." << endl;
	}

};

#endif // !GAMEMANAGER_H_
#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

#include "Character.h"
#include "Shop.h"
#include "Inventory.h"
#include "BattleManager.h"
#include "Item.h"
#include "Monster.h"

using namespace std;

// Text RPG���� GameManager�� �� �ϳ��� �����ؾ� �ϹǷ� �̱��� ���
class GameManager
{
private:
	// ���� ��� ������ �̱��� �ν��Ͻ��� ����
	static GameManager* instance;

	GameManager()
	{
		cout << "게임 매니저 생성\n";
	};

	~GameManager()
	{
		cout << "게임 매니저 소멸\n";
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
	void visitShop(Character* player);

	// �κ��丮 ǥ��
	void displayInventory(Inventory inventory);

};

#endif // !GAMEMANAGER_H_
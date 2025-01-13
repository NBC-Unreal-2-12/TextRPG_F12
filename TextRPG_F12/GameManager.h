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

// Text RPG에 GameManager는 하나만 있어야 하므로 싱글톤 사용
class GameManager
{
private:
	// 정적 멤버변수로 싱글톤 인스턴스를 저장
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
	// 싱글톤 인스턴스 접근 메서드
	static GameManager* getInstance()
	{
		if (instance == nullptr)
		{
			instance = new GameManager();
		}
		return instance;
	}

	// 게임 시작
	void InitGame()
	{
		Character::getInstance("test", 0)->displayStatus();

	}

	// 상점 방문
	void visitShop(Character* player);

	// 인벤토리 표시
	void displayInventory(Inventory inventory);

};

#endif // !GAMEMANAGER_H_
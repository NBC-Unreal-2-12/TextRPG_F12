#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "Character.h"
#include "Shop.h"
#include "Inventory.h"
#include "BattleManager.h"
#include "Item.h"
#include "ItemManager.h"
#include "Monster.h"
#include "MonsterFactory.h"

using namespace std;

// Text RPG에 GameManager는 하나만 있어야 하므로 싱글톤 사용
class GameManager
{
private:
	// 정적 멤버변수로 싱글톤 인스턴스를 저장
	static GameManager* instance;
	
	int round = 15; // 게임이 진행되는 총 라운드
	vector<vector<unique_ptr<Monster>>> monsterGroup; // 라운드별 몬스터들

	GameManager()
	{
		cout << "게임 매니저 생성\n";
		monsterGroup.resize(round); // 벡터 크기 미리 설정
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

	// 싱글톤 소멸 메서드
	static void destroyInstance()
	{
		delete instance;
		instance = nullptr;
	}

	// 게임 시작시 초기화 메서드
	void InitializeGame();

	// 상점 방문
	void visitShop(Character* player);

	// 인벤토리 표시
	void displayInventory(Inventory inventory);

	// 라운드 별 몬스터 마릿수를 결정하여 생성
	vector<unique_ptr<Monster>> generateMonsters(int round);

	// 특정 라운드의 몬스터 그룹을 반환
	const vector<unique_ptr<Monster>>& getMonsterGroup(int round) const;

	// 테스트용 모든 라운드의 몬스터 이름 출력
	void printAllMonsters() const;

};

#endif // !GAMEMANAGER_H_
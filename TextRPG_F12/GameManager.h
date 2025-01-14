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

	static void destroyInstance()
	{
		delete instance;
		instance = nullptr;
	}

	// 게임 시작
	void InitializeGame()
	{
		// 테스트 직업 생성 
		Job* job = new Warrior();

		// 캐릭터 이름 설정
		cout << "캐릭터 이름을 입력하세요: ";
		string name;
		getline(cin, name);

		// 싱글톤 객체 초기화 및 상태 출력
		Character::initialize(name, job);
		Character* player = Character::getInstance();
		player->displayStatus();

		// 미리 몬스터를 생성
		for (int currentRound = 1; currentRound <= round; currentRound++)
		{
			monsterGroup[currentRound - 1] = generateMonsters(currentRound);
		}


		// 필요에 따라 추가 초기화 작업 수행 가능
	}


	// 상점 방문
	void visitShop(Character* player);

	// 인벤토리 표시
	void displayInventory(Inventory inventory);

	// 라운드 별 몬스터 생성
	vector<unique_ptr<Monster>> generateMonsters(int round);

	// 특정 라운드의 몬스터 그룹을 반환
	const vector<unique_ptr<Monster>>& getMonsterGroup(int round) const
	{
		if (round < 0 || round >= static_cast<int>(monsterGroup.size()))
		{
			throw out_of_range("Invalid round index.");
		}
		return monsterGroup[round];
	}

	// 테스트용 모든 라운드의 몬스터 이름 출력
	void printAllMonsters() const;

};

#endif // !GAMEMANAGER_H_
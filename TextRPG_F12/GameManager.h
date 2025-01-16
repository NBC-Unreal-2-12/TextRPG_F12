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
	int currentRound = 0; // 현재 라운드
	vector<vector<unique_ptr<Monster>>> monsterGroup; // 라운드별 몬스터들

	bool isGameEnd; // 게임 종료 상태 변수

	GameManager() : isGameEnd(false)
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

	// 휴식하기
	void takeRest(Character* player);

	// 라운드 별 몬스터 마릿수를 결정하여 생성
	vector<unique_ptr<Monster>> generateMonsters(int round);

	// 특정 라운드의 몬스터 그룹을 반환
	vector<unique_ptr<Monster>>& getMonsterGroup(int round);

	int getCurrentRound()
	{
		return currentRound;
	}

	// 현재 라운드 정보를 갱신
	void setCurrentRound();

	// 현재 라운드 전투
	void combat(int currentRound);

	// 게임 종료 상태 확인용 getter/setter
	bool getIsGameEnd() const { return isGameEnd; }
	void setIsGameEnd(bool value) { isGameEnd = value; }

	// 테스트용 모든 라운드의 몬스터 이름 출력
	void printAllMonsters() const;
};

#endif // !GAMEMANAGER_H_
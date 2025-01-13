// TextRPG_F12.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include "GameManager.h"
#include "BattleManager.h"
#include "Character.h"
#include "Inventory.h"
#include "Item.h"
#include "Job.h"
#include "Monster.h"
#include "PlayerInput.h"
#include "Shop.h"
#include "Skill.h"

using namespace std;

// 게임 시작시 게임 매니저와 플레이어 생성
// 닉네임과 직업을 선택
// 플레이어의 정보 출력 후 엔터를 입력하여 전투로
// 
// 전투시 수준에 맞는 몬스터 풀에서 몬스터 인스턴스 생성
// 생성된 몬스터의 정보를 출력
// 엔터를 입력하여 전투 시작
// 
// 전투 시작시 공격속도를 비교하여 빠른 쪽이 선공
// 플레이어의 행동
// 1. 공격
// 2. 스킬
// 3. 인벤토리
// 4. 도망
// 몬스터의 행동
// 1. 공격
// 2. 스킬
// 플레이어의 체력이 0이되면 사망 -> 게임오버
// 몬스터의 체력이 0이되면 승리-> 상점방문여부 결정

// 상점 입장시 물품과 인벤토리 출력
// 구매 / 판매 결정
// 구매 결정시 
// 자판기처럼 n번 물품 선택해 구매 가능
// 판매 결정시
// 인벤토리의 n번 물품을 선택해 판매 가능
// 볼일을 마치면 퇴장->다음 전투로

// 조건을 달성하면 보스 등장
// 보스의 체력이 0이되면 승리

int main()
{
	GameManager* gameManager = GameManager::getInstance();
	gameManager->InitializeGame();
	Character* player = Character::getInstance();

	// 전투 테스트 코드입니다.
	BattleManager battleManager;

	Goblin* goblin1 = new Goblin();
	Goblin* goblin2 = new Goblin();
	vector<Monster*> monsterPool;
	monsterPool.push_back(goblin1);
	monsterPool.push_back(goblin2);

//	battleManager.startBattle(player,monsterPool);
	// startBattle의 인자는 vector<Monster*>보다 Monster*가 적절해 보입니다.

	gameManager->visitShop(player);
	battleManager.startBattle(player,monsterPool);



}
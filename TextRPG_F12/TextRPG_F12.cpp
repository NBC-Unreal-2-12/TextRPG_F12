// TextRPG_F12.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <limits> // numeric_limits 사용을 위해 필요
#include <cstdlib> // system() 함수 사용을 위해 필요
#include <thread> // std::this_thread::sleep_for 사용
#include <chrono> // std::chrono::seconds 사용

#include "GameManager.h"
#include "BattleManager.h"
#include "Character.h"
#include "Inventory.h"
#include "Item.h"
#include "Job.h"
#include "Monster.h"
#include "NormalMonster.h"
#include "EliteMonster.h"
#include "BossMonster.h"
#include "SpecialMonster.h"
#include "MonsterFactory.h"
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
// 매턴 선공을 결정
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

// 전투->상점 상점->전투로 이동할 때 화면 지우기
void gameStart() {
	cout << "Text RPG에 오신 것을 환영합니다." << endl;
	cout << "Press ENTER to continue..." << endl;

	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 엔터 입력받고 버퍼 지우기

	this_thread::sleep_for(chrono::seconds(1)); // 1초 대기
	system("cls"); // 화면 지우기 cls 명령 사용
}

void clearConsole()
{
	cout << "Enter 를 입력하여 다음으로.." << endl;
	cin.ignore(); // 엔터 키 입력 대기

	this_thread::sleep_for(chrono::seconds(1)); // 1초 대기
	system("cls"); // 화면 지우기 cls 명령 사용

}

int main()
{
	gameStart();
	srand(static_cast<unsigned>(time(nullptr))); // 시드 설정

	GameManager* gameManager = GameManager::getInstance();
	gameManager->InitializeGame();
	clearConsole();
	Character* player = Character::getInstance(); // 게임매니저, 플레이어 생성

	//gameManager->printAllMonsters();
	PlayerInput playerInput;

	while (true) {
		int choice = playerInput.getPlayerChoiceAfterBattle();
		if (choice == 1) 
		{
			gameManager->combat(gameManager->getCurrentRound());
		}
		else if (choice == 2) 
		{
			gameManager->visitShop(player);
		}
		playerInput.getPlayerChoiceAfterBattle();
	}

	clearConsole();
	gameManager->visitShop(player);
	//	battleManager.startBattle(player, monsterPool);
	gameManager->destroyInstance();
	return 0;
}

// 구현시 이건 테스트 해봐야겠는데? 싶은 것들을 추가해주세요
// 테스트 케이스 테이블
// 캐릭터 생성 테스트
	// 1. 게임 시작 시 캐릭터 이름 입력
	// 2. 해당 이름으로 캐릭터가 생성되는지 확인
// 캐릭터 이름 공백 입력
	// 1. 캐릭터 이름을 공백으로 입력
	// 2. 해당 이름으로 캐릭터가 생성되는지 확인
// 초기 상태 확인 테스트
	// 1. 캐릭터 생성 후 초기스탯 점검
// 전투 시스템 테스트
	// 1. 랜덤 몬스터와 전투
	// 2. 공격/피격 로직과 HP감소를 확인
	// 3. 스킬 사용시 로직 확인
	// 4. 적의 스킬 피격시 HP감소를 확인
// 전투 승리 보상 테스트
	// 1. 전투 승리 후 경험치 골드 획득
// 전투 패배 종료 테스트
	// 1. 플레이어 체력이 0아래로 내려갈 시 게임오버 메시지 출력, 종료
// 레벨업 테스트
	// 1. 일정 경험치 획득시 레벨 +1
	// 2. 체력/공격력 증가 정상 반영
// 보스전 테스트
	// 1. 보스 몬스터 소환 -> 승리 시 게임 클리어
// 상점 시스템 테스트
	// 1. 구매시 보유 골드 감소, 인벤토리에 아이템 추가
	// 2. 판매시 보유 골드 증가, 인벤토리에서 아이템 삭제
//
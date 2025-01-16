// TextRPG_F12.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <limits> // numeric_limits 사용을 위해 필요
#include <cstdlib> // system() 함수 사용을 위해 필요
#include <thread> // std::this_thread::sleep_for 사용
#include <chrono> // std::chrono::seconds 사용

#include <windows.h> // 콘솔창 내부 위치 출력 위치 조정 ( SetConsoleCursorPosition )

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


void delay(int milliseconds) { std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds)); }

void setTextColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들 가져오기
	SetConsoleTextAttribute(hConsole, color);          // 텍스트 색상 설정
}

// 아래 두 함수를 활용하여 ★콘솔창★ 내부에서 ★출력 위치★를 조정해줄 수 있다.
void setCursorPosition(int x, int y) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들 가져오기
	COORD position = { static_cast<SHORT>(x), static_cast<SHORT>(y) }; // 위치 설정
	SetConsoleCursorPosition(hConsole, position); // 커서 위치 설정
}

//void printCentered(const std::string& text, int lineNumber = 0, int color = 7) { // 현재 y축은 최상단을 기준으로 lineNumber값에 따라 구분함, y축 또한 중앙 정렬로 표시하려면 주석 부분 확인
//										 // int yOffset = 0;
//	// 콘솔 크기 확인
//	CONSOLE_SCREEN_BUFFER_INFO csbi;
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	int consoleWidth = 80; // 기본값
//	//int consoleHeight = 25; // 기본 크기
//
//	if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
//		consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
//		// consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1; // y축 계산
//	}
//
//	// 중앙 정렬 X 좌표 계산
//	int x = (consoleWidth - static_cast<int>(text.length())) / 2;
//
//	// Y좌표는 lineNumber에 따라 동적으로 계산
//	int y = lineNumber;
//	// int y = (consoleHeight / 2) + yOffset;
//
//	setCursorPosition(x, y); // 지정된 위치로 이동
//	setTextColor(color);     // 색상 설정
//	std::cout << text;       // 텍스트 출력
//	setTextColor(7);         // 기본 색상으로 복구
//}

void getConsoleSize(int& width, int& height) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
		width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
		height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	}
	else {
		// 기본 크기로 설정 (80x25)
		width = 80;
		height = 25;
	}
}

void printCentered(const std::string& text, int lineOffset = 0, int color = 7) {
	int consoleWidth, consoleHeight;
	getConsoleSize(consoleWidth, consoleHeight);

	// 중앙 정렬 X 좌표 계산
	int x = (consoleWidth - static_cast<int>(text.length())) / 2;

	// Y좌표는 중앙에서 lineOffset 만큼 이동
	int y = lineOffset;

	setCursorPosition(x, y); // 지정된 위치로 이동
	setTextColor(color);     // 색상 설정
	std::cout << text;       // 텍스트 출력
	setTextColor(7);         // 기본 색상으로 복구
}

void printBlinkingText(const std::string& text, int lineNumber, int blinkCount, int intervalMs, int color) {
	// 콘솔 크기 확인
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int consoleWidth = 80; // 기본 콘솔 너비

	if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
		consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	}

	// 중앙 정렬 X 좌표 계산
	int x = (consoleWidth - static_cast<int>(text.length())) / 2;

	// Y좌표는 lineNumber에 따라 동적으로 계산
	int y = lineNumber;

	// 콘솔 텍스트 색상 설정
	SetConsoleTextAttribute(hConsole, color);

	// 깜빡이는 효과 구현
	for (int i = 0; i < blinkCount; ++i) {
		setCursorPosition(x, y);
		std::cout << text;               // 텍스트 출력
		std::this_thread::sleep_for(std::chrono::milliseconds(intervalMs)); // 일정 시간 대기

		setCursorPosition(x, y);
		std::cout << std::string(text.length(), ' '); // 텍스트 지우기
		std::this_thread::sleep_for(std::chrono::milliseconds(intervalMs)); // 일정 시간 대기
	}

	// 마지막으로 텍스트를 출력한 상태로 고정
	setCursorPosition(x, y);
	std::cout << text;
}

void gameStart() 
{
	printCentered("=========================================================================", 0);
	delay(100);
	printCentered("######                                      ### ##   ### ##     # ###  ", 1);
	delay(300);
	printCentered("# ## #   ######  ##   ##   ######            ##  ##   ##  ##   ##  ##  ", 2);
	delay(100);
	printCentered("  ##    ##       ##  ##      ##              ##  ##   ##  ##  ###      ", 3);
	delay(300);
	printCentered("  ##    ##        ####       ##              ## ##    ## ##   ### ###  ", 4);
	delay(100);
	printCentered("  ##    ####       ##        ##              ## #     ##      ###  ##  ", 5);
	delay(100);
	printCentered("  ##    ##        ####       ##              ##  #    ##       ##  ##  ", 6);
	delay(300);
	printCentered("  ##    ##       ##  ##      ##             #### ##  ####       # ##   ", 7);
	delay(300);
	printCentered("        #######  ##   ##     ##                                        ", 8);
	delay(100);
	printCentered("=========================================================================", 9);

	std::string text = "> 시작하기 <";
	int lineNumber = 13; // 출력할 줄 번호

	// 콘솔 크기 확인
	int consoleWidth, consoleHeight;
	getConsoleSize(consoleWidth, consoleHeight);

	// "시작하기" 텍스트 출력 위치 계산
	int x = (consoleWidth - static_cast<int>(text.length())) / 2;

	// 텍스트 색상 설정
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	// 깜빡임 효과
	for (int i = 0; i < 3; ++i) {
		// 텍스트 출력
		setCursorPosition(x, lineNumber);
		std::cout << text;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		// 텍스트 지우기
		setCursorPosition(x, lineNumber);
		std::cout << std::string(text.length(), ' ');
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	// 마지막 텍스트 출력 (고정)
	setCursorPosition(x, lineNumber);
	std::cout << text;

	// 사용자 입력 대기
	std::cin.ignore(1000, '\n');
	// 커서를 텍스트 오른쪽에 배치
	setCursorPosition(x + static_cast<int>(text.length()) + 1, lineNumber);

	// 화면 정리 후 초기화
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	system("cls");
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void clearConsole()
{
	cout << "모험을 시작한다.." << endl;
	cin.ignore(); // 엔터 키 입력 대기
	this_thread::sleep_for(chrono::seconds(1)); // 1초 대기
	system("cls"); // 화면 지우기 cls 명령 사용
}

int main()
{
	srand(static_cast<unsigned>(time(nullptr))); // 시드 설정
	gameStart();

	GameManager* gameManager = GameManager::getInstance();
	gameManager->InitializeGame();
	Character* player = Character::getInstance(); // 게임매니저, 플레이어 생성

	//gameManager->printAllMonsters();
	PlayerInput playerInput;

	player->displayStatus();
	player->displayInventory();
	clearConsole();
	gameManager->combat(gameManager->getCurrentRound());

	while (gameManager->getIsGameEnd() == false)
	{
		player->displayStatus();
		player->displayInventory();
		int choice = playerInput.getPlayerChoiceAfterBattle();
		if (choice == 1)
		{
			gameManager->visitShop(player);
			gameManager->combat(gameManager->getCurrentRound());
		}
		else if (choice == 2)
		{
			// 휴식하기 추가
			gameManager->takeRest(player);
			gameManager->combat(gameManager->getCurrentRound());
		}

		if (player->isCharacterDead())
		{
			// 게임오버 출력
			// delay(1000);
			gameManager->setIsGameEnd(true); // break
		}
	}

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
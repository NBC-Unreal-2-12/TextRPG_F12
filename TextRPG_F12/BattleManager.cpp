#include "BattleManager.h"
#include "MonsterFactory.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib> // 난수 생성 함수( srand() ) 제공
#include <ctime> // srand의 시드 설정(현재시각)
#include <cctype> // isdigit 사용
#include "Inventory.h"

// 함수에서 참조할 변수 monster에 대하여
// ★BattleManager 호출 이전에 마주치게 될 monster는 이미 생성이 되어있는 상태.
// 
// TextRPG_F12.cpp(이하 main())에서 MonsterFactory.h를 참조하여 랜덤 몬스터 생성
// -> std::vector<std::unique_ptr<Monster>> monster;
// -> monsters.push_back(createMonster(round));
// 아래 BattleManager의 함수들은 저 unique_ptr<Monster>> 객체로 선언된 monster를 받아와야 함.

//vector<std::unique_ptr<Monster>> monsters;

// 초기화 생성자
BattleManager::BattleManager(Character* player, std::vector<std::unique_ptr<Monster>>& monster)
	: player(player), monster(monster) {
}

// 사용자에게 해당 라운드에 스폰된 몬스터 정보를 출력
void BattleManager::displayBattleState() {

	int round = GameManager::getInstance()->getCurrentRound() + 1;

	if (round < 15) {
		system("cls");
		std::cout << "========================================\n\n";
		setColor(6);
		std::cout << "라운드 " << round << "\n\n";
		cout << "~ 턴 " << currentTurn << " ~\n" << endl;
		setColor(7);
		std::cout << "========================================\n";
	}
	else // 보스 스테이지, 마지막 라운드
	{
		system("cls");
		std::cout << "========================================\n\n";
		setColor(4);
		std::cout << "라운드 " << round << ": Boss" << "\n\n";
		cout << "~ 턴 " << currentTurn << " ~\n" << endl;
		setColor(7);
		std::cout << "========================================\n";
	}
}

// 전투 종료 조건 확인
bool BattleManager::getAllMonsterDead()
{
	// 모든 몬스터가 사망했는지 확인
	allMonstersDead = true;
	for (const auto& monster : monster) {
		if (!monster->isMobDead()) {
			allMonstersDead = false;
			break;
		}
	}

	if (allMonstersDead) {
		// std::cout << "All monsters have been defeated!\n";
		return true;
	}

	return false;
}

void BattleManager::processPlayerTurn() {
	PlayerInput input;
	
	// isTurnEnd 초기화
	isTurnEnd = false;

	// 각 case에서 isTurnEnd bool 변수값을 관리하여 턴 종료 시점 결정
	while(!isTurnEnd) {
		showPlayerCombatInfo();
		int choice = input.getPlayerChoice();

		switch (choice) {
		case 1: // 공격
			//system("cls");
			//showMonsterCombatInfo();
			attackMonster();
			delay(500); // 0.5초 지연
			break;

		case 2: // 스킬
			//system("cls");
			//showMonsterCombatInfo();
			useSkillOnMonster();
			delay(500); // 0.5초 지연
			break;

		case 3: // 인벤토리
			useItem();
			delay(1000);
			displayBattleState();
			showMonsterCombatInfo();
			break;

		case 4: // 도망
			std::cout << "\n도망쳤습니다!!\n";
			isBattleActive = false;
			isTurnEnd = true;
			break;

		case 5: // 상태창
			displayBattleState();
			player->displayStatus();
			isTurnEnd = false;
			continue;

		case 6: // 몬스터 정보
			displayBattleState();
			showMonsterInfo();
			isTurnEnd = false;
			continue;

		default:
			std::cout << "유효하지 않은 선택입니다. 다시 시도해주세요.\n";
		}
	}
}

// 몬스터 행동 처리
void BattleManager::processMonsterTurn(unique_ptr<Monster>& monster)
{
	if (monster->isMobDead() == false)
	{
		std::cout << "\n==============================\n";
		setColor(12); // 빨강
		if (monster->getMobMana() != monster->getMobMaxMana())
		{
			std::cout << "\n";
			std::cout << monster->getMobName() << "이(가) 공격했습니다!" << std::endl;
		}
		else
		{
			std::cout << "\n";
			std::cout << monster->getMobName() << "이(가) 스킬을 사용했습니다!" << std::endl;
		}

		int damage = monster->useMobAttack();

		if (damage != 0) // 공격에 데미지가 있을 때
		{
			if (int randomType = std::rand() % 100 <= (monster->getMobAccuracy() / player->getEvasion())) // 랜덤값이 "몬스터 명중률 / 회피율" 보다 작아야 명중
			{
				//명중시

				std::cout << player->getName() << "이(가) " << damage << "의 데미지를 받았습니다." << std::endl;
				player->setHealth(player->getHealth() - damage);
				if (player->getHealth() >= 1)
				{
					std::cout << player->getName() << "의 남은 체력은 " << player->getHealth() << "입니다." << std::endl;
				}

				else
				{
					player->setCharacterDead(true);
					isBattleActive = false; // 플레이어가 죽었다고 간주, isBattleOver() 호출
				}
			}
			else
			{
				//회피시
				setColor(12); // 빨강
				cout << "빗나감!" << endl;
			}
		}
		delay(500); // 0.5초 지연
		setColor(7); // 하양
	}
}

void BattleManager::showMonsterCombatInfo()
{
	std::vector<int> aliveMonsterIndices;
	aliveMonsterIndices = getAliveMonsters();
	for (int index : aliveMonsterIndices)
	{
		int healthBars = 10 * monster[index]->getMobHealth() / monster[index]->getMobMaxHealth();
		std::cout << "\n\n";
		delay(300); // 0.3초 지연d
		monster[index]->mobFace();
		std::cout << "[" << index + 1 << "] " << monster[index]->getMobName();
		std::cout << "( 체력 : " << monster[index]->getMobHealth() << " / " << monster[index]->getMobMaxHealth();
		std::cout << ", 명중률: " << std::round(player->getAccuracy() / monster[index]->getMobEvasion()) << "% )\n";
		if (monster[index]->getMobMana() == monster[index]->getMobMaxMana())
		{
			setColor(4);
			cout << "[" << index + 1 << "] " << monster[index]->getMobName() << "이(가) 힘을 모으고 있습니다..\n" << endl;;
			setColor(7);
		}
		std::cout << "HP : ";
		for (int i = 0; i < healthBars; ++i) std::cout << "■";
		for (int i = healthBars; i < 10; ++i) std::cout << "□";
		std::cout << "\nMP : ";
		for (int i = 0; i < monster[index]->getMobMana(); i++)
		{
			cout << "★";
		}
		for (int i = monster[index]->getMobMana(); i < monster[index]->getMobMaxMana(); i++)
		{
			cout << "☆";
		}
		std::cout << "\n";

	}
}

void BattleManager::showPlayerCombatInfo() {
	// 현재 체력 및 최대 체력 가져오기
	int currentHealth = player->getHealth();
	int maxHealth = player->getMaxHealth();

	// 현재 마나 및 최대 마나 가져오기
	int currentMana = player->getMP();
	int maxMana = player->getMaxMP();

	// 현재 경험치 및 최대 경험치 가져오기
	int currentExp = player->getExp();
	int maxExp = player->getMaxExp();

	// 상태 출력
	delay(300); // 0.3초 지연
	std::cout << "\n==============================\n\n";
	std::cout << "플레이어 상태:\n";
	// 체력 상태바
	int healthBars = 20 * currentHealth / maxHealth;
	for (int i = 0; i < healthBars; ++i) std::cout << "■";
	for (int i = healthBars; i < 20; ++i) std::cout << "□";
	std::cout << "\n";
	std::cout << "체력: " << currentHealth << " / " << maxHealth << "\n\n";

	// 마나 상태바
	int manaBars = 20 * currentMana / maxMana;
	for (int i = 0; i < manaBars; ++i) std::cout << "■";
	for (int i = manaBars; i < 20; ++i) std::cout << "□";
	std::cout << "\n";
	std::cout << "마나: " << currentMana << " / " << maxMana << "\n\n";

	// 경험치바
	int expBars = 20 * currentExp / maxExp;
	for (int i = 0; i < expBars; ++i) std::cout << "■";
	for (int i = expBars; i < 20; ++i) std::cout << "□";
	std::cout << "\n";
	std::cout << "경험치: " << currentExp << " / " << maxExp << "\n\n";
}

void BattleManager::showMonsterInfo()
{

	// 살아있는 몬스터 목록 가져오기
	std::vector<int> aliveMonsterIndices = getAliveMonsters();
	if (aliveMonsterIndices.empty()) return;

	// 플레이어가 선택할 몬스터 정보 출력
	int selectedMonsterIndex = getMonsterChoice(aliveMonsterIndices);
	if (selectedMonsterIndex != -1)
	{
		monster[selectedMonsterIndex]->getMobInterface();
	}
}

void BattleManager::attackMonster() {
	std::vector<int> aliveMonsterIndices = getAliveMonsters();
	if (aliveMonsterIndices.empty()) {
		std::cout << "공격할 대상 몬스터가 없습니다!\n";
		return;
	}

	int selectedMonsterIndex = getMonsterChoice(aliveMonsterIndices);
	if (selectedMonsterIndex == -1) {
		return;
	}

	setColor(1); // 파랑색
	std::cout << "\n";

	int damage = player->getAttack();
	if (std::rand() % 100 <= (player->getAccuracy() / monster[selectedMonsterIndex]->getMobEvasion())) {
		monster[selectedMonsterIndex]->takeMobDamage(damage);

		std::cout << monster[selectedMonsterIndex]->getMobName() << "에게 " << damage << "의 데미지를 입혔습니다!\n";
		std::cout << monster[selectedMonsterIndex]->getMobName() << "의 남은 체력: " << monster[selectedMonsterIndex]->getMobHealth() << "\n";

		if (monster[selectedMonsterIndex]->isMobDead()) {
			std::cout << monster[selectedMonsterIndex]->getMobName() << "이(가) 쓰러졌습니다!\n";
			if (getAllMonsterDead()) isBattleActive = false;
		}
	}
	else {
		std::cout << "공격이 빗나갔습니다!\n";
	}
	isTurnEnd = true;
	setColor(7); // 기본색
}

void BattleManager::useSkillOnMonster()
{
	std::vector<int> aliveMonsterIndices = getAliveMonsters();
	if (aliveMonsterIndices.empty()) return;

	std::cout << "스킬 이름: " << player->getSkillName() << ", 마나 소모: " << player->getManaCost() << endl;
	std::cout << "\n";
	std::cout << player-> getSkillName() <<"을(를) 사용하시겠습니까?\n" << endl;

	int select;
	std::string input;

	while (true)
	{
		std::cout << "[1] 예" << std::endl;
		std::cout << "[2] 아니오" << std::endl;
		std::cout << ">> ";
		std::getline(std::cin, input);  // 전체 입력을 문자열로 받음

		// 입력이 숫자로만 이루어졌는지 확인
		if (!input.empty() && std::all_of(input.begin(), input.end(), ::isdigit))
		{
			select = std::stoi(input);  // 문자열을 정수로 변환
			if (select == 1 || select == 2)
			{
				break;
			}
			else
			{
				std::cout << "잘못된 입력입니다. 1 또는 2를 입력해 주세요." << std::endl;
			}
		}
		else
		{
			std::cout << "잘못된 입력입니다. 숫자만 입력해 주세요." << std::endl;
		}
	}
	if (select == 1)
	{
		if (player->getMP() < player->getManaCost())
		{
			std::cout << "\n마나가 부족합니다." << endl;
			delay(1000); // 1초 지연
			displayBattleState();
			showMonsterCombatInfo();
			return;
		}
		else
		{
			int selectedMonsterIndex = getMonsterChoice(aliveMonsterIndices);
			if (selectedMonsterIndex == -1)
			{
				return;
			}
			else
			{
				player->useSkill(monster[selectedMonsterIndex].get());
				setColor(1);
				std::cout << monster[selectedMonsterIndex]->getMobName() << "의 남은 체력 : " << monster[selectedMonsterIndex]->getMobHealth() << "\n";
				if (monster[selectedMonsterIndex]->isMobDead()) {
					std::cout << monster[selectedMonsterIndex]->getMobName() << "이(가) 쓰러졌습니다!\n";
					if (getAllMonsterDead()) isBattleActive = false;
				}
				setColor(7);
			}
			isTurnEnd = true;
		}
	}
	else if (select == 2)
	{
		std::cout << "스킬 사용 취소." << endl;
		delay(1000); // 1초 지연
		displayBattleState();
		showMonsterCombatInfo();
		return;
	}

}

std::vector<int> BattleManager::getAliveMonsters()
{
	std::vector<int> aliveMonsterIndices;
	for (size_t i = 0; i < monster.size(); ++i)
	{
		if (!monster[i]->isMobDead()) {
			aliveMonsterIndices.push_back(i);
		}
	}
	return aliveMonsterIndices;
}

int BattleManager::getMonsterChoice(const std::vector<int>& aliveMonsterIndices)
{
	int selectedMonsterIndex = -1;
	std::string input;

	while (true)
	{
		std::cout << "\n대상 몬스터의 번호를 입력하세요.\n\n";
		 for (int index : aliveMonsterIndices)
        {
            // 몬스터 이름 추가 출력
            std::cout << "[" << index + 1 << "] " << monster[index]->getMobName() << "\n"; 
        }
		std::cout << "\n[0] 되돌아가기\n\n"; // 되돌아가기 옵션 추가
		std::cout << ">> ";
		std::getline(std::cin, input);

		if (!input.empty() && std::all_of(input.begin(), input.end(), ::isdigit))
		{
			try
			{
				selectedMonsterIndex = std::stoi(input) - 1;

				// 되돌아가기 처리
				if (selectedMonsterIndex == -1) // 사용자가 0을 입력한 경우
				{
					isTurnEnd = false;
					displayBattleState();
					showMonsterCombatInfo();
					return -1; // 되돌아가기 신호로 -1 반환
				}

				// 선택한 몬스터가 유효한지 확인
				if (std::find(aliveMonsterIndices.begin(), aliveMonsterIndices.end(), selectedMonsterIndex) != aliveMonsterIndices.end())
				{
					break; // 유효한 몬스터 선택 시 반복문 탈출
				}
				else
				{
					std::cout << "\n유효한 몬스터 번호를 입력해 주세요.\n";
				}
			}
			catch (const std::out_of_range&)
			{
				std::cout << "\n입력값이 너무 큽니다. 유효한 숫자를 입력해 주세요.\n";
			}
		}
		else
		{
			std::cout << "\n유효하지 않은 입력입니다. 숫자만 입력해 주세요.\n";
		}
	}
	return selectedMonsterIndex;
}

void BattleManager::useItem() {
	int selectedItemIndex = -1;
	std::string input;

	while (true)
	{
		Inventory::getInstance()->listItem();
		std::cout << "\n\n사용할 아이템 번호를 입력해 주세요.\n";
		std::cout << "\n[0] 되돌아가기\n\n"; // 되돌아가기 옵션 추가
		std::cout << ">> ";
		std::getline(std::cin, input);

		if (!input.empty() && std::all_of(input.begin(), input.end(), ::isdigit))
		{
			try
			{
				selectedItemIndex = std::stoi(input) - 1;

				// 되돌아가기 처리
				if (selectedItemIndex == -1) // 사용자가 0을 입력한 경우
				{
					isTurnEnd = false;
					return; // 되돌아가기 신호로 -1 반환
				}

				// 선택한 아이템 인덱스가 유효한지 확인
				if (selectedItemIndex >= 0 && selectedItemIndex < Inventory::getInstance()->getInventory().size())
				{
					player->useItemFromInventory(selectedItemIndex);
					break; // 유효한 아이템 선택 시 반복문 탈출
				}
				else
				{
					std::cout << "\n유효한 아이템 번호를 입력해 주세요.\n";
				}
			}
			catch (const std::out_of_range&)
			{
				std::cout << "\n입력값이 너무 큽니다. 유효한 숫자를 입력해 주세요.\n";
			}
		}
		else
		{
			std::cout << "\n유효하지 않은 입력입니다. 숫자만 입력해 주세요.\n";
		}
	}
}

// 전투 시작
void BattleManager::startBattle(Character* player, std::vector<unique_ptr<Monster>>& monsters)
{
	this->player = player;
	this->monster = std::move(monsters);

	// TurnOrder 초기화 및 재정렬
	std::vector<TurnOrder> turnOrders;

	// 전투가 끝날 때까지 반복
	while (isBattleActive)
	{
		displayBattleState();
		showMonsterCombatInfo();
		delay(500); // 0.5초 딜레이
		// 플레이어의 공격 속도 추가
		turnOrders.push_back(TurnOrder(-1, true, player->getAttackSpeed()));

		// 몬스터들의 공격 속도 추가
		int idx = 0;
		for (auto& m : monster) {
			turnOrders.push_back(TurnOrder(idx++, false, m->getMobAttackSpeed()));
		}

		// 공격 속도에 따라 내림차순으로 정렬
		std::sort(turnOrders.begin(), turnOrders.end(), [](const TurnOrder& a, const TurnOrder& b) {
			return a.attackSpeed > b.attackSpeed;
			});
		// 첫 번째 순서부터 차례대로 진행
		for (TurnOrder& turn : turnOrders)
		{

			if (turn.isPlayer) // 플레이어의 턴인 경우
			{
				processPlayerTurn();
				if (!isBattleActive) break; // 전투가 끝났으면 종료
			}
			else
			{
				processMonsterTurn(monster[turn.index]);
				if (!isBattleActive) break; // 전투가 끝났으면 종료
			}
		}

		std::cout << "\n==============================\n";
		setColor(6);
		cout << "\n~ 턴 " << currentTurn << " 종료 ~" << endl;
		setColor(7);
		delay(2000); // 2초 지연
		turnOrders.clear();//전투 순서 벡터 초기화
		currentTurn++; // 현재 턴 추가
		system("cls"); // 화면 초기화
	}
	currentTurn = 1;
	resolveBattle();
}

// 전투 종료 처리
int BattleManager::resolveBattle()
{
	int round = GameManager::getInstance()->getCurrentRound() + 1;

	if (player->isCharacterDead())
	{
		setColor(7); // 하양
		std::cout << "전투에서 패배하셨습니다.\n";
		std::cout << "게임이 종료됩니다.\n"; // 게임오버 관련

		return 0; // 게임종료
	}
	else if (allMonstersDead)
	{
		std::cout << "축하합니다! 전투에서 승리하셨습니다!\n\n";
		GameManager* gameManager = GameManager::getInstance();
		int round = GameManager::getInstance()->getCurrentRound() + 1;
		int monsterCount = gameManager->getMonsterGroup(gameManager->getCurrentRound()).size();

		// 경험치, 돈, 아이템 획득 처리
		int expGained = 100 * round; // 획득 경험치
		int goldGained = 50 * (round * monsterCount); // 획득 골드

		player->setGold(goldGained);
		std::cout << "You gained " << expGained << " EXP and " << goldGained << " Gold.\n\n";

		player->addExp(expGained);
		int currentExp = player->getExp();
		int maxExp = player->getMaxExp();
		if (currentExp >= maxExp)
		{
			player->doLevelUp();
		}
	}

	// 처치한 몬스터 드랍 아이템 처리
	for (auto& monster : monster)
	{
		if (monster->isMobDead())
		{
			int idx = std::rand() % 100;
			Item* loot = nullptr;
			if (idx < 5) {
				loot = ItemManager::getInstance()->getLootByIndex(999);  // 10% 확률로 부활의 토템 드랍
			}
			else {
				loot = ItemManager::getInstance()->getLootByIndex(monster->dropItemIdx());  // 나머지 90%는 monster에서 아이템 드랍
			}
			setColor(6); // 노랑
			std::cout << "\n전리품 " << loot->getName() << "을(를) 습득하셨습니다. ";
			player->addItemToInventory(loot);
			setColor(7); // 하양
		}
	}

	if (round < 15)
	{
		// 다음 라운드 세팅
		GameManager* gameManager = GameManager::getInstance();
		gameManager->setCurrentRound();
	}
	else // round 15 (보스)
	{
		system("cls");
		std::cout << "모든 전투가 끝났습니다." << endl;
		std::cout << "Game Clear!! 축하드립니다.";

		GameManager* gameManager = GameManager::getInstance();
		gameManager->setIsGameEnd(true);
	}


	return 1;
}
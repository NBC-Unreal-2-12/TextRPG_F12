#include "GameManager.h"

using namespace std;
// 정적 멤버 변수 정의
GameManager* GameManager::instance = nullptr;

// 게임 시작시 초기화 메서드
void GameManager::InitializeGame()
{
	// 사용자 입력
	PlayerInput PI;
	// 캐릭터 이름 설정
	string name = PI.setPlayerName();
	system("cls");
	// 테스트 직업 생성
	Job* job = PI.setJobByPlayerInput();
	system("cls");
	// 싱글톤 객체 초기화 및 상태 출력
	Character::initialize(name, job);
	Character* player = Character::getInstance();
	player->displayStatus();

	// 라운드별 몬스터 그룹 초기화
	monsterGroup.clear();
	for (int currentRound = 1; currentRound <= round; currentRound++) {
		monsterGroup.emplace_back(generateMonsters(currentRound)); // 데이터 추가
	}


	// 필요에 따라 추가 초기화 작업 수행 가능
}

// 상점 방문
void GameManager::visitShop(Character* player)
{
	// 아이템 리스트 초기화
	ItemManager itemManager;
	itemManager.initializeDefaultItems();

	Shop shop(itemManager);
	shop.displayItems();

	int choice = -1;
	player->setGold(200);
	while (choice != 0)
	{
		cout << "구매 : 1, 판매 : 2,  인벤토리 확인 : 3, 나가기 : 0 >> ";
		cin >> choice;

		if (choice == 0)
		{
			return; // 나가기
		}
		else if (choice == 1)
		{
			int index;
			cout << "몇 번 아이템을 구매하시겠습니까? >> ";
			cin >> index;
			shop.buyItem(index, player);
		}
		else if (choice == 2)
		{
			player->displayInventory();
			int index;
			cout << "몇 번 아이템을 판매하시겠습니까? >> ";
			cin >> index;
			shop.sellItem(index, player);
		}
		else if (choice == 3)
		{
			player->displayInventory();
		}
		else
		{
			cout << "부적절한 입력입니다. 다시 입력해주세요." << endl;
		}
	}
}

// 라운드 별 몬스터 마릿수를 결정하여 생성
vector<unique_ptr<Monster>> GameManager::generateMonsters(int round)
{
	std::vector<std::unique_ptr<Monster>> monsters;
	MonsterFactory factory;

	int monsterCount = 0;
	int probability = std::rand() % 100 + 1;
	if (round <= 5)
	{
		monsterCount = (probability <= 70) ? 2 : 3;
	}
	else if (round <= 10)
	{
		monsterCount = (probability <= 50) ? 1 : 2;
	}
	else if (round < 15)
	{
		monsterCount = (probability <= 40) ? 1 : 2;
	}
	else // round 15
	{
		monsterCount = 1;
	}

	// 몬스터 생성
	for (int i = 0; i < monsterCount; ++i)
	{
		monsters.emplace_back(factory.createMonster(round));
	}

	return monsters;
}

// 특정 라운드의 몬스터 그룹을 반환
vector<unique_ptr<Monster>>& GameManager::getMonsterGroup(int round)
{
	if (round < 0 || round >= static_cast<int>(monsterGroup.size()))
	{
		throw out_of_range("Invalid round index.");
	}
	return monsterGroup[round];
}

// 현재 라운드 정보 갱신
void GameManager::setCurrentRound()
{
	currentRound += 1;
}

// 현재 라운드 전투
void GameManager::combat(int currentRound)
{
	if (currentRound < 0 || currentRound >= monsterGroup.size()) {
		std::cout << "Error: Invalid round index." << std::endl;
		return;
	}

	Character* player = Character::getInstance();

	// Null 체크
	if (!player || monsterGroup[currentRound].empty()) {
		std::cout << "Error: Null player or no monsters." << std::endl;
		return;
	}

	// BattleManager 생성 시 특정 라운드의 데이터를 전달
	BattleManager battleManager(player, monsterGroup[currentRound]);

	battleManager.startBattle(player, getMonsterGroup(currentRound));
	
}


void GameManager::printAllMonsters() const
{
	for (size_t roundIndex = 0; roundIndex < monsterGroup.size(); ++roundIndex)
	{
		cout << "Round " << roundIndex + 1 << " Monsters:" << endl;

		const auto& monsters = monsterGroup[roundIndex];
		if (monsters.empty())
		{
			cout << "  No monsters in this round." << endl;
		}
		else
		{
			for (const auto& monster : monsters)
			{
				cout << "  - " << monster->getMobName() << endl;
				monster->mobFace();
			}
		}
	}
}

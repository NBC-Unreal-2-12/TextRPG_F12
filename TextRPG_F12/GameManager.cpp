#include "GameManager.h"

void delay(int milliseconds);

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
	for (int i = 0; i < round; i++) {
		monsterGroup.emplace_back(generateMonsters(i)); // 데이터 추가
	}


	// 필요에 따라 추가 초기화 작업 수행 가능
	// 아이템 리스트 초기화
	ItemManager* itemManager = ItemManager::getInstance();
	itemManager->initializeDefaultItems();
}

// 상점 방문
void GameManager::visitShop(Character* player)
{
	ItemManager* itemManager = ItemManager::getInstance();
	Shop shop(itemManager);

	PlayerInput PI;	
	std::string input;
	int choice = -1;

	while (true)
	{
		// 상점 출력
		shop.displayItems();
		std::cout << "\n( 잔고 : " << player->getGold() << " )\n\n";

		cout << "구매 : 1, 판매 : 2, 나가기 : 0 >> ";
		std::getline(std::cin, input); // 전체 입력을 문자열로 받음

		// 입력값이 숫자로만 이루어졌는지 확인
		if (!input.empty() && std::all_of(input.begin(), input.end(), ::isdigit))
		{
			try
			{
				// 문자열을 정수로 변환
				choice = std::stoi(input);

				// 범위 확인
				if (choice == 0)
				{
					return; // 상점 나가기
				}
				// 선택한 아이템 인덱스가 유효한지 확인
				else if (choice == 1)
				{
					pair<int, int> inputValue = PI.getPlayerBuyingItem();
					if (inputValue.first == 0) continue;
					shop.buyItem(inputValue.first, inputValue.second, player);
					delay(1500);
				}
				else if (choice == 2)
				{
					if (!player->isInventoryEmpty())
					{
						pair<int, int> inputValue = PI.getPlayerSellingItem();
						if (inputValue.first == 0) continue;
						shop.sellItem(inputValue.first - 1, inputValue.second, player);
					}
					delay(1500);
				}
				else
				{
					std::cout << "\n부적절한 입력입니다. 다시 입력해주세요.\n";
				}
			}
			catch (const std::out_of_range&)
			{
				system("cls");
				std::cout << "\n입력값이 너무 큽니다. 유효한 숫자를 입력해 주세요.\n";
			}
		}
		else
		{
			system("cls");
			std::cout << "\n유효하지 않은 입력입니다. 숫자만 입력해 주세요.\n";
		}
	}
}

void GameManager::takeRest(Character* player)
{
	PlayerInput PI;

	system("cls");

	cout << R"(
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢁⡀⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⢂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡆⠀⡏⢲⡀⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣄⡰⢃⠼⠄⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣃⠀⡎⡕⠂⡼⠀⢀⠀⢠⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠸⡄⡠⢇⢰⠁⢆⠁⡜⣣⢘⡀⠄⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠠⡄⢠⡚⡁⢏⠎⢀⠈⠀⡜⣡⠏⡔⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠂⠱⠥⡘⢄⠊⠀⠀⠘⢠⠓⣸⡙⠀⠁⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠰⣄⢣⠄⠠⠀⠀⠀⠀⠃⡘⢖⡠⠞⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢸⡌⠢⠀⠀⠀⠀⠀⠁⠈⠐⡸⣹⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢰⡻⣏⢟⣣⢎⡁⠀⠀⠀⠀⠀⠀⠀⡐⢤⢃⣀⡀⢀⠀⠀⠀⠀
⠀⠀⠀⠠⣘⢷⣹⢮⣳⢮⡝⡲⣄⠦⣄⢦⡰⢲⡜⣎⣻⢼⡹⣏⡗⠀⠀⠀
⠀⠀⠀⠀⠩⢾⣭⠷⠋⠦⣑⠷⢎⡿⡜⠦⣝⢧⡻⢧⠉⡙⠙⠚⠀⠈⠀⠀
⠀⠀⠀⠀⠀⠈⠁⠀⠈⠀⠘⢦⡙⡜⠠⠁⠈⠧⡘⠊⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
			)" << endl;

	// 일정 비율로 HP/MP 회복
	cout << "모닥불을 쬐며 휴식했다..." << endl;
	player->setHealth(player->getHealth() + (player->getMaxHealth()*0.3));
	player->setMP(player->getMP() + (player->getMaxMP() * 0.3));

	cout << "마음이 따뜻해진다.." << endl;

	// 상태창 출력
	player->displayStatus();

	// 인벤토리 -> 아이템 사용
	// BattleManager battleManager(player, monsterGroup[0]);
	// battleManager.useItem();

	PI.getPlayerChoiceUsingItem();
}

// 라운드 별 몬스터 마릿수를 결정하여 생성
vector<unique_ptr<Monster>> GameManager::generateMonsters(int round)
{
	std::vector<std::unique_ptr<Monster>> monsters;
	MonsterFactory factory;

	int monsterCount = 0;
	int probability = std::rand() % 100 + 1;
	if (round == 0)
	{
		monsterCount = 1;
	}
	else if (round < 5)
	{
		monsterCount = (probability <= 70) ? 2 : 3;
	}
	else if (round < 10)
	{
		monsterCount = (probability <= 50) ? 1 : 2;
	}
	else if (round < 14)
	{
		monsterCount = (probability <= 40) ? 1 : 2;
	}
	else // round 14
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

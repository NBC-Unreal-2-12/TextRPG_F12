#include "PlayerInput.h"
#include "GameManager.h"
#include <iostream>
#include <string>
#include <algorithm> // all_of사용을 위해 필요
#include <limits> // numeric_limits 사용을 위해 필요
#include <cctype> // isdigit 사용

// 전투 중 사용자 입력
int PlayerInput::getPlayerChoiceInBattle()
{
	std::string input;
	int choice;

	while (true)
	{
		std::cout << "\n당신의 선택은..\n";
		std::cout << "1. 공격!\n";
		std::cout << "2. 스킬 사용!\n";
		std::cout << "3. 아이템 사용!\n";
		std::cout << "4. 도망친다..\n";
		std::cout << "5. 상태창!\n";
		std::cout << "6. 몬스터 정보!\n";
		std::cout << ">> ";
		std::getline(std::cin, input); // 전체 입력을 문자열로 받음
		std::cout << "\n==============================\n";

		// 입력값이 숫자로만 이루어졌는지 확인
		if (!input.empty() && std::all_of(input.begin(), input.end(), ::isdigit))
		{
			try
			{
				// 문자열을 정수로 변환
				choice = std::stoi(input);

				// 범위 확인
				if (choice >= 1 && choice <= 6)
				{
					break; // 유효한 입력 범위라면 반복문 탈출
				}
				else
				{
					std::cout << "\n잘못된 선택입니다. 1에서 6사이 값을 입력해 주세요.\n";
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

	return choice;
}

// 전투 이후 사용자 입력
int PlayerInput::getPlayerChoiceAfterBattle()
{

	int round = GameManager::getInstance()->getCurrentRound() + 1;
	std::string input;
	int choice;

	while (true)
	{
		if (round < 15) {
			std::cout << "\n어떻게 할까..? (다음 라운드 : " << round << ")\n";
			std::cout << "1. 상점 방문\n";
			std::cout << "2. 휴식하기\n";
			std::cout << ">> ";
		}
		else // round 15 (보스)
		{
			std::cout << "\n아마도 다음이 마지막이 될 것만 같다..\n";
			std::cout << "1. 상점 방문!\n";
			std::cout << "2. 휴식하기\n";
			std::cout << ">> ";
		}

		std::getline(std::cin, input); // 전체 입력을 문자열로 받음

		// 입력값이 숫자로만 이루어졌는지 확인
		if (!input.empty() && std::all_of(input.begin(), input.end(), ::isdigit))
		{
			try
			{
				// 문자열을 정수로 변환
				choice = std::stoi(input);

				// 범위 확인
				if (choice >= 0 && choice <= 2)
				{
					break; // 유효한 입력 범위라면 반복문 탈출
				}
				else
				{
					system("cls");
					std::cout << "\n잘못된 선택입니다. 1 아니면 2를 입력해 주세요.\n";
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

	return choice;
}

// 아이템 사용 선택
void PlayerInput::getPlayerChoiceUsingItem()
{
	std::string input;
	int choice;

	while (true)
	{
		Inventory::getInstance()->listItem();
		std::cout << "\n아이템 번호를 입력하여 사용할 수 있습니다.";
		std::cout << "\n===============================\n";
		std::cout << "[0] 다시 전투로!\n";

		std::getline(std::cin, input); // 전체 입력을 문자열로 받음

		// 입력값이 숫자로만 이루어졌는지 확인
		if (!input.empty() && std::all_of(input.begin(), input.end(), ::isdigit))
		{
			try
			{
				// 문자열을 정수로 변환
				choice = std::stoi(input);

				// 범위 확인
				if (choice ==0)
				{
					break; // 휴식 종료, 전투로 복귀
				}
				// 선택한 아이템 인덱스가 유효한지 확인
				else if (choice > 0 && choice <= Inventory::getInstance()->getInventory().size())
				{
					Character::getInstance()->useItemFromInventory(choice - 1);
					break; // 유효한 아이템 선택 시 반복문 탈출
				}
				else
				{
					std::cout << "\n유효한 아이템 번호를 입력해 주세요.\n";
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

	return;
}

pair<int, int> PlayerInput::getPlayerBuyingItem()
{
	std::string input;
	int index, itemCount;

	while (true)
	{
		cout << "\n몇 번 아이템을 구매하시겠습니까? ( 취소 : 0 )>> ";
		std::getline(std::cin, input); // 전체 입력을 문자열로 받음

		// 입력값이 숫자로만 이루어졌는지 확인
		if (!input.empty() && std::all_of(input.begin(), input.end(), ::isdigit))
		{
			try
			{
				// 문자열을 정수로 변환
				index = std::stoi(input);

				// 범위 확인
				if (index == 0)
				{
					return make_pair(0, 0); // 상점으로 복귀
				}
				else break;
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

	while (true)
	{
		cout << "\n수량을 선택해 주세요. ( 취소 : 0 ) >> ";
		std::getline(std::cin, input); // 전체 입력을 문자열로 받음

		// 입력값이 숫자로만 이루어졌는지 확인
		if (!input.empty() && std::all_of(input.begin(), input.end(), ::isdigit))
		{
			try
			{
				// 문자열을 정수로 변환
				itemCount = std::stoi(input);

				// 범위 확인
				if (itemCount == 0)
				{
					return make_pair(0, 0); // 상점으로 복귀
				}
				else break;
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

	return make_pair(index, itemCount);
}

pair<int, int> PlayerInput::getPlayerSellingItem()
{
	std::string input;
	int index, itemCount;

	while (true)
	{
		Character::getInstance()->displayInventory();
		cout << "\n몇 번 아이템을 판매하시겠습니까? ( 취소 : 0 )>> ";
		std::getline(std::cin, input); // 전체 입력을 문자열로 받음

		// 입력값이 숫자로만 이루어졌는지 확인
		if (!input.empty() && std::all_of(input.begin(), input.end(), ::isdigit))
		{
			try
			{
				// 문자열을 정수로 변환
				index = std::stoi(input);

				// 범위 확인
				if (index == 0)
				{
					return make_pair(0, 0); // 상점으로 복귀
				}
				else break;
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

	while (true)
	{
		cout << "\n수량을 선택해 주세요. ( 취소 : 0 ) >> ";
		std::getline(std::cin, input); // 전체 입력을 문자열로 받음

		// 입력값이 숫자로만 이루어졌는지 확인
		if (!input.empty() && std::all_of(input.begin(), input.end(), ::isdigit))
		{
			try
			{
				// 문자열을 정수로 변환
				itemCount = std::stoi(input);

				// 범위 확인
				if (itemCount == 0)
				{
					return make_pair(0, 0); // 상점으로 복귀
				}
				else break;
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

	return make_pair(index, itemCount);
}


// 캐릭터 생성 시 이름 지정
string PlayerInput::setPlayerName()
{
	std::cout << "캐릭터의 이름을 설정해 주세요.\n";
	string name;
	while (true)
	{
		getline(cin, name);
		name.erase(remove(name.begin(), name.end(), ' '), name.end());
		if (!name.empty()) break;
		cout << "\n잘못된 입력입니다. 다시 설정해 주세요.\n";
	}

	return name;
}

// 캐릭터 생성 시 직업 선택
Job* PlayerInput::setJobByPlayerInput()
{
	std::string input;
	int choice;
	Job* job = nullptr;

	while (true)
	{
		std::cout << "직업을 선택해 주세요.\n";
		std::cout << "1. 전사\n";
		std::cout << "2. 마법사\n";
		std::cout << "3. 궁수\n";
		std::cout << ">> ";

		std::getline(std::cin, input); // 전체 입력을 문자열로 받음

		// 입력값이 숫자로만 이루어졌는지 확인
		if (!input.empty() && std::all_of(input.begin(), input.end(), ::isdigit))
		{
			try
			{
				// 문자열을 정수로 변환
				choice = std::stoi(input);

				// 범위 확인
				if (choice >= 1 && choice <= 3)
				{
					switch (choice)
					{
					case 1:
						job = new Warrior();
						break;
					case 2:
						job = new Mage();
						break;
					case 3:
						job = new Archer();
						break;
					}
					break; // 유효한 입력 범위라면 반복문 탈출
				}
				else
				{
					system("cls");
					std::cout << "\n잘못된 선택입니다. 유효한 직업을 입력해 주세요.\n";
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

	return job;
}
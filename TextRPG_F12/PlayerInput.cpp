#include "PlayerInput.h"
#include <iostream>
#include <stdlib.h>

int PlayerInput::getPlayerChoice() 
{
    int choice;
    std::cout << "\n==============================\n";
    std::cout << "\nChoose your action : \n";
    std::cout << "1. 공격!\n";
    std::cout << "2. 스킬\n";
    std::cout << "3. 아이템\n";
    std::cout << "4. 도망친다\n";
    std::cout << "5. 상태\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cout << "\n==============================\n";
    return choice;
}

int PlayerInput::getPlayerChoiceAfterBattle()
{
    std::cout << "다음 행동을 선택해 주세요.\n";
    std::cout << "1. 다음 라운드 진행!\n";
    std::cout << "2. 상점 방문\n";
    std::cout << "\nEnter your choice : ";

    int choice;
    std::cin >> choice;

    return choice;
}


string PlayerInput::setPlayerName()
{
    std::cout << "캐릭터의 이름을 설정해 주세요.\n";
    string name;
    while (true)
    {
        getline(cin, name);
        name.erase(remove(name.begin(), name.end(), ' '), name.end());
        if (!name.empty()) break;
        cout << "잘못된 입력입니다. 다시 설정해 주세요.\n";
    }

    return name;
}


Job* PlayerInput::setJobByPlayerInput()
{
    std::cout << "직업을 선택해 주세요.\n";
    std::cout << "1. 전사\n";
    std::cout << "2. 마법사\n";
    std::cout << "3. 궁수\n";
    std::cout << "직업을 선택해 주세요 : ";

    int choice;
    while (true)
    {
        cin >> choice;
        if (choice >= 1 && choice <= 3) break;
        std::cout << "잘못된 입력입니다. 다시 선택해 주세요.\n";
    }

    cin.ignore();

    Job* job = nullptr;
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

    return job;
}
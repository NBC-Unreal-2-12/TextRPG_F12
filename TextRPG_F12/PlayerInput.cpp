#include "PlayerInput.h"
#include <iostream>

int PlayerInput::getPlayerChoice() 
{
    int choice;
    std::cout << "Choose your action:\n";
    std::cout << "1. 공격!\n";
    std::cout << "2. 스킬\n";
    std::cout << "3. 아이템\n";
    std::cout << "4. 도망친다\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}

int PlayerInput::getPlayerChoiceAfterBattle()
{
    std::cout << "축하합니다! 전투에서 승리하셨습니다!\n";
    std::cout << "다음 행동을 선택해 주세요.\n";
    std::cout << "1. 다음 라운드 진행!\n";
    std::cout << "2. 상점 방문\n";
    std::cout << "Enter your choice: ";

    int choice;
    std::cin >> choice;

    return choice;
}

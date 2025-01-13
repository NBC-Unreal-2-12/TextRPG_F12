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

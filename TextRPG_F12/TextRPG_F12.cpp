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

int main()
{
	GameManager* gameManager = GameManager::getInstance();
	gameManager->InitializeGame();


}
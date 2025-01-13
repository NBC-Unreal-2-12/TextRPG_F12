#include "BattleManager.h"
#include <iostream>
#include <algorithm>

// 전투 종료 조건 확인
bool BattleManager::isBattleOver()
{
    // 몬스터의 체력이 모두 0 이하인지 확인
    bool allMonstersDead = std::all_of(monster.begin(), monster.end(), [](Monster* monster)
        {
            return monster->isMobDead();
        });

    // 플레이어의 체력이 0 이하인지 확인
    bool playerDead = player->isCharacterDead();

    return allMonstersDead || playerDead;
}

// 행동 순서 결정
void BattleManager::determineTurnOrder()
{
    // 마주한 몬스터에 대한 로직은 나중에..
    isPlayerTurn = player->getAttackSpeed() >= monster[0]->getMobAttackSpeed();
}

// 플레이어 행동 처리
void BattleManager::processPlayerTurn()
{
    PlayerInput input;
    int choice = input.getPlayerChoice();

    switch (choice)
    {
    case 1: // 공격
        // player->attack(monster[0]);
        break;
    case 2: // 스킬
        // player->useSkill(monster);
        break;
    case 3: // 인벤토리
        break;
    case 4: // 도망
        // 1. character.h 에서 함수 호출
        /*if (player->attemptEscape()) {
            std::cout << "Player escaped successfully!\n";
            exit(0);
        }
        else {
            std::cout << "Escape attempt failed!\n";
        }*/
        break;
    default:
        std::cout << "Invalid choice.\n";
    }
}

// 몬스터 행동 처리
void BattleManager::processMonsterTurn()
{
    for (Monster* monster : monster)
    {
        if (!monster->isMobDead())
        {
            std::cout << "???'s attack!\n";
            monster->useMobAttack(); // 몬스터가 플레이어를 공격
            // useMobAttack()은 기본 공격이지만 monster의 마나가 가득차있을 때는 useSkill()을 호출하도록 되어있음, 그에 대한 출력은..?

            // player 피격 이벤트 구현
        }
    }
}

// 전투 시작
void BattleManager::startBattle(Character* player, std::vector<Monster*> monsters)
{
    this->player = player;
    this->monster = monster;

    std::cout << "Battle started!\n";

    while (!isBattleOver())
    {
        determineTurnOrder();

        if (isPlayerTurn)
        {
            processPlayerTurn();
            if (!isBattleOver()) processMonsterTurn();
        }
        else
        {
            processMonsterTurn();
            if (!isBattleOver()) processPlayerTurn();
        }
    }

    resolveBattle();
}

// 전투 종료 처리
void BattleManager::resolveBattle()
{
    if (player->isCharacterDead())
    {
        // 우선 텍스트 출력은 영어로..
        std::cout << "Player has been defeated. Game Over.\n";
    }
    else
    {
        std::cout << "Player won the battle!\n";

        // 경험치, 돈, 아이템 획득 처리
        int expGained = 100; // 획득 경험치
        int goldGained = 50; // 획득 골드

        //int currentExp = player->getExp();
        // player->addExp(currentExp);
        // player->setExp(currentExp + expGained);

        int existGold = player->getGold();
        player->setGold(existGold + expGained);

        std::cout << "You gained " << expGained << " EXP and " << goldGained << " Gold.\n";

        // 몬스터 드랍 아이템 처리
        for (Monster* monster : monster)
        {
            if (monster->isMobDead())
            {
                std::cout << "root ???\n";
                // player->addItemToInventory(monster->dropItem());
            }
        }
    }
}
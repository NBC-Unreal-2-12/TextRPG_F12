#include "BattleManager.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include "Inventory.h"

// 함수에서 참조할 변수 monster에 대하여
// ★BattleManager 호출 이전에 마주치게 될 monster는 이미 생성이 되어있는 상태.
// 
// TextRPG_F12.cpp(이하 main())에서 MonsterFactory.h를 참조하여 랜덤 몬스터 생성
// -> std::vector<std::unique_ptr<Monster>> monster;
// -> monsters.push_back(createMonster(round));
// 아래 BattleManager의 함수들은 저 unique_ptr<Monster>> 객체로 선언된 monster를 받아와야 함.

//vector<std::unique_ptr<Monster>> monsters;

// 전투 종료 조건 확인
bool BattleManager::isBattleOver()
{
    // 플레이어가 사망하면 전투 종료
    if (player->isCharacterDead()) {
        std::cout << "Player has been defeated!\n";
        return true;
    }

    // 모든 몬스터가 사망했는지 확인
    allMonstersDead = true;
    for (const auto& monster : monster) {
        if (!monster->isMobDead()) {
            allMonstersDead = false;
            break;
        }
    }

    if (allMonstersDead) {
        std::cout << "All monsters have been defeated!\n";
        return true;
    }

    return false;
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
        // 우선 테스트용 기능 구현만.
        std::cout << "player's attack!\n";
        monster[0]->takeMobDamage(player->getAttack());
        break;
    case 2: // 스킬
        player->useSkill(monster);
        break;
    case 3: // 인벤토리
        inventory->listItem();
        break;
    case 4: // 도망
        std::cout << "You ran away with all your might..\n";
        resolveBattle();
        break;
    default:
        std::cout << "Invalid choice.\n";
    }
}

// 몬스터 행동 처리
void BattleManager::processMonsterTurn()
{
    for (Monster* monsters : monster)
    {
        if (allMonstersDead == false)
        {
            std::cout << monsters->getMobName() << "이(가) 공격했습니다!" << std::endl;
            int damage = monsters->useMobAttack();
            std::cout << player->getName() << "이(가) " << damage << "의 데미지를 받았습니다." << std::endl;
            player->setHealth(damage);
            if (player->getHealth() >= 1)
            {
                std::cout << "남은 체력은 " << player->getHealth() << "입니다." << std::endl;
            }
            // 다음순서로 넘겨줌
            else
            {
                isBattleOver(); // 플레이어가 죽었다고 간주, isBattleOver() 호출
                resolveBattle();
            }
        }
    }
}

// 전투 시작
void BattleManager::startBattle(Character* player, std::vector<Monster*> monsters)
{
    this->player = player;
    this->monster = monster;

    std::cout << "Battle started!\n";

    // TurnOrder 구조체를 사용하여 전투 순서를 미리 결정
    std::vector<TurnOrder> turnOrders;

    // 플레이어의 공격 속도 추가
    turnOrders.push_back(TurnOrder(true, player->getAttackSpeed()));

    // 몬스터들의 공격 속도 추가
    for (Monster* m : monster) {
        turnOrders.push_back(TurnOrder(false, m->getMobAttackSpeed()));
    }

    // 공격 속도에 따라 내림차순으로 정렬
    std::sort(turnOrders.begin(), turnOrders.end(), [](const TurnOrder& a, const TurnOrder& b) {
        return a.attackSpeed > b.attackSpeed;
        });

    // 전투가 끝날 때까지 반복
    while (isBattleOver() != false)
    {
        // 첫 번째 순서부터 차례대로 진행
        for (TurnOrder& turn : turnOrders)
        {
            if (turn.isPlayer) // 플레이어의 턴인 경우
            {
                processPlayerTurn();
                if (isBattleOver()) break; // 전투가 끝났으면 종료
            }
            else
            {
                processMonsterTurn();
                if (isBattleOver()) break; // 전투가 끝났으면 종료
            }
        }
    }

    resolveBattle();
}

// 전투 종료 처리
int BattleManager::resolveBattle()
{

    if (player->isCharacterDead())
    {
        // 우선 텍스트 출력은 영어로..
        std::cout << "Player has been defeated. Game Over.\n";

        return 0; // 게임종료
    }
    else if (allMonstersDead)
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
                Item* loot = monster->dropItem();
                player->addItemToInventory(loot);
                std::cout << "전리품 " << loot << "을(를) 습득하셨습니다.";
            }
        }

        return 1; // 게임 진행
    }
    else // 도망, input
    {
        return 1;
    }
}
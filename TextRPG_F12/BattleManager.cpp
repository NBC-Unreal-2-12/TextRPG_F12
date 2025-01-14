#include "BattleManager.h"
#include "MonsterFactory.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib> // 난수 생성 함수( srand() ) 제공
#include <ctime> // srand의 시드 설정(현재시각)
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
    {
        // 살아있는 몬스터 목록 가져오기
        std::vector<int> aliveMonsterIndices;
        for (size_t i = 0; i < monster.size(); ++i) {
            if (!monster[i]->isMobDead()) {
                aliveMonsterIndices.push_back(i);
            }
        }

        // 살아있는 몬스터가 없으면 전투 종료
        if (aliveMonsterIndices.empty()) {
            std::cout << "모든 몬스터가 쓰러졌습니다. 전투가 종료됩니다." << std::endl;
            return;
        }

        // 현재 살아있는 몬스터 출력
        std::cout << "현재 살아있는 몬스터 목록:\n";
        for (int index : aliveMonsterIndices) {
            std::cout << "[" << index << "] " << monster[index]->getMobName()
                << " (HP: " << monster[index]->getMobHealth() << ")\n";
        }

        // 플레이어가 공격할 몬스터 선택
        int selectedMonsterIndex = -1;
        while (true) {
            std::cout << "공격할 몬스터의 번호를 입력하세요: ";
            std::cin >> selectedMonsterIndex;

            // 입력값 검증
            if (std::cin.fail() || std::find(aliveMonsterIndices.begin(), aliveMonsterIndices.end(), selectedMonsterIndex) == aliveMonsterIndices.end()) {
                std::cin.clear(); // 입력 상태 초기화
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 잘못된 입력 무시
                std::cout << "잘못된 입력입니다. 다시 입력해주세요.\n";
            }
            else {
                cin.ignore();
                break; // 유효한 입력일 경우 반복 종료
            }
        }

        // 몬스터 공격 처리
        if (std::rand() % 100 <= (player->getAccuracy() / monster[selectedMonsterIndex]->getMobEvasion()) * 100) {
            int damage = player->getAttack();
            monster[selectedMonsterIndex]->takeMobDamage(damage);
            std::cout << monster[selectedMonsterIndex]->getMobName() << "에게 " << damage << "의 데미지를 입혔습니다!\n";

            if (monster[selectedMonsterIndex]->isMobDead()) {
                std::cout << monster[selectedMonsterIndex]->getMobName() << "이(가) 쓰러졌습니다!\n";
            }
        }
        else {
            std::cout << "공격이 빗나갔습니다!\n";
        }
        break;
    }
    case 2: // 스킬
        if (int randomType = std::rand() % 100 <= (player->getAccuracy() / monster[0]->getMobEvasion())) // 랜덤값이 "명중률 / 몬스터회피율" 보다 작아야 명중
        {
            //player->useSkill(monster);
        }
        else
        {
            cout << "빗나감!" << endl;
        }
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
void BattleManager::processMonsterTurn(unique_ptr<Monster>& monster)
{
    if (monster->isMobDead() == false)
    {
        std::cout << monster->getMobName() << "이(가) 공격했습니다!" << std::endl;
        if (int randomType = std::rand() % 1 <= (monster->getMobAccuracy() / player->getAccuracy())) // 랜덤값이 "몬스터 명중률 / 회피율" 보다 작아야 명중
        {
            //명중시
            int damage = monster->useMobAttack();
            std::cout << player->getName() << "이(가) " << damage << "의 데미지를 받았습니다." << std::endl;
            player->setHealth(player->getHealth() - damage);
            if (player->getHealth() >= 1)
            {
                std::cout << "남은 체력은 " << player->getHealth() << "입니다." << std::endl;
            }

            else
            {
                player->setCharacterDead(true);
                isBattleOver(); // 플레이어가 죽었다고 간주, isBattleOver() 호출
                resolveBattle();
            }
        }
        else
        {
            //회피시
            cout << "빗나감!" << endl;
        }
    }

}

// 전투 시작
void BattleManager::startBattle(Character* player, std::vector<unique_ptr<Monster>>& monsters)
{
    this->player = player;
    this->monster = std::move(monsters);

    std::cout << "Battle started!\n";

    for (auto& m : monster) {
        cout << m->getMobName() << endl;
    }

    // TurnOrder 구조체를 사용하여 전투 순서를 미리 결정
    std::vector<TurnOrder> turnOrders;

    // 전투가 끝날 때까지 반복
    while (isBattleOver() == false)
    {
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
                if (isBattleOver()) break; // 전투가 끝났으면 종료
            }
            else
            {
                processMonsterTurn(monster[turn.index]);
                if (isBattleOver()) break; // 전투가 끝났으면 종료
            }
        }
        //전투 순서 벡터 초기화
        turnOrders.clear();
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
        for (auto& monster : monster)
        {
            if (monster->isMobDead())
            {
                int idx = std::rand() % 100;
                Item* loot = monster->dropItem(idx);
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
#ifndef BATTLEMANAGER_H_
#define BATTLEMANAGER_H_

#include "PlayerInput.h"
#include "GameManager.h"
#include "Monster.h"

#include <cstdlib>

class BattleManager 
{
private:
    struct TurnOrder {
        bool isPlayer;  // 플레이어인지 아닌지 구분
        int attackSpeed;  // 공격 속도

        // 생성자
        TurnOrder(bool isPlayer, int attackSpeed) : isPlayer(isPlayer), attackSpeed(attackSpeed) {}
    };
    Character* player;              // 플레이어 캐릭터
    vector<Monster*> monster; // 전투 참여 몬스터
    bool isPlayerTurn;              // 현재 턴이 플레이어의 턴인지 여부
    bool allMonstersDead = false;           // 몬스터들이 전멸했는지 여부

    Inventory* inventory;

public:
    // 전투 종료 조건 확인
    bool isBattleOver();

    // 행동 순서 결정
    void determineTurnOrder();

    // 플레이어 행동 처리
    void processPlayerTurn();

    // 몬스터 행동 처리
    void processMonsterTurn();

    // 전투 시작
    void startBattle(Character* player, const vector<unique_ptr<Monster>>& monster);

    // 전투 종료 처리
    int resolveBattle();
};

#endif

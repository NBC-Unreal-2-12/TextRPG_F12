#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include "PlayerInput.h"

class BattleManager {
private:
    Character* player;              // 플레이어 캐릭터
    Monster* monster; // 전투 참여 몬스터
    bool isPlayerTurn;              // 현재 턴이 플레이어의 턴인지 여부

    // 전투 종료 조건 확인
    bool isBattleOver();

    // 행동 순서 결정
    void determineTurnOrder();

    // 플레이어 행동 처리
    void processPlayerTurn();

    // 몬스터 행동 처리
    void processMonsterTurn();

    // 전투 종료 처리
    void resolveBattle();

public:
    // 전투 시작
    void startBattle(Character* player, Monster* monster);
};

#endif

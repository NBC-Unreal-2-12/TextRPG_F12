#ifndef BATTLEMANAGER_H_
#define BATTLEMANAGER_H_
#define NOMINMAX

#include "PlayerInput.h"
#include "GameManager.h"
#include "Monster.h"

#include <cstdlib>
#include <Windows.h>


class BattleManager 
{
private:
    struct TurnOrder {
        int index;
        bool isPlayer;  // 플레이어인지 아닌지 구분
        int attackSpeed;  // 공격 속도

        // 생성자
        TurnOrder(int index, bool isPlayer, int attackSpeed) : index(index), isPlayer(isPlayer), attackSpeed(attackSpeed) {}
    };

    Character* player;              // 플레이어 캐릭터
    vector<unique_ptr<Monster>>& monster; // 전투 참여 몬스터
    bool isPlayerTurn;              // 현재 턴이 플레이어의 턴인지 여부
    bool allMonstersDead = false;           // 몬스터들이 전멸했는지 여부

    Inventory* inventory;

public:

    // 생성자
    BattleManager(Character* player, std::vector<std::unique_ptr<Monster>>& monster);

    // 전투 종료 조건 확인
    bool isBattleOver();

    // 행동 순서 결정
    void determineTurnOrder();

    // 플레이어 행동 처리
    void processPlayerTurn();

    // 몬스터 행동 처리
    void processMonsterTurn(unique_ptr<Monster>& monster);

    // 전투 시작
    int startBattle(Character* player, vector<unique_ptr<Monster>>& monster);

    // 전투 종료 처리
    int resolveBattle();

    // 글자색 설정
    void setColor(int color)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
    }
};

#endif

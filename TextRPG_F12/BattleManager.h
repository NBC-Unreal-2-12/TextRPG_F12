#ifndef BATTLEMANAGER_H_
#define BATTLEMANAGER_H_
#define NOMINMAX

#include "PlayerInput.h"
#include "GameManager.h"
#include "Monster.h"

#include <cstdlib>
#include <Windows.h>
#include <chrono>
#include <thread>



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
    bool isBattleActive = true;     // 전투 진행 상태 확인
    bool isTurnEnd = false;         // 플레이어 턴 종료여부 확인
    int currentTurn;                // 현재 턴

    Inventory* inventory;

public:

    // 생성자
    BattleManager(Character* player, std::vector<std::unique_ptr<Monster>>& monster);

    // 전투 종료 조건 확인
    bool getAllMonsterDead();

    // 전투 화면 출력
    void displayBattleState();

    // 플레이어 행동 처리
    void processPlayerTurn();

    // 현재 전투 상황 출력
    void showMonsterCombatInfo();
    void showPlayerCombatInfo();

    // 몬스터 정보 출력
    void showMonsterInfo();

    // 몬스터 공격
    void attackMonster();

    // 몬스터 스킬로 공격
    void useSkillOnMonster();

    // 현재 남아있는 몬스터 반환
    std::vector<int> getAliveMonsters();

    // 특정 몬스터 선택
    int getMonsterChoice(const std::vector<int>& aliveMonsterIndices);

    // 몬스터 행동 처리
    void processMonsterTurn(unique_ptr<Monster>& monster);

    // 전투 시작
    void startBattle(Character* player, vector<unique_ptr<Monster>>& monster);

    // 전투 종료 처리
    int resolveBattle();

    // 글자색 설정
    void setColor(int color)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
    }

    // 딜레이
    void delay(int milliseconds)
    {
        //Beep(220, 200);
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    }

};

#endif

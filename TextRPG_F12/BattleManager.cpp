#include "BattleManager.h"

// 전투 종료 조건 확인
bool BattleManager::isBattleOver() { return true; }

// 행동 순서 결정
void BattleManager::determineTurnOrder() {}

// 플레이어 행동 처리
void BattleManager::processPlayerTurn() {}

// 몬스터 행동 처리
void BattleManager::processMonsterTurn() {}

// 전투 종료 처리
void BattleManager::resolveBattle() {}

// 전투 시작
void BattleManager::startBattle(Character* player, Monster* monster) {}
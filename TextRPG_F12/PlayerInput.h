#ifndef PLAYER_INPUT_H
#define PLAYER_INPUT_H

#include "Job.h"
#include "Inventory.h"

class PlayerInput 
{
public:
    // 사용자로부터 행동 선택 입력을 받음
    int getPlayerChoiceInBattle();  // 전투 메인 메뉴
    int getPlayerChoiceAfterBattle();  // 전투 이후 선택
    void getPlayerChoiceUsingItem();   // 아이템 사용 선택
    pair<int, int> getPlayerBuyingItem();  // 상점에서 아이템 구매
    pair<int, int> getPlayerSellingItem();  // 상점에서 아이템 판매
    string setPlayerName(); // 캐릭터 생성 시 이름 선택
    Job* setJobByPlayerInput(); // 캐릭터 생성 시 직업 선택
};

#endif

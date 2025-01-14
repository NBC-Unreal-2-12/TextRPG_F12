#ifndef PLAYER_INPUT_H
#define PLAYER_INPUT_H

#include "Job.h"

class PlayerInput 
{
public:
    // 사용자로부터 행동 선택 입력을 받음
    int getPlayerChoice();
    int getPlayerChoiceAfterBattle();
    string setPlayerName();
    Job* setJobByPlayerInput();
};

#endif

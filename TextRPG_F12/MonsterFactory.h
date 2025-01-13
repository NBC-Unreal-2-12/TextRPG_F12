#pragma once

#include <memory>

#include "Monster.h"
#include "NormalMonster.h"
#include "EliteMonster.h"
#include "SpecialMonster.h"
#include "BossMonster.h"

class MonsterFactory
{
public:
	std::unique_ptr<Monster> createMonster(int round);

    // 시드는 프로그램 전체에서 한 번만 설정.
    static void setSeed() {
        static bool isInitialized = false; // 시드가 이미 설정되었는지 확인
        if (!isInitialized) {
            // srand() 함수가 unsigned int 타입 값을 인수로 받기 때문에 time_t 타입 변수를 형변환 해준다.
            std::srand(static_cast<unsigned>(std::time(nullptr))); // 시드 설정, time(nullptr)이 가리키는 것은 현재 시각
            isInitialized = true;
        }
    }

    // 정적 메서드: 난수 생성
    static int getRandomInt(int min, int max) {
        return std::rand() % (max - min + 1) + min;
    }
};


#include "MonsterFactory.h"
#include <cstdlib> // 난수 생성 함수( srand() ) 제공
#include <ctime> // srand의 시드 설정(현재시각)
#include <memory>

std::unique_ptr<NormalMonster> createNormalMonster() 
{
    int randomType = std::rand() % 3; // 0, 1, 2 중 랜덤
    switch (randomType) 
    {
    case 0: return std::make_unique<Slime>();
    case 1: return std::make_unique<Orc>();
    case 2: return std::make_unique<Goblin>();
    default: return nullptr;
    }
}

std::unique_ptr<EliteMonster> createEliteMonster() 
{
    int randomType = std::rand() % 3; // 0, 1, 2 중 랜덤
    switch (randomType) 
    {
    case 0: return std::make_unique<EliteSlime>();
    case 1: return std::make_unique<EliteOrc>();
    case 2: return std::make_unique<EliteGoblin>();
    default: return nullptr;
    }
}

std::unique_ptr<SpecialMonster> createSpecialMonster() 
{
    int randomType = std::rand() % 3; // 0, 1, 2 중 랜덤
    switch (randomType) 
    {
    case 0: return std::make_unique<Dragon>();
    case 1: return std::make_unique<Balrog>();
    case 2: return std::make_unique<Kraken>();
    default: return nullptr;
    }
}

std::unique_ptr<BossMonster> createBossMonster() 
{
    int randomType = std::rand() % 1; // 0, 1, 2 중 랜덤
    switch (randomType) {
    case 0: return std::make_unique<GGD>();
    default: return nullptr;
    }
}

std::unique_ptr<Monster> MonsterFactory::createMonster(int round) 
{
    int probability = getRandomInt(1, 100); // 1~100 사이의 난수

    if (round <= 5) 
    {
        if (probability <= 80) return createNormalMonster();
        else return createEliteMonster();
    }
    else if (round <= 10) 
    {
        if (probability <= 50) return createNormalMonster();
        else if (probability <= 90) return createEliteMonster();
        else return createSpecialMonster();
    }
    else if (round < 15) 
    {
        if (probability <= 30) return createNormalMonster();
        else if (probability <= 70) return createEliteMonster();
        else if (probability <= 90) return createSpecialMonster();
        else return createBossMonster();
    }
    else 
    {
        return createBossMonster();
    }
}

// 어떻게 쓸건가?
/*
const int totalRounds = 15;

    for (int round = 1; round <= totalRounds; ++round) {
        std::cout << "Round " << round << " begins!\n";

        std::vector<std::unique_ptr<Monster>> monster;

        // 라운드별 몬스터 생성
        // 한 번에 여러마리를 생성하게 되면 for문으로 가능.
        monsters.push_back(createMonster(round));

        // 생성된 몬스터 출력
        std::cout << "A wild " << typeid(*monster).name() << " appeared!\n";
        monster->useMobAttack();

        std::cout << "Round " << round << " ends!\n\n";
    }
*/
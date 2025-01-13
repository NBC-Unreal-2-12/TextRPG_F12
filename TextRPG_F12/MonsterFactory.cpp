#include "MonsterFactory.h"
#include <cstdlib> // ���� ���� �Լ�( srand() ) ����
#include <ctime> // srand�� �õ� ����(����ð�)

std::unique_ptr<NormalMonster> createNormalMonster() {
    int randomType = std::rand() % 3; // 0, 1, 2 �� ����
    switch (randomType) {
    case 0: return std::make_unique<Slime>();
    case 1: return std::make_unique<Orc>();
    case 2: return std::make_unique<Goblin>();
    default: return nullptr;
    }
}

std::unique_ptr<EliteMonster> createEliteMonster() {
    int randomType = std::rand() % 3; // 0, 1, 2 �� ����
    switch (randomType) {
    case 0: return std::make_unique<EliteSlime>();
    case 1: return std::make_unique<EliteOrc>();
    case 2: return std::make_unique<EliteGoblin>();
    default: return nullptr;
    }
}

std::unique_ptr<SpecialMonster> createSpecialMonster() {
    int randomType = std::rand() % 3; // 0, 1, 2 �� ����
    switch (randomType) {
    case 0: return std::make_unique<Dragon>();
    case 1: return std::make_unique<Balrog>();
    case 2: return std::make_unique<Kraken>();
    default: return nullptr;
    }
}

std::unique_ptr<BossMonster> createBossMonster() {
    //int randomType = std::rand() % 3; // 0, 1, 2 �� ����
    //switch (randomType) {
    //case 0: return std::make_unique<EliteSlime>();
    //case 1: return std::make_unique<EliteOrc>();
    //case 2: return std::make_unique<EliteGoblin>();
    //default: return nullptr;
    //}
}

std::unique_ptr<Monster> createMonster(int round) {
    // srand() �Լ��� unsigned int Ÿ�� ���� �μ��� �ޱ� ������ time_t Ÿ�� ������ ����ȯ ���ش�.
    std::srand(static_cast<unsigned>(std::time(nullptr))); // time(nullptr)�� ����Ű�� ���� ���� �ð�
    int probability = std::rand() % 100 + 1; // 1~100 ���� ���� ��

    if (round <= 5) {
        if (probability <= 80) return createNormalMonster();
        else return createEliteMonster();
    }
    else if (round <= 10) {
        if (probability <= 50) return createNormalMonster();
        else if (probability <= 90) return createEliteMonster();
        else return std::make_unique<SpecialMonster>();
    }
    else if (round < 15) {
        if (probability <= 30) return createNormalMonster();
        else if (probability <= 70) return createEliteMonster();
        else if (probability <= 90) return std::make_unique<SpecialMonster>();
        else return std::make_unique<BossMonster>();
    }
    else {
        return std::make_unique<BossMonster>();
    }
}

// ��� ���ǰ�?
/*
const int totalRounds = 15;

    for (int round = 1; round <= totalRounds; ++round) {
        std::cout << "Round " << round << " begins!\n";

        std::vector<std::unique_ptr<Monster>> monster;

        // ���庰 ���� ����
        // �� ���� ���������� �����ϰ� �Ǹ� for������ ����.
        monsters.push_back(createMonster(round));

        // ������ ���� ���
        std::cout << "A wild " << typeid(*monster).name() << " appeared!\n";
        monster->useMobAttack();

        std::cout << "Round " << round << " ends!\n\n";
    }
*/
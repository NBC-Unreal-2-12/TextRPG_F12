#include <iostream>
#include <string>
#include "Character.h"

Character * Character::instance = nullptr;

Character::Character(string userName, Job* characterJob) :
    name(userName), job(characterJob), level(1), maxHealth(200), health(200), attack(30),
	experience(0), gold(0), accuracy(100), attackSpeed(5), evasion(1), isDead(false), mp(100), maxMp(100), maxExperience(100)
{
    characterJob->applyJobEffect(attack, maxHealth, attackSpeed, evasion, accuracy, maxMp);
    health = maxHealth;
    mp = maxMp;
}

void Character::initialize(string userName, Job* characterJob)
{
    if (instance == nullptr) {
        instance = new Character(userName, characterJob);
    }
    else {
        cout << "Character instance is already initialized!" << endl;
    }
}

Character* Character::getInstance()
{
    if (instance == nullptr) {
        cout << "Error: Character instance is not initialized. Call initialize() first." << endl;
        return nullptr;
    }
    return instance;
}


void Character::displayStatus()
{
    cout << "\nㅡㅡㅡㅡㅡㅡㅡㅡㅡ ౨ৎ ㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
    cout << "이름: " << name << endl;
    cout << "직업: " << job->getJobName() << endl;
    switch (job->getJobIndex())
    {
    case 0:
        cout << R"(
         ⠀⠀⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠈⢧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠘⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠈⢿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠫⡷⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⠘⠄⢢⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⠀⠈⢔⠳⡀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠢⠈⢆⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⠌⣓⠖⠂⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠋⠈⢢⡀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠱⡀⠀
         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⠀
             )" << endl;
        break;
    case 1:
        cout << R"(
         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⡀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢳⢆⠀⢘⡆⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡌⣤⠚⠄⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠋⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⠀⣰⠃⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⡜⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⡜⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⡞⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⢀⠞⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠌⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
             )" << endl;
        break;
    case 2:
        cout << R"(
         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠴⠒⠒⠋⠋⠛⠉⠀⠀⠀
         ⠀⠀⠁⠄⠀⠀⠀⠀⠀⠀⠀⠠⡼⠊⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠈⠠⠀⠀⠀⠀⣖⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⠁⣖⡺⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⣰⡛⠉⠐⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠠⣷⠃⠀⠀⠀⠐⠠⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⣸⠁⠀⠀⠀⠀⠀⠀⠈⠐⠄⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⢈⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠂⣀⡀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⢈⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢿⡻⣄⠀⠀
         ⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠂⠀⠁⠀⠀⠀⠀⠉⠉⠀⠀
         ⠀⠀⠀⠀⠀⠀⢹⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠰⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
             )" << endl;
        break;

    default:
        break;
    }
    cout << "레벨: " << level << endl;
    cout << "체력: " << health << " / " << maxHealth << endl;
    cout << "마나: " << mp << " / " << maxMp << endl;
    cout << "경험치: " << experience << " / " << maxExperience << endl;
    cout << "공격력: " << attack << endl;
    cout << "공격속도: " << attackSpeed << endl;
    cout << "명중률: " << accuracy << endl;
    cout << "회피율: " << evasion << endl;
    cout << "보유골드: " << gold << endl;
    cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡ ౨ৎ ㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
}

void Character::levelUp()
{
    level++;
    maxHealth += job->getHealthGrowth();
	health += job->getHealthGrowth();
    maxMp += job->getManaGrowth();
	mp += job->getManaGrowth();
    attack += job->getAttackGrowth();
    evasion += job->getEvasionGrowth();
    accuracy += job->getAccuracyGrowth();
    cout << "레벨업! " << name << " 의 레벨이 " << level << "이 되었습니다!" << endl;
}

void Character::doLevelUp()
{

    while (experience >= maxExperience)
    {
        experience -= maxExperience;
        maxExperience = maxExperience * 1.45;
        levelUp();
    }
    displayStatus();
}

// 캐릭터 인벤토리 관련 메서드
void Character::useItemFromInventory(int index)
{
    Inventory::getInstance()->useItem(index, this);
}

void Character::addItemToInventory(Item* item)
{
    Inventory::getInstance()->addItem(item);
}

void Character::sellItemFromInventory(int index)
{
    Inventory::getInstance()->sellItem(index);
}

void Character::displayInventory()
{
    Inventory::getInstance()->listItem();
}

Item* Character::findItemFromInventory(int index)
{
    return Inventory::getInstance()->findItem(index);
}

bool Character::isInventoryEmpty()
{
    if (Inventory::getInstance()->isInventoryEmpty())
    {
        return true;
    }

    return false;
}


// 추가

int Character::getGold()
{
    return gold;
}

void Character::setGold(int sellPrice)
{
    gold += sellPrice;
}
double Character::getExp()
{
    return experience;
}
double Character::getMaxExp()
{
    return round(maxExperience);
}
void Character::addExp(int set_exp)
{
    experience += set_exp;
}
bool Character::isCharacterDead()
{
    return isDead;
}
void Character::setCharacterDead(bool dead) {
    vector<Item*> item = Inventory::getInstance()->getInventory();
    auto it = find_if(item.begin(), item.end(), [](Item* i) { return dynamic_cast<ReviveItem*>(i) != nullptr; }); // 죽기 전 ReviveItem 찾기
    if (it != item.end()) {
        item.erase(it);
        health += 50;
    }
    else { // 없을 시 isDead = true;
        isDead = true;
    }
}

int Character::getHealth()
{
    return health;
}
void Character::setHealth(int set_health)
{
    if (set_health > maxHealth)
    {
        health = maxHealth;
    }
    else
    {
        health = set_health;
    }
    
}
int Character::getMaxHealth()
{
    return maxHealth;
}
int Character::getMP()
{
    return mp;
}
void Character::setMP(int set_mp)
{
    if (set_mp > maxMp)
    {
        mp = maxMp;
    }
    else
    {
        mp = set_mp;
    }
}
int Character::getMaxMP()
{
    return maxMp;
}
void Character::setMaxMP(int set_maxMp)
{
    maxMp = set_maxMp;
}
double Character::getAttack()
{
    return attack;
}
void Character::setAttack(int set_attack)
{
    attack = set_attack;
}
int Character::getAttackSpeed()
{
    return attackSpeed;
}

void Character::setAttackSpeed(int set_attackSpeed)
{
    attackSpeed = set_attackSpeed;
}

double Character::getAccuracy()
{
    return accuracy;
}

void Character::setAccuracy(double set_accuracy)
{
    accuracy = set_accuracy;
}

double Character::getEvasion()
{
    return evasion;
}

void Character::setEvation(double set_evasion)
{
    evasion = set_evasion;
}

void Character::receiveDamage(int damage)
{
    health -= damage;
    if (health <= 0)
    {
        health = 0;
        isDead = true;
    }
    cout << name << "이(가) " << damage << "의 데미지를 입었습니다. 남은 체력: " << health << endl;
}

double Character::getDamageFactor()
{
    return job->getDamageFactor();
}

void Character::useSkill(Monster* target)
{
    // Job에서 Skill 객체 가져오기
    Skill* skill = job->getSkill();

    // 스킬의 마나 소모량 가져오기
    int manaCost = skill->getManaCost();

    // MP 부족 시 스킬 사용 불가
    if (mp < manaCost)
    {
        cout << name << "의 마나가 부족합니다!" << endl;
        return;
    }

    // 스킬의 데미지 배율 가져오기
    double damageFactor = skill->getDamageFactor();

    // 데미지 계산
    int damage = static_cast<int>(attack * damageFactor);

    // MP 소모
    useMP(manaCost);

    // 몬스터에게 데미지 적용
    target->takeMobDamage(damage);

    // 출력
    setColor(5);
    cout << "\n" << name << "의 " << skill->getSkillName() << "!\n\n";
    setColor(7);

    setColor(1);
    cout << target->getMobName() << "에게 " << damage << " 데미지를 입혔습니다!\n";
    setColor(7);
}

void Character::useMP(int cost)
{
    mp -= cost;
    if (mp < 0) mp = 0;
}

string Character::getSkillName()
{
    return job->getSkillName();
}

int Character::getManaCost()
{
    return job->getManaCost();
}

string Character::getName()
{
    return name;
}

// 글자색 설정
void Character::setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
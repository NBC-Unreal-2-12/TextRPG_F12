#include <iostream>
#include <string>
#include "Character.h"

Character* Character::instance = nullptr;

Character::Character(string userName, Job* characterJob) : 
    name(userName), job(characterJob), level(1), maxHealth(200), health(200), attack(30), 
    experience(0), gold(0), accuracy(100), attackSpeed(5), evasion(1), isDead(false), mp(100), maxMp(100)
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
    cout << "\n현재 유저의 정보" << endl;
	cout << "이름: " << name << endl;
    cout << "직업: " << job->getJobName() << endl;
    cout << "레벨: " << level << endl;
    cout << "체력: " << health << "/" << maxHealth << endl;
    cout << "마나: " << mp << "/" << maxMp << endl;
    cout << "경험치: " << experience << endl;
    cout << "공격력: " << attack << endl;
    cout << "보유골드: " << gold << endl;
    cout << "공격속도: " << attackSpeed << endl;
    cout << "명중률: " << accuracy << endl;
    cout << "회피율: " << evasion << endl;
}

void Character::levelUp()
{
    level++;
    maxHealth += job->getHealthGrowth();
    maxMp += job->getManaGrowth();
    attack += job->getAttackGrowth();
    evasion += job->getEvasionGrowth();
    accuracy += job->getAccuracyGrowth();
    cout << "레벨업!" << name << "의 레벨이 " << level << "이 되었습니다!" << endl;
	displayStatus();
}

void Character::useItemFromInventory(int index)
{
    inventory.useItem(index, this);
}

void Character::addItemToInventory(Item* item)
{
    inventory.addItem(item);
}

void Character::sellItemFromInventory(int index)
{
    inventory.sellItem(index);
}

void Character::displayInventory() 
{
    inventory.listItem();
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
int Character::getExp()
{
    return experience;
}
void Character::setExp(int set_exp)
{
	experience = set_exp;
}
bool Character::isCharacterDead()
{
    return isDead;
}
void Character::setCharacterDead(bool dead) {
    vector<Item*> item = inventory.getInventory();
    auto it = find_if(item.begin(), item.end(), [](Item* i){ return dynamic_cast<ReviveItem*>(i) != nullptr; }); // 죽기 전 ReviveItem 찾기
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
	health = set_health;
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
	mp = set_mp;
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
int Character::getAttackSpeed()
{
    return attackSpeed;
}
Item* Character::findItemFromInventory(int index)
{
    return inventory.findItem(index);
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
	cout << name << "이 " << damage << " 데미지를 입었습니다. 남은 체력: " << health << endl;
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
    cout << name << "은" << target->getMobName()
        << " 에게 " << skill->getSkillName()
        << "를 사용해서 " << damage << " 데미지를 입혔습니다!" << endl;
}

void Character::useMP(int cost)
{
    mp -= cost;
    if (mp < 0) mp = 0;
}

string Character::getName()
{
    return name;
}

void Character::doLevelUp()
{
    while (experience >= 100)
    {
        levelUp();
        std::cout << "레벨업! 레벨이 " << level << "이 되었습니다." << endl;
    }
}

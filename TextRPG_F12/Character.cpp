#include <iostream>
#include <string>
#include "Character.h"

Character* Character::instance = nullptr;

Character::Character(string userName, Job* characterJob) : 
    name(userName), job(characterJob), level(1), maxHealth(200), health(200), attack(30), 
    experience(0), gold(0), accuracy(100), attackSpeed(20), evasion(1), isDead(false), mp(100), maxMp(100)
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
    cout << "현재 유저의 정보" << endl;
	cout << "이름: " << name << endl;
    cout << "레벨: " << level << endl;
    cout << "체력: " << health << "/" << maxHealth << endl;
    cout << "마나: " << mp << "/" << maxMp << endl;
    cout << "경험치: " << experience << endl;
    cout << "공격력: " << attack << endl;
    cout << "보유골드: " << gold << endl;
    cout << "공격속도: " << attackSpeed << endl;
    cout << "명중률: " << accuracy << endl;
    cout << "회피율: " << evasion << endl;
    cout << "직업: " << job->getJobName() << endl;
}

void Character::levelUp()
{
    level++;
    maxHealth += level * 20;
    health = maxHealth;
	maxMp += level * 10;
	mp = maxMp;
    attack += level * 5;
    cout << "레벨업!" << name << "의 레벨이 " << level << "이 되었습니다!" << endl;
}

void Character::useItem(Item* item)
{
    inventory.removeItem(item);
}

void Character::addItemToInventory(Item* item)
{
    inventory.addItem(item);
}

void Character::removeItemFromInventory(Item* item)
{
    inventory.removeItem(item);
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
bool Character::findItemFromInventory(Item* item)
{
    return inventory.hasItem(item);
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

void Character::useSkill(vector<Monster*>& targets)
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

    // 몬스터 목록이 비어 있는 경우
    if (targets.empty())
    {
        cout << "공격할 대상이 없습니다!" << endl;
        return;
    }

    // 타겟 선택 (여기서 첫 번째 몬스터를 기본 타겟으로 선택)
    Monster* target = nullptr;

    cout << "공격할 대상을 선택하세요:" << endl;
    for (size_t i = 0; i < targets.size(); ++i)
    {
        cout << i + 1 << ". " << targets[i]->getMobName()
            << " (체력: " << targets[i]->getMobHealth() << ")" << endl;
    }

    int choice;
	bool validInput = false;

    while (!validInput) 
    {
        cin >> choice;
        // 유효한 선택인지 확인
        if (choice < 1 || choice > static_cast<int>(targets.size()))
        {
            cout << "잘못된 선택입니다. 스킬을 사용하지 않았습니다." << endl;
            continue;
        }
        validInput = true;
        break;
    }

    // 선택된 타겟
    target = targets[choice - 1];

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
    return string();
}


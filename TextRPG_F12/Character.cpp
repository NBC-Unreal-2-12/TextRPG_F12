#include <iostream>
#include "Character.h"

using namespace std;

Character* Character::instance = nullptr;

Character::Character(string userName, Job* characterJob) : name(userName), job(characterJob), level(1), maxHealth(200), health(200), attack(30), experience(0), gold(0), accuracy(100), attackSpeed(20), evasion(1), isDead(false), mp(100), maxMp(100)
{
    characterJob->applyJobEffect(attack, maxHealth, attackSpeed, evasion, accuracy, maxMp);
    health = maxHealth;
    mp = maxMp;
}

Character* Character::getInstance(string userName, Job* characterJob) {
    if (instance == nullptr) {
        instance = new Character(userName, characterJob);
    }
    return instance;
}

void Character::displayStatus()
{
    cout << "현재 유저의 정보" << endl;
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
void Character::displayInventory() {
    inventory.listItem();
}


// 추가

int Character::getGold() {
    return gold;
}

void Character::setGold(int sellPrice) {
    gold += sellPrice;
}

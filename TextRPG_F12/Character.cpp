#include <iostream>
#include "Character.h"
#include "item"

using namespace std;

Character* Character::instance = nullptr;

Character::Character(string userName, Job* characterJob) : name(userName), job(characterJob), level(1), maxHelth(200), helth(200), attack(30), experience(0), gold(0), accuracy(100), attackspeed(20), evasion(1), isDead(false), mp(100), maxMp(100)
{
    characterJob->applyJobEffect(attack, maxHelth,attackspeed,evasion,accuracy,maxMp);
    helth = maxHelth;
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
    cout << "체력: " << helth << "/" << maxHelth << endl;
    cout << "마나: " << mp << "/" << maxMp << endl;
    cout << "경험치: " << experience << endl;
    cout << "공격력: " << attack << endl;
    cout << "보유골드: " << gold << endl;
	cout << "공격속도: " << attackspeed << endl;
	cout << "명중률: " << accuracy << endl;
	cout << "회피율: " << evasion << endl;
    cout << "직업: " << job->getJobName() << endl;
}

void Character::levelUp()
{
    level++;
    maxHelth += level * 20;
    helth = maxHelth;
    attack += level * 5;
    cout << "레벨업!" << name << "의 레벨이 " << level << "이 되었습니다!" << endl;
}


void Character::useItem(Item* item)
{
	inventory.useItem(item);
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
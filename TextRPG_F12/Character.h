#ifndef CHARACTER_H
#define CHARACTER_H
#pragma once

#include <string>
#include "Job.h"
#include "Inventory.h"
#include "Item.h"
#include "Monster.h"

using namespace std;


class Character
{
private:
	string name;	// 이름
    int level;      // 레벨
    int health;     // 현재 체력
    int maxHealth;  // 최대 체력
	int mp;     // 현재 마나
	int maxMp;      // 최대 마나
	double attack;  // 공격력
	int experience;     // 경험치
	int gold;       // 골드
	int attackSpeed;        // 공격속도
	double accuracy;            // 명중률
	double evasion;     // 회피율  
	Job* job;       // 직업
	bool isDead;        // 사망 여부    
    static Character* instance; // 싱글톤 인스턴스
    Character(string userName, Job* characterJob);
    Inventory inventory;                

public:
    Character(const Character&) = delete;
    Character& operator=(const Character&) = delete;
	static void initialize(string userName, Job* characterJob);
	static Character* getInstance();
	void displayStatus();   // 현재 상태 출력
	void levelUp();     // 레벨업
	void useItem(Item* item);   // 아이템 사용   
	void addItemToInventory(Item* item);   // 인벤토리에 아이템 추가
	bool findItemFromInventory(Item* item); // 인벤토리에서 아이템 찾기
	void removeItemFromInventory(Item* item); // 인벤토리에서 아이템 제거
	void displayInventory(); // 인벤토리 표시
	int getGold(); // 골드 getter
	void setGold(int sellPrice); // 골드 setter
	bool isCharacterDead();		 // 사망 여부 getter
	int getHealth();                // health getter
    int getMP();                    // mp getter
    double getAttack();             // 데미지 getter
    int getAttackSpeed();           // 공격속도 getter
	void setAttackSpeed(int set_attackSpeed); // 공격속도 setter
    double getAccuracy();           // 명중률 getter
	void setAccuracy(double set_accuracy); // 명중률 setter
    double getEvasion();            // 회피율 getter
	void setEvation(double set_evasion); // 회피율 setter
	void receiveDamage(int damage); // 유저가 데미지를 받는 메서드
    void useSkill(Monster& target); // 스킬 사용 메서드
	void useMP(int useMp); // MP 사용 메서드
	string getName();	// 이름 getter
};

#endif
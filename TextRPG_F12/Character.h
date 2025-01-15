#ifndef CHARACTER_H
#define CHARACTER_H
#pragma once
#define NOMINMAX

#include <string>
#include <Windows.h>
#include "Job.h"
#include "Inventory.h"
#include "Item.h"
#include "Monster.h"

using namespace std;

class Monster;

class Character
{
private:
	string name;	// 이름
    int level;      // 레벨
    int health;     // 현재 체력
    int maxHealth;  // 최대 체력
	int mp;			// 현재 마나
	int maxMp;      // 최대 마나
	double attack;  // 공격력
	int experience;     // 경험치
	int maxExperience;  // 최대 경험치
	int gold;       // 골드
	int attackSpeed;        // 공격속도
	double accuracy;            // 명중률
	double evasion;     // 회피율  
	Job* job;       // 직업
	bool isDead;        // 사망 여부    
    static Character* instance; // 싱글톤 인스턴스
    Character(string userName, Job* characterJob);
	Inventory inventory;                // 인벤토리

public:
    Character(const Character&) = delete;
    Character& operator=(const Character&) = delete;
	static void initialize(string userName, Job* characterJob);	// 인스턴스 초기화
	static Character* getInstance();				// 인스턴스 가져오기
	void displayStatus();   // 현재 상태 출력
	void levelUp();     // 레벨업
	void doLevelUp();   // 레벨업 확인
	void useItemFromInventory(int index);   // 아이템 사용   
	void addItemToInventory(Item* item);   // 인벤토리에 아이템 추가
	Item* findItemFromInventory(int index); // 인벤토리에서 아이템 찾기
	bool isInventoryEmpty();
	void sellItemFromInventory(int index); // 인벤토리에서 아이템 제거
	void displayInventory(); // 인벤토리 표시
	int getGold(); // 골드 getter
	void setGold(int sellPrice); // 골드 setter
	int getExp();				// 경험치 getter
	int getMaxExp();			// 최대 경험치 getter
	void addExp(int set_exp);	// 경험치 setter
	bool isCharacterDead();		 // 사망 여부 getter
	void setCharacterDead(bool dead);		//사망 setter
	int getHealth();                // health getter
	void setHealth(int set_health); // health setter
	int getMaxHealth();				// maxhealth getter
    int getMP();                    // mp getter
	void setMP(int set_mp);			// mp setter
	int getMaxMP();				// maxMp getter
	void setMaxMP(int set_maxMp);	// maxMp setter
    double getAttack();             // 데미지 getter
    void setAttack(int set_attack);             // 데미지 getter
    int getAttackSpeed();           // 공격속도 getter
	void setAttackSpeed(int set_attackSpeed); // 공격속도 setter
    double getAccuracy();           // 명중률 getter
	void setAccuracy(double set_accuracy); // 명중률 setter
    double getEvasion();            // 회피율 getter
	void setEvation(double set_evasion); // 회피율 setter
	void receiveDamage(int damage); // 유저가 데미지를 받는 메서드
    void useSkill(Monster* target); // 스킬 사용 메서드
	void useMP(int useMp); // MP 사용 메서드
	string getName();	// 이름 getter
	void setColor(int color);	// 글자색 설정
	
};

#endif
#pragma once
#include "Monster.h"

class EliteMonster : public Monster
{
public:
	EliteMonster(const std::string& name)
		: Monster(name)
	{
	}
};

class EliteSlime : public EliteMonster
{
public:
	EliteSlime() : EliteMonster("엘리트 슬라임")
	{
        mobName = "엘리트 슬라임";
        mobHealth = 500;
        mobMaxHealth = 500;
        mobAttack = 50;
        mobMana = 0;
        mobMaxMana = 3;
        mobAttackSpeed = 14;
        mobAccuracy = 120;
        mobEvasion = 1.5;
        lootIdx = 106; // 슬라임 왕관
    }

     void mobFace() override
     {
         setColor(4);
         cout << R"(
 ⠀⠀⠀⠀⠀⠀⠀⡠⠔⠦⣀⠀⠀⠀⠀
 ⠀⠀⠀⠀⠀⣀⣾⠀⠀⠀⠈⡆⠀⠀⠀
 ⠀⢀⣴⣶⣿⣿⣿⣷⣄⠀⠀⡆⠀⠀⠀
 ⢰⣿⣿⣿⣿⣿⣿⣿⣿⣆⠐⠀⣀⡀⠀
 ⠸⣿⣿⣿⣿⣿⣿⣿⣿⠗⠘⠤⠿⠗⠀
 ⠀⠈⠉⠉⠛⠛⠉⠉⠁⠀⠀⠀⠀⠀⠀
             )" << endl;
         setColor(7);
     }

     int useMobSkill() override
     {
         cout << mobName << "이(가) 200만큼 회복합니다." << endl;

         if (mobMaxHealth - mobHealth <= 200)
         {
             mobHealth = mobMaxHealth;
         }
         else
         {
             mobHealth += 200;
         }
         return 0;
     }
};

class EliteOrc : public EliteMonster
{
public:
	EliteOrc() : EliteMonster("엘리트 오크")
	{
        mobName = "엘리트 오크";
        mobHealth = 500;
        mobMaxHealth = 500;
        mobAttack = 50;
        mobMana = 0;
        mobMaxMana = 3;
        mobAttackSpeed = 14;
        mobAccuracy = 120;
        mobEvasion = 1.5;
        lootIdx = 105; // 오크 대왕의 검
    }

    void mobFace() override
    {
        setColor(4);
        cout << R"(
⠀⠀⠀⠀⠀⠀⣿⣿⣄⡀⡀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣻⣿⣿⣿⣿⣿⣆⠀⠀
⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣂⠀
⠀⠀⠀⠀⠀⣸⣿⢿⣿⣿⣿⡌⠹⣿⡄
⠀⠀⠀⠀⢠⣿⠇⣺⣿⣿⣿⣷⠄⢹⡯
⠀⠀⠀⠀⢰⣿⣦⣿⣿⣿⣿⣿⣇⠴⣿
⠀⠀⠀⢀⡾⠏⣰⣿⣿⠿⣿⣿⠻⠀⠉
⠀⣀⣶⡿⠁⠀⣺⣿⡃⠈⣿⣿⠀⠀⠀
⣼⣿⡿⠁⠀⠀⠺⣿⡇⠀⠹⣿⡇⠀⠀
⠛⠋⠀⠀⠀⠀⢈⣿⡆⠀⠀⣻⡇⠀⠀
⠀⠀⠀⠀⠀⠰⠿⠋⠃⠀⠀⣿⡿⠀⠀
        )" << endl;
        setColor(7);
    }

    int useMobSkill() override
    {
        cout << mobName << "의 공격력이 30 증가합니다." << endl;
        mobAttack += 30;
        return 0;
    }
};

class EliteGoblin : public EliteMonster
{
public:
	EliteGoblin() : EliteMonster("엘리트 고블린")
	{
        mobName = "엘리트 고블린";
        mobHealth = 350;
        mobMaxHealth = 350;
        mobAttack = 50;
        mobMana = 0;
        mobMaxMana = 3;
        mobAttackSpeed = 16;
        mobAccuracy = 120;
        mobEvasion = 2;
        lootIdx = 104; // 고블린 대장의 반지
    }

    void mobFace() override
    {
        setColor(4);
        cout << R"(⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢅⡀⠀⠀⡀⣔⢀⠀⡀⡄⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢠⡹⣜⢦⢣⢳⢱⢱⢺⢤⡠⡠⡆⣆⠀⠀⠀⠀⠀⠀
⠀⠀⠀⢀⢠⡢⣟⣗⡧⣧⡣⢧⡳⣽⣳⢵⢕⣟⡧⡣⠀⠀⠀⠀⠀
⠀⠀⢠⣺⠕⠉⠈⠺⡽⡮⣯⣪⢯⣗⣯⠳⡑⠈⢫⢮⡰⠀⠀⠀⠀
⠀⣀⢷⠹⢀⢠⣰⢴⣻⣽⢮⣺⣺⣪⢖⠄⠀⠀⠘⣵⢫⠤⠀⠀⠀
⠀⢗⠌⢃⢌⢧⢯⢯⣳⣝⡯⣯⡿⣽⢽⡗⢆⠀⢠⠺⢪⢯⡲⡢⡀
⠀⠀⠀⢇⣗⢽⡍⠳⣷⡳⣫⢯⣟⢽⡱⡀⠀⠀⠈⡇⠈⡖⡵⠘⠀
⠀⠀⠀⠀⠈⣳⣣⠀⡢⠫⠈⠫⠪⢷⢝⡦⡀⠀⠀⠀⠀⠃⠀⠀⠀
⠀⠀⠀⢠⢰⢕⠯⠂⠀⠀⠀⠀⠀⠸⡱⡣⣏⣆⠀⠀⠀⠀⠀⠀⠀
⠀⠰⣝⢞⠕⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⡜⣆⢀⠀⠀⠀⠀⠀
⠀⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢯⢞⡳⣕⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠃⠈⠀⠁⠀⠀⠀
        )" << endl;
        setColor(7);
    }

    int useMobSkill() override
    {
        cout << mobName << "이(가) 두 배의 데미지를 가합니다." << endl;
        return mobAttack * 2;
    }
};
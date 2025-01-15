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
        mobAttack = 30;
        mobMana = 0;
        mobMaxMana = 3;
        mobAttackSpeed = 15;
        mobAccuracy = 95;
        mobEvasion = 1.5;
        loot.emplace_back(new MonsterLoot("슬라임 왕관", 20));
        loot.emplace_back(new ReviveItem("부활의 토템", 300, 100));
    }

     void mobFace() override
     {
         cout << R"(
 ⠀⠀⠀⠀⠀⠀⠀⡠⠔⠦⣀⠀⠀⠀⠀
 ⠀⠀⠀⠀⠀⣀⣾⠀⠀⠀⠈⡆⠀⠀⠀
 ⠀⢀⣴⣶⣿⣿⣿⣷⣄⠀⠀⡆⠀⠀⠀
 ⢰⣿⣿⣿⣿⣿⣿⣿⣿⣆⠐⠀⣀⡀⠀
 ⠸⣿⣿⣿⣿⣿⣿⣿⣿⠗⠘⠤⠿⠗⠀
 ⠀⠈⠉⠉⠛⠛⠉⠉⠁⠀⠀⠀⠀⠀⠀
             )" << endl;
     }

    int useMobSkill() override
    {
        cout << mobName << "이(가) 100만큼 회복합니다." << endl;
        mobHealth += 100;
        return 0;
    }
};

class EliteOrc : public EliteMonster
{
public:
	EliteOrc() : EliteMonster("엘리트 오크")
	{
        mobName = "엘리트 오크";
        mobHealth = 400;
        mobAttack = 50;
        mobMana = 0;
        mobMaxMana = 3;
        mobAttackSpeed = 10;
        mobAccuracy = 95;
        mobEvasion = 1.3;
        loot.emplace_back(new MonsterLoot("오크 대왕의 검", 20));
        loot.emplace_back(new ReviveItem("부활의 토템", 300, 100));
    }

    void mobFace() override
    {
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
    }

    int useMobSkill() override
    {
        cout << mobName << "의 공격력이 20 증가합니다." << endl;
        mobAttack += 20;
        return 0;
    }
};

class EliteGoblin : public EliteMonster
{
public:
	EliteGoblin() : EliteMonster("엘리트 고블린")
	{
        mobName = "엘리트 고블린";
        mobHealth = 300;
        mobAttack = 40;
        mobMana = 0;
        mobMaxMana = 3;
        mobAttackSpeed = 18;
        mobAccuracy = 50 + 20;
        mobEvasion = 4;
        loot.emplace_back(new MonsterLoot("고블린 대장의 반지", 20));
        loot.emplace_back(new ReviveItem("부활의 토템", 300, 100));
    }

    void mobFace() override
    {
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
    }

    int useMobSkill() override
    {
        cout << mobName << "이(가) 두 배의 데미지를 가합니다." << endl;
        return mobAttack * 2;
    }
};
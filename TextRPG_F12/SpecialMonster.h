#pragma once
#include "Monster.h"

class SpecialMonster : public Monster
{
public:
	SpecialMonster(const std::string& name)
		: Monster(name) 
	{
	}
};

class Dragon : public SpecialMonster
{
public:
	Dragon() : SpecialMonster("드래곤")
	{
        mobName = "드래곤";
        mobHealth = 700;
        mobMaxHealth = 700;
        mobAttack = 70;
        mobMana = 0;
        mobMaxMana = 3;
        mobAttackSpeed = 20;
        mobAccuracy = 150;
        mobEvasion = 3;
        lootIdx = 107; // 드래곤의 비늘
    }

    void mobFace() override
    {
            cout << R"(
⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⣠⣠⣤⣄⠀⠈⣿⣿⣦⣄⠀⠀⠀⠀⠀⠀⠀
⠀⠀⣼⡿⠋⢉⣿⠀⢀⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀
⠀⠀⠝⠀⢠⣾⣿⣠⣾⣿⣿⣿⣿⣿⣿⡀⠀⠀⠀⠀
⠀⠀⠀⠀⣾⣿⣿⣿⣟⠛⢽⠟⠫⣿⣿⡆⠀⠀⠀⠀
⠀⠀⠀⠀⠘⣿⢿⣿⣿⣷⣆⠀⠀⠉⠉⠇⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣸⠽⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣴⠃⠀⣹⣻⡾⠿⣿⣶⣿⠟⠒⠢⠀⠀⠀
⠀⠀⠀⠀⠁⠀⠀⠀⠀⠈⠀⠀⠈⠀⠀⠀⠀⠈⠁⠀
            )" << endl;
    }

    int useMobSkill() override
    {
        cout << mobName << "이(가) 두 배의 데미지를 가합니다." << endl;
        return mobAttack * 2;
    }
};

class Balrog : public SpecialMonster
{
public:
	Balrog() : SpecialMonster("발록")
	{
        mobName = "발록";
        mobHealth = 1200;
        mobMaxHealth = 1200;
        mobAttack = 70;
        mobMana = 0;
        mobMaxMana = 3;
        mobAttackSpeed = 16;
        mobAccuracy = 150;
        mobEvasion = 2;
        lootIdx = 108; // 발록의 재
    }

     void mobFace()
     {
             cout << R"(
 ⠀⠀⠀⠀⠀⢰⡄⠀⠀⠀⠀⠀⠀⢴⠀⠀⠀⠀⠀⠀
 ⠀ ⠀⠀ ⣾⣝⠀⠀ ⠀⠀ ⣿⣣⡀⠀
 ⠀⠀ ⠀⣺⣽⣻⣄⣀⣡⢤⣰⣺⣟⣿⣳⡄⠀⠀⠀
    ⠀⣸⣟⢷⢫⢕⢟⡾⡿⣽⢞⡽⣽⣷⢿⡄⠀
    ⠀⣿⢾⣻⢔⡕⡽⡪⡹⢽⣳⢿⣻⣽⣟⣷⠀⠀
 ⠀⠀⢀⢻⣳⣽⢝⣪⢧⡱⣨⣟⣮⣫⢾⡿⣟⣿⠅⠀
 ⠀⠙⢭⢧⢳⡹⠀⢈⣨⣟⡵⣧⢮⡳⡕⠇⠈⠻⠁⠀
  ⠀⠀⠀⠀⠀⠐⢽⣺⣏⠙⠱⣯⣗⠀⠀⠀⠀ ⠀
        ⠀⢀⣤⣮⡏⠀⢠⢿⣦⠀⠀ ⠀⠀⠀
             )" << endl;
     }

    int useMobSkill() override
    {
        cout << mobName << "의 공격력이 50 증가합니다." << endl;
        mobAttack += 50;
        return 0;
    }
};

class Kraken : public SpecialMonster
{
public:
	Kraken() : SpecialMonster("크라켄")
	{
        mobName = "크라켄";
        mobHealth = 1200;
        mobMaxHealth = 1200;
        mobAttack = 70;
        mobMana = 0;
        mobMaxMana = 3;
        mobAttackSpeed = 1;
        mobAccuracy = 150;
        mobEvasion = 2;
        lootIdx = 109; // 크라켄의 심장
    }

    void mobFace()
    {
            cout << R"(⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⣤⣄⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⡀⠀⣾⣿⣿⣿⣿⣷⠀⠀⡀⠀⠀⠀⠀
⠀⠀⠀⠀⠍⣹⢆⢿⣿⣿⣿⣿⡿⡰⣏⠩⠀⠀⠀⠀
⠀⠀⠀⠀⣰⡏⣼⢨⢿⣿⣿⡿⡅⣇⢹⣦⠀⠀⠀⠀
⠀⠀⠀⠀⣿⣧⣛⣶⣷⣿⣿⣾⣶⣛⣼⣿⠀⠀⠀⠀
⠀⠀⠀⠀⣼⡿⠾⣪⣾⡿⢿⣷⣕⠷⢿⣧⠀⠀⠀⠀
⠀⠀⠀⠀⠻⠿⢹⣿⠉⢲⡖⠉⣿⡏⠿⠟⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠈⠛⠛⠁⠈⠛⠛⠁⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        )" << endl;
    }

    int useMobSkill() override
    {
        cout << mobName << "이(가) 300만큼 회복합니다." << endl;

        if (mobMaxHealth - mobHealth <= 300)
        {
            mobHealth = mobMaxHealth;
        }
        else
        {
            mobHealth += 300;
        }
        return 0;
    }
};
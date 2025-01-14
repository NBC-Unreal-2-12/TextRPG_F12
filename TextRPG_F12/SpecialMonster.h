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
	Dragon() : SpecialMonster("Dragon")
	{
        mobName = "Dragon";
        mobHealth = 20;
        mobAttack = 10;
        mobMana = 0;
        mobMaxMana = 3;
        mobAttackSpeed = 1;
        mobAccuracy = 50 + 20;
        mobEvasion = 1;
        loot.emplace_back(new MonsterLoot("드래곤의 비늘", 20));
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
	Balrog() : SpecialMonster("Balrog")
	{
        mobName = "Balrog";
        mobHealth = 20;
        mobAttack = 10;
        mobMana = 0;
        mobMaxMana = 3;
        mobAttackSpeed = 1;
        mobAccuracy = 50 + 20;
        mobEvasion = 1;
        loot.emplace_back(new MonsterLoot("발록의 재", 20));
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
        cout << mobName << "의 공격력이 5 증가합니다." << endl;
        mobAttack += 5;
        return mobAttack;
    }
};

class Kraken : public SpecialMonster
{
public:
	Kraken() : SpecialMonster("Kraken")
	{
        mobName = "Kraken";
        mobHealth = 20;
        mobAttack = 10;
        mobMana = 0;
        mobMaxMana = 3;
        mobAttackSpeed = 1;
        mobAccuracy = 50 + 20;
        mobEvasion = 1;
        loot.emplace_back(new MonsterLoot("크라켄의 심장", 20));
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
        cout << mobName << "이(가) 20만큼 회복합니다." << endl;
        mobHealth += 20;
        return mobAttack;
    }
};
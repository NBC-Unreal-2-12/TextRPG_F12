#pragma once
#include "Monster.h"

class NormalMonster : public Monster
{
public:
	NormalMonster(const std::string& name)
		: Monster(name)
	{
	}
};

class Slime : public NormalMonster
{
public:
	Slime() : NormalMonster("슬라임")
	{
		mobName = "슬라임";
		mobHealth = 150;
		mobMaxHealth = 150;
		mobAttack = 20;
		mobMana = 0;
		mobMaxMana = 3;
		mobAttackSpeed = 7;
		mobAccuracy = 70;
		mobEvasion = 1.3;
		lootIdx = 103; // 슬라임 젤리
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
		cout << mobName << "이(가) 20만큼 회복합니다." << endl;

		if (mobMaxHealth - mobHealth <= 20)
		{
			mobHealth = mobMaxHealth;
		}
		else
		{
			mobHealth += 20;
		}
		return 0;
	}
};

class Orc : public NormalMonster
{
public:
	Orc() : NormalMonster("오크")
	{
		mobName = "오크";
		mobHealth = 100;
		mobMaxHealth = 100;
		mobAttack = 40;
		mobMana = 0;
		mobMaxMana = 3;
		mobAttackSpeed = 1;
		mobAccuracy = 70;
		mobEvasion = 1.1;
		lootIdx = 102; // 오크의 부서진 검
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
		cout << mobName << "의 공격력이 10 증가합니다." << endl;
		mobAttack += 10;
		return 0;
	}
};

class Goblin : public NormalMonster
{
public:
	Goblin() : NormalMonster("고블린")
	{
		mobName = "고블린";
		mobHealth = 50;
		mobMaxHealth = 50;
		mobAttack = 30;
		mobMana = 0;
		mobMaxMana = 3;
		mobAttackSpeed = 10;
		mobAccuracy = 70;
		mobEvasion = 1.3;
		lootIdx = 101; // 고블린의 작은 동전
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


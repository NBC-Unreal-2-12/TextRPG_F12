#pragma once
#include "Monster.h"
#include <Windows.h>
#include <chrono>
#include <thread>

class BossMonster : public Monster
{
public:
	BossMonster(const std::string& name) // 만약 보스를 두 마리 이상 만들면 인자가 필요해 질 것.
		: Monster(name)
	{
	}
};

class GGD : public BossMonster
{
public:
	GGD() : BossMonster("GGD")
	{
		mobName = "고길동";
		mobHealth = 5000;
		mobMaxHealth = 5000;
		mobAttack = 50;
		mobMana = 0;
		mobMaxMana = 3;
		mobAttackSpeed = 20;
		mobAccuracy = 200;
		mobEvasion = 2;
		lootIdx = 110;  // 가시고기의 갈비뼈
	}

	void mobFace()
	{
		cout << R"(
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⢷⣷⣣⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⢏⣿⣿⡵⡀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣠⣮⣷⣿⣿⣿⣿⣷⣄⣄⠀⠀⠀⠀⠈⢞⣿⣿⡵⡀⠀⠀⠀⠀⠀
 ⠀⠀⡠⣿⣿⣿⣿⣿⣿⣿⣿⣧⣏⢦⣤⡀⠀⠀⠀⠫⣻⣿⣾⢄⠀⠀⠀
 ⠀⣔⣿⣿⣿⣿⣿⠿⣿⠻⢟⣿⣿⣿⣿⣿⡆⠀⠀⠀⠑⡿⣿⣯⢆⠀⠀
 ⢰⣸⢿⣻⢟⠃⠉⠉⠀⡠⠤⠸⣸⣿⣿⣿⡳⠁⠀⠀⠀⠀⡨⠺⠿⠇⢓⡄
 ⠧⠊⠁⠘⣖⣳⠠⣶⣋⡹⠁⠀⠛⣩⢻⠋⠀⠀⠀⠀⠀⢀⠇⠀⠀⠀⠀⢾⠀
⠀⠀⢠⠂⠁⠓⠒⠊⠀⡠⠤⡀⢠⠀⠚⠀⠀⠀⠀⠀⡠⠊⢀⠤⡤⣔⠩⠼⡀
⠀⠀⢇⠀⠀⢀⡠⢔⣪⠠⠖⠇⡘⠀⠀⠀⢀⠄⠒⠉⢀⠔⠁⠀⣧⢞⠮⠭⠵⡀
⠀⠀⠘⠒⠉⣾⣀⣀⠀⣀⣀⠦⠗⠹⠙⠃⠁⠀⡠⠔⡡⠔⠒⠉⡨⢴⢹⣿⣏⡆
⠀⠀⠀⠀⡸⠉⠀⠀⠁⠀⠀⠀⠀⣇⡠⡄⡶⠯⠔⠈⠀⠀⡠⠊⠀⠀⡿⣿⣿⡇
⠀⠀⠀⢀⠇⠀⠀⠀⠀⢀⣀⠤⡤⠵⠊⢸⠀⡠⠤⠤⠐⠉⠀⠀⠀⠀⣷⣿⢿⡇
⠀⠀⢀⠃⠀⢀⣀⣀⣀⣠⣀⣀⣿⠉⠉⠉⠉⠀⠀
			)" << endl;
	}

	void delay(int milliseconds)
	{
		//Beep(220, 200);
		std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
	}

	int useMobSkill() override
	{
		cout << "[かみなりのこきゅう]-." << endl;
		delay(500);
		cout << mobName << "이(가) 1000만큼 회복합니다." << endl;
		cout << mobName << " 의 공격력이 30 증가합니다." << endl;
		delay(1000);

		cout << "[いちのかた]-." << endl;
		delay(500);
		cout << mobName << "의 명중률이 50 증가합니다." << endl;
		cout << mobName << "의 회피율이 0.3 증가합니다." << endl;
		delay(1000);

		cout << "[へきれきいっせん]-!!" << endl;
		cout << mobName << "이(가) 두 배의 데미지를 가합니다.\n" << endl;
		delay(1000);

		if (mobMaxHealth - mobHealth <= 20) // 회복
		{
			mobHealth = mobMaxHealth;
		}
		else
		{
			mobHealth += 1000;
		}

		mobAttack += 30;
		mobAccuracy += 50;
		mobEvasion += 0.3;
		return mobAttack * 2;
	}
};
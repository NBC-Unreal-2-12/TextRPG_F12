#pragma once
#include "Monster.h"

class BossMonster : public Monster
{
public:
	BossMonster() {};
	BossMonster(const std::string& name) // 만약 보스를 두 마리 이상 만들면 인자가 필요해 질 것.
		: Monster(name)
	{
	}

	int useMobSkill() override
	{
		return 0;
	};
};

class GGD : public BossMonster
{
public:
	GGD() : BossMonster("GGD")
	{
		mobName = "고길동";
		mobHealth = 20;
		mobAttack = 10;
		mobMana = 0;
		mobMaxMana = 3;
		mobAttackSpeed = 1;
		mobAccuracy = 50 + 20;
		mobEvasion = 1;
		loot = new MonsterLoot("가시고기의 갈비뼈", 20);
	}

	/* void mobFace()
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
	 }*/

	int useMobSkill() override
	{
		cout << mobName << "이(가) 20만큼 회복합니다." << endl;
		cout << mobName << " 의 공격력이 5 증가합니다." << endl;
		cout << mobName << "의 명중률이 50 증가합니다." << endl;
		cout << mobName << "의 회피율이 0.5 증가합니다." << endl;
		cout << mobName << "이(가) 두 배의 데미지를 가합니다." << endl;
		mobHealth += 20;
		mobAttack += 5;
		mobAccuracy += 50;
		mobEvasion += 0.5;
		return mobAttack * 2;
	}
};
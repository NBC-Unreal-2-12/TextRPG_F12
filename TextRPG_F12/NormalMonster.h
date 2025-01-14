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
	Slime() : NormalMonster("Slime")
	{
		mobName = "Slime";
		mobHealth = 20;
		mobAttack = 10;
		mobMana = 0;
		mobMaxMana = 3;
		mobAttackSpeed = 1;
		mobAccuracy = 50 + 20;
		mobEvasion = 1;
		loot.emplace_back(new MonsterLoot("슬라임 젤리", 20));
	}

	void mobFace() override
	{
		cout << R"(
                         ...            
                       !*=$=$.          
       :-,.           !=~..,~=*         
      ,;-.;.         ~$.     .*!        
      .:~,.-        ,~--       #        
      ,;;~~.       -::-,!      ~*       
       =!~,       ~~:~-, :     ;$       
       #~        ;-::~-,..!    ;=       
       *:     ,!:~::~-,,...;,  ;$       
        $, ,~!~-:::~--,,.   :-.:#       
        :#$~--~::~~---,..    .!#        
        .*--~::::~----,..     ,*        
        ;,;$$;::~-----,..      :.       
       ;,~,-@!::~---~@#,.       $       
       #-:#:$;::~---$-!$,..     :.      
      .~-:;=*;!;~---!.-:,...... ,-      
      -,-:;;;;*:;;--;@@;,........-      
      ,,-:;;;:*;*----,---,,.  ..,-      
       *-:;;;:**=---------,...,.--      
       $.~::;:!~~~---------,,,, #       
       .:--~::;.,~---------,-,.~~       
        ;-.-~::*;~~----------.,=        
         =,.~::;:~~~~-------.,#         
         .~!.-~:::::::::~~,-*~.         
           .*~::--~~~~~::~!:            
               .*@@@@@=~ 
		)" << endl;
	}

	int useMobSkill() override
	{
		cout << mobName << "이(가) 20만큼 회복합니다." << endl;
		mobHealth += 20;
		return mobAttack;
	}
};

class Orc : public NormalMonster
{
public:
	Orc() : NormalMonster("Orc")
	{
		mobName = "Orc";
		mobHealth = 20;
		mobAttack = 10;
		mobMana = 0;
		mobMaxMana = 3;
		mobAttackSpeed = 1;
		mobAccuracy = 50 + 20;
		mobEvasion = 1;
		loot.emplace_back(new MonsterLoot("오크의 부서진 검", 20));
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
		cout << mobName << "의 공격력이 5 증가합니다." << endl;
		mobAttack += 5;
		return mobAttack;
	}
};

class Goblin : public NormalMonster
{
public:
	Goblin() : NormalMonster("Goblin")
	{
		mobName = "Goblin";
		mobHealth = 20;
		mobAttack = 10;
		mobMana = 0;
		mobMaxMana = 3;
		mobAttackSpeed = 1;
		mobAccuracy = 50 + 20;
		mobEvasion = 1;
		loot.emplace_back(new MonsterLoot("고블린의 작은 동전", 20));
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


#ifndef MONSTERS_H
#define MONSTERS_H

#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "Inventory.h"
#include "Character.h"

using namespace std;

class Monster
{
public:
    Monster() {};

    Monster(const std::string& name) : name(name) { }

    string name;

    virtual ~Monster() = default;

    string getMobName() { return this->mobName; }

    int getMobHealth() { return this->mobHealth; }

    int getMobAttack() { return this->mobAttack; }

    int getMobMana() { return this->mobMana; }

    int getMobMaxMana() { return this->mobMaxMana; }

    int getMobAttackSpeed() { return this->mobAttackSpeed; }

    double getMobAccuracy() { return this->mobAccuracy; }

    double getMobEvasion() { return this->mobEvasion; }

    bool isMobDead() { return this->mobHealth <= 0; }

    virtual int useMobSkill() = 0;

    virtual void mobFace() = 0;

    int useMobAttack() // 몬스터가 공격할 때
    {
        if (mobMana < mobMaxMana) // mobMaxMana만큼 Attack
        {
            mobMana++; // 공격할 때 마다 마나++
            cout << "마나 : " << mobMana << " / " << mobMaxMana << endl;
            return mobAttack;
        }
        else
        {
            mobMana = 0; // 마나 초기화
            cout << "스킬 사용!" << endl;
            return useMobSkill();
        }
    }

    void takeMobDamage(int damage) // 몬스터가 공격 받을 때
    {
        this->mobHealth -= damage;
        if (this->mobHealth <= 0)
        {
            this->mobHealth = 0;
        }
        cout << this->mobName << " 이 " << damage << " 데미지 받음. 남은 체력 : " << this->mobHealth << endl;
        isMobDead();
    }

    void getMobInterface() //인터페이스 출력
    {
        mobFace();
        cout << "이름 : " << this->mobName << endl;
        cout << "체력 : " << this->mobHealth << endl;
        cout << "공격력 : " << this->mobAttack << endl;
        cout << "현재 마나 : " << this->mobMana << endl;
        cout << "최대 마나 : " << this->mobMaxMana << endl;
        cout << "속도 : " << this->mobAttackSpeed << endl;
        cout << "명중률 : " << this->mobAccuracy << endl;
        cout << "회피율 : " << this->mobEvasion << endl;
    }

    Item* dropItem(int idx)
    {
        return loot[idx%loot.size()];
    }

protected:
    string mobName = "Unknown";
    int mobHealth = 99;
    int mobAttack = 99;
    int mobAttackSpeed = 99;
    int mobMana = 99;
    int mobMaxMana = 99;
    double mobAccuracy = 99;
    double mobEvasion = 99;
    vector<Item*> loot;
};


//class Goblin : public Monster // 고블린
//{
//
//public:
//    Goblin()
//    {
//        mobName = "Goblin";
//        mobHealth = 20;
//        mobAttack = 10;
//        mobMana = 0;
//        mobMaxMana = 3;
//        mobAttackSpeed = 1;
//        mobAccuracy = 50 + 20;
//        mobEvasion = 1;
//        loot.emplace_back(MonsterLoot("고블린의 작은 동전", 20));
//    }
//
//    /*void mobFace() override
//    {
//            cout << R"(⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⢅⡀⠀⠀⡀⣔⢀⠀⡀⡄⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⢠⡹⣜⢦⢣⢳⢱⢱⢺⢤⡠⡠⡆⣆⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⢀⢠⡢⣟⣗⡧⣧⡣⢧⡳⣽⣳⢵⢕⣟⡧⡣⠀⠀⠀⠀⠀
//⠀⠀⢠⣺⠕⠉⠈⠺⡽⡮⣯⣪⢯⣗⣯⠳⡑⠈⢫⢮⡰⠀⠀⠀⠀
//⠀⣀⢷⠹⢀⢠⣰⢴⣻⣽⢮⣺⣺⣪⢖⠄⠀⠀⠘⣵⢫⠤⠀⠀⠀
//⠀⢗⠌⢃⢌⢧⢯⢯⣳⣝⡯⣯⡿⣽⢽⡗⢆⠀⢠⠺⢪⢯⡲⡢⡀
//⠀⠀⠀⢇⣗⢽⡍⠳⣷⡳⣫⢯⣟⢽⡱⡀⠀⠀⠈⡇⠈⡖⡵⠘⠀
//⠀⠀⠀⠀⠈⣳⣣⠀⡢⠫⠈⠫⠪⢷⢝⡦⡀⠀⠀⠀⠀⠃⠀⠀⠀
//⠀⠀⠀⢠⢰⢕⠯⠂⠀⠀⠀⠀⠀⠸⡱⡣⣏⣆⠀⠀⠀⠀⠀⠀⠀
//⠀⠰⣝⢞⠕⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⡜⣆⢀⠀⠀⠀⠀⠀
//⠀⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢯⢞⡳⣕⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠃⠈⠀⠁⠀⠀⠀
//            )" << endl;
//    }*/
//
//
//    int useMobSkill() override
//    {
//        cout << mobName << "이(가) 두 배의 데미지를 가합니다." << endl;
//        return mobAttack * 2;
//    }
//};

//class Orc : public Monster //오크
//{
//
//public:
//    Orc()
//    {
//        mobName = "Orc";
//        mobHealth = 20;
//        mobAttack = 10;
//        mobMana = 0;
//        mobMaxMana = 3;
//        mobAttackSpeed = 1;
//        mobAccuracy = 50 + 20;
//        mobEvasion = 1;
//        loot.emplace_back(MonsterLoot("오크의 부서진 검", 20));
//    }
//
//    /*void mobFace() override
//    {
//        cout << R"(
//⠀⠀⠀⠀⠀⠀⣿⣿⣄⡀⡀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⠀⣻⣿⣿⣿⣿⣿⣆⠀⠀
//⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣂⠀
//⠀⠀⠀⠀⠀⣸⣿⢿⣿⣿⣿⡌⠹⣿⡄
//⠀⠀⠀⠀⢠⣿⠇⣺⣿⣿⣿⣷⠄⢹⡯
//⠀⠀⠀⠀⢰⣿⣦⣿⣿⣿⣿⣿⣇⠴⣿
//⠀⠀⠀⢀⡾⠏⣰⣿⣿⠿⣿⣿⠻⠀⠉
//⠀⣀⣶⡿⠁⠀⣺⣿⡃⠈⣿⣿⠀⠀⠀
//⣼⣿⡿⠁⠀⠀⠺⣿⡇⠀⠹⣿⡇⠀⠀
//⠛⠋⠀⠀⠀⠀⢈⣿⡆⠀⠀⣻⡇⠀⠀
//⠀⠀⠀⠀⠀⠰⠿⠋⠃⠀⠀⣿⡿⠀⠀
//        )" << endl;
//    }*/
//
//    int useMobSkill() override
//    {
//        cout << mobName << "의 공격력이 5 증가합니다." << endl;
//        mobAttack += 5;
//        return mobAttack;
//    }
//};

//class Slime : public Monster // 슬라임
//{
//
//public:
//    Slime()
//    {
//        mobName = "Slime";
//        mobHealth = 20;
//        mobAttack = 10;
//        mobMana = 0;
//        mobMaxMana = 3;
//        mobAttackSpeed = 1;
//        mobAccuracy = 50 + 20;
//        mobEvasion = 1;
//        loot.emplace_back(MonsterLoot("슬라임 젤리", 20));
//    }
//
//    /*void mobFace() override
//    {
//            cout << R"(
//⠀⠀⠀⠀⠀⠀⠀⡠⠔⠦⣀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⣀⣾⠀⠀⠀⠈⡆⠀⠀⠀
//⠀⢀⣴⣶⣿⣿⣿⣷⣄⠀⠀⡆⠀⠀⠀
//⢰⣿⣿⣿⣿⣿⣿⣿⣿⣆⠐⠀⣀⡀⠀
//⠸⣿⣿⣿⣿⣿⣿⣿⣿⠗⠘⠤⠿⠗⠀
//⠀⠈⠉⠉⠛⠛⠉⠉⠁⠀⠀⠀⠀⠀⠀
//            )" << endl;
//    }*/
//
//    int useMobSkill() override
//    {
//        cout << mobName << "이(가) 20만큼 회복합니다." << endl;
//        mobHealth += 20;
//        return mobAttack;
//    }
//};



//class EliteGoblin : public Monster // 엘리트 고블린
//{
//
//public:
//    EliteGoblin()
//    {
//        mobName = "Elite Goblin";
//        mobHealth = 20;
//        mobAttack = 10;
//        mobMana = 0;
//        mobMaxMana = 3;
//        mobAttackSpeed = 1;
//        mobAccuracy = 50 + 20;
//        mobEvasion = 1;
//        loot = new MonsterLoot("고블린 대장의 반지", 20);
//    }
//
//    /*void mobFace() override
//    {
//        cout << R"(⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⢅⡀⠀⠀⡀⣔⢀⠀⡀⡄⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⢠⡹⣜⢦⢣⢳⢱⢱⢺⢤⡠⡠⡆⣆⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⢀⢠⡢⣟⣗⡧⣧⡣⢧⡳⣽⣳⢵⢕⣟⡧⡣⠀⠀⠀⠀⠀
//⠀⠀⢠⣺⠕⠉⠈⠺⡽⡮⣯⣪⢯⣗⣯⠳⡑⠈⢫⢮⡰⠀⠀⠀⠀
//⠀⣀⢷⠹⢀⢠⣰⢴⣻⣽⢮⣺⣺⣪⢖⠄⠀⠀⠘⣵⢫⠤⠀⠀⠀
//⠀⢗⠌⢃⢌⢧⢯⢯⣳⣝⡯⣯⡿⣽⢽⡗⢆⠀⢠⠺⢪⢯⡲⡢⡀
//⠀⠀⠀⢇⣗⢽⡍⠳⣷⡳⣫⢯⣟⢽⡱⡀⠀⠀⠈⡇⠈⡖⡵⠘⠀
//⠀⠀⠀⠀⠈⣳⣣⠀⡢⠫⠈⠫⠪⢷⢝⡦⡀⠀⠀⠀⠀⠃⠀⠀⠀
//⠀⠀⠀⢠⢰⢕⠯⠂⠀⠀⠀⠀⠀⠸⡱⡣⣏⣆⠀⠀⠀⠀⠀⠀⠀
//⠀⠰⣝⢞⠕⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⡜⣆⢀⠀⠀⠀⠀⠀
//⠀⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢯⢞⡳⣕⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠃⠈⠀⠁⠀⠀⠀
//        )" << endl;
//    }*/
//
//    int useMobSkill() override
//    {
//        cout << mobName << "이(가) 두 배의 데미지를 가합니다." << endl;
//        return mobAttack * 2;
//    }
//};

//class EliteOrc : public Monster // 엘리트 오크
//{
//
//public:
//    EliteOrc()
//    {
//        mobName = "Elite Orc";
//        mobHealth = 20;
//        mobAttack = 10;
//        mobMana = 0;
//        mobMaxMana = 3;
//        mobAttackSpeed = 1;
//        mobAccuracy = 50 + 20;
//        mobEvasion = 1;
//        loot = new MonsterLoot("오크 대왕의 검", 20);
//    }
//
//    /*void mobFace() override
//    {
//        cout << R"(
//⠀⠀⠀⠀⠀⠀⣿⣿⣄⡀⡀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⠀⣻⣿⣿⣿⣿⣿⣆⠀⠀
//⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣂⠀
//⠀⠀⠀⠀⠀⣸⣿⢿⣿⣿⣿⡌⠹⣿⡄
//⠀⠀⠀⠀⢠⣿⠇⣺⣿⣿⣿⣷⠄⢹⡯
//⠀⠀⠀⠀⢰⣿⣦⣿⣿⣿⣿⣿⣇⠴⣿
//⠀⠀⠀⢀⡾⠏⣰⣿⣿⠿⣿⣿⠻⠀⠉
//⠀⣀⣶⡿⠁⠀⣺⣿⡃⠈⣿⣿⠀⠀⠀
//⣼⣿⡿⠁⠀⠀⠺⣿⡇⠀⠹⣿⡇⠀⠀
//⠛⠋⠀⠀⠀⠀⢈⣿⡆⠀⠀⣻⡇⠀⠀
//⠀⠀⠀⠀⠀⠰⠿⠋⠃⠀⠀⣿⡿⠀⠀
//        )" << endl;
//    }*/
//
//    int useMobSkill() override
//    {
//        cout << mobName << "의 공격력이 5 증가합니다." << endl;
//        mobAttack += 5;
//        return mobAttack;
//    }
//};

//class EliteSlime : public Monster // 엘리트 슬라임
//{
//
//public:
//    EliteSlime()
//    {
//        mobName = "Elite Slime";
//        mobHealth = 20;
//        mobAttack = 10;
//        mobMana = 0;
//        mobMaxMana = 3;
//        mobAttackSpeed = 1;
//        mobAccuracy = 50 + 20;
//        mobEvasion = 1;
//        loot = new MonsterLoot("슬라임 왕관", 20);
//    }
//
//   /* void mobFace() override
//    {
//        cout << R"(
//⠀⠀⠀⠀⠀⠀⠀⡠⠔⠦⣀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⣀⣾⠀⠀⠀⠈⡆⠀⠀⠀
//⠀⢀⣴⣶⣿⣿⣿⣷⣄⠀⠀⡆⠀⠀⠀
//⢰⣿⣿⣿⣿⣿⣿⣿⣿⣆⠐⠀⣀⡀⠀
//⠸⣿⣿⣿⣿⣿⣿⣿⣿⠗⠘⠤⠿⠗⠀
//⠀⠈⠉⠉⠛⠛⠉⠉⠁⠀⠀⠀⠀⠀⠀
//            )" << endl;
//    }*/
//
//    int useMobSkill() override
//    {
//        cout << mobName << "이(가) 20만큼 회복합니다." << endl;
//        mobHealth += 20;
//        return mobAttack;
//    }
//};

//class Dragon : public Monster // 드래곤
//{
//
//public:
//    Dragon()
//    {
//        mobName = "Dragon";
//        mobHealth = 20;
//        mobAttack = 10;
//        mobMana = 0;
//        mobMaxMana = 3;
//        mobAttackSpeed = 1;
//        mobAccuracy = 50 + 20;
//        mobEvasion = 1;
//        loot = new MonsterLoot("드래곤의 비늘", 20);
//    }
//
//    /*void mobFace() override
//    {
//            cout << R"(
//⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⣠⣠⣤⣄⠀⠈⣿⣿⣦⣄⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⣼⡿⠋⢉⣿⠀⢀⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀
//⠀⠀⠝⠀⢠⣾⣿⣠⣾⣿⣿⣿⣿⣿⣿⡀⠀⠀⠀⠀
//⠀⠀⠀⠀⣾⣿⣿⣿⣟⠛⢽⠟⠫⣿⣿⡆⠀⠀⠀⠀
//⠀⠀⠀⠀⠘⣿⢿⣿⣿⣷⣆⠀⠀⠉⠉⠇⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⣸⠽⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⣴⠃⠀⣹⣻⡾⠿⣿⣶⣿⠟⠒⠢⠀⠀⠀
//⠀⠀⠀⠀⠁⠀⠀⠀⠀⠈⠀⠀⠈⠀⠀⠀⠀⠈⠁⠀
//            )" << endl;
//    }*/
//
//    int useMobSkill() override
//    {
//        cout << mobName << "이(가) 두 배의 데미지를 가합니다." << endl;
//        return mobAttack * 2;
//    }
//};

//class Balrog : public Monster // 발록
//{
//
//public:
//    Balrog()
//    {
//        mobName = "Balrog";
//        mobHealth = 20;
//        mobAttack = 10;
//        mobMana = 0;
//        mobMaxMana = 3;
//        mobAttackSpeed = 1;
//        mobAccuracy = 50 + 20;
//        mobEvasion = 1;
//        loot = new MonsterLoot("발록의 재", 20);
//    }
//
//   /* void mobFace()
//    {
//            cout << R"(
//⠀⠀⠀⠀⠀⢰⡄⠀⠀⠀⠀⠀⠀⢴⠀⠀⠀⠀⠀⠀
//⠀ ⠀⠀ ⣾⣝⠀⠀ ⠀⠀ ⣿⣣⡀⠀     
//⠀⠀ ⠀⣺⣽⣻⣄⣀⣡⢤⣰⣺⣟⣿⣳⡄⠀⠀⠀
//   ⠀⣸⣟⢷⢫⢕⢟⡾⡿⣽⢞⡽⣽⣷⢿⡄⠀
//   ⠀⣿⢾⣻⢔⡕⡽⡪⡹⢽⣳⢿⣻⣽⣟⣷⠀⠀
//⠀⠀⢀⢻⣳⣽⢝⣪⢧⡱⣨⣟⣮⣫⢾⡿⣟⣿⠅⠀
//⠀⠙⢭⢧⢳⡹⠀⢈⣨⣟⡵⣧⢮⡳⡕⠇⠈⠻⠁⠀
// ⠀⠀⠀⠀⠀⠐⢽⣺⣏⠙⠱⣯⣗⠀⠀⠀⠀ ⠀
//       ⠀⢀⣤⣮⡏⠀⢠⢿⣦⠀⠀ ⠀⠀⠀
//            )" << endl;
//    }*/
//
//    int useMobSkill() override
//    {
//        cout << mobName << "의 공격력이 5 증가합니다." << endl;
//        mobAttack += 5;
//        return mobAttack;
//    }
//};

//class Kraken : public Monster // 크라켄
//{
//
//public:
//    Kraken()
//    {
//        mobName = "Kraken";
//        mobHealth = 20;
//        mobAttack = 10;
//        mobMana = 0;
//        mobMaxMana = 3;
//        mobAttackSpeed = 1;
//        mobAccuracy = 50 + 20;
//        mobEvasion = 1;
//        loot = new MonsterLoot("크라켄의 심장", 20);
//    }
//
//    /*void mobFace()
//    {
//            cout << R"(⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⣤⣄⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⡀⠀⣾⣿⣿⣿⣿⣷⠀⠀⡀⠀⠀⠀⠀
//⠀⠀⠀⠀⠍⣹⢆⢿⣿⣿⣿⣿⡿⡰⣏⠩⠀⠀⠀⠀
//⠀⠀⠀⠀⣰⡏⣼⢨⢿⣿⣿⡿⡅⣇⢹⣦⠀⠀⠀⠀
//⠀⠀⠀⠀⣿⣧⣛⣶⣷⣿⣿⣾⣶⣛⣼⣿⠀⠀⠀⠀
//⠀⠀⠀⠀⣼⡿⠾⣪⣾⡿⢿⣷⣕⠷⢿⣧⠀⠀⠀⠀
//⠀⠀⠀⠀⠻⠿⢹⣿⠉⢲⡖⠉⣿⡏⠿⠟⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⠀⠈⠛⠛⠁⠈⠛⠛⠁⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//        )" << endl;
//    }*/
//
//    int useMobSkill() override
//    {
//        cout << mobName << "이(가) 20만큼 회복합니다." << endl;
//        mobHealth += 20;
//        return mobAttack;
//    }
//};

//class GGD : public Monster // 보스
//{
//
//public:
//    GGD()
//    {
//        mobName = "고길동";
//        mobHealth = 20;
//        mobAttack = 10;
//        mobMana = 0;
//        mobMaxMana = 3;
//        mobAttackSpeed = 1;
//        mobAccuracy = 50 + 20;
//        mobEvasion = 1;
//        loot = new MonsterLoot("가시고기의 갈비뼈", 20);
//    }
//
//   /* void mobFace()
//    {
//            cout << R"(
//⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⢷⣷⣣⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⢏⣿⣿⡵⡀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⣠⣮⣷⣿⣿⣿⣿⣷⣄⣄⠀⠀⠀⠀⠈⢞⣿⣿⡵⡀⠀⠀⠀⠀⠀
// ⠀⠀⡠⣿⣿⣿⣿⣿⣿⣿⣿⣧⣏⢦⣤⡀⠀⠀⠀⠫⣻⣿⣾⢄⠀⠀⠀
// ⠀⣔⣿⣿⣿⣿⣿⠿⣿⠻⢟⣿⣿⣿⣿⣿⡆⠀⠀⠀⠑⡿⣿⣯⢆⠀⠀
// ⢰⣸⢿⣻⢟⠃⠉⠉⠀⡠⠤⠸⣸⣿⣿⣿⡳⠁⠀⠀⠀⠀⡨⠺⠿⠇⢓⡄
// ⠧⠊⠁⠘⣖⣳⠠⣶⣋⡹⠁⠀⠛⣩⢻⠋⠀⠀⠀⠀⠀⢀⠇⠀⠀⠀⠀⢾⠀
//⠀⠀⢠⠂⠁⠓⠒⠊⠀⡠⠤⡀⢠⠀⠚⠀⠀⠀⠀⠀⡠⠊⢀⠤⡤⣔⠩⠼⡀
//⠀⠀⢇⠀⠀⢀⡠⢔⣪⠠⠖⠇⡘⠀⠀⠀⢀⠄⠒⠉⢀⠔⠁⠀⣧⢞⠮⠭⠵⡀
//⠀⠀⠘⠒⠉⣾⣀⣀⠀⣀⣀⠦⠗⠹⠙⠃⠁⠀⡠⠔⡡⠔⠒⠉⡨⢴⢹⣿⣏⡆
//⠀⠀⠀⠀⡸⠉⠀⠀⠁⠀⠀⠀⠀⣇⡠⡄⡶⠯⠔⠈⠀⠀⡠⠊⠀⠀⡿⣿⣿⡇
//⠀⠀⠀⢀⠇⠀⠀⠀⠀⢀⣀⠤⡤⠵⠊⢸⠀⡠⠤⠤⠐⠉⠀⠀⠀⠀⣷⣿⢿⡇
//⠀⠀⢀⠃⠀⢀⣀⣀⣀⣠⣀⣀⣿⠉⠉⠉⠉⠀⠀
//            )" << endl;
//    }*/
//
//    int useMobSkill() override
//    {
//        cout << mobName << "이(가) 20만큼 회복합니다." << endl;
//        cout << mobName << " 의 공격력이 5 증가합니다." << endl;
//        cout << mobName << "의 명중률이 50 증가합니다." << endl;
//        cout << mobName << "의 회피율이 0.5 증가합니다." << endl;
//        cout << mobName << "이(가) 두 배의 데미지를 가합니다." << endl;
//        mobHealth += 20;
//        mobAttack += 5;
//        mobAccuracy += 50;
//        mobEvasion += 0.5;
//        return mobAttack * 2;
//    }
//};

#endif // MONSTERS_H
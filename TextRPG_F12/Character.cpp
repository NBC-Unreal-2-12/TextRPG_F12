#include "Character.h"
#include <iostream>
#include <string>
#include "GameManager.h"

using namespace std;

Character* Character::instance = nullptr;

Character::Character(string userName, Job* characterJob) :
	name(userName), job(characterJob), level(1), maxHealth(200), health(200), attack(30),
	experience(0), gold(0), accuracy(100), attackSpeed(5), evasion(1), isDead(false), mp(100), maxMp(100), maxExperience(200)
{
	characterJob->applyJobEffect(attack, maxHealth, attackSpeed, evasion, accuracy, maxMp);
	health = maxHealth;
	mp = maxMp;
}

void Character::initialize(string userName, Job* characterJob)
{
	if (instance == nullptr) {
		instance = new Character(userName, characterJob);
	}
	else {
		cout << "Character instance is already initialized!" << endl;
	}
}

Character* Character::getInstance()
{
	if (instance == nullptr) {
		cout << "Error: Character instance is not initialized. Call initialize() first." << endl;
		return nullptr;
	}
	return instance;
}


void Character::displayStatus()
{
	cout << "\nㅡㅡㅡㅡㅡㅡㅡㅡㅡ ౨ৎ ㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
	cout << "이름: " << name << endl;
	cout << "직업: " << job->getJobName() << endl;
	switch (job->getJobIndex())
	{
	case 0:
		cout << R"(
         ⠀⠀⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠈⢧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠘⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠈⢿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠫⡷⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⠘⠄⢢⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⠀⠈⢔⠳⡀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠢⠈⢆⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⠌⣓⠖⠂⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠋⠈⢢⡀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠱⡀⠀
         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⠀
             )" << endl;
		break;
	case 1:
		cout << R"(
         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⡀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢳⢆⠀⢘⡆⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡌⣤⠚⠄⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠋⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⠀⣰⠃⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⡜⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⡜⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⡞⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⢀⠞⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠌⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
             )" << endl;
		break;
	case 2:
		cout << R"(
         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠴⠒⠒⠋⠋⠛⠉⠀⠀⠀
         ⠀⠀⠁⠄⠀⠀⠀⠀⠀⠀⠀⠠⡼⠊⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠈⠠⠀⠀⠀⠀⣖⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⠁⣖⡺⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠀⣰⡛⠉⠐⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠠⣷⠃⠀⠀⠀⠐⠠⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⣸⠁⠀⠀⠀⠀⠀⠀⠈⠐⠄⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⢈⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠂⣀⡀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⢈⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢿⡻⣄⠀⠀
         ⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠂⠀⠁⠀⠀⠀⠀⠉⠉⠀⠀
         ⠀⠀⠀⠀⠀⠀⢹⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
         ⠀⠀⠀⠀⠀⠀⠰⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
             )" << endl;
		break;

	default:
		break;
	}
	cout << "레벨: " << level << endl;
	cout << "체력: " << health << " / " << maxHealth << endl;
	cout << "마나: " << mp << " / " << maxMp << endl;
	cout << "경험치: " << round(experience) << " / " << round(maxExperience) << endl;
	cout << "공격력: " << attack << endl;
	cout << "공격속도: " << attackSpeed << endl;
	cout << "명중률: " << accuracy << endl;
	cout << "회피율: " << evasion << endl;
	cout << "보유골드: " << gold << endl;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡ ౨ৎ ㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
}

void Character::levelUp()
{
	level++;
	maxHealth += job->getHealthGrowth();
	health += job->getHealthGrowth();
	maxMp += job->getManaGrowth();
	mp += job->getManaGrowth();
	attack += job->getAttackGrowth();
	evasion += job->getEvasionGrowth();
	accuracy += job->getAccuracyGrowth();
	cout << "레벨업! " << name << " 의 레벨이 " << level << "이 되었습니다!" << endl;

	if (level == 5)     // 레벨 5일때 스킬 추가
	{
		switch (job->getJobIndex()) {
		case 0:     // 전사일 경우
			job->addSkill(make_unique<SwordDance>());     // 방어 태세 스킬 추가
			cout << "레벨이 5가 되어 " << job->getSkillName(2) << "를 배웠습니다!" << endl;
			break;
		case 1:     // 마법사일 경우
			job->addSkill(make_unique<HeavenlyLight>());     // 얼음 방패 스킬 추가
			cout << "레벨이 5가 되어 " << job->getSkillName(2) << "를 배웠습니다!" << endl;
			break;
		case 2:     // 궁수일 경우
			job->addSkill(make_unique<PreciseShot>());     // 정밀 사격 스킬 추가
			cout << "레벨이 5가 되어 " << job->getSkillName(2) << "를 배웠습니다!" << endl;
		}
	}
}

void Character::doLevelUp()
{

	while (experience >= maxExperience)
	{
		experience -= maxExperience;
		maxExperience = maxExperience * 1.45;
		levelUp();
	}
}

// 캐릭터 인벤토리 관련 메서드
void Character::useItemFromInventory(int index)
{
	Inventory::getInstance()->useItem(index, this);
}

void Character::addItemToInventory(Item* item)
{
	Inventory::getInstance()->addItem(item);
}

void Character::sellItemFromInventory(int index)
{
	Inventory::getInstance()->sellItem(index);
}

void Character::displayInventory()
{
	Inventory::getInstance()->listItem();
}

int Character::displaySkillList(double playerAttack)
{
	job->displaySkills(playerAttack);
	const vector<unique_ptr<Skill>>& skills = job->getSkills(); // Job에서 스킬 목록 가져오기
	return skills.size();
}

Item* Character::findItemFromInventory(int index)
{
	return Inventory::getInstance()->findItem(index);
}

bool Character::isInventoryEmpty()
{
	if (Inventory::getInstance()->isInventoryEmpty())
	{
		return true;
	}

	return false;
}


// 추가

int Character::getGold()
{
	return gold;
}

void Character::setGold(int sellPrice)
{
	gold += sellPrice;
	
}
int Character::getExp()
{
	return round(experience);
}
int Character::getMaxExp()
{
	return round(maxExperience);
}
void Character::addExp(int set_exp)
{
	experience += set_exp;
}
bool Character::isCharacterDead()
{
	return isDead;
}
void Character::setCharacterDead(bool dead) {
	vector<Item*> item = Inventory::getInstance()->getInventory();
	auto it = find_if(item.begin(), item.end(), [](Item* i) { return dynamic_cast<ReviveItem*>(i) != nullptr; }); // 죽기 전 ReviveItem 찾기
	if (it != item.end()) {
		item.erase(it);
		health += 50;
	}
	else { // 없을 시 isDead = true;
		isDead = true;
	}
}

int Character::getHealth()
{
	return health;
}
void Character::setHealth(int set_health)
{
	if (set_health > maxHealth)
	{
		health = maxHealth;
	}
	else
	{
		health = set_health;
	}

}
int Character::getMaxHealth()
{
	return maxHealth;
}
int Character::getMP()
{
	return mp;
}
void Character::setMP(int set_mp)
{
	if (set_mp > maxMp)
	{
		mp = maxMp;
	}
	else
	{
		mp = set_mp;
	}
}
int Character::getMaxMP()
{
	return maxMp;
}
void Character::setMaxMP(int set_maxMp)
{
	maxMp = set_maxMp;
}
double Character::getAttack()
{
	return attack;
}
void Character::setAttack(int set_attack)
{
	attack = set_attack;
}
int Character::getAttackSpeed()
{
	return attackSpeed;
}

void Character::setAttackSpeed(int set_attackSpeed)
{
	attackSpeed = set_attackSpeed;
}

double Character::getAccuracy()
{
	return accuracy;
}

void Character::setAccuracy(double set_accuracy)
{
	accuracy = set_accuracy;
}

double Character::getEvasion()
{
	return evasion;
}

void Character::setEvation(double set_evasion)
{
	evasion = set_evasion;
}

void Character::receiveDamage(int damage)
{
	health -= damage;
	if (health <= 0)
	{
		health = 0;
		isDead = true;
	}
	cout << name << "이(가) " << damage << "의 데미지를 입었습니다. 남은 체력: " << health << endl;
}

void Character::useNormalSkill(Monster* target, int skillIndex)
{

	const vector<unique_ptr<Skill>>& skills = job->getSkills(); // Job에서 스킬 목록 가져오기

	// 선택된 스킬 가져오기
	const Skill* skill = job->getSkill(skillIndex); // getSkill() 메서드로 선택된 스킬 가져오기

	if (skill == nullptr) {
		cout << "잘못된 스킬 선택입니다." << endl;
		return;
	}

	// 스킬의 데미지 배율 가져오기
	double damageFactor = skill->getDamageFactor();

	// 데미지 계산 (기본 공격력을 스킬의 데미지 배율로 곱함)
	int damage = static_cast<int>(attack * damageFactor);

	// MP 소모
	useMP(skill->getManaCost());

	// 몬스터에게 데미지 적용
	target->takeMobDamage(damage);

	// 출력
	setColor(1);
	cout << "\n" << name << "이(가) " << skill->getSkillName() << "을(를) 사용했습니다!\n";
	cout << target->getMobName() << "에게 " << damage << "의 데미지를 입혔습니다!\n";
	setColor(7);
}

void Character::useAreaSkill(std::vector<std::unique_ptr<Monster>>& monsters, int skillIndex)
{
	const vector<unique_ptr<Skill>>& skills = job->getSkills(); // Job에서 스킬 목록 가져오기

	// 선택된 스킬 가져오기
	const Skill* skill = job->getSkill(skillIndex); // getSkill() 메서드로 선택된 스킬 가져오기

	if (skill == nullptr) {
		cout << "잘못된 스킬 선택입니다." << endl;
		return;
	}

	// 스킬의 데미지 배율 가져오기
	double damageFactor = skill->getDamageFactor();

	// 데미지 계산 (기본 공격력을 스킬의 데미지 배율로 곱함)
	int damage = static_cast<int>(attack * damageFactor);

	// MP 소모
	useMP(skill->getManaCost());

	// 광역기일 경우 모든 몬스터에게 데미지 적용
	for (auto& monster : monsters) {
		// 몬스터에게 데미지 적용
		monster->takeMobDamage(damage);

		// 출력
		setColor(1);
		cout << "\n" << name << "이(가) " << skill->getSkillName() << "을(를) 사용했습니다!\n";
		cout << monster->getMobName() << "에게 " << damage << "의 데미지를 입혔습니다!\n";

		// 몬스터가 죽었는지 확인
		if (monster->isMobDead()) {
			cout << monster->getMobName() << "이(가) 쓰러졌습니다!\n";
		}

		delay(500);
	}
}

void Character::useMP(int cost)
{
	mp -= cost;
	if (mp < 0) mp = 0;
}

string Character::getSkillName(size_t index)
{
	return job->getSkillName(index);
}



int Character::getManaCost(size_t index)
{
	return job->getManaCost(index);
}

string Character::getSkillTypeName(size_t index)
{
	return job->getSkillTypeName(index);
}

SkillType Character::getSkillType(size_t index)
{
	return job->getSkillType(index);
}

double Character::getDamageFactor(size_t index)
{
	return job->getDamageFactor(index);
}

string Character::getName()
{
	return name;
}

// 글자색 설정
void Character::setColor(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}
﻿#pragma once

#include <memory>

#include "Monster.h"
#include "NormalMonster.h"
#include "EliteMonster.h"
#include "SpecialMonster.h"
#include "BossMonster.h"

class MonsterFactory
{
public:
	std::unique_ptr<Monster> createMonster(int round);

};


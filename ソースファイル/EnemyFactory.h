#pragma once
#include <memory>
#include "Enemy.h"

class EnemyFactory
{
public:
	static std::unique_ptr<Enemy>CreateEnemy(EnemyType type);
};


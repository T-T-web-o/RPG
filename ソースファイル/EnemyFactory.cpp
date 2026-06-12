#include "EnemyFactory.h"

std::unique_ptr<Enemy> EnemyFactory::CreateEnemy(EnemyType type)
{
    auto enemy = std::make_unique<Enemy>();

    enemy->Init(type);

    return enemy;
}

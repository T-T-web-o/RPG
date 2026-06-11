#include "Enemy.h"
#include "DxLib.h"

Enemy::Enemy()
{
	x = 1300;
	y = 540;

	hp = 0;
	attack = 0;
	defense = 0;
	attackRange = 0;

	isDead = false;
	enemyHandle = LoadGraph(TEXT("Resource/Model/Enemy1.png"));
}

Enemy::~Enemy()
{
	DeleteGraph(enemyHandle);
}

void Enemy::Init(EnemyType type)
{
	this->type = type;

	switch (type)
	{
	case BLUE_SLIME:
		hp = 30;
		attack = 10;
		defense = 0;
		attackRange = 240;
		break;

	case GREEN_SLIME:
		hp = 40;
		attack = 10;
		defense = 0;
		attackRange = 240;
		break;
	}
}

void Enemy::Update()
{
	x -= 3;
}

void Enemy::Draw()
{
	if (isDead)
	{
		return;
	}

	DrawExtendGraph(
		x,
		y,
		x + 100,
		y + 100,
		enemyHandle,
		TRUE
	);
}

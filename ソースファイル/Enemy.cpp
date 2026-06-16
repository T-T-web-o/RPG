#include "Enemy.h"
#include "DxLib.h"

int Enemy::enemyHandle = -1;

Enemy::Enemy()
{
	type = ENEMY_NONE;

	x = 1300;
	y = 540;

	hp = 0;
	maxHp = 0;
	attack = 0;
	defense = 0;
	attackRange = 0;

	isDead = false;

	// 敵画像を未読み込みの場合のみロード
	if (Enemy::enemyHandle == -1)
	{
		Enemy::enemyHandle =LoadGraph(TEXT("Resource/Model/Enemy1.png"));
	}
}

Enemy::~Enemy()
{
}

void Enemy::Init(EnemyType type)
{
	this->type = type;

	switch (type)
	{
	case BLUE_SLIME:
		hp = 30;
		maxHp = 30;
		attack = 10;
		defense = 0;
		attackRange = 240;
		break;

	case GREEN_SLIME:
		hp = 40;
		maxHp = 40;
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

	int w = 100;
	int h = 100;

	DrawExtendGraph(
		x,
		y,
		x + w,
		y + h,
		enemyHandle,
		TRUE
	);

	// HPバー表示
	int hpWidth = hp * 100 / maxHp;
	// 枠
	DrawBox(x, y - 20, x + 100, y-10,
		GetColor(255, 255, 255), FALSE);

	// HP
	DrawBox(x, y-20, x + hpWidth, y-10, GetColor(0, 255, 0), TRUE);
}

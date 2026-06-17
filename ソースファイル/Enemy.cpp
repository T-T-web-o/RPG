#include "Enemy.h"
#include "DxLib.h"

int Enemy::blueSlimeHandle = -1;

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

	rewardGold = 0;

	isDead = false;

	// 敵画像を未読み込みの場合のみロード
	if (Enemy::blueSlimeHandle == -1)
	{
		Enemy::blueSlimeHandle =LoadGraph(TEXT("Resource/Model/Enemy1.png"));
	}

	blueSlimeBossHandle = LoadGraph(TEXT("Resource/Model/Boss1.png"));
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
		rewardGold = 10;
		break;

	case GREEN_SLIME:
		hp = 40;
		maxHp = 40;
		attack = 10;
		defense = 0;
		attackRange = 240;
		rewardGold = 20;
		break;

	case BLUE_SLIME_BOSS:
		hp = 100;
		maxHp = 100;
		attack = 15;
		defense = 0;
		attackRange = 240;
		rewardGold = 100;
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

	

	if (type == BLUE_SLIME)
	{
		DrawExtendGraph(
			x,
			y,
			x + w,
			y + h,
			blueSlimeHandle,
			TRUE);
	}
	else if (type == BLUE_SLIME_BOSS)
	{
		DrawExtendGraph(
			x,
			y,
			x + w,
			y + h,
			blueSlimeBossHandle,
			TRUE);
	}

	// HPバー表示
	int hpWidth = hp * 100 / maxHp;
	// 枠
	DrawBox(x, y - 20, x + 100, y-10,
		GetColor(255, 255, 255), FALSE);

	// HP
	DrawBox(x, y-20, x + hpWidth, y-10, GetColor(0, 255, 0), TRUE);
}

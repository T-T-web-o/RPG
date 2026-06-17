#pragma once

// 敵の種類
enum EnemyType
{
	ENEMY_NONE,
	BLUE_SLIME,
	GREEN_SLIME,
	BLUE_SLIME_BOSS
};

class Enemy
{
public:
	// 座標
	int x, y;

	EnemyType type;

	// ステータス
	int hp;
	int maxHp;
	int attack;
	int defense;
	int attackRange;

	// 獲得金額
	int rewardGold;

	void Init(EnemyType type);

	// 青スライム
	static int blueSlimeHandle;

	// 青スライムボス
	int blueSlimeBossHandle;

	bool isDead;
	Enemy();
	~Enemy();

	void Update();
	void Draw();
};


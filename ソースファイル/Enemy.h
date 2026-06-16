#pragma once

// 敵の種類
enum EnemyType
{
	ENEMY_NONE,
	BLUE_SLIME,
	GREEN_SLIME
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

	static int enemyHandle;

	bool isDead;
	Enemy();
	~Enemy();

	void Update();
	void Draw();
};


#pragma once

// “G‚Ìí—Ş
enum EnemyType
{
	ENEMY_NONE,
	BLUE_SLIME,
	GREEN_SLIME
};

class Enemy
{
public:
	// À•W
	int x, y;

	EnemyType type;

	int hp;
	int attack;
	int defense;
	int attackRange;

	void Init(EnemyType type);

	int enemyHandle;

	bool isDead;
	Enemy();
	~Enemy();

	void Update();
	void Draw();
};


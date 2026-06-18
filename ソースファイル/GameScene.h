#pragma once
#include "Scene.h"
#include "Character.h"
#include "Enemy.h"
#include "Rune.h"
#include <vector>
#include <memory>

// 獲得ゴールド表示用
struct GoldText
{
	int x;
	int y;
	int value;
	int timer;
};

class GameScene:public Scene
{
private:

	std::vector<std::unique_ptr<Enemy>> enemies;

	std::vector<GoldText>goldTexts;

	int bgHandle;

	// 背景のX座標
	int bgX;
	
	// マウスの座標XY
	int mouseX, mouseY;

	bool playerEncount;
	bool enemyEncount;

	// 攻撃
	int attackTimer;
	int enemyAttackTimer;

	// GameOver
	bool isGameOver;
	int gameOverTimer;
	int youDiedHandle;

	Enemy* targetEnemy;
	int minDistance;

	// 敵の生きている数
	int aliveCount;

	// 回復時間
	int healTimer;

	// wave処理
	int wave;
	
	// ボススポーンフラグ
	bool bossSpawned;

	// ステージ
	int world;
	int stage;

	int runeHandle;

	int runeX;
	int runeY;
public:
	GameScene();
	~GameScene();

	void SpawnEnemies();

	void Update()override;
	void Draw()override;
};


#pragma once
#include "Scene.h"
#include "Character.h"
#include "Enemy.h"
#include <vector>
#include <memory>

class GameScene:public Scene
{
private:

	std::vector<std::unique_ptr<Enemy>> enemies;

	int bgHandle;

	// ”wŒi‚ÌXÀ•W
	int bgX;

	Character player;

	bool playerEncount;
	bool enemyEncount;

	// UŒ‚
	int attackTimer;
	int enemyAttackTimer;

	// GameOver
	bool isGameOver;
	int gameOverTimer;
	int youDiedHandle;

	Enemy* targetEnemy;
	int minDistance;

public:
	GameScene(CharacterType type);
	~GameScene();
	void Update()override;
	void Draw()override;
};


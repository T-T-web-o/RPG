#include "GameScene.h"
#include <cmath>
#include "DxLib.h"

GameScene::GameScene(CharacterType type)
{
	player.Init(type);

	attackTimer = 0;

	enemyAttackTimer = 0;

	playerEncount = false;
	
	enemyEncount = false;

	// îwåiâÊëú
	bgHandle = LoadGraph(TEXT("Resource/Model/background.png"));

	bgX = 0;

	for (int i = 0; i < 5; i++)
	{
		auto enemy = std::make_unique<Enemy>();
		enemy->Init(BLUE_SLIME);

		enemy->x = 1000 + i * 300;
		enemy->y = 540;

		enemies.push_back(std::move(enemy));
	}
}

GameScene::~GameScene()
{
	DeleteGraph(bgHandle);
}

void GameScene::Update()
{
	targetEnemy = nullptr;
	minDistance = 999999;

	if (!playerEncount)
	{
		bgX -= 2;
		if (bgX <= -1280)
		{
			bgX = 0;
		}
	}
	
	// ÉvÉåÉCÉÑÅ[çXêV
	player.Update();

	// ìGçXêV
	for (auto& enemy : enemies)
	{
		if (enemy->isDead)
		{
			continue;
		}

		if (!enemyEncount)
		{
			enemy->Update();
		}

		// ìGÇ∆ÇÃãóó£ÇÇÕÇ©ÇÈ
		distance = abs(enemy->x - player.x);

		if (distance < minDistance)
		{
			minDistance = distance;
			targetEnemy = enemy.get();
		}
	}
	
	if (targetEnemy != nullptr)
	{
		playerEncount = (!targetEnemy->isDead && minDistance <= player.attackRange);
		enemyEncount = (minDistance <= targetEnemy->attackRange);
		// çUåÇîÕàÕÇ…óàÇΩÇÁçUåÇ
		if (playerEncount)
		{
			attackTimer++;

			if (attackTimer >= 30)
			{
				targetEnemy->hp -= player.attack;
				attackTimer = 0;
			}
		}

		// ìGÇÃçUåÇ
		if (minDistance <= targetEnemy->attackRange)
		{
			enemyAttackTimer++;

			if (enemyAttackTimer >= 60)
			{
				player.hp -= targetEnemy->attack;
				enemyAttackTimer = 0;
			}
		}

		// ìGÇÃHPÇ™0Ç…Ç»Ç¡ÇΩÇÁè¡ãé
		if (targetEnemy->hp <= 0)
		{
			targetEnemy->isDead = true;
		}
		if (player.hp <= 0)
		{

		}
	}
	else
	{
		playerEncount = false;
	}

	if (playerEncount)
	{
		player.isAttack = true;
	}
	else
	{
		player.isAttack = false;
	}
}

void GameScene::Draw()
{
	// îwåiÇï`âÊ
	DrawExtendGraph(bgX, 0, bgX + 1280, 770, bgHandle, TRUE);

	DrawExtendGraph(bgX + 1280, 0, bgX + 2560, 770, bgHandle, TRUE);

	player.Draw();

	for (auto& enemy : enemies)
	{
		if (!enemy->isDead)
		{
			enemy->Draw();
		}
	}

	int hpWidth = player.hp * 150 / player.maxHp;
	// òg
	DrawBox(250, 400, 400, 420,
		GetColor(255, 255, 255), FALSE);

	// HP
	DrawBox(250, 400, 250 + hpWidth, 420, GetColor(0, 255, 0), TRUE);
}

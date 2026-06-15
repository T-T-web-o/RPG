#include "GameScene.h"
#include "EnemyFactory.h"
#include "GameManager.h"
#include <cmath>
#include "DxLib.h"
#include <limits>


GameScene::GameScene(CharacterType type)
{
	player.Init(type);

	attackTimer = 0;

	enemyAttackTimer = 0;

	playerEncount = false;
	
	enemyEncount = false;

	isGameOver = false;

	gameOverTimer = 0;

	// ”wŒi‰æ‘œ
	bgHandle = LoadGraph(TEXT("Resource/Model/background.png"));

	// GameOver‰æ‘œ
	youDiedHandle = LoadGraph(TEXT("Resource/Model/YOUDIED.png"));

	bgX = 0;

	for (int i = 0; i < 5; i++)
	{
		auto enemy = EnemyFactory::CreateEnemy(BLUE_SLIME);

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
	minDistance = INT_MAX;

	if (!playerEncount)
	{
		bgX -= 2;
		if (bgX <= -1280)
		{
			bgX = 0;
		}
	}
	
	// ƒvƒŒƒCƒ„[XV
	player.Update();

	// “GXV
	for (auto& enemy : enemies)
	{
		if (enemy->isDead)
		{
			continue;
		}

		int distance = abs(enemy->x - player.x);

		// UŒ‚”ÍˆÍŠO‚È‚ç‘Oi
		if (distance > enemy->attackRange)
		{
			enemy->Update();
		}

		// ˆê”Ô‹ß‚¢“G‚ð’T‚·
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
		// UŒ‚”ÍˆÍ‚É—ˆ‚½‚çUŒ‚
		if (playerEncount)
		{
			attackTimer++;

			if (attackTimer >= 30)
			{
				targetEnemy->hp -= player.attack;
				if (targetEnemy->hp < 0)
				{
					targetEnemy->hp = 0;
				}
				attackTimer = 0;
			}
		}

		// “G‚ÌUŒ‚
		if (enemyEncount)
		{
			enemyAttackTimer++;

			if (enemyAttackTimer >= 60)
			{
				player.hp -= targetEnemy->attack;
				if (player.hp <= 0)
				{
					isGameOver = true;
				}
				enemyAttackTimer = 0;
			}
		}

		// “G‚ÌHP‚ª0‚É‚È‚Á‚½‚çÁ‹Ž
		if (targetEnemy->hp <= 0)
		{
			targetEnemy->isDead = true;
		}
	}
	else
	{
		playerEncount = false;
		enemyEncount = false;
	}

	// GameOver
	if (isGameOver)
	{
		gameOverTimer++;

		if (gameOverTimer >= 180)
		{
			GameManager::GetInstance().ChangeScene(std::make_unique<GameScene>(player.type));
		}
	}

	player.isAttack = playerEncount;
}

void GameScene::Draw()
{
	// ”wŒi‚ð•`‰æ
	DrawExtendGraph(bgX, 0, bgX + 1280, 770, bgHandle, TRUE);

	DrawExtendGraph(bgX + 1280, 0, bgX + 2560, 770, bgHandle, TRUE);

	player.Draw();

	for (auto& enemy : enemies)
	{
		if (!enemy->isDead)
		{
			enemy->Draw();
		}

		int y = 50;

		for (auto& enemy : enemies)
		{
			DrawFormatString(
				50, y,
				GetColor(255, 255, 255),
				TEXT("EnemyX=%d"),
				enemy->x
			);

			y += 30;
		}
	}

	int hpWidth = player.hp * 150 / player.maxHp;
	// ˜g
	DrawBox(250, 400, 400, 420,
		GetColor(255, 255, 255), FALSE);

	// HP
	DrawBox(250, 400, 250 + hpWidth, 420, GetColor(0, 255, 0), TRUE);

	SetFontSize(20);
	DrawFormatString(250,380,GetColor(255, 255, 255),TEXT("HP %d / %d"),player.hp,player.maxHp);

	// GameOver—p‰æ‘œ•\Ž¦
	if (isGameOver)
	{
		DrawGraph(0, 200, youDiedHandle, TRUE);
	}
}

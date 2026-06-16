#include "GameScene.h"
#include "EnemyFactory.h"
#include "GameManager.h"
#include <cmath>
#include "DxLib.h"
#include <limits>


GameScene::GameScene(CharacterType type)
{
	// 使用キャラを取得
	player.Init(type);

	// 攻撃タイマー
	attackTimer = 0;
	enemyAttackTimer = 0;

	// 戦闘状況
	playerEncount = false;
	enemyEncount = false;

	// ゲームオーバー状態
	isGameOver = false;

	// ゲームオーバー表示時間
	gameOverTimer = 0;

	// 背景画像
	bgHandle = LoadGraph(TEXT("Resource/Model/background.png"));

	// GameOver画像
	youDiedHandle = LoadGraph(TEXT("Resource/Model/YOUDIED.png"));

	// 背景X座標初期化
	bgX = 0;

	// 敵生成
	SpawnEnemies();
}

GameScene::~GameScene()
{
	DeleteGraph(bgHandle);
	DeleteGraph(youDiedHandle);
}

// 敵をスポーン
void GameScene::SpawnEnemies()
{
	for (int i = 0; i < 5; i++)
	{
		auto enemy = EnemyFactory::CreateEnemy(BLUE_SLIME);

		enemy->x = 1300 + i * 300;
		enemy->y = 540;

		enemies.push_back(std::move(enemy));
	}
}

void GameScene::Update()
{
	aliveCount = 0;
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
	
	// プレイヤー更新
	player.Update();

	// 敵更新
	for (auto& enemy : enemies)
	{
		if (enemy->isDead)
		{
			continue;
		}

		// プレイヤーとの距離
		int distance = abs(enemy->x - player.x);

		// 攻撃範囲外なら前進
		if (distance > enemy->attackRange)
		{
			enemy->Update();
		}

		// 一番近い敵を探す
		if (distance < minDistance)
		{
			minDistance = distance;
			targetEnemy = enemy.get();
		}
	}
	
	// ターゲットが存在する場合
	if (targetEnemy != nullptr)
	{
		// プレイヤーの攻撃判定
		playerEncount = (!targetEnemy->isDead && minDistance <= player.attackRange);

		// 敵の攻撃判定
		enemyEncount = (minDistance <= targetEnemy->attackRange);

		// 攻撃範囲に来たら攻撃
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

		// 敵の攻撃
		if (enemyEncount)
		{
			enemyAttackTimer++;

			if (enemyAttackTimer >= 60)
			{
				player.hp -= targetEnemy->attack;
				// プレイヤー死亡
				if (player.hp <= 0)
				{
					isGameOver = true;
				}
				enemyAttackTimer = 0;
			}
		}

		// 敵死亡
		if (targetEnemy->hp <= 0)
		{
			targetEnemy->isDead = true;
			player.exp += 10;
			player.gold += targetEnemy->rewardGold;
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

		// 3秒後にリスタート
		if (gameOverTimer >= 180)
		{
			GameManager::GetInstance().ChangeScene(std::make_unique<GameScene>(player.type));
		}
		return;
	}

	// 攻撃モーション切り替え
	player.isAttack = playerEncount;

	// 生存敵数を確認
	for (auto& enemy : enemies)
	{
		if (!enemy->isDead)
		{
			aliveCount++;
		}
	}

	// 全滅したら敵を再生成
	if (aliveCount == 0)
	{
		enemies.clear(); 
		SpawnEnemies();
	}

	// レベルアップ
	if (player.exp >= player.nextExp)
	{
		player.level++;

		player.exp = 0;

		player.nextExp += 50;

		player.maxHp += 20;

		player.hp = player.maxHp;
	}
}

void GameScene::Draw()
{
	// 背景を描画
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
	}

	// GameOver用画像表示
	if (isGameOver)
	{
		DrawGraph(0, 200, youDiedHandle, TRUE);
	}
}

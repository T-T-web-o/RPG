#include "GameManager.h"
#include "TitleScene.h"

//============================================================
// コンストラクタ
// ゲーム開始時に最初のシーンを設定する
//============================================================
GameManager::GameManager()
{
	currentScene = std::make_unique<TitleScene>();
}

GameManager& GameManager::GetInstance()
{
	static GameManager instance;
	return instance;
}

void GameManager::Update()
{
	currentScene->Update();
}

void GameManager::Draw()
{
	currentScene->Draw();
}

void GameManager::ChangeScene(std::unique_ptr<Scene> next)
{
	currentScene = std::move(next);
}

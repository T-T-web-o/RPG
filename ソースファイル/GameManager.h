#pragma once
#include "Scene.h"
#include <memory>

class GameManager
{
private:
	GameManager();

	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;

	std::unique_ptr<Scene> currentScene;
public:
	static GameManager& GetInstance();
	void Update();
	void Draw();

	void ChangeScene(std::unique_ptr<Scene>next);
};


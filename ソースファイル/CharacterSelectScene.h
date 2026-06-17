#pragma once
#include "Scene.h"
#include "Character.h"
#include <tchar.h>

class CharacterSelectScene:public Scene
{
private:
	int mouseX, mouseY;

	// キャラクター画像
	int knightSelectHandle;
	int rangerSelectHandle;
	int healerSelectHandle;

	CharacterType selectedType;

	// キャラクター種類
	CharacterType types[3];

	// キャラクター画像
    int handles[3];

	// キャラクター名前
	const TCHAR* names[3];
public:

	CharacterSelectScene();
	~CharacterSelectScene();

	void Update()override;
	void Draw()override;
};


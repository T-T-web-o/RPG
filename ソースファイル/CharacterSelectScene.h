#pragma once
#include "Scene.h"
#include "Character.h"

class CharacterSelectScene:public Scene
{
private:
	int mouseX, mouseY;

	int knightSelectHandle;
	int rangerSelectHandle;
	int healerSelectHandle;

	CharacterType selectedType;

public:

	CharacterSelectScene();
	~CharacterSelectScene();

	void Update()override;
	void Draw()override;
};


#pragma once
#include "Scene.h"
#include "Character.h"
#include <tchar.h>

class CharacterSelectScene:public Scene
{
private:
	int mouseX, mouseY;

	int knightSelectHandle;
	int rangerSelectHandle;
	int healerSelectHandle;

	CharacterType selectedType;

	CharacterType types[3];

    int handles[3];

	const TCHAR* names[3];
public:

	CharacterSelectScene();
	~CharacterSelectScene();

	void Update()override;
	void Draw()override;
};


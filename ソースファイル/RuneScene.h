#pragma once
#include "Scene.h"
#include "Rune.h"
#include <tchar.h>

class RuneScene:public Scene
{
private:
	// ƒ‹[ƒ“‚Ìí—Ş
	Rune runes[4];

	// ƒ‹[ƒ“‚Ì–¼‘O
	const TCHAR* names[4];
public:
	RuneScene();

	void Update()override;

	void Draw()override;
};


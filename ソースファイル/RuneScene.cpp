#include "RuneScene.h"
#include "DxLib.h"

RuneScene::RuneScene()
{
	// ƒ‹[ƒ“İ’è
	runes[0].Init(RUNE_ATTACK);
	runes[1].Init(RUNE_HP);
	runes[2].Init(RUNE_GOLD);
	runes[3].Init(RUNE_EXP);

	// ƒ‹[ƒ“–¼İ’è
	names[0] = TEXT("Attack");
	names[1] = TEXT("HP");
	names[2] = TEXT("Gold");
	names[3] = TEXT("EXP");
}

void RuneScene::Update()
{
	
}

void RuneScene::Draw()
{
	SetFontSize(40);
    DrawString(550,20,TEXT("Rune Shop"),GetColor(255, 255, 255));

	for (int i = 0; i < 4; i++)
	{
		int x = 150 + i * 250;

		DrawBox(x, 250, x + 200, 450, GetColor(255, 255, 255), FALSE);

		DrawString(x + 50, 250, names[i], GetColor(255, 255, 0));
	}
}

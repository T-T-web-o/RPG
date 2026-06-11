#include "TitleScene.h"
#include "GameManager.h"
#include "CharacterSelectScene.h"
#include "DxLib.h"

const int TITLE_TEXT_X = 200;
const int TITLE_TEXT_Y = 200;
const int TITLE_FONTSIZE = 40;
const int TEXT_COLOR = GetColor(255, 255, 255);

void TitleScene::Update()
{
	// Enter‰Ÿ‚µ‚½‚çGameScene‚Ö
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		GameManager::GetInstance().ChangeScene(std::make_unique<CharacterSelectScene>());
	}
	
}

void TitleScene::Draw()
{
	SetFontSize(TITLE_FONTSIZE);
	DrawString(TITLE_TEXT_X, TITLE_TEXT_Y, TEXT("TITLE"), TEXT_COLOR);
}

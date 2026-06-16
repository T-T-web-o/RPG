#include "CharacterSelectScene.h"
#include "GameManager.h"
#include "GameScene.h"
#include "DxLib.h"

CharacterSelectScene::CharacterSelectScene()
{
	mouseX = 0;
	mouseY = 0;

    selectedType = CHARACTER_NONE;

    // キャラクター画像
    knightSelectHandle = LoadGraph(TEXT("Resource/Model/Select1.png"));
    rangerSelectHandle = LoadGraph(TEXT("Resource/Model/Select2.png"));
    healerSelectHandle = LoadGraph(TEXT("Resource/Model/Select3.png"));
}

CharacterSelectScene::~CharacterSelectScene()
{
    DeleteGraph(knightSelectHandle);
    DeleteGraph(rangerSelectHandle);
    DeleteGraph(healerSelectHandle);
}

void CharacterSelectScene::Update()
{
    GetMousePoint(&mouseX, &mouseY);

    static int oldMouse = 0;

    int mouse = GetMouseInput();

    if ((mouse & MOUSE_INPUT_LEFT) &&
        !(oldMouse & MOUSE_INPUT_LEFT))
    {
        // KNIGHT
        if (mouseX >= 100 && mouseX <= 320 &&
            mouseY >= 180 && mouseY <= 500)
        {
            selectedType = KNIGHT;
        }
        // RANGER
        else if (mouseX >= 530 && mouseX <= 750 &&
            mouseY >= 180 && mouseY <= 500)
        {
            selectedType = RANGER;
        }
        // HEALER
        else if (mouseX >= 960 && mouseX <= 1180 &&
            mouseY >= 180 && mouseY <= 500)
        {
            selectedType = HEALER;
        }

        // 決定ボタン
        if (selectedType != CHARACTER_NONE)
        {
            if (mouseX >= 490 && mouseX <= 790 &&
                mouseY >= 620 && mouseY <= 690)
            {
                GameManager::GetInstance().player.Init(selectedType);

                GameManager::GetInstance().ChangeScene(
                    std::make_unique<GameScene>()
                );
            }
        }
    }
}

void CharacterSelectScene::Draw()
{
    SetFontSize(50);
    DrawString(430, 50, TEXT("Character Select"), GetColor(255, 255, 255));

    // KNIGHT
    DrawBox(100, 180, 320, 500, GetColor(255, 255, 255), FALSE);
    DrawExtendGraph(120, 220, 300, 460, knightSelectHandle, TRUE);
    if (selectedType == KNIGHT)
    {
        DrawBox(100, 180, 320, 500,
            GetColor(255, 255, 0), FALSE);
    }

    // RANGER
    DrawBox(530, 180, 750, 500, GetColor(255, 255, 255), FALSE);
    DrawExtendGraph(550, 220, 730, 460, rangerSelectHandle, TRUE);
    if (selectedType == RANGER)
    {
        DrawBox(530, 180, 750, 500,
            GetColor(255, 255, 0), FALSE);
    }

    // HEALER
    DrawBox(960, 180, 1180, 500, GetColor(255, 255, 255), FALSE);
    DrawExtendGraph(980, 220, 1160, 460, healerSelectHandle, TRUE);
    if (selectedType == HEALER)
    {
        DrawBox(960, 180, 1180, 500,
            GetColor(255, 255, 0), FALSE);
    }

    SetFontSize(30);
    DrawString(160, 140, TEXT("ナイト"), GetColor(255, 255, 0));
    DrawString(580, 140, TEXT("レンジャー"), GetColor(255, 255, 0));
    DrawString(1020, 140, TEXT("ヒーラー"), GetColor(255, 255, 0));

    // 決定ボタン
    if (selectedType != CHARACTER_NONE)
    {
        DrawBox(490, 620, 790, 690,GetColor(255, 255, 0), FALSE);
        DrawString(600, 640, TEXT("決定"), GetColor(255, 255, 255));
    }
    else
    {
        DrawBox(490, 620, 790, 690,GetColor(255, 255, 255), FALSE);
        DrawString(600, 640, TEXT("決定"), GetColor(255, 255, 255));
    }
}
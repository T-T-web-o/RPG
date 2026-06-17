#include "CharacterSelectScene.h"
#include "GameManager.h"
#include "GameScene.h"
#include "DxLib.h"

CharacterSelectScene::CharacterSelectScene()
{
    // マウス座標初期化
    mouseX = 0;
    mouseY = 0;

    // 未選択状態
    selectedType = CHARACTER_NONE;

    // キャラクター種類設定
    types[0] = KNIGHT;
    types[1] = RANGER;
    types[2] = HEALER;

    // キャラクター選択画像読み込み
    knightSelectHandle = LoadGraph(TEXT("Resource/Model/Select1.png"));
    rangerSelectHandle = LoadGraph(TEXT("Resource/Model/Select2.png"));
    healerSelectHandle = LoadGraph(TEXT("Resource/Model/Select3.png"));

    // 画像ハンドル設定
    handles[0] = knightSelectHandle;
    handles[1] = rangerSelectHandle;
    handles[2] = healerSelectHandle;

    // キャラクター名設定
    names[0] = TEXT(" ナイト");
    names[1] = TEXT("レンジャー");
    names[2] = TEXT("ヒーラー");
}

CharacterSelectScene::~CharacterSelectScene()
{
    DeleteGraph(knightSelectHandle);
    DeleteGraph(rangerSelectHandle);
    DeleteGraph(healerSelectHandle);
}

void CharacterSelectScene::Update()
{
    // マウス座標取得
    GetMousePoint(&mouseX, &mouseY);

    // 前フレームのマウス入力状態
    static int oldMouse = 0;

    // 現在のマウス入力状態
    int mouse = GetMouseInput();

    // マウス左クリック時
    if ((mouse & MOUSE_INPUT_LEFT) &&
        !(oldMouse & MOUSE_INPUT_LEFT))
    {
        // キャラクター選択
        for (int i = 0; i < 3; i++)
        {
            int x = 100 + i * 430;

            if (mouseX >= x &&
                mouseX <= x + 220 &&
                mouseY >= 180 &&
                mouseY <= 500)
            {
                selectedType = types[i];
            }
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
    oldMouse = mouse;
}

void CharacterSelectScene::Draw()
{
    SetFontSize(50);
    DrawString(430, 50, TEXT("Character Select"), GetColor(255, 255, 255));

    // 選択画像を表示
    for (int i = 0; i < 3; i++)
    {
        int x = 100 + i * 430;
        // 枠
        DrawBox(x, 180,x + 220, 500,GetColor(255, 255, 255),FALSE);

        // キャラクター画像
        DrawExtendGraph(x + 20, 220, x + 200, 460, handles[i], TRUE);

        // 名前
        DrawString(x + 10, 130, names[i], GetColor(255, 255, 0));

        // 選択枠
        if (selectedType == types[i])
        {
            DrawBox(x, 180, x + 220, 500, GetColor(255, 255, 0), FALSE);
        }
    }
   
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
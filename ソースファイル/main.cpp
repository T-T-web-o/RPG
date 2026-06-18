#include "Dxlib.h"
#include "GameManager.h"
#include "Input.h"

//============================================================
// アプリケーションのエントリーポイント
// Windowsアプリの main 関数
//============================================================
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // ウインドウモードで起動
    ChangeWindowMode(TRUE);

    SetGraphMode(1280, 720, 32);

    // DxLib初期化
    if (DxLib_Init() == -1)
    {
        return -1;
    }

    // 裏画面描画
    SetDrawScreen(DX_SCREEN_BACK);

    // ===== メインループ =====
    while (ProcessMessage() == 0)
    {
        // 画面クリア
        ClearDrawScreen();
        
        // 入力処理更新
        Input::Update();

        GameManager::GetInstance().Update();

        GameManager::GetInstance().Draw();

        // 画面反映
        ScreenFlip();
    }

    // DxLibの終了処理
    DxLib_End();

    return 0;
}
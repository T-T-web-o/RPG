#include "Input.h"
#include "DxLib.h"

//staticメンバ変数
int Input::nowMouse = 0;
int Input::prevMouse = 0;

void Input::Update()
{
    // 前フレームのマウス入力状態
    prevMouse = nowMouse;

    // 現在のマウス入力状態 int nowMouse = GetMouseInput();
    nowMouse = GetMouseInput();
}

bool Input::IsLeftTrigger()
{
	return (nowMouse & MOUSE_INPUT_LEFT) &&
        !(prevMouse & MOUSE_INPUT_LEFT);
}

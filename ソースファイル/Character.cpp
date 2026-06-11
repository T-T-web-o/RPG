#include "Character.h"
#include "DxLib.h"

Character::Character()
{
    type = CHARACTER_NONE;

    // 座標初期化
	x = 200;
	y = 200;

    // ステータス初期化
	hp = 0;
	attack = 0;
    magic = 0;
	defense = 0;
    attackRange = 0;
	level = 1;

    // アニメーション処理初期化
    animFrame = 0;
    frameCount = 0;

    // 攻撃フラグ初期化
    isAttack = false;

    // キャラクター画像 
    LoadDivGraph(TEXT("Resource/Model/knight.png"), 12, 6, 2, 248, 276, knightHandle);
    LoadDivGraph(TEXT("Resource/Model/ranger.png"), 12, 6, 2, 248, 276, rangerHandle);
    LoadDivGraph(TEXT("Resource/Model/healer.png"), 12, 6, 2, 248, 276,healerHandle);
}

// デストラクタ
Character::~Character()
{
    for (int i = 0; i < 12; i++)
    {
        DeleteGraph(knightHandle[i]);
        DeleteGraph(rangerHandle[i]);
        DeleteGraph(healerHandle[i]);
    }
}

void Character::Init(CharacterType type)
{
	this->type = type;

    // キャラごとに初期ステータスを振り分け
	switch (type)
	{
    case KNIGHT:
        hp = 110;
        maxHp = 110;
        attack = 15;
        magic = 0;
        defense = 10;
        attackRange = 250;
        break;

    case RANGER:
        hp = 90;
        maxHp = 90;
        attack = 20;
        magic = 5;
        defense = 5;
        attackRange = 250;
        break;

    case HEALER:
        hp = 80;
        maxHp = 80;
        attack = 5;
        magic = 20;
        defense = 8;
        attackRange = 400;
        break;
	}
}

void Character::Update()
{
    // アニメーションの更新
    frameCount++;

    if (frameCount % 10 == 0)
    {
        animFrame++;

        if (animFrame >= 6)
        {
            animFrame = 0;
        }
    }

}

void Character::Draw()
{
    // 選択キャラを描画
    switch (type)
    {
    case CHARACTER_NONE:
        break;

        // ナイト
    case KNIGHT:
        if (isAttack)
        {
            DrawGraph(x, y + 160, knightHandle[animFrame + 6], TRUE);
        }
        else
        {
            DrawGraph(x, y + 240, knightHandle[animFrame], TRUE);
        }
        break;

        // レンジャー
    case RANGER:
        if (isAttack)
        {
            DrawGraph(x, y + 160, rangerHandle[animFrame + 6], TRUE);
        }
        else
        {
            DrawGraph(x, y + 240, rangerHandle[animFrame], TRUE);
        }
        break;

        // ヒーラー
    case HEALER:
        if (isAttack)
        {
            DrawGraph(x, y + 160, healerHandle[animFrame + 6], TRUE);
        }
        else
        {
            DrawGraph(x, y + 240, healerHandle[animFrame], TRUE);
        }
        break;

    default:
        break;
    }
    
}

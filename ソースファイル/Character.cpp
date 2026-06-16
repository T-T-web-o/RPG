#include "Character.h"
#include "DxLib.h"

Character::Character()
{
    type = CHARACTER_NONE;

    // 座標初期化
	x = 200;
	y = 440;

    // ステータス初期化
	hp = 0;
    maxHp = 0;
	attack = 0;
    magic = 0;
	defense = 0;
    attackRange = 0;
	level = 1;

    // 経験値
    exp = 0;
    nextExp = 100;

    // 所持金
    gold = 0;

    // アニメーション処理初期化
    animFrame = 0;
    frameCount = 0;

    // 攻撃フラグ初期化
    isAttack = false;

    // 死亡フラグ
    isDead = false;
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
        level = 1;
        break;

    case RANGER:
        hp = 90;
        maxHp = 90;
        attack = 20;
        magic = 5;
        defense = 5;
        attackRange = 250;
        level = 1;
        break;

    case HEALER:
        hp = 80;
        maxHp = 80;
        attack = 5;
        magic = 20;
        defense = 8;
        attackRange = 400;
        level = 1;
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
            DrawGraph(x, y-80, knightHandle[animFrame + 6], TRUE);
        }
        else
        {
            DrawGraph(x, y , knightHandle[animFrame], TRUE);
        }
        break;

        // レンジャー
    case RANGER:
        if (isAttack)
        {
            DrawGraph(x, y-80, rangerHandle[animFrame + 6], TRUE);
        }
        else
        {
            DrawGraph(x, y, rangerHandle[animFrame], TRUE);
        }
        break;

        // ヒーラー
    case HEALER:
        if (isAttack)
        {
            DrawGraph(x, y-80 , healerHandle[animFrame + 6], TRUE);
        }
        else
        {
            DrawGraph(x, y, healerHandle[animFrame], TRUE);
        }
        break;

    default:
        break;
    }

    //==============================================
    // HPバー表示
    //==============================================
    int hpWidth = hp * 150 / maxHp;
    // 枠
    DrawBox(70, 120, 220, 150,
        GetColor(255, 255, 255), FALSE);

    // HP
    DrawBox(70, 120,70 + hpWidth, 150,  GetColor(0, 255, 0), TRUE);

    SetFontSize(20);
    DrawFormatString(75, 125, GetColor(255, 255, 255), TEXT("HP %d / %d"), hp, maxHp);

    // レベル
    DrawFormatString(70, 100,GetColor(255, 255, 255),TEXT("Lv.%d"),level);

    //==============================================
    // 経験値バー表示
    //==============================================
    int expWidth = exp * 150 / nextExp;

    // 枠
    DrawBox(70, 150, 220, 180,GetColor(255, 255, 255), FALSE);

    // exp
    DrawBox(70, 150, 70 + expWidth, 180,GetColor(0, 0, 255), TRUE);

    SetFontSize(20);
    DrawFormatString(75, 155, GetColor(255, 255, 255), TEXT("EXP %d / %d"), exp, nextExp);

    // 所持金
    DrawFormatString(70, 190, GetColor(255, 255, 255), TEXT("所持金 : %d"), gold);
}

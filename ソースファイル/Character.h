#pragma once
#include "Enemy.h"

// キャラの種類
enum CharacterType
{
    CHARACTER_NONE,
    KNIGHT,
    RANGER,
    HEALER
};

class Character
{
public:
    // 画像
    int knightHandle[12];
    int rangerHandle[12];
    int healerHandle[12];

    int animFrame;
    int frameCount;
    
    // 座標
    int x, y;

    // 画像サイズ
    int w, h;

    // 削除フラグ
    bool isDead;  

    // 攻撃フラグ
    bool isAttack;

    // ステータス
    int hp;
    int maxHp;
    int attack;
    int magic;
    int defense;
    int level;
    int attackRange;

    // キャラの種類
    CharacterType type;

    // 敵
    Enemy enemy;

    // コンストラクタ
    Character();

    // デストラクタ
    ~Character();

    // キャラクターの初期設定
    void Init(CharacterType type);

    // 更新処理
    void Update();

    // 描画処理
    void Draw();
};


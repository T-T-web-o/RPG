#pragma once

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

    // 経験値
    int exp;
    int nextExp;

    // 所持金
    int gold;

    // キャラの種類
    CharacterType type;

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


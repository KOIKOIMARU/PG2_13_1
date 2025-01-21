#pragma once
#include "Struct.h"
#include "Bullet.h"


// プレイヤークラス
class Player {
public:
	// メンバ変数

	// プレイヤーの変数
	Transform player_;
	// 弾の変数
	Bullet* Bullet_;
	 
	// コンストラクタの宣言
	Player(int posX, int posY, int radius, int speed);
	// デストラクタの宣言
	~Player();

public:
	// メンバ関数

	// プレイヤーを更新させる関数の宣言
	void Update(char* keys, char* preKeys);

	// プレイヤーを描画させる関数の宣言
	void Draw();
};
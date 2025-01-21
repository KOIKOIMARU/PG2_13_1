#pragma once
#include "Struct.h"

// 弾クラス
class Bullet {
public:
	// メンバ変数

	// 弾の変数
	Transform Bullet_;
	int isShot_;

	// コンストラクタの宣言
	Bullet(int posX, int posY, int radius, int speed, int isShot);

public:
	// メンバ関数
	 
	// 弾を更新させる関数の宣言
	void Update();
	 
	// 弾を描画させる関数の宣言
	void Draw();
};
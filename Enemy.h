#pragma once
#include "Struct.h"
#include "Bullet.h"

class Enemy{
public:
	static int isAlive_;
	// メンバ変数
	Transform Enemy_;

	// 弾の変数
	Bullet* Bullet_;

	// コンストラクタの宣言
	Enemy(int posX, int posY, int radius, int speed);

	// デストラクタの宣言
	~Enemy();

public:
	// メンバ関数 

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update(char* keys, int bulletX, int bulletY, int bulletRadius);

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

};


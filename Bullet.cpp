#include <Novice.h>
#include "Bullet.h"

// コンストラクタの定義
Bullet::Bullet(int posX, int posY, int radius, int speed, int isShot) {
	// メンバ変数の初期化
	Bullet_.posX = posX;
	Bullet_.posY = posY;
	Bullet_.radius = radius;
	Bullet_.speed = speed;
	isShot_ = isShot;
}

/// <summary>
/// 弾を更新させる関数
/// </summary>
void Bullet::Update() {
	if (isShot_) {
		Bullet_.posY -= Bullet_.speed;
		if (Bullet_.posY <= 0 - Bullet_.radius) {
			isShot_ = false;
		}
	}
}

/// <summary>
/// 弾を描画させる関数
/// </summary>
void Bullet::Draw() {
	Novice::DrawEllipse(
		Bullet_.posX, Bullet_.posY,
		Bullet_.radius, Bullet_.radius,
		0.0f, WHITE, kFillModeSolid);
}
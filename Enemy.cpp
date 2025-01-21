#include <Novice.h>
#include "Enemy.h"

// コンストラクタの定義
Enemy::Enemy(int posX, int posY, int radius, int speed) {
	// メンバ変数の初期化
	Enemy_.posX = posX;
	Enemy_.posY = posY;
	Enemy_.radius = radius;
	Enemy_.speed = speed;
}

// デストラクタの定義
Enemy::~Enemy() {} 

/// <summary>
/// 円を移動させ、壁に衝突で反射
/// </summary>
void Enemy::Update(char* keys, int bulletX, int bulletY, int bulletRadius) {
	if (isAlive_) {
		Enemy_.posX += Enemy_.speed;

		if (Enemy_.posX < Enemy_.radius || Enemy_.posX > 1280 - Enemy_.radius) {
			Enemy_.speed *= -1;
		}

		// 弾と敵の当たり判定
		int dx = bulletX - Enemy_.posX;
		int dy = bulletY - Enemy_.posY;
		int distanceSquared = dx * dx + dy * dy;

		int combinedRadius = bulletRadius + Enemy_.radius;
		if (distanceSquared < combinedRadius * combinedRadius) {
			isAlive_ = false;
		}

	}else {
		if (keys[DIK_R]) {
			isAlive_ = true;
		}
	}
}

/// <summary>
/// 円を描画する
/// </summary>
void Enemy::Draw() {
	if (isAlive_) {
		Novice::DrawEllipse(Enemy_.posX, Enemy_.posY, Enemy_.radius, Enemy_.radius, 0.0f, RED, kFillModeSolid);
	}
}

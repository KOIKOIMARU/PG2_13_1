#include <Novice.h>
#include "Player.h"


// コンストラクタの定義
Player::Player(int posX, int posY, int radius, int speed) {
	// メンバ変数の初期化
	player_.posX = posX;
	player_.posY = posY;
	player_.radius = radius;
	player_.speed = speed;
	// 弾クラスの実体を生成
	Bullet_ = new Bullet(0, 0, 20, 10, true);
}

// デストラクタの定義
Player::~Player() {
	// ポインタ削除
	delete Bullet_;
}

/// <summary>
/// プレイヤーを更新させる関数
/// </summary>
/// <param name="keys">キー</param>
/// <param name="preKeys">前のキー</param>
void Player::Update(char* keys, char* preKeys) {
	// 移動処理
	if (keys[DIK_W]) {
		player_.posY -= player_.speed;
	}
	if (keys[DIK_S]) {
		player_.posY += player_.speed;
	}
	if (keys[DIK_D]) {
		player_.posX += player_.speed;
	}
	if (keys[DIK_A]) {
		player_.posX -= player_.speed;
	}

	// 発射処理
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && !Bullet_->isShot_) {
		Bullet_->Bullet_.posX = player_.posX;
		Bullet_->Bullet_.posY = player_.posY;
		Bullet_->isShot_ = true;
	}

	// 弾の更新関数の呼び出し
	Bullet_->Update();
}

/// <summary>
/// プレイヤーを描画させる関数
/// </summary>
void Player::Draw() {
	Novice::DrawEllipse(
		player_.posX, player_.posY,
		player_.radius, player_.radius,
		0.0f, GREEN, kFillModeSolid);

	// 弾の描画関数の呼び出し
	Bullet_->Draw();
}
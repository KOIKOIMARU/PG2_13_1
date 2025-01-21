#include <Novice.h>
#include "Player.h"
#include "Enemy.h"

const char kWindowTitle[] = "LC1B_08_コイズミリョウ_静的メンバ変数";

// 敵の静的メンバ変数の初期化
int Enemy::isAlive_ = true;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// 変数の宣言と初期化

	// プレイヤーのインスタンス生成
	Player* player = new Player(640, 600, 30, 10);

	// 敵のインスタンス生成
	Enemy* enemy1 = new Enemy(100, 100, 20, 10);
	Enemy* enemy2 = new Enemy(300, 300, 20, 10);


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		// プレイヤー更新処理
		player->Update(keys, preKeys);

		// 敵更新処理
		enemy1->Update(keys, player->Bullet_->Bullet_.posX, player->Bullet_->Bullet_.posY, player->Bullet_->Bullet_.radius);
		enemy2->Update(keys, player->Bullet_->Bullet_.posX, player->Bullet_->Bullet_.posY, player->Bullet_->Bullet_.radius);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		// プレイヤー描画処理
		player->Draw();

		// 敵描画処理
		enemy1->Draw();
		enemy2->Draw();

		// 情報の描画
		Novice::ScreenPrintf(0, 0, "enemyA isAlive = %d", enemy1->isAlive_);
		Novice::ScreenPrintf(0, 20, "enemyB isAlive = %d", enemy2->isAlive_);
		Novice::ScreenPrintf(0, 40, "WASD : player Move");
		Novice::ScreenPrintf(0, 60, "shot : SPACE");
		Novice::ScreenPrintf(0, 80, "enemy respawn : R");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// メモリの開放
	delete player;
	delete enemy1;
	delete enemy2;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

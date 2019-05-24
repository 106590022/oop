#pragma once


namespace game_framework {
/////////////////////////////////////////////////////////////////////////////
// 這個class提供可以用鍵盤或滑鼠控制的擦子
// 看懂就可以改寫成自己的程式了
/////////////////////////////////////////////////////////////////////////////

	class CGameMap;
	class CBullet;
	class CBomb;
	class CEnemy;
	class CHealthPoints;
	class CWeapon;
	class CProps;
	class CBackpack;
	class CPlayer
	{
	public:
		CPlayer();
		~CPlayer();
		int  GetX1();					// 擦子左上角 x 座標
		int  GetY1();					// 擦子左上角 y 座標
		int  GetX2();					// 擦子右下角 x 座標
		int  GetY2();					// 擦子右下角 y 座標
		void Initialize();				// 設定擦子為初始值
		void LoadBitMap();				// 載入圖形
		void OnMove(CGameMap&, vector<CEnemy*> &enemies);					// 移動玩家
		void OnShow(CGameMap&);//CGameMap &map);					// 將玩家圖形貼到畫面
		void SetMovingDown(bool flag);	// 設定是否正在往下移動
		void SetMovingLeft(bool flag);	// 設定是否正在往左移動
		void SetMovingRight(bool flag); // 設定是否正在往右移動
		void SetMovingUp(bool flag);	// 設定是否正在往上移動
		void SetIsAttack(bool flag);
		void SetXY(int nx, int ny);		// 設定玩家左上角座標
		void SetDirection(int);
		void Attack();
		void Damage(int damage);
		void GetScore(int point);
		void GetProps(vector<CProps*> &props);
		void OnShowInfo();
		void SwitchWeapon();
		int getblood() { return blood; };
		int *GetCoins() { return &coins; };
		int GetDirection();
		int CurrentScore();
		CBackpack& GetBackpack();
	protected:
		CAnimation animation[4];		// 玩家的動畫
		CHealthPoints *hp;
		CWeapon **weapon;
		CBackpack *backpack;
		CMovingBitmap icon[2];
		CInteger num[2];
        int x, y;				// 玩家左上角座標
        bool isMovingDown;			// 是否正在往下移動
        bool isMovingLeft;			// 是否正在往左移動
        bool isMovingRight;			// 是否正在往右移動
        bool isMovingUp;			// 是否正在往上移動
		bool isAttack;
		int blood;
        int direction;
		int score;
		int coins;
		time_t tstart, tend;
	};

}

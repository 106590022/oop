#pragma once
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	//子彈class
	/////////////////////////////////////////////////////////////////////////////
	class CEnemy;
	class CGameMap;
	class CBullet
	{
	public:
		CBullet();
		virtual void LoadBitMap() = 0;			// 載入圖形
		virtual void OnMove(CGameMap&);			// 移動
		virtual void OnShow(CGameMap&);			// 將圖形貼到畫面
		virtual void HitEnemy(CEnemy&);
		//void HitGasoline(vector<CEnemy*> &enemies);
		virtual bool GetIsHit();
		virtual ~CBullet();
	protected:
		int x, y;				// 圖形座標
		int velocity;			// 目前的速度(點/次)
		int damage;
		int direction;
		int distance;
		int range;
		bool isHit;
		bool isMovingDown;			// 是否正在往下移動
		bool isMovingLeft;			// 是否正在往左移動
		bool isMovingRight;			// 是否正在往右移動
		bool isMovingUp;			// 是否正在往上移動
		CAnimation animation;	// 利用動畫作圖形
		CMovingBitmap bulletsBmp[4];
	};
}

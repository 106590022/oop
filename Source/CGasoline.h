#pragma once
namespace game_framework {
	class CBullet;
	class CDifferentTime;
	class CGasoline :public CBullet
	{
	public:
		CGasoline(int px, int py);
		void LoadBitMap();			// 載入圖形
		void setHit(bool state) {  isBoom = state; };
		int  IsBoom() { return isBoom; };
		void HitEnemy(CEnemy&);
		void OnMove(CGameMap& map);			// 移動
		void OnShow(CGameMap&);
		int GetY1();
		int GetY2();
		int GetX1();
		int GetX2();
		~CGasoline();
	private:
		bool isBoom;
		bool tmpIsBoom;
		CAnimation boom;
		static int fixPos[7][2];
		const  int tmpX, tmpY;
		static int position[30][40];
		CDifferentTime *time;
	};
}

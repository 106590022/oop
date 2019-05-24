#pragma once
#include "aStar.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 敵人Class
	/////////////////////////////////////////////////////////////////////////////
	class CGameMap;
	class CPlayer;
	class CBase;
	class CHealthPoints;
	class CDifferentTime;
	class Cordinate;
	struct Node;
	class CEnemy
	{
	public:
		CEnemy(int X_POS,int Y_POS);
		int  GetX1();					
		int  GetY1();					
		int  GetX2();					
		int  GetY2();
		int GetValue();
		int GetBlood();
		void SetValue(int val);
		void Hit(CPlayer& player);
		void Hit(CBase& base);
		void LoadBitMap();				// 載入圖形
		void OnMove(CPlayer &player, CBase &base, CGameMap &map);			// 移動敵人
		void OnShow(CGameMap &map);			// 將敵人圖形貼到畫面
		void SetXY(int nx, int ny);		// 設定敵人左上角座標
		void Damage(int);
		bool GetIsAlive();
		~CEnemy();
	protected:
		CAnimation animation[3];		// 敵人的動畫
		CHealthPoints *hp;
		int x, y;					// 敵人左上角座標
		bool is_alive, isHit;				// 是否活著
		bool isUp, isDown, isLeft, isRight;
		bool isSearch = false;
		int blood;
		int ex, ey;
		int value = 0;
		vector<Node> path, tmppath;
		Node nenemy, nplayer,nbase;
		//CDifferentTime *time;
		Cordinate *route;
	};
}

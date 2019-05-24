#pragma once
namespace game_framework {
	class CGameMap
	{
	public:
		CGameMap();
		void LoadBitMap();
		void OnShow();
		void OnMove();
		int ScreenX(int);
		int ScreenY(int);
		void SetIsleft(bool);
		void SetIsRight(bool);
		void SetIsDown(bool);
		void SetIsUp(bool);
		void SetValue(int x,int y,char value);
		int IsEmpty(int x, int y);	//是否該點為障礙物
	protected:
		CMovingBitmap map;
		vector<vector<char>> data;
		const int MH, MW;
		bool isLeft;	//是否碰到左邊界
		bool isRight;	//是否碰到右邊界
		bool isDown;
		bool isUp;
		int sx, sy;
	};
}


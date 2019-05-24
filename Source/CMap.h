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
		int IsEmpty(int x, int y);	//�O�_���I����ê��
	protected:
		CMovingBitmap map;
		vector<vector<char>> data;
		const int MH, MW;
		bool isLeft;	//�O�_�I�쥪���
		bool isRight;	//�O�_�I��k���
		bool isDown;
		bool isUp;
		int sx, sy;
	};
}


#pragma once
#include "aStar.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �ĤHClass
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
		void LoadBitMap();				// ���J�ϧ�
		void OnMove(CPlayer &player, CBase &base, CGameMap &map);			// ���ʼĤH
		void OnShow(CGameMap &map);			// �N�ĤH�ϧζK��e��
		void SetXY(int nx, int ny);		// �]�w�ĤH���W���y��
		void Damage(int);
		bool GetIsAlive();
		~CEnemy();
	protected:
		CAnimation animation[3];		// �ĤH���ʵe
		CHealthPoints *hp;
		int x, y;					// �ĤH���W���y��
		bool is_alive, isHit;				// �O�_����
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

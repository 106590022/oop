#pragma once
namespace game_framework {
	class CEnemy;
	class CBullet;
	class CGameMap;
	class CPlayer;
	class CWeapon {
	public:
		CWeapon();
		virtual ~CWeapon();
		virtual void LoadBitMap() = 0;
		virtual void OnMove(CGameMap & map, CPlayer &player);
		virtual void OnShow(CGameMap &map);
		void OnShowInfo();
		virtual void Attack() = 0;
		virtual void HitEnemy(vector<CEnemy*> &enemies);
		int GetBulletsNum();
		CWeapon* GetType(){ return ReturnType(); }
	protected:
		virtual CWeapon* ReturnType() = 0;
		vector<CBullet*> bullets;
		int wx, wy, direction, ms;
		int nBullets;
		int factor;
		bool Delay(int ms);
		CMovingBitmap weapon[4];
		CMovingBitmap icon;
		CInteger num;
		int cx,cy;
	private:
		time_t tstart, tend;
	};
}
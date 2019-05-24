#pragma once
namespace game_framework {
	class CWeapon;
	class CGameMap;
	class CPlayer;
	class CBomb :public CWeapon
	{
	public:
		CBomb(int kind);
		~CBomb();
		void LoadBitMap();
		void OnShow(CGameMap &map);
		void OnMove(CGameMap & map, CPlayer &player);
		vector<CBullet*> GetGasonline() { if (kind == 1)return bullets; };
		int GetKind() { return kind; };
		void AddBullet(int num) { nBullets += num; };
		bool IsEmpty();
		void Attack();
	protected:
		CBomb* ReturnType() { return this; };
	private:
		int kind;
		int px, py;
		bool validX, validY;
	};
}
#pragma once
namespace game_framework {
	class CWeapon;
	class CGameMap;
	class CPlayer;
	class CEnemy;
	class CBackpack {
	public:
		CBackpack();
		~CBackpack();
		vector<CWeapon*>& AddWeapon();
		CWeapon** GetWeapon();
		void LoadBitMap();
		void OnShow(CGameMap &map);
		void OnMove(CGameMap &map, CPlayer &player, vector<CEnemy*> &enemies);
	private:
		vector<CWeapon*> weapons;
		CWeapon* item;
		int coins;
		int kind;
	};
}
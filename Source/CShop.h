#pragma once
namespace game_framework {
	class CWeapon;
	class CGameMap;
	class CPlayer;
	class CShop {
	public:
		CShop(int *pcoin);
		~CShop();
		void LoadBitMap();
		void OnShow();
		void OnMove(vector<CWeapon*>&weapons);
		void SetOnShow(bool state) { show = state; };
		void SetShowKind(int kind) { this->kind = kind; };
		bool IsShow() { return show; };
		void BuyWeapon(bool confirm, vector<CWeapon*>&weapons);
	private:
		typedef  std::array<CMovingBitmap, 3> goods;
		vector<pair<goods,int>> weapons;
		CMovingBitmap shop;
	
		vector<pair<CMovingBitmap,CInteger>> icon;
		bool show;
		int kind;
		int *coins;
	};
}

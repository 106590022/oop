#pragma once
namespace game_framework {
	class CWeapon;
	class CBomb;
	class CRocket :public CWeapon
	{
	public:
		CRocket();
		void LoadBitMap();
		void Attack();
		void HitGasonline(CBomb &gasoline);
	protected:
		CRocket* ReturnType() { return this; };
	};
}

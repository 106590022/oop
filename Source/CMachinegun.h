#pragma once
namespace game_framework {
	class CWeapon;
	class CBomb;
	class CMachinegun :public CWeapon
	{
	public:
		CMachinegun();
		void LoadBitMap();
		void Attack();
		void HitGasonline(CBomb &gasoline);
	protected:
		CMachinegun* ReturnType() { return this; };
	};
}

#pragma once
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	//¤l¼uclass
	/////////////////////////////////////////////////////////////////////////////
	class CBullet;
	class CGasoline;
	class CGunBullet:public CBullet
	{
	public:
		CGunBullet(int direction, int x, int y);
		void LoadBitMap();	
		void HitGasoline(CGasoline *gasoline);
		~CGunBullet();
	};
}

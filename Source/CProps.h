#pragma once
namespace game_framework {
	class CPlayer;
	class CGameMap;
	class CProps {
	public:
		CProps();
		~CProps();
		virtual void LoadBitMap() = 0;
		void OnShow(CGameMap &map);
		void OnMove();
		CProps* IsGot(CPlayer &player);
	protected:
		int x, y;
		virtual CProps* ReturnType() = 0;
		CAnimation props;
	};
}
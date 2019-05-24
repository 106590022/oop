#pragma once
namespace game_framework {
	class CHealthPoints {
	public:
		CHealthPoints(int, int, int, int, int);
		void ShowHP(int x,int y,int percent);
	private:
		int bar_width;
		int bar_height;
		int percent;
		int frame;
		int background;
		int blood;
	};
}

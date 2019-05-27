#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CWeapon.h"
#include "CBullet.h" //在weapon.h不是編譯過了嗎
#include "CBomb.h"
#include "CMachineBullet.h"
#include "CMachineBullet1.h"
#include "CMachineBullet2.h"
#include "CGasoline.h"
#include "CMachinegun.h"
#include <string>

namespace game_framework {
	CMachinegun::CMachinegun()
	{
		ms = 40;
		nBullets = INT_MAX;
		factor = 2;
	}
	void CMachinegun::LoadBitMap()
	{
		int weapons[4] = { IDB_MACHINEGUN_UP, IDB_MACHINEGUN_DOWN, IDB_MACHINEGUN_LEFT, IDB_MACHINEGUN_RIGHT };
		for (int i = 0; i < 4; i++)
			weapon[i].LoadBitmap(weapons[i], RGB(255, 255, 255));
		icon.LoadBitmapA(IDB_MACHINEGUN_RIGHT, RGB(255, 255, 255));
	}
	void CMachinegun::Attack()
	{
		if (Delay(ms)) {
			CAudio::Instance()->Play(AUDIO_SHOT, false);
			bullets.emplace_back(new CMachineBullet(direction, wx, wy));
			bullets.emplace_back(new CMachineBullet1(direction, wx, wy));
			bullets.emplace_back(new CMachineBullet2(direction, wx, wy));
		}
	}
	void CMachinegun::HitGasonline(CBomb & gasoline)
	{
		vector<CBullet*> gasolines = gasoline.GetGasonline();

		for (auto item = gasolines.begin(); item != gasolines.end(); item++) {
			//GAME_ASSERT(false, "----343------");

			for (auto bullet = bullets.begin(); bullet != bullets.end(); bullet++) {
				//GAME_ASSERT(false, "----------");
				((CMachineBullet*)(*bullet))->HitGasoline((CGasoline*)((*item)));
			}
		}
	}
}
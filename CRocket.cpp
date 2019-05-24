#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CWeapon.h"
#include "CBullet.h" //在weapon.h不是編譯過了嗎
#include "CBomb.h"
#include "CGunBullet.h"
#include "CGasoline.h"
#include "CRocket.h"
#include <string>

namespace game_framework {
	CRocket::CRocket()
	{
		ms = 200;
		nBullets = INT_MAX;
		factor = 2;
	}
	void CRocket::LoadBitMap()
	{
		int weapons[4] = { IDB_ROCKET1, IDB_ROCKET2, IDB_ROCKET3, IDB_ROCKET4 };
		for (int i = 0; i < 4; i++)
			weapon[i].LoadBitmap(weapons[i], RGB(255, 255, 255));
		icon.LoadBitmapA(IDB_SHOTGUN4, RGB(255, 255, 255));
	}
	void CRocket::Attack()
	{
		if (Delay(ms)) {
			CAudio::Instance()->Play(AUDIO_SHOT, false);
			bullets.emplace_back(new CGunBullet(direction, wx, wy));
		}
	}
	void CRocket::HitGasonline(CBomb & gasoline)
	{
		vector<CBullet*> gasolines = gasoline.GetGasonline();

		for (auto item = gasolines.begin(); item != gasolines.end(); item++) {
			//GAME_ASSERT(false, "----343------");

			for (auto bullet = bullets.begin(); bullet != bullets.end(); bullet++) {
				//GAME_ASSERT(false, "----------");
				((CGunBullet*)(*bullet))->HitGasoline((CGasoline*)((*item)));
			}
		}
	}
}
#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CBullet.h"
#include "CGasoline.h"
#include "CGunBullet.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CBouncingBall: BouncingBall class
	/////////////////////////////////////////////////////////////////////////////
	
	
	void CGunBullet::LoadBitMap()
	{
		animation.AddBitmap(IDB_BULLET, RGB(255, 255, 255));
	}

	void CGunBullet::HitGasoline(CGasoline * gasoline)
	{

		if (gasoline->GetY1() <= y && y <= gasoline->GetY2() && gasoline->GetX1() <= x && x <= gasoline->GetX2() && !gasoline->IsBoom())
		{
			CAudio::Instance()->Play(AUDIO_BOOM, false);
			isHit = true;
			gasoline->setHit(true);
		}
	}


	CGunBullet::CGunBullet(int direction, int x, int y)
	{
		this->x = x;
		this->y = y;
		this->direction = direction;
		damage = 5;
		range = 500;
		velocity = 10;
		LoadBitMap();
	}

	CGunBullet::~CGunBullet()
	{

	}

}
#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CBullet.h"
#include "CGasoline.h"
#include "CMachineBullet.h"
#include "CMap.h"
#include "CEnemy.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CBouncingBall: BouncingBall class
	/////////////////////////////////////////////////////////////////////////////


	void CMachineBullet::LoadBitMap()
	{
		int MachinegunBullet[4] = { IDB_MACHINEGUN_BULLET_UP ,IDB_MACHINEGUN_BULLET_DOWN, IDB_MACHINEGUN_BULLET_LEFT, IDB_MACHINEGUN_BULLET_RIGHT };
		for (int i = 0; i < 4; i++)
			bulletsBmp[i].LoadBitmapA(MachinegunBullet[i], RGB(255, 255, 255));
	}
	void CMachineBullet::OnMove(CGameMap& map)
	{
		
		if (isHit == false && distance <= range && map.IsEmpty(x, y) != 1 && map.IsEmpty(x, y) != 3)
		{
			switch (direction)
			{
			case U:
				y -= velocity;
				break;
			case D:
				y += velocity;
				break;
			case L:
				x -= velocity;
				break;
			case R:
				x += velocity;
				break;
			}
			distance += velocity;

		}
		else
		{
			isHit = true;
		}

	}
	void CMachineBullet::OnShow(CGameMap & map)
	{
		if (isHit == false && distance <= range) {
			bulletsBmp[direction].SetTopLeft(map.ScreenX(x), map.ScreenY(y));
			bulletsBmp[direction].ShowBitmap();
		}
		
	}

	void CMachineBullet::HitGasoline(CGasoline * gasoline)
	{

		if (gasoline->GetY1() <= y && y <= gasoline->GetY2() && gasoline->GetX1() <= x && x <= gasoline->GetX2() && !gasoline->IsBoom())
		{
			CAudio::Instance()->Play(AUDIO_BOOM, false);
			isHit = true;
			gasoline->setHit(true);
		}
	}


	CMachineBullet::CMachineBullet(int direction, int x, int y)
	{
		this->x = x;
		this->y = y;
		this->direction = direction;
		damage = 5;
		range = 500;
		velocity = 10;
		LoadBitMap();
	}

	CMachineBullet::~CMachineBullet()
	{

	}

}
#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CBullet.h"
#include "CGasoline.h"
#include "CRocketBullet.h"
#include "CEnemy.h"
#include "CMap.h"


namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CBouncingBall: BouncingBall class
	/////////////////////////////////////////////////////////////////////////////


	void CRocketBullet::LoadBitMap()
	{
		
		int RocketBullet[4] = { IDB_ROCKET_BULLET_UP ,IDB_ROCKET_BULLET_DOWN, IDB_ROCKET_BULLET_LEFT, IDB_ROCKET_BULLET_RIGHT };
		for (int i = 0; i < 4; i++)
			bulletsBmp[i].LoadBitmapA(RocketBullet[i], RGB(255, 255, 255));

		int RocketBoomAnimation[7] = { IDB_GASBOOM1 ,IDB_GASBOOM2,IDB_GASBOOM3,IDB_GASBOOM4,IDB_GASBOOM5,IDB_GASBOOM6,IDB_GASBOOM7 };
		for (int i = 0; i < 7; i++)
			RocketBoom.AddBitmap(RocketBoomAnimation[i], RGB(255, 255, 255));
		RocketBoom.SetDelayCount(7);
	}

	void CRocketBullet::OnMove(CGameMap& map)
	{
		if (isBoom == true)
		{	
			if (!RocketBoom.IsFinalBitmap())
			{
				RocketBoom.OnMove();
			}
			else
				isHit = true;
			
		}
		if (isBoom == false && distance <= range && map.IsEmpty(x, y) != 1 && map.IsEmpty(x, y) != 3)
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
			isBoom = true;
		}

	}
	void CRocketBullet::OnShow(CGameMap & map)
	{
		if (isBoom == true && !RocketBoom.IsFinalBitmap()) {
			RocketBoom.SetTopLeft(map.ScreenX(x), map.ScreenY(y));
			RocketBoom.OnShow();
		}
		else {
			bulletsBmp[direction].SetTopLeft(map.ScreenX(x), map.ScreenY(y));
			bulletsBmp[direction].ShowBitmap();
		}
	}
	void  CRocketBullet::HitEnemy(CEnemy& enemy)
	{
		if (enemy.GetX1() <= x && x <= enemy.GetX2() && enemy.GetY1() <= y && y <= enemy.GetY2())
		{
			CAudio::Instance()->Play(AUDIO_BOOM, false);
			isBoom = true;
			//isHit = true;
			enemy.Damage(damage);
			if (enemy.GetBlood() <= 0)
				enemy.SetValue(10);
		}
	}
	void CRocketBullet::HitGasoline(CGasoline * gasoline)
	{

		if (gasoline->GetY1() <= y && y <= gasoline->GetY2() && gasoline->GetX1() <= x && x <= gasoline->GetX2() && !gasoline->IsBoom())
		{
			
			isHit = true;
			gasoline->setHit(true);
		}
	}
	/*int CGasoline::GetX1()
	{
		return x / 30 * 30;
	}
	int CGasoline::GetX2()
	{
		return x / 30 * 30 + 29;
	}
	int CGasoline::GetY1()
	{
		return y / 30 * 30;
	}
	int CGasoline::GetY2()
	{
		return y / 30 * 30 + animation.Height();
	}*/

	CRocketBullet::CRocketBullet(int direction, int x, int y)
	{
		this->x = x;
		this->y = y;
		this->direction = direction;
		damage = 50;
		range = 500;
		velocity = 12;
		LoadBitMap();
		isBoom = false;
	}

	CRocketBullet::~CRocketBullet( )
	{
		
	}

}
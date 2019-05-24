#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CBullet.h"
#include "CEnemy.h"
#include "CMap.h"
namespace game_framework {
	CBullet::CBullet()
	{
		distance = 0;
		damage = 0;
		range = 0;
		velocity = 0;
		isHit = false;
	}
	void CBullet::OnMove(CGameMap& map)
	{
		animation.OnMove();	
		if (isHit == false && distance <= range && map.IsEmpty(x,y)!=1 && map.IsEmpty(x, y) != 3)
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

	void CBullet::OnShow(CGameMap& map)
	{
		if (isHit == false && distance<=range) {
			animation.SetTopLeft(map.ScreenX(x), map.ScreenY(y));
			animation.OnShow();
		}
	}
	void CBullet::HitEnemy(CEnemy &enemy)
	{

		if (enemy.GetX1() <= x && x <= enemy.GetX2() && enemy.GetY1() <= y && y <= enemy.GetY2())
		{
			isHit = true;
			enemy.Damage(damage);
			if(enemy.GetBlood()<=0)
				enemy.SetValue(10);
		}
	}

	bool CBullet::GetIsHit()
	{
		return isHit;
	}

	CBullet::~CBullet()
	{
		
	}

}
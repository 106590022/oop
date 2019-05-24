#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CProps.h"
#include "CPlayer.h"
#include "CMap.h"
namespace game_framework {
	CProps::CProps()
	{
		//LoadBitMap();
	}

	CProps::~CProps()
	{
		TRACE("Prop delete\n");
	}
	void CProps::OnShow(CGameMap &map)
	{
		props.SetTopLeft(map.ScreenX(x), map.ScreenY(y));
		props.OnShow();
	}
	void CProps::OnMove()
	{
		props.OnMove();
	}
	CProps* CProps::IsGot(CPlayer &player)
	{
		if (player.GetY1() <= y && y <= player.GetY2() && player.GetX1() <= x && x <= player.GetX2())
			return ReturnType();
		else
			return NULL;
	}
}
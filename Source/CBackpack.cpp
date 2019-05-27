#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <typeInfo>
#include "CWeapon.h"
#include "CGun.h"
#include "CRocket.h"
#include "CMachinegun.h"
#include "CBomb.h"
#include "CBackpack.h"
namespace game_framework {
	CBackpack::CBackpack()
	{	weapons.emplace_back(new CRocket());
		weapons.emplace_back(new CMachinegun());
		weapons.emplace_back(new CGun());
		
		coins = 0;
		kind = 0;
		item = nullptr;
		
	}
	CBackpack::~CBackpack()
	{
		for (auto it = weapons.begin(); it != weapons.end(); it++)
			delete *it;
		weapons.clear();
		
	}
	vector<CWeapon*>& CBackpack::AddWeapon()
	{
		return weapons;
	}
	CWeapon ** CBackpack::GetWeapon()
	{
		kind = kind < weapons.size() - 1 ? kind + 1 : 0;
		item = weapons[kind];
		return &item;
	}
	void CBackpack::LoadBitMap()// 這邊載入武器圖片!!!
	{
		for(int i=0 ; i <3; i++)
		{
			weapons[i]->LoadBitMap();
		}
		//(*weapons.begin())->LoadBitMap();

		//(*weapons.rbegin())->LoadBitMap();
	}
	void CBackpack::OnShow(CGameMap &map)
	{
		for (auto item = weapons.rbegin(); item!=weapons.rend(); item++)
			(*item)->OnShow(map);
	}
	void CBackpack::OnMove(CGameMap &map,CPlayer &player, vector<CEnemy*> &enemies)
	{
	
		const std::type_info& bomb = typeid(CBomb);
		const std::type_info& current = typeid(*(weapons[kind]->GetType()));

		for (auto i = 0; i < weapons.size(); i++) {
			weapons[i]->OnMove(map, player);
			weapons[i]->HitEnemy(enemies);
			const std::type_info& it = typeid(*(weapons[i]->GetType()));
			if (current == bomb && it == bomb && ((CBomb*)weapons[kind])->IsEmpty() && kind != 0)
				GetWeapon();
			
			else if (it == bomb && ((CBomb*)weapons[i])->GetKind() == 1 && kind == 0) 
				((CGun*)weapons[0])->HitGasonline(*(CBomb*)(weapons[i]));

		}
	}
}

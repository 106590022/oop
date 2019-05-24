#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <typeInfo>
#include <array>
#include "CShop.h"
#include "CWeapon.h"
#include "CBomb.h"
#include "CGun.h"
#include "CMap.h"
#include "CPlayer.h"
#include "CBackpack.h"

namespace game_framework {
	CShop::CShop(int *pcoin)
	{
		coins = pcoin;
		show = false;
		kind = -1;
	}
	CShop::~CShop()
	{
		TRACE("Shop delete\n");
	}
	void CShop::LoadBitMap()
	{
		CMovingBitmap coin;
		CInteger num;
		coin.LoadBitmapA(IDB_COINS, RGB(255, 255, 255));
		icon.emplace_back(make_pair(coin, num));

		int goodsImg[2][3] = { {IDB_SHOP_MINE,IDB_SHOP_MINEB,IDB_SHOP_MINE_INTRO} ,{IDB_SHOP_GAS,IDB_SHOP_GASB,IDB_SHOP_GAS_INTRO} };
		for (int i = 0; i < 2; i++) {
			goods item;
			for (int j = 0; j < 3; j++) {
				
				item[j].LoadBitmapA(goodsImg[i][j], RGB(18, 21, 29));
			}
			icon.emplace_back(make_pair(item[0], num));
			icon.back().second.SetInteger(0);
			weapons.emplace_back(make_pair(item, 10));
		}
		shop.LoadBitmapA(IDB_SHOP);
		
	}
	void CShop::OnShow()
	{
		int goodsPos[2][2] = { {150,340},{215,336} };
		for (int i = 0; i < 2; i++) {
			weapons[i].first[0].SetTopLeft(goodsPos[i][0], goodsPos[i][1]);
			weapons[i].first[1].SetTopLeft(goodsPos[i][0], goodsPos[i][1]);
			weapons[i].first[2].SetTopLeft(534,383);
		}
		shop.SetTopLeft(80, 150);
		if (show == true) {
			shop.ShowBitmap();
			for (int i = 0; i < 2; i++) {
							if (*coins >= weapons[i].second) {
					weapons[i].first[0].ShowBitmap();
					//goods[i][2].ShowBitmap();
				}
				else
					weapons[i].first[1].ShowBitmap();

				//TRACE("*************************x=%d   y=%d\n", p.x, p.y);
			
			}
			if (kind != -1) {
				SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
				weapons[kind].first[2].ShowBitmap();
			}
			icon[0].first.SetTopLeft(550, 550);
			icon[0].first.ShowBitmap(0.25);
			icon[0].second.SetTopLeft(600, 550);
			icon[0].second.SetInteger(*coins);
			icon[0].second.ShowBitmap();
			if (kind != -1) {
				icon[kind + 1].first.SetTopLeft(700, 550);
				icon[kind + 1].first.ShowBitmap();
				icon[kind + 1].second.SetTopLeft(750, 550);
				icon[kind + 1].second.ShowBitmap();
			}
		}		
	}
	void CShop::OnMove(vector<CWeapon*>&weapons)
	{
		if (kind != -1) {
			const std::type_info& bomb = typeid(CBomb);
			auto item = weapons.begin();
			for (item; item != weapons.end(); item++) {
				const std::type_info& it = typeid(*((*item)->GetType()));
				if (it == bomb) {
					if (((CBomb*)(*item))->GetKind() == kind) {
						//GAME_ASSERT(false, "f");
						icon[kind + 1].second.SetInteger((*item)->GetBulletsNum());
					}
				}
			}
		}
	}
	void CShop::BuyWeapon(bool confirm, vector<CWeapon*>&weapons)
	{
		if (kind != -1) {
			if (show && confirm && *coins >= this->weapons[kind].second) {
				CAudio::Instance()->Play(AUDIO_BUY, false);
				const std::type_info& bomb = typeid(CBomb);
				auto item = weapons.begin();
				for (item; item != weapons.end(); item++) {
					const std::type_info& it = typeid(*((*item)->GetType()));
					if (it == bomb) {
						if (((CBomb*)(*item))->GetKind() == kind) {
							((CBomb*)(*item))->AddBullet(10);
							*coins -= 10;
							break;
						}
					}
				}
				if (item == weapons.end()) {
					if (kind == 0 || kind == 1) {
						weapons.emplace_back(new CBomb(kind));
						*coins -= 10;
					}
				}
			}
		}
	}
}
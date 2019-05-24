/*
 * mygame.cpp: ���ɮ��x�C��������class��implementation
 * Copyright (C) 2002-2008 Woei-Kae Chen <wkc@csie.ntut.edu.tw>
 *
 * This file is part of game, a free game development framework for windows.
 *
 * game is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * game is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * History:
 *   2002-03-04 V3.1
 *          Add codes to demostrate the use of CMovingBitmap::ShowBitmap(CMovingBitmap &).
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *      2. Demo the use of CInteger in CGameStateRun.
 *   2005-09-13
 *      Rewrite the codes for CBall and CEraser.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *      1. Add codes to display IDC_GAMECURSOR in GameStateRun.
 *   2006-02-08 V4.2
 *      1. Revise sample screens to display in English only.
 *      2. Add code in CGameStateInit to demo the use of PostQuitMessage().
 *      3. Rename OnInitialUpdate() -> OnInit().
 *      4. Fix the bug that OnBeginState() of GameStateInit is not called.
 *      5. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      6. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2006-12-30
 *      1. Bug fix: fix a memory leak problem by replacing PostQuitMessage(0) as
 *         PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE,0,0).
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress.
 *   2010-03-23 V4.6
 *      1. Demo MP3 support: use lake.mp3 to replace lake.wav.
*/

#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"

namespace game_framework {
/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����C���}�Y�e������
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame* g)
    : CGameState(g)
{
}

void CGameStateInit::OnInit()
{
    //
    // ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
    //     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
    //
    ShowInitProgress(0);	// �@�}�l��loading�i�׬�0%
    //
    // �}�l���J���
    //
   // logo.LoadBitmap(IDB_BACKGROUND);
    Sleep(300);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
    //
	c_menu.LoadBitmap();
	CAudio::Instance()->Load(AUDIO_BOOM, "sounds\\boom.mp3");	// ���J�s��0���n��ding.wav
	CAudio::Instance()->Load(AUDIO_SHOT, "sounds\\Laser_Gun.mp3");
	CAudio::Instance()->Load(AUDIO_FOREST, "sounds\\magic_forest.mp3");	// ���J�s��2���n��ntut.mid
	CAudio::Instance()->Load(AUDIO_CRY, "sounds\\cry.mp3");
	CAudio::Instance()->Load(AUDIO_GAS, "sounds\\gas_put.mp3");
	CAudio::Instance()->Load(AUDIO_MINE, "sounds\\mine_put.mp3");
	CAudio::Instance()->Load(AUDIO_MINE_BOOM, "sounds\\mine_boom.mp3");
	CAudio::Instance()->Load(AUDIO_ALA, "sounds\\ala.mp3");
	CAudio::Instance()->Load(AUDIO_GOLD, "sounds\\gold.mp3");
	CAudio::Instance()->Load(AUDIO_HEAL, "sounds\\heal.mp3");
	CAudio::Instance()->Load(AUDIO_MONSTER_CRY, "sounds\\monster_cry.mp3");
	CAudio::Instance()->Load(AUDIO_BUY, "sounds\\buy.mp3");

    // ��OnInit�ʧ@�|����CGameStaterRun::OnInit()�A�ҥH�i���٨S��100%
    //
}

void CGameStateInit::OnBeginState()
{

}

void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
   
    if (nChar == KEY_SPACE)
        GotoGameState(GAME_STATE_RUN);						// ������GAME_STATE_RUN
    else if (nChar == KEY_ESC)								// Demo �����C������k
        PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// �����C��
}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
    GotoGameState(GAME_STATE_RUN);		// ������GAME_STATE_RUN
}
CMenu::CMenu()
{
	x = y = 0;
}


void CMenu::LoadBitmap()
{
	pic.LoadBitmap(IDB_MENU);
	// �� pic.LoadBitmap(��Bitmaps\\Tortoise.bmp��);
}
void CMenu::OnShow()
{
	pic.SetTopLeft(x, y);
	pic.ShowBitmap();
}

void CGameStateInit::OnShow()
{
	c_menu.OnShow();
    //
    // �K�Wlogo
    //
   // logo.SetTopLeft((SIZE_X - logo.Width()) / 2, SIZE_Y / 8);
    //logo.ShowBitmap();
    //
    // Demo�ù��r�����ϥΡA���L�}�o�ɽкɶq�קK�����ϥΦr���A���CMovingBitmap����n
    //
    /*CDC* pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC
    CFont f, *fp;
    f.CreatePointFont(160, "Times New Roman");	// ���� font f; 160���16 point���r
    fp = pDC->SelectObject(&f);					// ��� font f
    pDC->SetBkColor(RGB(0, 0, 0));
    pDC->SetTextColor(RGB(255, 255, 0));
    //pDC->TextOut(120, 220, "Please click mouse or press SPACE to begin.");
    //pDC->TextOut(5, 395, "Press Ctrl-F to switch in between window mode and full screen mode.");
    //if (ENABLE_GAME_PAUSE)
        //pDC->TextOut(5, 425, "Press Ctrl-Q to pause the Game.");

    //pDC->TextOut(5, 455, "Press Alt-F4 or ESC to Quit.");
    pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
    CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
	*/
}

/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����������A(Game Over)
/////////////////////////////////////////////////////////////////////////////

CGameStateOver::CGameStateOver(CGame* g)
    : CGameState(g)
{
}

void CGameStateOver::OnMove()
{
}

void CGameStateOver::OnBeginState()
{
    counter = 30 * 5; // 5 seconds
}

void CGameStateOver::OnInit()
{
    //
    // ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
    //     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
    //
    ShowInitProgress(66);	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���66%
    //
    // �}�l���J���
    //
    Sleep(300);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
    //
    // �̲׶i�׬�100%
    //
    ShowInitProgress(100);
}

void CGameStateOver::OnShow()
{
    CDC* pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC
    CFont f, *fp;
    f.CreatePointFont(160, "Times New Roman");	// ���� font f; 160���16 point���r
    fp = pDC->SelectObject(&f);					// ��� font f
    pDC->SetBkColor(RGB(0, 0, 0));
    pDC->SetTextColor(RGB(255, 255, 0));
    char str[80];								// Demo �Ʀr��r�ꪺ�ഫ
    sprintf(str, "Game Over ! (%d)", counter / 30);
    pDC->TextOut(240, 210, str);
    pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
    CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
}

/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame* g):shop(new CShop(player.GetCoins())), CGameState(g)
{
	
}

CGameStateRun::~CGameStateRun()
{

	for (auto it = enemies.begin(); it != enemies.end(); ++it)
	{
		delete (*it);
	}
	for (auto it = props.begin(); it != props.end(); ++it)
	{
		delete (*it);
	}
	delete shop;
	props.clear();
	enemies.clear();

	TRACE("myprops delete\n");
	TRACE("myenemies delete\n");
}

void CGameStateRun::OnBeginState()
{
    const int BALL_GAP = 90;
    const int BALL_XY_OFFSET = 45;
    const int BALL_PER_ROW = 7;
    const int HITS_LEFT = 10;
    const int HITS_LEFT_X = 590;
    const int HITS_LEFT_Y = 0;
    const int BACKGROUND_X = 60;
    const int ANIMATION_SPEED = 15;
	CAudio::Instance()->Play(AUDIO_FOREST, true);

}

void CGameStateRun::OnInit()  								// �C������Ȥιϧγ]�w
{
    //
    // ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
    //     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
    //
    ShowInitProgress(33);	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���33%
    //
    // �}�l���J���
    //
	enemies.emplace_back(new CEnemy(100,100));
	tstart = 0;
	
    gamemap.LoadBitMap();
	
    player.LoadBitMap();
	base.LoadBitMap(gamemap);
	shop->LoadBitMap();
	//player.GetWeapon(weapons[0]);

    //
    // ��������Loading�ʧ@�A�����i��
    //
    ShowInitProgress(50);
    Sleep(300); // ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
    //
    // �~����J��L���
    //
}
void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
	if (nChar == KEY_CTRL) {
		player.SwitchWeapon();
	}
	if (nChar == KEY_TAB)
		shop->SetOnShow(true);

    if (nChar == KEY_LEFT) {
        player.SetMovingLeft(true);
        player.SetDirection(L);
    }

    if (nChar == KEY_RIGHT) {
        player.SetMovingRight(true);
        player.SetDirection(R);
    }

    if (nChar == KEY_UP) {
        player.SetMovingUp(true);
        player.SetDirection(U);
    }

    if (nChar == KEY_DOWN) {
        player.SetMovingDown(true);
        player.SetDirection(D);
    }
	if (nChar == KEY_SPACE) {
		player.SetIsAttack(true);
	}
	
		
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == KEY_TAB)
		shop->SetOnShow(false);

    if (nChar == KEY_LEFT) {
        player.SetMovingLeft(false);
    }

    if (nChar == KEY_RIGHT) {
        player.SetMovingRight(false);
    }

    if (nChar == KEY_UP)
        player.SetMovingUp(false);

	if (nChar == KEY_DOWN) {
		player.SetMovingDown(false);
	}
	if (nChar == KEY_SPACE) {
		player.SetIsAttack(false);
	}
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{

	if (shop->IsShow()) {
		shop->BuyWeapon(true, player.GetBackpack().AddWeapon());
	}
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
	
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
	//TRACE("*************************x=%d   y=%d\n", point.x, point.y);
	if (shop->IsShow()) {
		if (330 <= point.y && point.y <= 375) {
			if (145 <= point.x && point.x <= 190) {
				shop->SetShowKind(0);
			}
			else if (205 <= point.x && point.x <= 250) {
				shop->SetShowKind(1);
			}
		}
		else
			shop->SetShowKind(-1);
	}

    // �S�ơC�p�G�ݭn�B�z�ƹ����ʪ��ܡA�gcode�b�o��
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnMove()
{
		//
		// �p�G�Ʊ�ק�cursor���˦��A�h�N�U���{����commment�����Y�i
		//
		 //SetCursor(AfxGetApp()->LoadCursor(IDC_GAMECURSOR));
		//
	shop->OnMove(player.GetBackpack().AddWeapon());
	if (!shop->IsShow()) {
		srand((int)time(NULL));
		gamemap.OnMove();
		player.OnMove(gamemap,enemies);
		base.OnMove();
		for (auto enemy = enemies.begin(); enemy != enemies.end(); )
		{
			if (!((*enemy)->GetIsAlive())) {
				
				int score = (*enemy)->GetValue();
				player.GetScore(score);
				if (score != 0) {
					if (rand() % 2)
						props.emplace_back(new CHeal((*enemy)->GetX1(), (*enemy)->GetY1()));
					else 
						props.emplace_back(new CCoin((*enemy)->GetX1(), (*enemy)->GetY1()));
				}
				delete * enemy;
				enemy = enemies.erase(enemy);
			}
			else {
				(*enemy)->Hit(player);
				(*enemy)->Hit(base);
				(*enemy)->OnMove(player, base, gamemap);
				++enemy;
			}
		}

		player.Attack();
		player.GetProps(props);
		if (tstart == 0)
			tstart = clock();

		else if (difftime(tend, tstart) > 5000) {
			if (rand() % 2)
				enemies.emplace_back(new CEnemy(rand() % 100 + 1000, rand() % 700 + 100));
			else
				enemies.emplace_back(new CEnemy(rand() % 100 + 50, rand() % 700 + 100));
			tend = tstart = 0;
		}
		else
			tend = clock();


	}

}

void CGameStateRun::OnShow()
{
    //
    //  �`�N�GShow�̭��d�U���n���ʥ��󪫥󪺮y�СA���ʮy�Ъ��u�@����Move���~��A
    //        �_�h��������sø�Ϯ�(OnDraw)�A����N�|���ʡA�ݰ_�ӷ|�ܩǡC���ӳN�y
    //        ���AMove�t�dMVC����Model�AShow�t�dView�A��View�������Model�C
    //
    //
    gamemap.OnShow();


	for (auto prop = props.begin(); prop != props.end(); prop++)
		(*prop)->OnShow(gamemap);
	player.OnShow(gamemap);
	for (auto enemy = enemies.begin(); enemy != enemies.end(); enemy++)
		(*enemy)->OnShow(gamemap);
	
	base.OnShow(gamemap);
	shop->OnShow();
	/*CDC* pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC
	CFont f, *fp;
	f.CreatePointFont(160, "Times New Roman");	// ���� font f; 160���16 point���r
	fp = pDC->SelectObject(&f);					// ��� font f
	pDC->SetBkColor(TRANSPARENT);
	pDC->SetTextColor(RGB(255, 255, 0));
	char str[80];								// Demo �Ʀr��r�ꪺ�ഫ
	//sprintf(str, "%d,%d %d %d", player.GetX1(),player.GetY1(),enemies.size(),((CBomb*)weapons[2])->GetGasonline().size());
	pDC->TextOut(0, 0, str);
	pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
	CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC*/
	if (!shop->IsShow())
		player.OnShowInfo();

	
	
}

}
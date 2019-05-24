#pragma once
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	//�l�uclass
	/////////////////////////////////////////////////////////////////////////////
	class CEnemy;
	class CGameMap;
	class CBullet
	{
	public:
		CBullet();
		virtual void LoadBitMap() = 0;			// ���J�ϧ�
		virtual void OnMove(CGameMap&);			// ����
		virtual void OnShow(CGameMap&);			// �N�ϧζK��e��
		virtual void HitEnemy(CEnemy&);
		//void HitGasoline(vector<CEnemy*> &enemies);
		virtual bool GetIsHit();
		virtual ~CBullet();
	protected:
		int x, y;				// �ϧήy��
		int velocity;			// �ثe���t��(�I/��)
		int damage;
		int direction;
		int distance;
		int range;
		bool isHit;
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
		CAnimation animation;	// �Q�ΰʵe�@�ϧ�
		CMovingBitmap bulletsBmp[4];
	};
}

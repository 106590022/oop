#pragma once


namespace game_framework {
/////////////////////////////////////////////////////////////////////////////
// �o��class���ѥi�H����L�ηƹ�������l
// �����N�i�H��g���ۤv���{���F
/////////////////////////////////////////////////////////////////////////////

	class CGameMap;
	class CBullet;
	class CBomb;
	class CEnemy;
	class CHealthPoints;
	class CWeapon;
	class CProps;
	class CBackpack;
	class CPlayer
	{
	public:
		CPlayer();
		~CPlayer();
		int  GetX1();					// ���l���W�� x �y��
		int  GetY1();					// ���l���W�� y �y��
		int  GetX2();					// ���l�k�U�� x �y��
		int  GetY2();					// ���l�k�U�� y �y��
		void Initialize();				// �]�w���l����l��
		void LoadBitMap();				// ���J�ϧ�
		void OnMove(CGameMap&, vector<CEnemy*> &enemies);					// ���ʪ��a
		void OnShow(CGameMap&);//CGameMap &map);					// �N���a�ϧζK��e��
		void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
		void SetIsAttack(bool flag);
		void SetXY(int nx, int ny);		// �]�w���a���W���y��
		void SetDirection(int);
		void Attack();
		void Damage(int damage);
		void GetScore(int point);
		void GetProps(vector<CProps*> &props);
		void OnShowInfo();
		void SwitchWeapon();
		int getblood() { return blood; };
		int *GetCoins() { return &coins; };
		int GetDirection();
		int CurrentScore();
		CBackpack& GetBackpack();
	protected:
		CAnimation animation[4];		// ���a���ʵe
		CHealthPoints *hp;
		CWeapon **weapon;
		CBackpack *backpack;
		CMovingBitmap icon[2];
		CInteger num[2];
        int x, y;				// ���a���W���y��
        bool isMovingDown;			// �O�_���b���U����
        bool isMovingLeft;			// �O�_���b��������
        bool isMovingRight;			// �O�_���b���k����
        bool isMovingUp;			// �O�_���b���W����
		bool isAttack;
		int blood;
        int direction;
		int score;
		int coins;
		time_t tstart, tend;
	};

}

//=========================================================
//�쐬:2022/05/24
// �Q�[�����s�׽
//=========================================================

//--- �C���N���[�h�K�[�h
#ifndef __GAME_APP_H__
#define __GAME_APP_H__

//--- �C���N���[�h��
#include "fps.h"

//--- �O���Q��
class CScene;

//--- �N���X��`
class CGameApp
{
private:
	DWORD m_dwFixedTime;
	DWORD m_dwLastTime;
	CScene* m_pMainScene;
public:
	CGameApp();
	~CGameApp();
	void Update();
	void Draw();

	void SetFixedTime(DWORD time) { m_dwFixedTime = time; }
};

#endif __GAME_APP__
//=========================================================
//作成:2022/05/24
// ゲーム実行ｸﾗｽ
//=========================================================

//--- インクルードガード
#ifndef __GAME_APP_H__
#define __GAME_APP_H__

//--- インクルード部
#include "fps.h"

//--- 前方参照
class CScene;

//--- クラス定義
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
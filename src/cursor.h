//=========================================================
// 作成:2022/04/21
// カーソル: 部品ｸﾗｽ
//=========================================================
//--- インクルードガード
#ifndef __CURSOR_H__
#define __CURSOR_H__

//--- インクルード部
#include "component.h"

//--- 前方参照
class CGameObject;

//--- クラス定義
class CCursor : public CComponent
{
private:
	bool m_bInput;				// カーソルを移動しない時用
	int m_nPoint;				// 
	int m_nOldPoint;			// 
	int m_nMax;					// 最大数
public:
	//--- ﾒﾝﾊﾞ関数
	CCursor();
	CCursor(CGameObject* owner);
	~CCursor();

	void Init();
	void Update();

	void InputSwitch() { m_bInput ^= true; };
	//--- セッター・ゲッター
	void SetMax(int value) { m_nMax = value; };
	int GetPos() { return m_nPoint; };
	int GetOldPos() { return m_nOldPoint; };
};

#endif // !__CURSOR_H__


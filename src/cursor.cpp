//=========================================================
// 作成:2022/04/21
// カーソル: 部品ｸﾗｽ
//=========================================================

//--- インクルード部
#include "cursor.h"

// コンストラクタ
CCursor::CCursor()
	:m_bInput(false),m_nMax(1),m_nPoint(0),m_nOldPoint(0)
{
}
// 引数付きコンストラクタ
CCursor::CCursor(CGameObject* owner)
	:CComponent(owner), m_bInput(false), m_nMax(1), m_nPoint(0), m_nOldPoint(0)
{
}
// デストラクタ
CCursor::~CCursor()
{

}
// 初期化
void CCursor::Init()
{

}
// 更新
void CCursor::Update()
{
	if (m_nPoint != m_nOldPoint)
	{
		m_nOldPoint = m_nPoint;
	}
}
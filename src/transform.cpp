//=========================================================
//作成:2022/04/19 (火曜日)
// トランスフォーム : 部品ｸﾗｽ
//=========================================================

//--- インクルード部
#include "transform.h"
#include "gameObject.h"
#include "localTrasform.h"
#include <math.h>

// 名前空間
namespace
{
	const float RATE_ROTATE = 0.2f;
}

// コンストラクタ
CTransform::CTransform()
	:m_pParent(nullptr),m_pChilds(0),m_vPos(0,0,0), m_vRot(0,0,0), m_vScale(0,0,0), m_vVel(0,0,0), m_vAccel(1,1,1),
	m_vTargetPos(0, 0, 0), m_vDestRot(0, 0, 0),m_pLocal(nullptr)
{
}
CTransform::CTransform(XMFLOAT3 pos, XMFLOAT3 rot, XMFLOAT3 size, XMFLOAT3 vel, CGameObject* pOwner)
	:m_pParent(nullptr),m_pChilds(0),m_vPos(pos),m_vRot(rot),m_vScale(size),m_vVel(vel), m_vAccel(1,1,1),
	m_vTargetPos(0,0,0),m_vDestRot(0,0,0), m_pLocal(nullptr)
{
}
CTransform::~CTransform()
{
	if (m_pLocal)
	{
		delete m_pLocal;
	}
}
void CTransform::Update()
{
	// ローカル座標の変更
	if (m_pLocal)
	{
		m_pLocal->Update();
	}

	XMFLOAT3 oldPos = m_vPos;		// 現在座標確保

	// 加速量を移動量に
	MULTIPLY_FLOAT3(m_vVel, m_vAccel);	
	// 座標の移動
	ADD_FLOAT3(m_vPos, m_vVel);

	// 変更されていれば
	if (oldPos.x != m_vPos.x ||
		oldPos.y != m_vPos.y ||
		oldPos.z != m_vPos.z)
	{
		// 中心位置からの差をとり、角度を変更
		//m_vDestRot.y = XMConvertToDegrees(atan2f(-(m_vPos.x - oldPos.x), -(m_vPos.z - oldPos.z)));
	}

	// 目的の角度までの差分
	float fDiffRotY = m_vDestRot.y - m_vRot.y;
	if (fDiffRotY >= 180.0f) {
		fDiffRotY -= 360.0f;
	}
	if (fDiffRotY < -180.0f) {
		fDiffRotY += 360.0f;
	}
	// 目的の角度まで慣性をかける
	m_vRot.y += fDiffRotY * RATE_ROTATE;
	if (m_vRot.y >= 180.0f) {
		m_vRot.y -= 360.0f;
	}
	if (m_vRot.y < -180.0f) {
		m_vRot.y += 360.0f;
	}
}

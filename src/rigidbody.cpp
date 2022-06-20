//=========================================================
// 作成:2022/05/24
// 物理
//=========================================================

//--- インクルード部
#include "rigidbody.h"
#include "transform.h"

//--- 定数定義
namespace {
	const float GRAVITY = 0.98f;		// 重力 座標系によって向きが違う
}

// コンストラクタ
CRigidbody::CRigidbody()
	:m_bGravity(true), m_bIsSleep(false)
{
	for (int cnt = 0; cnt < 3; ++cnt)
	{
		m_pFreezPos[cnt] = nullptr;
		m_pFreezRot[cnt] = nullptr;
	}
}
CRigidbody::~CRigidbody()
{
	for (int cnt = 0; cnt < 3; ++cnt)
	{
		if (m_pFreezPos[cnt])
			delete m_pFreezPos[cnt];
		if (m_pFreezRot[cnt])
			delete m_pFreezRot[cnt];
	}
}
void CRigidbody::Update()
{
	XMFLOAT3 pos = gameObject->GetTransform()->GetPos();
	XMFLOAT3 rot = gameObject->GetTransform()->GetRot();

	// 重力を与える
	if (m_bGravity)
	{
		pos.y += -GRAVITY;
	}

	// 位置固定
	if (m_pFreezPos[0])
		pos.x = *m_pFreezPos[0];
	if (m_pFreezPos[1])
		pos.y = *m_pFreezPos[1];
	if (m_pFreezPos[2])
		pos.z = *m_pFreezPos[2];
	// 角度
	if (m_pFreezRot[0])
		rot.x = *m_pFreezRot[0];
	if (m_pFreezRot[1])
		rot.y = *m_pFreezRot[1];
	if (m_pFreezRot[2])
		rot.z = *m_pFreezRot[2];

	gameObject->GetTransform()->SetPos(pos);
	gameObject->GetTransform()->SetRot(rot);

	// 動いたか動いてないか
	if (pos.x == m_vOldPos.x && pos.y == m_vOldPos.y &&
		pos.z == m_vOldPos.z)
	{
		m_bIsSleep = true;
	}
	else
	{
		m_bIsSleep = false;
	}

	m_vOldPos = pos;
}
// TODO: Initから呼び出されなければ機能しない
void CRigidbody::SetFreezPos(bool x, bool y, bool z)
{
	XMFLOAT3 pos = gameObject->GetTransform()->GetPos();
	// 格納フラグかつ、nullであれば格納
	if (x && !m_pFreezPos[0])
		m_pFreezPos[0] = new float(pos.x);
	if (y && !m_pFreezPos[1])
		m_pFreezPos[1] = new float(pos.y);
	if (z && !m_pFreezPos[2])
		m_pFreezPos[2] = new float(pos.z);
}
void CRigidbody::SetFreezRot(bool x, bool y, bool z)
{
	XMFLOAT3 rot = gameObject->GetTransform()->GetRot();
	// 格納フラグかつ、nullであれば格納
	if (x && !m_pFreezRot[0])
		m_pFreezRot[0] = new float(rot.x);
	if (y && !m_pFreezRot[1])
		m_pFreezRot[1] = new float(rot.y);
	if (z && !m_pFreezRot[2])
		m_pFreezRot[2] = new float(rot.z);
}

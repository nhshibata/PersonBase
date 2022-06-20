//--- インクルード部
#include "Transform.h"
#include "localTrasform.h"
#include <math.h>

//=========================================================
CLocalTransform::CLocalTransform(CTransform* world)
	:m_vPos(0, 0, 0), m_vRot(0, 0, 0), m_vScale(0, 0, 0),/* m_vVel(0, 0, 0), m_vAccel(1, 1, 1),*/m_pWorldTransform(world)
{
	m_vPos = world->GetPos();
	m_vRot = world->GetRot();
	m_vScale = world->GetScale();
	//m_vVel = world->GetVel();
	//m_vAccel = world->GetAccel();

	m_pParent = world->GetParent();
	XMFLOAT3 pos = m_pParent->GetPos();
	XMFLOAT3 angle = m_pParent->GetRot();
	// 角度
	angle.x += m_vRot.x;
	angle.y += m_vRot.y;
	angle.z += m_vRot.z;
	m_pWorldTransform->SetRot(angle);
	// 座標
	pos.x = (pos.x - m_vPos.x) * cos(angle.x);
	pos.y = (pos.y - m_vPos.y) * sin(angle.y);
	pos.z = (pos.z - m_vPos.z) * -sin(angle.z);
	m_pWorldTransform->SetPos(pos);
	// 拡大率
	MULTIPLY_FLOAT3(m_vScale, m_pParent->GetScale());
	//MULTIPLY_FLOAT3(m_vVel, parent->GetVel());
}
CLocalTransform::~CLocalTransform()
{

}
void CLocalTransform::Update()
{
	CTransform* parent = m_pWorldTransform->GetParent();
	XMFLOAT3 pos = parent->GetPos();
	XMFLOAT3 angle = parent->GetRot();
	// 座標
	pos.x = (pos.x - m_vPos.x) * cos(angle.x);
	pos.y = (pos.y - m_vPos.y) * sin(angle.y);
	pos.z = (pos.z - m_vPos.z) * -sin(angle.z);

	m_pWorldTransform->SetPos(m_vPos);
}
XMFLOAT3 CLocalTransform::NewPos(XMFLOAT3 value)
{
	XMFLOAT3 pos = m_pParent->GetPos();
	XMFLOAT3 angle = m_pParent->GetRot();
	m_vPos = value;
	// 座標
	pos.x = (pos.x - m_vPos.x) * cos(angle.x);
	pos.y = (pos.y - m_vPos.y) * sin(angle.y);
	pos.z = (pos.z - m_vPos.z) * -sin(angle.z);
	return pos;
}

XMFLOAT3 CLocalTransform::NewRot(XMFLOAT3 value) 
{ 
	m_vRot = value; return XMFLOAT3(ADD_FLOAT3B(m_vRot, m_pParent->GetRot())); 
};
XMFLOAT3 CLocalTransform::NewScale(XMFLOAT3 value) 
{
	m_vScale = value; return XMFLOAT3(MULTIPLY_FLOAT3B(m_vScale, m_pParent->GetScale())); 
};
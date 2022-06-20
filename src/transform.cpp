//=========================================================
//�쐬:2022/04/19 (�Ηj��)
// �g�����X�t�H�[�� : ���i�׽
//=========================================================

//--- �C���N���[�h��
#include "transform.h"
#include "gameObject.h"
#include "localTrasform.h"
#include <math.h>

// ���O���
namespace
{
	const float RATE_ROTATE = 0.2f;
}

// �R���X�g���N�^
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
	// ���[�J�����W�̕ύX
	if (m_pLocal)
	{
		m_pLocal->Update();
	}

	XMFLOAT3 oldPos = m_vPos;		// ���ݍ��W�m��

	// �����ʂ��ړ��ʂ�
	MULTIPLY_FLOAT3(m_vVel, m_vAccel);	
	// ���W�̈ړ�
	ADD_FLOAT3(m_vPos, m_vVel);

	// �ύX����Ă����
	if (oldPos.x != m_vPos.x ||
		oldPos.y != m_vPos.y ||
		oldPos.z != m_vPos.z)
	{
		// ���S�ʒu����̍����Ƃ�A�p�x��ύX
		//m_vDestRot.y = XMConvertToDegrees(atan2f(-(m_vPos.x - oldPos.x), -(m_vPos.z - oldPos.z)));
	}

	// �ړI�̊p�x�܂ł̍���
	float fDiffRotY = m_vDestRot.y - m_vRot.y;
	if (fDiffRotY >= 180.0f) {
		fDiffRotY -= 360.0f;
	}
	if (fDiffRotY < -180.0f) {
		fDiffRotY += 360.0f;
	}
	// �ړI�̊p�x�܂Ŋ�����������
	m_vRot.y += fDiffRotY * RATE_ROTATE;
	if (m_vRot.y >= 180.0f) {
		m_vRot.y -= 360.0f;
	}
	if (m_vRot.y < -180.0f) {
		m_vRot.y += 360.0f;
	}
}

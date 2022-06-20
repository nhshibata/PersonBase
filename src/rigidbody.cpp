//=========================================================
// �쐬:2022/05/24
// ����
//=========================================================

//--- �C���N���[�h��
#include "rigidbody.h"
#include "transform.h"

//--- �萔��`
namespace {
	const float GRAVITY = 0.98f;		// �d�� ���W�n�ɂ���Č������Ⴄ
}

// �R���X�g���N�^
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

	// �d�͂�^����
	if (m_bGravity)
	{
		pos.y += -GRAVITY;
	}

	// �ʒu�Œ�
	if (m_pFreezPos[0])
		pos.x = *m_pFreezPos[0];
	if (m_pFreezPos[1])
		pos.y = *m_pFreezPos[1];
	if (m_pFreezPos[2])
		pos.z = *m_pFreezPos[2];
	// �p�x
	if (m_pFreezRot[0])
		rot.x = *m_pFreezRot[0];
	if (m_pFreezRot[1])
		rot.y = *m_pFreezRot[1];
	if (m_pFreezRot[2])
		rot.z = *m_pFreezRot[2];

	gameObject->GetTransform()->SetPos(pos);
	gameObject->GetTransform()->SetRot(rot);

	// �������������ĂȂ���
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
// TODO: Init����Ăяo����Ȃ���΋@�\���Ȃ�
void CRigidbody::SetFreezPos(bool x, bool y, bool z)
{
	XMFLOAT3 pos = gameObject->GetTransform()->GetPos();
	// �i�[�t���O���Anull�ł���Ίi�[
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
	// �i�[�t���O���Anull�ł���Ίi�[
	if (x && !m_pFreezRot[0])
		m_pFreezRot[0] = new float(rot.x);
	if (y && !m_pFreezRot[1])
		m_pFreezRot[1] = new float(rot.y);
	if (z && !m_pFreezRot[2])
		m_pFreezRot[2] = new float(rot.z);
}

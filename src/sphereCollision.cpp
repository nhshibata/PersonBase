//=========================================================
//�쐬:2022/05/02
// �R���W�����׽(�����蔻�� ) : �h���׽
//=========================================================

//--- �C���N���[�h��
#include "sphereCollision.h"

//
CSphereCollision::CSphereCollision(float radius)
{

}
//
CSphereCollision::~CSphereCollision()
{

}
bool CSphereCollision::Sphere(XMFLOAT3 Apos, float Ar, XMFLOAT3 Bpos, float Br)
{
	float dx = Apos.x - Bpos.x;
	float dy = Apos.y - Bpos.y;
	float dz = Apos.z - Bpos.z;
	float dr = Ar + Br;
	return dx * dx + dy * dy + dz * dz <= dr * dr;
}
// ���̓����蔻��
bool CSphereCollision::CollisionSphere(XMFLOAT3 pos, float radius)
{
	if (Sphere(m_pTransform->GetPos(), m_fRadius, pos, radius))
	{
		return true;
	}
	return false;
}		
// �R���W�����׽���������ɂƂ��āA�����蔻����s��
bool CSphereCollision::HitCheckPtr(CCollision* col)
{
	CGameObject* obj = col->GetOwner();
	CSphereCollision* com = obj->GetComponent<CSphereCollision>();

	// �R���|�[�l���g�������Ă��Ȃ�
	if (com == nullptr)
	{
		return false;
	}

	// ����
	if (CollisionSphere(obj->GetTransform()->GetPos(), com->GetRadius()))
	{
		HitResponse(col);
		return true;
	}

	return false;
}

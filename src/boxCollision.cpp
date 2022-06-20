//=========================================================
//�쐬:2022/05/02
// �R���W�����׽(�����蔻�� ) : �h���׽
//
//=========================================================

//--- �C���N���[�h��
#include "boxCollision.h"

//
CBoxCollision::CBoxCollision(XMFLOAT3 size)
{

}
CBoxCollision::~CBoxCollision()
{

}
//
bool CBoxCollision::Box(XMFLOAT3 Apos, XMFLOAT3 Asize, XMFLOAT3 Bpos, XMFLOAT3 Bsize)
{
	return (Apos.x - Asize.x <= Bpos.x + Bsize.x) &&
		(Bpos.x - Bsize.x <= Apos.x + Asize.x) &&
		(Apos.y - Asize.y <= Bpos.y + Bsize.y) &&
		(Bpos.y - Bsize.y <= Apos.y + Asize.y) &&
		(Apos.z - Asize.z <= Bpos.z + Bsize.z) &&
		(Bpos.z - Bsize.z <= Apos.z + Asize.z);
}
// �����蔻��
bool CBoxCollision::CollisionAABB(XMFLOAT3 pos, XMFLOAT3 size)
{
	if (Box(m_pTransform->GetPos(), m_vSize, pos, size))
	{
		return true;
	}
	return false;
}
// �R���W�����׽���������ɂƂ��āA�����蔻����s��
bool CBoxCollision::HitCheckPtr(CCollision* col)
{
	CGameObject* obj = col->GetOwner();
	CBoxCollision* com = obj->GetComponent<CBoxCollision>();
	
	if (com == nullptr)
	{
		return false;
	}

	// ����
	if (CollisionAABB(obj->GetTransform()->GetPos(), com->GetSize()))
	{
		HitResponse(col);
		return true;
	}

	return false;
}

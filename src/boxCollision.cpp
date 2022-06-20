//=========================================================
//作成:2022/05/02
// コリジョンｸﾗｽ(当たり判定 ) : 派生ｸﾗｽ
//
//=========================================================

//--- インクルード部
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
// 当たり判定
bool CBoxCollision::CollisionAABB(XMFLOAT3 pos, XMFLOAT3 size)
{
	if (Box(m_pTransform->GetPos(), m_vSize, pos, size))
	{
		return true;
	}
	return false;
}
// コリジョンｸﾗｽを引き数にとって、当たり判定を行う
bool CBoxCollision::HitCheckPtr(CCollision* col)
{
	CGameObject* obj = col->GetOwner();
	CBoxCollision* com = obj->GetComponent<CBoxCollision>();
	
	if (com == nullptr)
	{
		return false;
	}

	// 判定
	if (CollisionAABB(obj->GetTransform()->GetPos(), com->GetSize()))
	{
		HitResponse(col);
		return true;
	}

	return false;
}

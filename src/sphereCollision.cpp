//=========================================================
//作成:2022/05/02
// コリジョンｸﾗｽ(当たり判定 ) : 派生ｸﾗｽ
//=========================================================

//--- インクルード部
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
// 球の当たり判定
bool CSphereCollision::CollisionSphere(XMFLOAT3 pos, float radius)
{
	if (Sphere(m_pTransform->GetPos(), m_fRadius, pos, radius))
	{
		return true;
	}
	return false;
}		
// コリジョンｸﾗｽを引き数にとって、当たり判定を行う
bool CSphereCollision::HitCheckPtr(CCollision* col)
{
	CGameObject* obj = col->GetOwner();
	CSphereCollision* com = obj->GetComponent<CSphereCollision>();

	// コンポーネントを持っていない
	if (com == nullptr)
	{
		return false;
	}

	// 判定
	if (CollisionSphere(obj->GetTransform()->GetPos(), com->GetRadius()))
	{
		HitResponse(col);
		return true;
	}

	return false;
}

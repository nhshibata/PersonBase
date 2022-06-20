//=========================================================
//作成:2022/05/02
// コリジョンｸﾗｽ(当たり判定 ) : 派生ｸﾗｽ
//=========================================================
//--- インクルードガード
#ifndef __SPHERE_COLLISION_H__
#define __SPHERE_COLLISION_H__

//--- インクルード部
#include "collision.h"

//--- クラス定義
class CSphereCollision : public CCollision
{
private:
	float m_fRadius;			// 当たり判定球
public:
	//--- ﾒﾝﾊﾞ関数
	CSphereCollision(float radius = 0.0f);
	~CSphereCollision();

	//--- ゲッター・セッター
	float GetRadius() { return m_fRadius; };
	void SetRadius(float radius) { m_fRadius = radius; };

	bool Sphere(XMFLOAT3 Apos, float Ar, XMFLOAT3 Bpos, float Br);
	bool CollisionSphere(XMFLOAT3 pos, float radius);

	//
	bool HitCheckPtr(CCollision* col);		// コリジョンｸﾗｽを引き数にとって、当たり判定を行う
};

#endif // !__SPHERE_COLLISION_H__

//=========================================================
//作成:2022/05/02
// コリジョンｸﾗｽ(当たり判定 ) : 派生ｸﾗｽ
//=========================================================
//--- インクルードガード
#ifndef __BOX_COLLISION_H__
#define __BOX_COLLISION_H__

//--- インクルード部
#include "collision.h"

//--- クラス定義
class CBoxCollision : public CCollision
{
private:
	XMFLOAT3 m_vSize;			// 当たり判定サイズ

public:
	const std::string CLASS_NAME = "sphereCol";
	std::string GetName() { return CLASS_NAME; };
public:
	CBoxCollision(XMFLOAT3 size = XMFLOAT3(1, 1, 1));
	~CBoxCollision();

	//--- ゲッター・セッター
	XMFLOAT3 GetSize() { return m_vSize; };
	void SetSize(XMFLOAT3 size) { m_vSize = size; };
	bool Box(XMFLOAT3 Apos, XMFLOAT3 Asize, XMFLOAT3 Bpos, XMFLOAT3 Bsize);
	bool CollisionAABB(XMFLOAT3 pos, XMFLOAT3 size);

	//
	bool HitCheckPtr(CCollision* col);		// コリジョンｸﾗｽを引き数にとって、当たり判定を行う

};
#endif // __BOX_COLLISION_H__

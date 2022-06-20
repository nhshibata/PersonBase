//=========================================================
// 作成:2022/05/24
// 物理
//=========================================================

//--- インクルードガード
#ifndef __RIGIDBODY_H__
#define __RIGIDBODY_H__

//---- インクルード部
#include "component.h"

//--- クラス定義
class CRigidbody : CComponent
{
private:
	using XMFLOAT3P = float*[3];
private:
	
	bool m_bGravity;
	bool m_bIsSleep;
	bool m_bCollisionDetectionMode;		// 当たり判定を行うか

	XMFLOAT3 m_vOldPos;
	XMFLOAT3P m_pFreezPos;
	XMFLOAT3P m_pFreezRot;
public:
	CRigidbody();
	~CRigidbody();
	void Update();

	bool UseGravity(){ return m_bGravity; }
	bool IsSleeping(){ return m_bIsSleep; }
	bool SetGravity(bool value){ m_bGravity = value; }
	// 位置・角度固定
	void SetFreezPos(bool x, bool y, bool z);
	void SetFreezRot(bool x, bool y, bool z);
};

#endif // !__RIGIDBODY_H__

//=========================================================
// 作成:2022/04/19
// 更新:2022/05/11 親子関係の実装。ローカル座標用のｸﾗｽ作成
// トランスフォーム : 部品ｸﾗｽ
//=========================================================

//--- インクルードガード
#ifndef __LOCAL_TRANSFORM_H__
#define __LOCAL_TRANSFORM_H__

//--- インクルード部
#include "main.h"

class CTransform;

// ローカル情報
class CLocalTransform
{
private:
	//--- メンバ変数
	CTransform* m_pWorldTransform;	// ワールド情報
	CTransform* m_pParent;
	XMFLOAT3 m_vPos;				// 座標
	XMFLOAT3 m_vRot;				// 角度
	XMFLOAT3 m_vScale;				// 大きさ
	//XMFLOAT3 m_vVel;				// 移動量
	//XMFLOAT3 m_vAccel;			// 加速
public:
	//--- ﾒﾝﾊﾞ関数
	CLocalTransform(CTransform*);
	~CLocalTransform();
	void Update();

	// ゲッター・セッター
	XMFLOAT3 GetPos() { return m_vPos; };
	XMFLOAT3 GetRot() { return m_vRot; };
	XMFLOAT3 GetScale() { return m_vScale; };
	//XMFLOAT3 GetVel()				{ return m_vVel; };
	//XMFLOAT3 GetAccel()			{ return m_vAccel; };
	void SetPos(XMFLOAT3 value) { m_vPos = value; };
	void SetRot(XMFLOAT3 value) { m_vRot = value; /*ADD_FLOAT3(m_vRot, m_pWorldTransform->GetParent()->GetRot());*/ };
	void SetScale(XMFLOAT3 value) { m_vScale = value; };
	//void SetVel(XMFLOAT3 value)	{ m_vVel = value; };
	//void SetAccel(XMFLOAT3 value)	{ m_vAccel = value; };
	XMFLOAT3 NewPos(XMFLOAT3 value);
	XMFLOAT3 NewRot(XMFLOAT3 value);
	XMFLOAT3 NewScale(XMFLOAT3 value);
};

#endif
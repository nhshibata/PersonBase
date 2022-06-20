//=========================================================
// 作成:2022/04/19
// 更新:2022/05/11 親子関係の実装。ローカル座標用のｸﾗｽ作成
// トランスフォーム : 部品ｸﾗｽ
//=========================================================

//--- インクルードガード
#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

//--- インクルード部
//#include "main.h"
#include "localTrasform.h"
#include "component.h"
#include <vector>

//--- 前方参照
//class CLocalTransform;
//class CGameObject;

//--- クラス定義
class CTransform : public CComponent
{
private:
	//--- メンバ変数
	XMFLOAT3 m_vPos;			// 座標
	XMFLOAT3 m_vTargetPos;		// 目標座標
	XMFLOAT3 m_vRot;			// 角度
	XMFLOAT3 m_vDestRot;		// 目標角度
	XMFLOAT3 m_vScale;			// 大きさ
	XMFLOAT3 m_vVel;			// 移動量
	XMFLOAT3 m_vAccel;			// 加速
protected:
	//CGameObject* m_pOwner;				// 持ち主
	CTransform* m_pParent;				// 親オブジェクト
	std::vector<CTransform*> m_pChilds;	// 子要素リスト
	CLocalTransform* m_pLocal;			// 親子関係時のローカル座標
public:
	//--- メンバ関数
	CTransform();
	CTransform(XMFLOAT3 pos, XMFLOAT3 rot, XMFLOAT3 size, XMFLOAT3 vel = XMFLOAT3{0,0,0}, CGameObject* pOwner = nullptr);
	~CTransform();
	void Update();

	// ゲッター・セッター
	XMFLOAT3 GetPos()					{ return m_vPos; };
	XMFLOAT3 GetRot()					{ return m_vRot; };
	XMFLOAT3 GetScale()					{ return m_vScale; };
	XMFLOAT3 GetVel()					{ return m_vVel; };
	XMFLOAT3 GetAccel()					{ return m_vAccel; };
	void SetPos(XMFLOAT3 value)			{ if (!m_pLocal)m_vPos = value; else m_vPos = m_pLocal->NewPos(value); };
	void SetTargetPos(XMFLOAT3 value)	{ m_vTargetPos = value; };
	void SetRot(XMFLOAT3 value)			{ if (!m_pLocal)m_vRot = value; else m_vRot = m_pLocal->NewRot(value); };
	void SetDestRot(XMFLOAT3 value)		{ m_vDestRot = value; };
	void SetScale(XMFLOAT3 value)		{ if (!m_pLocal)m_vScale = value; else m_vScale = m_pLocal->NewScale(value); };
	void SetVel(XMFLOAT3 value)			{ m_vVel = value; };
	void SetAccel(XMFLOAT3 value)		{ m_vAccel = value; };

	// 親子関係
	//CGameObject* GetOwner()				{ return m_pOwner; };				// 持ち主を返す
	CTransform* GetParent()				{ return m_pParent; };				// 親を返す
	int GetChildCount()					{ return (int)m_pChilds.size(); };	// 要素数を返す
	CTransform* GetChild(int cnt)		{ return m_pChilds[cnt]; };			// 指定番号目の子要素を返す
	CLocalTransform* GetLocal()			{ return m_pLocal;}					// ローカルﾃﾞｰﾀを渡す
	//void SetOwner(CGameObject* pOwner)	{ m_pOwner = pOwner; }				// 持ち主を設定
	void SetParent(CTransform* parent)	{ m_pParent = parent; m_pLocal = new CLocalTransform(this); }	// 親要素追加
	void AddChild(CTransform* child)	{ m_pChilds.push_back(child); child->SetParent(this); }			// 子要素追加
};

#endif // !__TRANSFORM_H__


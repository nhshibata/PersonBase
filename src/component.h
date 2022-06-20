//=========================================================
//作成:2022/04/19 (火曜日)
// コンポーネントｸﾗｽ : 基底クラス
//=========================================================

//--- インクルードガード
#ifndef __COMPONENT_H__
#define __COMPONENT_H__

//--- インクルード部
#include "gameObject.h"
#include "fps.h"			// 時間を知ることが必要なため、インクルード

//--- 前方参照
//class CGameObject;

//--- クラス定義
class CComponent
{
private:

protected:
	CGameObject* m_pOwner;			// 持ち主
	bool m_bActive;					// アクティブ状態
	
public:
	// 自身の所有者を示す定数定義
#define gameObject GetOwner()

public:
	//--- ﾒﾝﾊﾞ関数
	CComponent():m_pOwner(nullptr),m_bActive(true){};
	CComponent(CGameObject* owner):m_pOwner(owner), m_bActive(true) {};
	virtual ~CComponent() {};
	virtual void Init() = 0;			// 初期化 他コンポーネントの取得などを行う 必ず実装
	virtual void Update() = 0;			// 更新 必ず実装
	virtual void LateUpdate() {};		// 遅い更新
	virtual void FixedUpdate() {};		// 一定時間の更新

	// セッター・ゲッター
	bool IsActive() { return m_bActive; };
	void SetActive(bool value) { m_bActive = value; };
	std::string GetName() { return typeid(this).name; }
	CGameObject* GetOwner() { return m_pOwner; };
	CTransform* Transform() { return m_pOwner->GetTransform(); }
	CTag::E_Tag Tag() { return m_pOwner->GetTagPtr()->GetTag(); }

	// gameobject省略用関数
	void AddComponent(CComponent* com) { gameObject->AddComponent(com); }
	template <class T> T* GetComponent() { return gameObject->GetComponent<T>(); }
	//CComponent* GetComponent(std::string name) { gameObject->GetComponent(name); }

	//--- 仮想関数
	// 衝突したときに呼び出される関数
	// 実装したい時にオーバーライドする
	virtual void OnCollisionStay(CGameObject* obj) {};		// 
	virtual void OnCollisionEnter(CGameObject* obj) {};		// 
	virtual void OnTriggerStay(CGameObject* obj) {};		// 
	virtual void OnTriggerEnter(CGameObject* obj) {};		// 
	void HitCheck(CGameObject* obj) { OnCollisionStay(obj); OnCollisionEnter(obj); OnTriggerStay(obj); OnTriggerEnter(obj); };

};

#endif __COMPONENT_H__

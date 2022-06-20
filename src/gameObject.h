//=========================================================
//作成:2022/04/19 (火曜日)
// ゲームオブジェクト : 基底クラス
// 
//=========================================================

//--- インクルードガード
#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

//--- インクルード部
#include <string>
#include <map>
#include <list>
#include "transform.h"
#include "tag.h"
#include "layer.h"
#include <typeinfo>

//--- 前方参照
class CComponent;
class CScene;

//--- クラス定義
class CGameObject
{
public:
	//--- 列挙体定義
	enum E_ObjectState // オブジェクトの状態
	{
		ACTIVE,				// 更新状態
		WAIT,				// 待機
		DESTROY,			// 削除
		TAKEOVER,			// 引き継ぎ（使いまわし)
		MAX_OBJECT_STATE,	// 最大数
	};
private:
	//--- 静的メンバ変数
	using GAMEOBJECT = std::map <std::string, CGameObject*>;
	using GAMEOBJECT_PAIR = std::pair<std::string, CGameObject*>;
	static GAMEOBJECT m_pObjects;			// 全てのゲームオブジェクトを管理
	static CScene* m_pScene;
protected:
	//--- 再定義
	using COOMPONENT = std::list<CComponent*>;
	//using COOMPONENT_PAIR 
	//--- メンバ変数
	std::string m_objName;		// 名前
	COOMPONENT m_pComponent;	// 所持コンポーネント
	E_ObjectState m_eState;		// 現在状況
	CTransform m_Transform;		// パラメータ
	CTag m_Tag;					// タグ
	CLayer m_Layer;				// レイヤー
	
public:
	CGameObject();
	CGameObject(std::string name, CTransform trans);
	CGameObject(std::string name, CTransform trans, CTag* tag, CLayer* layer);
	virtual ~CGameObject();

	virtual void Init();				// 初期化
	virtual void Update();				// ゲームオブジェクトごとの更新
	virtual void LateUpdate();			// ゲームオブジェクトごとの更新
	virtual void FixedUpdate();		// 一定時間の更新

	//--- コンポーネント
	bool AddComponent(CComponent* com);				// コンポーネントの追加
	bool RemoveComponent(std::string comName);		// コンポーネントの破棄
	//CComponent* GetComponent(std::string comName);	// コンポーネントの取得

	template <class T> T* GetComponent()
	{
		T* component = nullptr;
		for (COOMPONENT::iterator it = m_pComponent.begin(); it != m_pComponent.end(); ++it) {
			if (typeid(*component).name() == typeid(it).name())
			{
				component = (T*)(*it);
				return component;
			}
		}
		return nullptr;
	}

	// ゲッター・セッター
	CTransform* GetTransform() { return &m_Transform; };
	std::string GetName() { return m_objName; }
	E_ObjectState GetState() { return m_eState; };
	CTag* GetTagPtr() { return &m_Tag; };
	CLayer* GetLayerPtr() { return &m_Layer; };
	void SetName(std::string name) { m_objName = name; };
	void SetState(E_ObjectState state) { m_eState = state; };
	void SetTag(CTag::E_Tag tag) { m_Tag.SetTag(tag); };
	void SetLayer(CLayer::E_Layer layer) { m_Layer.SetLayer(layer); };

	//--- 仮想関数
	// コンポーネントが持つ衝突関数の呼び出し
	void OnCollisionEnter(CGameObject* obj);
	void OnCollisionStay(CGameObject* obj);
	void OnTriggerStay(CGameObject* obj);
	void OnTriggerEnter(CGameObject* obj);
	//void HitCheck(CGameObject* obj);

	//--- 静的メンバ変数
	static void AddObject(CGameObject* obj) { m_pObjects.insert(GAMEOBJECT_PAIR(obj->GetName(), obj)); SetSceneObject(obj);}
	static void SetSceneObject(CGameObject* obj);
	static CGameObject* Find(std::string name);
	static CGameObject* Find(CTag::E_Tag tag);
	static std::list<CGameObject*> FindObjects(CTag::E_Tag tag);
	static void SetScene(CScene* scene) { m_pScene = scene; }
};

#endif __GAME_OBJECT_H__

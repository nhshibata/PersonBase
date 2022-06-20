//=========================================================
// ゲームオブジェクト : 基底クラス
//---------------------------------------------------------
// 作成:2022/04/19 (火曜日)
// 更新:2022/05/11 タグが一致するオブジェクトを全て取得する関数作成
//			課題: 同一のコンポーネントを使う場合、mapは適切ではない
//=========================================================

//--- インクルード部
#include "gameObject.h"
#include "component.h"
#include "scene.h"

//--- 静的メンバ変数
std::map<std::string, CGameObject*> CGameObject::m_pObjects;
CScene* CGameObject::m_pScene;

// コンストラクタ
CGameObject::CGameObject()
{
	AddObject(this);
}
CGameObject::CGameObject(std::string name, CTransform trans)
	:m_objName(name), m_Transform(trans), m_eState(E_ObjectState::ACTIVE),m_pComponent()
{
	AddObject(this);
}
CGameObject::CGameObject(std::string name, CTransform trans, CTag* tag, CLayer* layer)
	:m_objName(name), m_Transform(trans), m_Tag(*tag), m_Layer(*layer),m_eState(E_ObjectState::ACTIVE),m_pComponent()
{
	AddObject(this);
}
CGameObject::~CGameObject()
{
	// コンポーネントの破棄
	COOMPONENT::iterator it;
	for (it = m_pComponent.begin(); it != m_pComponent.end(); ++it)
	{
		delete (*it);
	}

	// 自身を除外
	m_pObjects.erase(GetName());
}
// 初期化
void CGameObject::Init()
{
	// 持ち主を教える
	m_Transform.SetOwner(this);

	// コンポーネントの初期化
	COOMPONENT::iterator it;
	for (it = m_pComponent.begin(); it != m_pComponent.end(); ++it)
	{
		(*it)->Init();
	}
}
// コンポーネントの更新
void CGameObject::Update()
{
	COOMPONENT::iterator it;
	for (it = m_pComponent.begin(); it != m_pComponent.end(); ++it)
	{
		if (!(*it)->IsActive())
		{
			continue;
		}

		(*it)->Update();
	}
}
// ゲームオブジェクトごとの遅い更新
void CGameObject::LateUpdate()
{
	COOMPONENT::iterator it;
	for (it = m_pComponent.begin(); it != m_pComponent.end(); ++it)
	{
		if (!(*it)->IsActive())
		{
			continue;
		}

		(*it)->LateUpdate();
	}
}
// 一定時間の更新
void CGameObject::FixedUpdate()
{
	COOMPONENT::iterator it;
	for (it = m_pComponent.begin(); it != m_pComponent.end(); ++it)
	{
		if (!(*it)->IsActive())
		{
			continue;
		}

		(*it)->FixedUpdate();
	}
}
//CComponent* CGameObject::Draw(){}
// コンポーネントの追加
bool CGameObject::AddComponent(CComponent* com)
{
	COOMPONENT::iterator it;
	// 登録されていれば追加しない
	for (it = m_pComponent.begin(); it != m_pComponent.end(); ++it)
	{
		// 文字列を比較し、一致していれば返す
		//if ((*it)->GetName().find(com->GetName()) != std::string::npos)
		//{
		//	return false;
		//}
	}
	// 追加
	//m_pComponent.insert(COOMPONENT_PAIR(com->GetName(), com));
	m_pComponent.push_back(com);
	return true;
}
// コンポーネントの破棄
bool CGameObject::RemoveComponent(std::string comName)
{
	COOMPONENT::iterator it;
	for (it = m_pComponent.begin(); it != m_pComponent.end(); ++it)
	{
		// 文字列を比較し、一致していれば返す
		//if ((*it)->GetName().find(comName) != std::string::npos)
		//{
		//	// 削除
		//	delete (*it);
		//	// 除外
		//	m_pComponent.erase(it);
		//	break;
		//}
	}
	return true;
}
// 文字列を引き数にしたコンポーネントの取得
//CComponent* CGameObject::GetComponent(std::string comName)
//{
//	//return m_pComponent[comName];
//
//	COOMPONENT::iterator it;
//	for (it = m_pComponent.begin(); it != m_pComponent.end(); ++it)
//	{
//		// 文字列を比較し、一致していれば返す
//		if ((*it)->GetName().find(comName) != std::string::npos)
//		{
//			return (*it);
//		}
//	}
//	return nullptr;
//}
//
void CGameObject::OnCollisionEnter(CGameObject* obj)
{
	COOMPONENT::iterator it = m_pComponent.begin();
	for (; it != m_pComponent.end(); ++it)
	{
		(*it)->OnCollisionEnter(obj);
	}
}
void CGameObject::OnCollisionStay(CGameObject* obj)
{
	COOMPONENT::iterator it = m_pComponent.begin();
	for (; it != m_pComponent.end(); ++it)
	{
		(*it)->OnCollisionStay(obj);
	}
}
void CGameObject::OnTriggerStay(CGameObject* obj)
{
	COOMPONENT::iterator it = m_pComponent.begin();
	for (; it != m_pComponent.end(); ++it)
	{
		(*it)->OnTriggerStay(obj);
	}
}
void CGameObject::OnTriggerEnter(CGameObject* obj)
{
	COOMPONENT::iterator it = m_pComponent.begin();
	for (; it != m_pComponent.end(); ++it)
	{
		(*it)->OnTriggerEnter(obj);
	}
}

//--- 静的メンバ関数
// オブジェクト名で取得
CGameObject* CGameObject::Find(std::string name)
{
	// 名前があればポインタを返す
	// なければnullptrが返る
	return m_pObjects[name];
}
// tagが一致するオブジェクトを返す
CGameObject* CGameObject::Find(CTag::E_Tag tag)
{
	GAMEOBJECT::iterator it = m_pObjects.begin();

	for (; it != m_pObjects.end(); ++it)
	{
		if ((*it).second->GetTagPtr()->GetTag() == tag)
		{
			return (*it).second;
		}
	}
	return nullptr;
}
// tagが一致するオブジェクトを全て返す
std::list<CGameObject*> CGameObject::FindObjects(CTag::E_Tag tag)
{
	GAMEOBJECT::iterator it = m_pObjects.begin();
	std::list<CGameObject*> objs(0);

	for (; it != m_pObjects.end(); ++it)
	{
		if ((*it).second->GetTagPtr()->GetTag() == tag)
		{
			objs.push_back((*it).second);
		}
	}
	return objs;
}

void CGameObject::SetSceneObject(CGameObject* obj)
{
	m_pScene->SetGameObject(obj);
}
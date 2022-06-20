//=========================================================
// 作成:2022/04/21
// Factoryメソッド
// ComponentFactryを呼び出し、依頼されたオブジェクトを作成する
// +α タグの設定やレイヤーの設定も行う
// NOTE: !あくまでも基本的なオブジェクトのみ! 特定のキャラを作成する場合、CharacterFactoryを作る
//=========================================================

//--- インクルード部
#include "objectFactory.h"
#include "componentFactory.h"
#include "gameObject.h"

// 依頼に応じて生成し、インスタンスを引き渡す
CGameObject* CObjectFactory::CreateObject(E_ObjFactory oder)
{
	CGameObject* obj = new CGameObject();

	switch (oder)
	{
	case CObjectFactory::OBJ_EMPTY:
		break;
	case CObjectFactory::OBJ_UI:
		break;
	case CObjectFactory::OBJ_DEFAULT:
		break;
	default:
		break;
	}

	return obj;
}
// オブジェクトを受け取り、依頼のコンポーネントを追加する
bool CObjectFactory::CreateObject(CGameObject* owner, E_ObjFactory oder)
{
	// 工場の生成
	CComponentFactory* pFactory = new CComponentFactory();

	// コンポーネントの追加
	switch (oder)
	{
	case CObjectFactory::OBJ_EMPTY:
		break;
	case CObjectFactory::OBJ_UI:
		owner->AddComponent(pFactory->CreateComponent(owner, pFactory->COM_CURSOR));
		break;
	case CObjectFactory::OBJ_DEFAULT:
		owner->AddComponent(pFactory->CreateComponent(owner, pFactory->COM_COLLISION));
		break;
	default:
		break;
	}

	// 下の処理は行わない
	if (oder == OBJ_EMPTY)
	{
		return true;
	}
	// レイヤーとタグの設定
	SetLayer(owner, oder);
	SetTag(owner, oder);

	return true;
}
// タグの設定
bool CObjectFactory::SetTag(CGameObject* owner, E_ObjFactory oder)
{
	//owner->SetTag(CTag::PLAYER);
	return true;
}
// レイヤーの設定
bool CObjectFactory::SetLayer(CGameObject* owner, E_ObjFactory oder)
{
	//owner->SetLayer(CLayer::UI);
	return true;
}
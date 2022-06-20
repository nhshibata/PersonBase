//=========================================================
//作成:2022/04/20 (水曜日)
// シーンｸﾗｽ : 基底クラス
//=========================================================

//--- インクルード部
#include "scene.h"
#include "component.h"
#include "collision.h"

//--- 静的メンバ変数
CScene* CScene::m_pCurrentScene;

// コンストラクタ
CScene::CScene():m_pObjects(0),m_pDrawComponent(0)
{
	Init();
}
// デストラクタ
CScene::~CScene()
{
	Uninit();
}
// 初期化
void CScene::Init()
{
	// 現在シーンを教える
	// シーンに対してゲームオブジェクトを引き渡す
	CGameObject::SetScene(this);
}
// 解放
void CScene::Uninit()
{
	// イテレーター
	GAMEOBJECT_VEC::iterator it;
	//COMPONENT_LIST::iterator drawIt;

	for (it = m_pObjects.begin(); it != m_pObjects.end(); ++it)
	{
		delete (*it);
	}
}
// 更新
void CScene::Update()
{
	// 変数宣言
	GAMEOBJECT_VEC::iterator it;		// イテレーター
	GAMEOBJECT_VEC pDestoroyObj(0);	// 破棄するオブジェクトを格納
	GAMEOBJECT_VEC pActiveObj(0);		// アクティブなオブジェクトを格納

	// オブジェクト更新
	// コンポーネントの更新
	for (it = m_pObjects.begin(); it != m_pObjects.end(); ++it)
	{
		// 状態により分岐
		switch ((*it)->GetState())
		{
		case CGameObject::ACTIVE:				// 通常の更新
			// トランスフォームの更新
			(*it)->GetTransform()->Update();
			// アクティブなオブジェクトを格納
			pActiveObj.push_back(*it);
			break;
		case CGameObject::WAIT:					// 待機
			break;
		case CGameObject::DESTROY:				// 削除オブジェクト
			// 格納
			pDestoroyObj.push_back(*it);
			break;
		case CGameObject::TAKEOVER:				// 引き継ぎ待ち
			break;
		case CGameObject::MAX_OBJECT_STATE:		// 最大数
			break;
		default:
			break;
		}
	}

	// 当たり判定の実行
	CollisionCheck();

	//--- アクティブのものだけ
	// コンポーネントの更新
	for (it = pActiveObj.begin(); it != pActiveObj.end(); ++it)
	{
		(*it)->Update();
	}
	// 最後の方に更新したいものを更新
	for (it = pActiveObj.begin(); it != pActiveObj.end(); ++it)
	{
		(*it)->LateUpdate();
	}

	// オブジェクトの破棄
	for (it = pDestoroyObj.begin(); it != pDestoroyObj.end(); ++it)
	{
		delete (*it);
	}

	// 配列のリセット
	pActiveObj.clear();
	pDestoroyObj.clear();
}
// 一定時間の更新
void CScene::FixedUpdate()
{
	GAMEOBJECT_VEC::iterator it;		// イテレーター

	// オブジェクト更新
	// コンポーネントの更新
	for (it = m_pObjects.begin(); it != m_pObjects.end(); ++it)
	{
		// 状態により分岐
		if ((*it)->GetState() == CGameObject::ACTIVE)
			(*it)->FixedUpdate();
	}
}
// 描画
void CScene::Draw()
{
	COMPONENT_LIST::iterator it;		// イテレーター
	
	// レイヤー順に並び替え
	// FIXME: 現在状況では、レイヤーを設定していないDrawComponentを定義するべきか?
	//m_pDrawComponent.sort([](CLayer i, CLayer j)->bool
	//{
	//	return i.GetLayer() < j.GetLayer();	// 昇順
	//});

	// 描画
	for (it = m_pDrawComponent.begin(); it != m_pDrawComponent.end(); ++it)
	{
		(*it)->Update();
	}

	// クリア
	//m_pDrawComponent.clear();
}
// 当たり判定
// REVIEW: 改善の余地あり
void CScene::CollisionCheck()
{
	// イテレーター
	COLLISION_VEC::iterator it;		

	for (it = m_pCollisionComponent.begin(); it != m_pCollisionComponent.end(); ++it)
	{
		for (COLLISION_VEC::iterator objIt = m_pCollisionComponent.begin(); objIt != m_pCollisionComponent.end(); ++objIt)
		{
			// 同一のオブジェクトは判定しない
			if (it == objIt)
			{
				continue;
			}

			// コリジョンｸﾗｽを引き渡す
			(*it)->HitCheckPtr((*objIt));
		}// pair
	}// this

	// 配列を空に
	m_pCollisionComponent.clear();
}

//--- セッター・ゲッター
//CGameObject* CScene::GetGameObject(std::string name)
//{
//	GAMEOBJECT_VEC::iterator it;		// イテレーター
//
//	for (it = m_pObjects.begin(); it < m_pObjects.end(); ++it)
//	{
//		// 名前が含まれていれば
//		if ((*it)->GetName().compare(name) != -1)
//		{
//			return (*it);
//		}
//	}
//
//	return nullptr;
//}
//// タグによる取得
//// 同一のタグ名をランダムに探すため、使い道が限られる
//CGameObject* CScene::GetGameObject(CTag::E_Tag tag)
//{
//	GAMEOBJECT_VEC::iterator it;		// イテレーター
//
//	for (it = m_pObjects.begin(); it < m_pObjects.end(); ++it)
//	{
//		// 同一のタグ名なら
//		if ((*it)->GetTagPtr()->GetTag() == tag)
//		{
//			return (*it);
//		}
//	}
//	return nullptr;
//}

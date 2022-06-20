//=========================================================
//作成:2022/04/19 (火曜日)
// シーンｸﾗｽ : 基底クラス
//=========================================================
#ifndef __SCENE_H__
#define __SCENE_H__

//--- インクルード部
#include "gameObject.h"
#include <vector>
#include <list>

//--- 定数定義
#define GAME Get()

//--- 前方参照
class CCollision;
//--- クラス定義
class CScene
{
private:
	//--- 静的メンバ変数
	static CScene* m_pCurrentScene;
protected:
	//--- 再定義
	using GAMEOBJECT_VEC = std::vector<CGameObject*>;
	using COMPONENT_LIST = std::list<CComponent*>;
	using COLLISION_VEC = std::vector<CCollision*>;
protected:
	//--- メンバ変数
	GAMEOBJECT_VEC m_pObjects;				// ゲームシーンごとのオブジェクト
	COMPONENT_LIST m_pDrawComponent;		// 描画するコンポーネント(配列であり、ソートするかも。毎フレーム空にする)
	COLLISION_VEC m_pCollisionComponent;	// 当たり判定ｸﾗｽ

	// TODO: 破棄しないオブジェクト用の静的変数を用意すべきか？
	void CollisionCheck();
public:
	//--- ﾒﾝﾊﾞ関数
	CScene();
	virtual ~CScene();
	virtual void Init();
	virtual void Uninit();
	virtual void Update();
	virtual void FixedUpdate();
	virtual void Draw();

	//--- セッター・ゲッター
	void SetGameObject(CGameObject* obj) { // オブジェクト配列内に存在するか検索 最後尾であれば、配列内に存在するため、格納
		if(std::find(m_pObjects.begin(), m_pObjects.end(), obj) == m_pObjects.end())m_pObjects.push_back(obj); }
	void SetDrawComponent(CComponent* com) { m_pDrawComponent.push_back(com); }
	void SetColComponent(CCollision* com) { m_pCollisionComponent.push_back(com); }

	//--- 静的ﾒﾝﾊﾞ関数
	static void SetScene(CScene* scene){ m_pCurrentScene = scene; };	// シーンの更新
	static CScene* Get() { return m_pCurrentScene; };					// 現在シーンの取得
};

#endif // !__SCENE_H__

/*
シーンで行うこと
ゲームオブジェクトクラスの更新(および、各コンポーネントの更新)
オブジェクト同士の当たり判定(GetComponentで確認を行う)
シーン遷移の条件
ゲームオブジェクトのDrawから引き渡された描画の実行

// コンポーネントの認識のため、命名規則を設ける。
// 例 : 描画するためのコンポーネントにはDraw、当たり判定にはCollisionを付ける

*/


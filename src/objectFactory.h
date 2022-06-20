//=========================================================
// 作成:2022/04/21
// Factoryメソッド
// ComponentFactryを呼び出し、依頼されたオブジェクトを作成する
// +α タグの設定やレイヤーの設定も行う
//=========================================================

//--- インクルードガード
#ifndef __OBJECT_FACTORY_H__
#define __OBJECT_FACTORY_H__

//--- 前方参照
class CGameObject;

//--- ｸﾗｽ定義
class CObjectFactory
{
public:
	enum E_ObjFactory
	{
		OBJ_EMPTY,		// 空のオブジェクト
		OBJ_UI,			// UI
		OBJ_BG,			// BG
		OBJ_DEFAULT,	// 通常
		OBJ_STATIC,		// 静的オブジェクト(動かない)

		OBJ_DEBUG,		// 必要か?デバッグ用
	};
public:
	CObjectFactory() {};
	~CObjectFactory() {};

	CGameObject* CreateObject(E_ObjFactory oder);
	bool CreateObject(CGameObject* obj, E_ObjFactory oder);
	bool SetTag(CGameObject* obj, E_ObjFactory oder);
	bool SetLayer(CGameObject* obj, E_ObjFactory oder);

};

#endif // !__OBJECT_FACTORY_H__


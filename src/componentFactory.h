//=========================================================
// 作成:2022/04/21
// Factoryメソッド
//=========================================================
//--- インクルードガード
#ifndef __COMPONENT_FACTORY_H__
#define __COMPONENT_FACTORY_H__

//--- インクルード部
#include "component.h"

//--- 前方参照
class CGameObject;

//--- クラス定義
class CComponentFactory
{
private:
public:
	// TODO: コンポーネントを追加するごとに、ここも追加する必要がある
	enum E_Component
	{
		COM_COLLISION,
		COM_CURSOR,
	};
public:
	CComponentFactory(){};	
	~CComponentFactory() {};

	CComponent* CreateComponent(CGameObject* obj, E_Component com);// コンポーネントの仕様上、gameObjectを受け取る必要がある。
};

#endif // !__COMPONENT_FACTORY_H__


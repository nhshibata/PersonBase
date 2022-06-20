//=========================================================
// 作成:2022/04/22
// Factoryメソッド
//=========================================================

//--- インクルード部
#include "componentFactory.h"
#include "boxCollision.h"
#include "sphereCollision.h"
#include "cursor.h"
#include "player.h"

// コンポーネント作成
CComponent* CComponentFactory::CreateComponent(CGameObject* owner, E_Component com)
{
	switch (com)
	{
	case CComponentFactory::COM_COLLISION:
		return new CCollision(owner);
		break;
	case CComponentFactory::COM_CURSOR:
		return new CCursor(owner);
		break;
	default:
		break;
	}
	owner->GetComponent<CSphereCollision>();

	return nullptr;
}
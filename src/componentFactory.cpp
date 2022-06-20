//=========================================================
// �쐬:2022/04/22
// Factory���\�b�h
//=========================================================

//--- �C���N���[�h��
#include "componentFactory.h"
#include "boxCollision.h"
#include "sphereCollision.h"
#include "cursor.h"
#include "player.h"

// �R���|�[�l���g�쐬
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
//=========================================================
// �쐬:2022/04/21
// Factory���\�b�h
//=========================================================
//--- �C���N���[�h�K�[�h
#ifndef __COMPONENT_FACTORY_H__
#define __COMPONENT_FACTORY_H__

//--- �C���N���[�h��
#include "component.h"

//--- �O���Q��
class CGameObject;

//--- �N���X��`
class CComponentFactory
{
private:
public:
	// TODO: �R���|�[�l���g��ǉ����邲�ƂɁA�������ǉ�����K�v������
	enum E_Component
	{
		COM_COLLISION,
		COM_CURSOR,
	};
public:
	CComponentFactory(){};	
	~CComponentFactory() {};

	CComponent* CreateComponent(CGameObject* obj, E_Component com);// �R���|�[�l���g�̎d�l��AgameObject���󂯎��K�v������B
};

#endif // !__COMPONENT_FACTORY_H__


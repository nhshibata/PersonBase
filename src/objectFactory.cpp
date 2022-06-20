//=========================================================
// �쐬:2022/04/21
// Factory���\�b�h
// ComponentFactry���Ăяo���A�˗����ꂽ�I�u�W�F�N�g���쐬����
// +�� �^�O�̐ݒ�⃌�C���[�̐ݒ���s��
// NOTE: !�����܂ł���{�I�ȃI�u�W�F�N�g�̂�! ����̃L�������쐬����ꍇ�ACharacterFactory�����
//=========================================================

//--- �C���N���[�h��
#include "objectFactory.h"
#include "componentFactory.h"
#include "gameObject.h"

// �˗��ɉ����Đ������A�C���X�^���X�������n��
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
// �I�u�W�F�N�g���󂯎��A�˗��̃R���|�[�l���g��ǉ�����
bool CObjectFactory::CreateObject(CGameObject* owner, E_ObjFactory oder)
{
	// �H��̐���
	CComponentFactory* pFactory = new CComponentFactory();

	// �R���|�[�l���g�̒ǉ�
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

	// ���̏����͍s��Ȃ�
	if (oder == OBJ_EMPTY)
	{
		return true;
	}
	// ���C���[�ƃ^�O�̐ݒ�
	SetLayer(owner, oder);
	SetTag(owner, oder);

	return true;
}
// �^�O�̐ݒ�
bool CObjectFactory::SetTag(CGameObject* owner, E_ObjFactory oder)
{
	//owner->SetTag(CTag::PLAYER);
	return true;
}
// ���C���[�̐ݒ�
bool CObjectFactory::SetLayer(CGameObject* owner, E_ObjFactory oder)
{
	//owner->SetLayer(CLayer::UI);
	return true;
}
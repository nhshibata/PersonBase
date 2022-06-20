//=========================================================
// �쐬:2022/04/21
// Factory���\�b�h
// ComponentFactry���Ăяo���A�˗����ꂽ�I�u�W�F�N�g���쐬����
// +�� �^�O�̐ݒ�⃌�C���[�̐ݒ���s��
//=========================================================

//--- �C���N���[�h�K�[�h
#ifndef __OBJECT_FACTORY_H__
#define __OBJECT_FACTORY_H__

//--- �O���Q��
class CGameObject;

//--- �׽��`
class CObjectFactory
{
public:
	enum E_ObjFactory
	{
		OBJ_EMPTY,		// ��̃I�u�W�F�N�g
		OBJ_UI,			// UI
		OBJ_BG,			// BG
		OBJ_DEFAULT,	// �ʏ�
		OBJ_STATIC,		// �ÓI�I�u�W�F�N�g(�����Ȃ�)

		OBJ_DEBUG,		// �K�v��?�f�o�b�O�p
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


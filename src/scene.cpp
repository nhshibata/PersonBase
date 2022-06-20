//=========================================================
//�쐬:2022/04/20 (���j��)
// �V�[���׽ : ���N���X
//=========================================================

//--- �C���N���[�h��
#include "scene.h"
#include "component.h"
#include "collision.h"

//--- �ÓI�����o�ϐ�
CScene* CScene::m_pCurrentScene;

// �R���X�g���N�^
CScene::CScene():m_pObjects(0),m_pDrawComponent(0)
{
	Init();
}
// �f�X�g���N�^
CScene::~CScene()
{
	Uninit();
}
// ������
void CScene::Init()
{
	// ���݃V�[����������
	// �V�[���ɑ΂��ăQ�[���I�u�W�F�N�g�������n��
	CGameObject::SetScene(this);
}
// ���
void CScene::Uninit()
{
	// �C�e���[�^�[
	GAMEOBJECT_VEC::iterator it;
	//COMPONENT_LIST::iterator drawIt;

	for (it = m_pObjects.begin(); it != m_pObjects.end(); ++it)
	{
		delete (*it);
	}
}
// �X�V
void CScene::Update()
{
	// �ϐ��錾
	GAMEOBJECT_VEC::iterator it;		// �C�e���[�^�[
	GAMEOBJECT_VEC pDestoroyObj(0);	// �j������I�u�W�F�N�g���i�[
	GAMEOBJECT_VEC pActiveObj(0);		// �A�N�e�B�u�ȃI�u�W�F�N�g���i�[

	// �I�u�W�F�N�g�X�V
	// �R���|�[�l���g�̍X�V
	for (it = m_pObjects.begin(); it != m_pObjects.end(); ++it)
	{
		// ��Ԃɂ�蕪��
		switch ((*it)->GetState())
		{
		case CGameObject::ACTIVE:				// �ʏ�̍X�V
			// �g�����X�t�H�[���̍X�V
			(*it)->GetTransform()->Update();
			// �A�N�e�B�u�ȃI�u�W�F�N�g���i�[
			pActiveObj.push_back(*it);
			break;
		case CGameObject::WAIT:					// �ҋ@
			break;
		case CGameObject::DESTROY:				// �폜�I�u�W�F�N�g
			// �i�[
			pDestoroyObj.push_back(*it);
			break;
		case CGameObject::TAKEOVER:				// �����p���҂�
			break;
		case CGameObject::MAX_OBJECT_STATE:		// �ő吔
			break;
		default:
			break;
		}
	}

	// �����蔻��̎��s
	CollisionCheck();

	//--- �A�N�e�B�u�̂��̂���
	// �R���|�[�l���g�̍X�V
	for (it = pActiveObj.begin(); it != pActiveObj.end(); ++it)
	{
		(*it)->Update();
	}
	// �Ō�̕��ɍX�V���������̂��X�V
	for (it = pActiveObj.begin(); it != pActiveObj.end(); ++it)
	{
		(*it)->LateUpdate();
	}

	// �I�u�W�F�N�g�̔j��
	for (it = pDestoroyObj.begin(); it != pDestoroyObj.end(); ++it)
	{
		delete (*it);
	}

	// �z��̃��Z�b�g
	pActiveObj.clear();
	pDestoroyObj.clear();
}
// ��莞�Ԃ̍X�V
void CScene::FixedUpdate()
{
	GAMEOBJECT_VEC::iterator it;		// �C�e���[�^�[

	// �I�u�W�F�N�g�X�V
	// �R���|�[�l���g�̍X�V
	for (it = m_pObjects.begin(); it != m_pObjects.end(); ++it)
	{
		// ��Ԃɂ�蕪��
		if ((*it)->GetState() == CGameObject::ACTIVE)
			(*it)->FixedUpdate();
	}
}
// �`��
void CScene::Draw()
{
	COMPONENT_LIST::iterator it;		// �C�e���[�^�[
	
	// ���C���[���ɕ��ёւ�
	// FIXME: ���ݏ󋵂ł́A���C���[��ݒ肵�Ă��Ȃ�DrawComponent���`����ׂ���?
	//m_pDrawComponent.sort([](CLayer i, CLayer j)->bool
	//{
	//	return i.GetLayer() < j.GetLayer();	// ����
	//});

	// �`��
	for (it = m_pDrawComponent.begin(); it != m_pDrawComponent.end(); ++it)
	{
		(*it)->Update();
	}

	// �N���A
	//m_pDrawComponent.clear();
}
// �����蔻��
// REVIEW: ���P�̗]�n����
void CScene::CollisionCheck()
{
	// �C�e���[�^�[
	COLLISION_VEC::iterator it;		

	for (it = m_pCollisionComponent.begin(); it != m_pCollisionComponent.end(); ++it)
	{
		for (COLLISION_VEC::iterator objIt = m_pCollisionComponent.begin(); objIt != m_pCollisionComponent.end(); ++objIt)
		{
			// ����̃I�u�W�F�N�g�͔��肵�Ȃ�
			if (it == objIt)
			{
				continue;
			}

			// �R���W�����׽�������n��
			(*it)->HitCheckPtr((*objIt));
		}// pair
	}// this

	// �z������
	m_pCollisionComponent.clear();
}

//--- �Z�b�^�[�E�Q�b�^�[
//CGameObject* CScene::GetGameObject(std::string name)
//{
//	GAMEOBJECT_VEC::iterator it;		// �C�e���[�^�[
//
//	for (it = m_pObjects.begin(); it < m_pObjects.end(); ++it)
//	{
//		// ���O���܂܂�Ă����
//		if ((*it)->GetName().compare(name) != -1)
//		{
//			return (*it);
//		}
//	}
//
//	return nullptr;
//}
//// �^�O�ɂ��擾
//// ����̃^�O���������_���ɒT�����߁A�g������������
//CGameObject* CScene::GetGameObject(CTag::E_Tag tag)
//{
//	GAMEOBJECT_VEC::iterator it;		// �C�e���[�^�[
//
//	for (it = m_pObjects.begin(); it < m_pObjects.end(); ++it)
//	{
//		// ����̃^�O���Ȃ�
//		if ((*it)->GetTagPtr()->GetTag() == tag)
//		{
//			return (*it);
//		}
//	}
//	return nullptr;
//}

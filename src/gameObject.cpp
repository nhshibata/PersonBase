//=========================================================
// �Q�[���I�u�W�F�N�g : ���N���X
//---------------------------------------------------------
// �쐬:2022/04/19 (�Ηj��)
// �X�V:2022/05/11 �^�O����v����I�u�W�F�N�g��S�Ď擾����֐��쐬
//			�ۑ�: ����̃R���|�[�l���g���g���ꍇ�Amap�͓K�؂ł͂Ȃ�
//=========================================================

//--- �C���N���[�h��
#include "gameObject.h"
#include "component.h"
#include "scene.h"

//--- �ÓI�����o�ϐ�
std::map<std::string, CGameObject*> CGameObject::m_pObjects;
CScene* CGameObject::m_pScene;

// �R���X�g���N�^
CGameObject::CGameObject()
{
	AddObject(this);
}
CGameObject::CGameObject(std::string name, CTransform trans)
	:m_objName(name), m_Transform(trans), m_eState(E_ObjectState::ACTIVE),m_pComponent()
{
	AddObject(this);
}
CGameObject::CGameObject(std::string name, CTransform trans, CTag* tag, CLayer* layer)
	:m_objName(name), m_Transform(trans), m_Tag(*tag), m_Layer(*layer),m_eState(E_ObjectState::ACTIVE),m_pComponent()
{
	AddObject(this);
}
CGameObject::~CGameObject()
{
	// �R���|�[�l���g�̔j��
	COOMPONENT::iterator it;
	for (it = m_pComponent.begin(); it != m_pComponent.end(); ++it)
	{
		delete (*it);
	}

	// ���g�����O
	m_pObjects.erase(GetName());
}
// ������
void CGameObject::Init()
{
	// �������������
	m_Transform.SetOwner(this);

	// �R���|�[�l���g�̏�����
	COOMPONENT::iterator it;
	for (it = m_pComponent.begin(); it != m_pComponent.end(); ++it)
	{
		(*it)->Init();
	}
}
// �R���|�[�l���g�̍X�V
void CGameObject::Update()
{
	COOMPONENT::iterator it;
	for (it = m_pComponent.begin(); it != m_pComponent.end(); ++it)
	{
		if (!(*it)->IsActive())
		{
			continue;
		}

		(*it)->Update();
	}
}
// �Q�[���I�u�W�F�N�g���Ƃ̒x���X�V
void CGameObject::LateUpdate()
{
	COOMPONENT::iterator it;
	for (it = m_pComponent.begin(); it != m_pComponent.end(); ++it)
	{
		if (!(*it)->IsActive())
		{
			continue;
		}

		(*it)->LateUpdate();
	}
}
// ��莞�Ԃ̍X�V
void CGameObject::FixedUpdate()
{
	COOMPONENT::iterator it;
	for (it = m_pComponent.begin(); it != m_pComponent.end(); ++it)
	{
		if (!(*it)->IsActive())
		{
			continue;
		}

		(*it)->FixedUpdate();
	}
}
//CComponent* CGameObject::Draw(){}
// �R���|�[�l���g�̒ǉ�
bool CGameObject::AddComponent(CComponent* com)
{
	COOMPONENT::iterator it;
	// �o�^����Ă���Βǉ����Ȃ�
	for (it = m_pComponent.begin(); it != m_pComponent.end(); ++it)
	{
		// ��������r���A��v���Ă���ΕԂ�
		//if ((*it)->GetName().find(com->GetName()) != std::string::npos)
		//{
		//	return false;
		//}
	}
	// �ǉ�
	//m_pComponent.insert(COOMPONENT_PAIR(com->GetName(), com));
	m_pComponent.push_back(com);
	return true;
}
// �R���|�[�l���g�̔j��
bool CGameObject::RemoveComponent(std::string comName)
{
	COOMPONENT::iterator it;
	for (it = m_pComponent.begin(); it != m_pComponent.end(); ++it)
	{
		// ��������r���A��v���Ă���ΕԂ�
		//if ((*it)->GetName().find(comName) != std::string::npos)
		//{
		//	// �폜
		//	delete (*it);
		//	// ���O
		//	m_pComponent.erase(it);
		//	break;
		//}
	}
	return true;
}
// ��������������ɂ����R���|�[�l���g�̎擾
//CComponent* CGameObject::GetComponent(std::string comName)
//{
//	//return m_pComponent[comName];
//
//	COOMPONENT::iterator it;
//	for (it = m_pComponent.begin(); it != m_pComponent.end(); ++it)
//	{
//		// ��������r���A��v���Ă���ΕԂ�
//		if ((*it)->GetName().find(comName) != std::string::npos)
//		{
//			return (*it);
//		}
//	}
//	return nullptr;
//}
//
void CGameObject::OnCollisionEnter(CGameObject* obj)
{
	COOMPONENT::iterator it = m_pComponent.begin();
	for (; it != m_pComponent.end(); ++it)
	{
		(*it)->OnCollisionEnter(obj);
	}
}
void CGameObject::OnCollisionStay(CGameObject* obj)
{
	COOMPONENT::iterator it = m_pComponent.begin();
	for (; it != m_pComponent.end(); ++it)
	{
		(*it)->OnCollisionStay(obj);
	}
}
void CGameObject::OnTriggerStay(CGameObject* obj)
{
	COOMPONENT::iterator it = m_pComponent.begin();
	for (; it != m_pComponent.end(); ++it)
	{
		(*it)->OnTriggerStay(obj);
	}
}
void CGameObject::OnTriggerEnter(CGameObject* obj)
{
	COOMPONENT::iterator it = m_pComponent.begin();
	for (; it != m_pComponent.end(); ++it)
	{
		(*it)->OnTriggerEnter(obj);
	}
}

//--- �ÓI�����o�֐�
// �I�u�W�F�N�g���Ŏ擾
CGameObject* CGameObject::Find(std::string name)
{
	// ���O������΃|�C���^��Ԃ�
	// �Ȃ����nullptr���Ԃ�
	return m_pObjects[name];
}
// tag����v����I�u�W�F�N�g��Ԃ�
CGameObject* CGameObject::Find(CTag::E_Tag tag)
{
	GAMEOBJECT::iterator it = m_pObjects.begin();

	for (; it != m_pObjects.end(); ++it)
	{
		if ((*it).second->GetTagPtr()->GetTag() == tag)
		{
			return (*it).second;
		}
	}
	return nullptr;
}
// tag����v����I�u�W�F�N�g��S�ĕԂ�
std::list<CGameObject*> CGameObject::FindObjects(CTag::E_Tag tag)
{
	GAMEOBJECT::iterator it = m_pObjects.begin();
	std::list<CGameObject*> objs(0);

	for (; it != m_pObjects.end(); ++it)
	{
		if ((*it).second->GetTagPtr()->GetTag() == tag)
		{
			objs.push_back((*it).second);
		}
	}
	return objs;
}

void CGameObject::SetSceneObject(CGameObject* obj)
{
	m_pScene->SetGameObject(obj);
}
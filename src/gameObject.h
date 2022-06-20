//=========================================================
//�쐬:2022/04/19 (�Ηj��)
// �Q�[���I�u�W�F�N�g : ���N���X
// 
//=========================================================

//--- �C���N���[�h�K�[�h
#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

//--- �C���N���[�h��
#include <string>
#include <map>
#include <list>
#include "transform.h"
#include "tag.h"
#include "layer.h"
#include <typeinfo>

//--- �O���Q��
class CComponent;
class CScene;

//--- �N���X��`
class CGameObject
{
public:
	//--- �񋓑̒�`
	enum E_ObjectState // �I�u�W�F�N�g�̏��
	{
		ACTIVE,				// �X�V���
		WAIT,				// �ҋ@
		DESTROY,			// �폜
		TAKEOVER,			// �����p���i�g���܂킵)
		MAX_OBJECT_STATE,	// �ő吔
	};
private:
	//--- �ÓI�����o�ϐ�
	using GAMEOBJECT = std::map <std::string, CGameObject*>;
	using GAMEOBJECT_PAIR = std::pair<std::string, CGameObject*>;
	static GAMEOBJECT m_pObjects;			// �S�ẴQ�[���I�u�W�F�N�g���Ǘ�
	static CScene* m_pScene;
protected:
	//--- �Ē�`
	using COOMPONENT = std::list<CComponent*>;
	//using COOMPONENT_PAIR 
	//--- �����o�ϐ�
	std::string m_objName;		// ���O
	COOMPONENT m_pComponent;	// �����R���|�[�l���g
	E_ObjectState m_eState;		// ���ݏ�
	CTransform m_Transform;		// �p�����[�^
	CTag m_Tag;					// �^�O
	CLayer m_Layer;				// ���C���[
	
public:
	CGameObject();
	CGameObject(std::string name, CTransform trans);
	CGameObject(std::string name, CTransform trans, CTag* tag, CLayer* layer);
	virtual ~CGameObject();

	virtual void Init();				// ������
	virtual void Update();				// �Q�[���I�u�W�F�N�g���Ƃ̍X�V
	virtual void LateUpdate();			// �Q�[���I�u�W�F�N�g���Ƃ̍X�V
	virtual void FixedUpdate();		// ��莞�Ԃ̍X�V

	//--- �R���|�[�l���g
	bool AddComponent(CComponent* com);				// �R���|�[�l���g�̒ǉ�
	bool RemoveComponent(std::string comName);		// �R���|�[�l���g�̔j��
	//CComponent* GetComponent(std::string comName);	// �R���|�[�l���g�̎擾

	template <class T> T* GetComponent()
	{
		T* component = nullptr;
		for (COOMPONENT::iterator it = m_pComponent.begin(); it != m_pComponent.end(); ++it) {
			if (typeid(*component).name() == typeid(it).name())
			{
				component = (T*)(*it);
				return component;
			}
		}
		return nullptr;
	}

	// �Q�b�^�[�E�Z�b�^�[
	CTransform* GetTransform() { return &m_Transform; };
	std::string GetName() { return m_objName; }
	E_ObjectState GetState() { return m_eState; };
	CTag* GetTagPtr() { return &m_Tag; };
	CLayer* GetLayerPtr() { return &m_Layer; };
	void SetName(std::string name) { m_objName = name; };
	void SetState(E_ObjectState state) { m_eState = state; };
	void SetTag(CTag::E_Tag tag) { m_Tag.SetTag(tag); };
	void SetLayer(CLayer::E_Layer layer) { m_Layer.SetLayer(layer); };

	//--- ���z�֐�
	// �R���|�[�l���g�����Փˊ֐��̌Ăяo��
	void OnCollisionEnter(CGameObject* obj);
	void OnCollisionStay(CGameObject* obj);
	void OnTriggerStay(CGameObject* obj);
	void OnTriggerEnter(CGameObject* obj);
	//void HitCheck(CGameObject* obj);

	//--- �ÓI�����o�ϐ�
	static void AddObject(CGameObject* obj) { m_pObjects.insert(GAMEOBJECT_PAIR(obj->GetName(), obj)); SetSceneObject(obj);}
	static void SetSceneObject(CGameObject* obj);
	static CGameObject* Find(std::string name);
	static CGameObject* Find(CTag::E_Tag tag);
	static std::list<CGameObject*> FindObjects(CTag::E_Tag tag);
	static void SetScene(CScene* scene) { m_pScene = scene; }
};

#endif __GAME_OBJECT_H__

//=========================================================
//�쐬:2022/04/19 (�Ηj��)
// �R���|�[�l���g�׽ : ���N���X
//=========================================================

//--- �C���N���[�h�K�[�h
#ifndef __COMPONENT_H__
#define __COMPONENT_H__

//--- �C���N���[�h��
#include "gameObject.h"
#include "fps.h"			// ���Ԃ�m�邱�Ƃ��K�v�Ȃ��߁A�C���N���[�h

//--- �O���Q��
//class CGameObject;

//--- �N���X��`
class CComponent
{
private:

protected:
	CGameObject* m_pOwner;			// ������
	bool m_bActive;					// �A�N�e�B�u���
	
public:
	// ���g�̏��L�҂������萔��`
#define gameObject GetOwner()

public:
	//--- ���ފ֐�
	CComponent():m_pOwner(nullptr),m_bActive(true){};
	CComponent(CGameObject* owner):m_pOwner(owner), m_bActive(true) {};
	virtual ~CComponent() {};
	virtual void Init() = 0;			// ������ ���R���|�[�l���g�̎擾�Ȃǂ��s�� �K������
	virtual void Update() = 0;			// �X�V �K������
	virtual void LateUpdate() {};		// �x���X�V
	virtual void FixedUpdate() {};		// ��莞�Ԃ̍X�V

	// �Z�b�^�[�E�Q�b�^�[
	bool IsActive() { return m_bActive; };
	void SetActive(bool value) { m_bActive = value; };
	std::string GetName() { return typeid(this).name; }
	CGameObject* GetOwner() { return m_pOwner; };
	CTransform* Transform() { return m_pOwner->GetTransform(); }
	CTag::E_Tag Tag() { return m_pOwner->GetTagPtr()->GetTag(); }

	// gameobject�ȗ��p�֐�
	void AddComponent(CComponent* com) { gameObject->AddComponent(com); }
	template <class T> T* GetComponent() { return gameObject->GetComponent<T>(); }
	//CComponent* GetComponent(std::string name) { gameObject->GetComponent(name); }

	//--- ���z�֐�
	// �Փ˂����Ƃ��ɌĂяo�����֐�
	// �������������ɃI�[�o�[���C�h����
	virtual void OnCollisionStay(CGameObject* obj) {};		// 
	virtual void OnCollisionEnter(CGameObject* obj) {};		// 
	virtual void OnTriggerStay(CGameObject* obj) {};		// 
	virtual void OnTriggerEnter(CGameObject* obj) {};		// 
	void HitCheck(CGameObject* obj) { OnCollisionStay(obj); OnCollisionEnter(obj); OnTriggerStay(obj); OnTriggerEnter(obj); };

};

#endif __COMPONENT_H__

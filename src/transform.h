//=========================================================
// �쐬:2022/04/19
// �X�V:2022/05/11 �e�q�֌W�̎����B���[�J�����W�p�̸׽�쐬
// �g�����X�t�H�[�� : ���i�׽
//=========================================================

//--- �C���N���[�h�K�[�h
#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

//--- �C���N���[�h��
//#include "main.h"
#include "localTrasform.h"
#include "component.h"
#include <vector>

//--- �O���Q��
//class CLocalTransform;
//class CGameObject;

//--- �N���X��`
class CTransform : public CComponent
{
private:
	//--- �����o�ϐ�
	XMFLOAT3 m_vPos;			// ���W
	XMFLOAT3 m_vTargetPos;		// �ڕW���W
	XMFLOAT3 m_vRot;			// �p�x
	XMFLOAT3 m_vDestRot;		// �ڕW�p�x
	XMFLOAT3 m_vScale;			// �傫��
	XMFLOAT3 m_vVel;			// �ړ���
	XMFLOAT3 m_vAccel;			// ����
protected:
	//CGameObject* m_pOwner;				// ������
	CTransform* m_pParent;				// �e�I�u�W�F�N�g
	std::vector<CTransform*> m_pChilds;	// �q�v�f���X�g
	CLocalTransform* m_pLocal;			// �e�q�֌W���̃��[�J�����W
public:
	//--- �����o�֐�
	CTransform();
	CTransform(XMFLOAT3 pos, XMFLOAT3 rot, XMFLOAT3 size, XMFLOAT3 vel = XMFLOAT3{0,0,0}, CGameObject* pOwner = nullptr);
	~CTransform();
	void Update();

	// �Q�b�^�[�E�Z�b�^�[
	XMFLOAT3 GetPos()					{ return m_vPos; };
	XMFLOAT3 GetRot()					{ return m_vRot; };
	XMFLOAT3 GetScale()					{ return m_vScale; };
	XMFLOAT3 GetVel()					{ return m_vVel; };
	XMFLOAT3 GetAccel()					{ return m_vAccel; };
	void SetPos(XMFLOAT3 value)			{ if (!m_pLocal)m_vPos = value; else m_vPos = m_pLocal->NewPos(value); };
	void SetTargetPos(XMFLOAT3 value)	{ m_vTargetPos = value; };
	void SetRot(XMFLOAT3 value)			{ if (!m_pLocal)m_vRot = value; else m_vRot = m_pLocal->NewRot(value); };
	void SetDestRot(XMFLOAT3 value)		{ m_vDestRot = value; };
	void SetScale(XMFLOAT3 value)		{ if (!m_pLocal)m_vScale = value; else m_vScale = m_pLocal->NewScale(value); };
	void SetVel(XMFLOAT3 value)			{ m_vVel = value; };
	void SetAccel(XMFLOAT3 value)		{ m_vAccel = value; };

	// �e�q�֌W
	//CGameObject* GetOwner()				{ return m_pOwner; };				// �������Ԃ�
	CTransform* GetParent()				{ return m_pParent; };				// �e��Ԃ�
	int GetChildCount()					{ return (int)m_pChilds.size(); };	// �v�f����Ԃ�
	CTransform* GetChild(int cnt)		{ return m_pChilds[cnt]; };			// �w��ԍ��ڂ̎q�v�f��Ԃ�
	CLocalTransform* GetLocal()			{ return m_pLocal;}					// ���[�J���ް���n��
	//void SetOwner(CGameObject* pOwner)	{ m_pOwner = pOwner; }				// �������ݒ�
	void SetParent(CTransform* parent)	{ m_pParent = parent; m_pLocal = new CLocalTransform(this); }	// �e�v�f�ǉ�
	void AddChild(CTransform* child)	{ m_pChilds.push_back(child); child->SetParent(this); }			// �q�v�f�ǉ�
};

#endif // !__TRANSFORM_H__


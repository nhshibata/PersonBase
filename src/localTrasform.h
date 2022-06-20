//=========================================================
// �쐬:2022/04/19
// �X�V:2022/05/11 �e�q�֌W�̎����B���[�J�����W�p�̸׽�쐬
// �g�����X�t�H�[�� : ���i�׽
//=========================================================

//--- �C���N���[�h�K�[�h
#ifndef __LOCAL_TRANSFORM_H__
#define __LOCAL_TRANSFORM_H__

//--- �C���N���[�h��
#include "main.h"

class CTransform;

// ���[�J�����
class CLocalTransform
{
private:
	//--- �����o�ϐ�
	CTransform* m_pWorldTransform;	// ���[���h���
	CTransform* m_pParent;
	XMFLOAT3 m_vPos;				// ���W
	XMFLOAT3 m_vRot;				// �p�x
	XMFLOAT3 m_vScale;				// �傫��
	//XMFLOAT3 m_vVel;				// �ړ���
	//XMFLOAT3 m_vAccel;			// ����
public:
	//--- ���ފ֐�
	CLocalTransform(CTransform*);
	~CLocalTransform();
	void Update();

	// �Q�b�^�[�E�Z�b�^�[
	XMFLOAT3 GetPos() { return m_vPos; };
	XMFLOAT3 GetRot() { return m_vRot; };
	XMFLOAT3 GetScale() { return m_vScale; };
	//XMFLOAT3 GetVel()				{ return m_vVel; };
	//XMFLOAT3 GetAccel()			{ return m_vAccel; };
	void SetPos(XMFLOAT3 value) { m_vPos = value; };
	void SetRot(XMFLOAT3 value) { m_vRot = value; /*ADD_FLOAT3(m_vRot, m_pWorldTransform->GetParent()->GetRot());*/ };
	void SetScale(XMFLOAT3 value) { m_vScale = value; };
	//void SetVel(XMFLOAT3 value)	{ m_vVel = value; };
	//void SetAccel(XMFLOAT3 value)	{ m_vAccel = value; };
	XMFLOAT3 NewPos(XMFLOAT3 value);
	XMFLOAT3 NewRot(XMFLOAT3 value);
	XMFLOAT3 NewScale(XMFLOAT3 value);
};

#endif
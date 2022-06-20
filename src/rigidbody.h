//=========================================================
// �쐬:2022/05/24
// ����
//=========================================================

//--- �C���N���[�h�K�[�h
#ifndef __RIGIDBODY_H__
#define __RIGIDBODY_H__

//---- �C���N���[�h��
#include "component.h"

//--- �N���X��`
class CRigidbody : CComponent
{
private:
	using XMFLOAT3P = float*[3];
private:
	
	bool m_bGravity;
	bool m_bIsSleep;
	bool m_bCollisionDetectionMode;		// �����蔻����s����

	XMFLOAT3 m_vOldPos;
	XMFLOAT3P m_pFreezPos;
	XMFLOAT3P m_pFreezRot;
public:
	CRigidbody();
	~CRigidbody();
	void Update();

	bool UseGravity(){ return m_bGravity; }
	bool IsSleeping(){ return m_bIsSleep; }
	bool SetGravity(bool value){ m_bGravity = value; }
	// �ʒu�E�p�x�Œ�
	void SetFreezPos(bool x, bool y, bool z);
	void SetFreezRot(bool x, bool y, bool z);
};

#endif // !__RIGIDBODY_H__

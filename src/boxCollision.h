//=========================================================
//�쐬:2022/05/02
// �R���W�����׽(�����蔻�� ) : �h���׽
//=========================================================
//--- �C���N���[�h�K�[�h
#ifndef __BOX_COLLISION_H__
#define __BOX_COLLISION_H__

//--- �C���N���[�h��
#include "collision.h"

//--- �N���X��`
class CBoxCollision : public CCollision
{
private:
	XMFLOAT3 m_vSize;			// �����蔻��T�C�Y

public:
	const std::string CLASS_NAME = "sphereCol";
	std::string GetName() { return CLASS_NAME; };
public:
	CBoxCollision(XMFLOAT3 size = XMFLOAT3(1, 1, 1));
	~CBoxCollision();

	//--- �Q�b�^�[�E�Z�b�^�[
	XMFLOAT3 GetSize() { return m_vSize; };
	void SetSize(XMFLOAT3 size) { m_vSize = size; };
	bool Box(XMFLOAT3 Apos, XMFLOAT3 Asize, XMFLOAT3 Bpos, XMFLOAT3 Bsize);
	bool CollisionAABB(XMFLOAT3 pos, XMFLOAT3 size);

	//
	bool HitCheckPtr(CCollision* col);		// �R���W�����׽���������ɂƂ��āA�����蔻����s��

};
#endif // __BOX_COLLISION_H__

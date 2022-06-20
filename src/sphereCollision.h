//=========================================================
//�쐬:2022/05/02
// �R���W�����׽(�����蔻�� ) : �h���׽
//=========================================================
//--- �C���N���[�h�K�[�h
#ifndef __SPHERE_COLLISION_H__
#define __SPHERE_COLLISION_H__

//--- �C���N���[�h��
#include "collision.h"

//--- �N���X��`
class CSphereCollision : public CCollision
{
private:
	float m_fRadius;			// �����蔻�苅
public:
	//--- ���ފ֐�
	CSphereCollision(float radius = 0.0f);
	~CSphereCollision();

	//--- �Q�b�^�[�E�Z�b�^�[
	float GetRadius() { return m_fRadius; };
	void SetRadius(float radius) { m_fRadius = radius; };

	bool Sphere(XMFLOAT3 Apos, float Ar, XMFLOAT3 Bpos, float Br);
	bool CollisionSphere(XMFLOAT3 pos, float radius);

	//
	bool HitCheckPtr(CCollision* col);		// �R���W�����׽���������ɂƂ��āA�����蔻����s��
};

#endif // !__SPHERE_COLLISION_H__

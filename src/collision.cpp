//=========================================================
//�쐬:2022/04/20 (���j��)
// �R���W�����׽(�����蔻�� ) : ���׽
// ���ƃ{�b�N�X�̓����蔻��͕�����������������?
//=========================================================

//--- �C���N���[�h��
#include "collision.h"
#include "scene.h"

// �R���X�g���N�^
CCollision::CCollision() 
	:m_bIsTrigger(false), m_pTransform(nullptr), m_vOldPos(0,0,0),m_HitSubjectTag(CTag::DEFAULT),
	m_pEnterList(0), m_pStayList(0)
{
}
// �����t���R���X�g���N�^
CCollision::CCollision(CGameObject* owner, bool trigger)
	:CComponent(owner), m_bIsTrigger(trigger), m_pTransform(nullptr), m_vOldPos(0, 0, 0), m_HitSubjectTag(CTag::DEFAULT),
	m_pEnterList(0),m_pStayList(0)
{
}
// �f�X�g���N�^
CCollision::~CCollision()
{

}
// ������
void CCollision::Init()
{
	m_pTransform = m_pOwner->GetTransform();
	// �ߋ����W
	m_vOldPos = m_pTransform->GetPos();
}
// �X�V
void CCollision::Update()
{
	// �^�O���ύX����Ă��邩������Ȃ��̂ŁA������
	SetColTag(CTag::DEFAULT);

	// �ڂ��Ă���I�u�W�F�����
	// TODO: ���ꂽ�I�u�W�F�𔻒肷��Ȃ炱�̎�
	ColObjectUpdate();

	// �ߋ����W���X�V
	m_vOldPos = m_pTransform->GetPos();

	// �����蔻��̗v��
	CScene::Get()->SetColComponent(this);
}
// �V�[������Ăяo����铖���������̏���
void CCollision::HitResponse(CCollision* col)
{
	CGameObject* obj = col->GetOwner();
	std::list<CGameObject*>::iterator it = std::find(m_pEnterList.begin(), m_pEnterList.end(), obj);
	// �g���K�[��true / �Փ˃I�u�W�F��true�Ȃ�
	bool trigger = m_bIsTrigger | col->IsTrigger();

	// �Փ˂����I�u�W�F�N�g�̃^�O��ۑ�
	SetColTag(obj->GetTagPtr()->GetTag());

	// �Փ˃��X�g�Ɋi�[
	// �G���^�[���X�g�Ɋi�[���Ă��Ȃ���΁A�i�[
	if (it == m_pEnterList.end())
	{
		// Enter���X�g
		m_pEnterList.push_back(obj);
		if (!trigger)
		{
			// ���̍��W���i�[
			m_pTransform->SetPos(m_vOldPos);
			m_pOwner->OnCollisionEnter(obj);
		}
		else
		{
			m_pOwner->OnTriggerEnter(obj);
		}
	}
	// Stay
	if (std::find(m_pEnterList.begin(), m_pEnterList.end(), obj) == m_pEnterList.end())
	{
		if (!trigger)
		{
			// ���̍��W���i�[
			m_pTransform->SetPos(m_vOldPos);
			//
			m_pOwner->OnCollisionStay(obj);
		}
		else
		{
			m_pOwner->OnTriggerStay(obj);
		}
	}
}
void CCollision::ColObjectUpdate()
{
	std::list<CGameObject*>::iterator it;
	// Enter���X�g��Stay�I�u�W�F���Ȃ���Ώ��O
	for (it = m_pStayList.begin(); it != m_pStayList.end(); ++it)
	{
		if (std::find(m_pEnterList.begin(), m_pEnterList.end(), (*it)) == m_pEnterList.end())
		{
			it = m_pStayList.erase(it);
		}
	}
	// �i�[���Ă��Ȃ����̂ݏ���
	if (m_pStayList.size() != 0)
	{
		// Enter���X�g����Stay���X�g�֊i�[
		m_pStayList = m_pEnterList;
	}
	// ���̔���̂��߁A�N���A
	m_pEnterList.clear();
}

//
//// �x�N�g���̑傫�������߂�
//float VectorLength(XMFLOAT3 vector)
//{
//	return (vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
//}
//
//// �x�N�g���̓��ς����߂�
//float VectorInner(XMFLOAT3 vec1, XMFLOAT3 vec2)
//{
//	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
//}
//
//// �x�N�g���̐��K��
//XMFLOAT3 VectorNormalize(XMFLOAT3 vec)
//{
//	float l = (float)sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
//	XMFLOAT3 Normal;
//	Normal.x = vec.x / l;
//	Normal.y = vec.y / l;
//	Normal.z = vec.z / l;
//	return Normal;
//}
//// �x�N�g�����m�̓���
//float VectorDot(XMFLOAT3 v1, XMFLOAT3 v2)
//{
//	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
//}
//// �x�N�g�����m�̓���
//float VectorDotDegrees(XMFLOAT3 v1, XMFLOAT3 v2)
//{
//	return XMConvertToDegrees((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
//}
//// �x�N�g�����m�̊O��
//XMFLOAT3 VectorOuter(XMFLOAT3 vec1, XMFLOAT3 vec2)
//{
//	return XMFLOAT3((vec1.y * vec2.z) - (vec1.z * vec2.y),
//		(vec1.z * vec2.x) - (vec1.x * vec2.z),
//		(vec1.x * vec2.y) - (vec1.y * vec2.x));
//}
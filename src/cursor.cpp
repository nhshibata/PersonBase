//=========================================================
// �쐬:2022/04/21
// �J�[�\��: ���i�׽
//=========================================================

//--- �C���N���[�h��
#include "cursor.h"

// �R���X�g���N�^
CCursor::CCursor()
	:m_bInput(false),m_nMax(1),m_nPoint(0),m_nOldPoint(0)
{
}
// �����t���R���X�g���N�^
CCursor::CCursor(CGameObject* owner)
	:CComponent(owner), m_bInput(false), m_nMax(1), m_nPoint(0), m_nOldPoint(0)
{
}
// �f�X�g���N�^
CCursor::~CCursor()
{

}
// ������
void CCursor::Init()
{

}
// �X�V
void CCursor::Update()
{
	if (m_nPoint != m_nOldPoint)
	{
		m_nOldPoint = m_nPoint;
	}
}
//=========================================================
//�쐬:2022/04/21
// �v���C���[�N���X
// 
//=========================================================

//--- �C���N���[�h��
#include "player.h"
#include "collision.h"

// �R���X�g���N�^
CPlayer::CPlayer()
{
	// �R���|�[�l���g�̒ǉ� �O���̕�����
	AddComponent(new CCollision());
}
// �R���X�g���N�^
CPlayer::CPlayer(CGameObject* owner)
	:CComponent(owner)
{
	// �^�O�̐ݒ�
	gameObject->SetTag(CTag::PLAYER);

	// �R���|�[�l���g�̒ǉ� �O���̕�����
	AddComponent(new CCollision());
}
CPlayer::~CPlayer()
{

}
void CPlayer::Init()
{

}
void CPlayer::Update()
{

}
void CPlayer::LateUpdate()
{
}
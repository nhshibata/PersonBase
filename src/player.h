//=========================================================
//�쐬:2022/04/21
// �v���C���[�N���X
// 
//=========================================================

//--- �C���N���[�h�K�[�h
#ifndef __PLAYER_H__
#define __PLAYER_H__

//--- �C���N���[�h��
#include "component.h"


//--- �N���X��`
class CPlayer : public CComponent
{
private:
	//const std::string CLASS_NAME = "player";
public:
	//--- ���ފ֐�
	CPlayer();
	CPlayer(CGameObject* owner);
	~CPlayer();

	void Init();				// ������ ���R���|�[�l���g�̎擾�Ȃǂ��s��
	void Update();				// �X�V
	void LateUpdate();			// �x���X�V

	// �Z�b�^�[�E�Q�b�^�[
};

#endif // !__PLAYER_H__

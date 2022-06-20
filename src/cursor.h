//=========================================================
// �쐬:2022/04/21
// �J�[�\��: ���i�׽
//=========================================================
//--- �C���N���[�h�K�[�h
#ifndef __CURSOR_H__
#define __CURSOR_H__

//--- �C���N���[�h��
#include "component.h"

//--- �O���Q��
class CGameObject;

//--- �N���X��`
class CCursor : public CComponent
{
private:
	bool m_bInput;				// �J�[�\�����ړ����Ȃ����p
	int m_nPoint;				// 
	int m_nOldPoint;			// 
	int m_nMax;					// �ő吔
public:
	//--- ���ފ֐�
	CCursor();
	CCursor(CGameObject* owner);
	~CCursor();

	void Init();
	void Update();

	void InputSwitch() { m_bInput ^= true; };
	//--- �Z�b�^�[�E�Q�b�^�[
	void SetMax(int value) { m_nMax = value; };
	int GetPos() { return m_nPoint; };
	int GetOldPos() { return m_nOldPoint; };
};

#endif // !__CURSOR_H__


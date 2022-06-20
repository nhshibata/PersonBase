//=========================================================
//�쐬:2022/05/24
// �Q�[�����s�׽
//=========================================================

//--- �C���N���[�h��
#include "GameApp.h"
#include "scene.h"
#include "titleScene.h"

// �R���X�g���N�^
CGameApp::CGameApp()
	:m_pMainScene(nullptr), m_dwFixedTime(0.02)
{
	m_pMainScene = new CTitleScene;
	m_dwLastTime = CFps::GetTime();
}
// �f�X�g���N�^
CGameApp::~CGameApp()
{
	if (m_pMainScene)
	{
		delete m_pMainScene;
	}
}
void CGameApp::Update()
{
	// ��莞�Ԃ̍X�V
	if (CFps::GetTime() - m_dwLastTime >= m_dwFixedTime)
	{
		m_pMainScene->FixedUpdate();
		m_dwLastTime = CFps::GetTime();
	}

	m_pMainScene->Update();
}
void CGameApp::Draw()
{
	m_pMainScene->Draw();
}

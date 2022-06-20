//=========================================================
//作成:2022/05/24
// ゲーム実行ｸﾗｽ
//=========================================================

//--- インクルード部
#include "GameApp.h"
#include "scene.h"
#include "titleScene.h"

// コンストラクタ
CGameApp::CGameApp()
	:m_pMainScene(nullptr), m_dwFixedTime(0.02)
{
	m_pMainScene = new CTitleScene;
	m_dwLastTime = CFps::GetTime();
}
// デストラクタ
CGameApp::~CGameApp()
{
	if (m_pMainScene)
	{
		delete m_pMainScene;
	}
}
void CGameApp::Update()
{
	// 一定時間の更新
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

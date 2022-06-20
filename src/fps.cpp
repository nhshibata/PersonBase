

// --- インクルード部 ---
#include "fps.h"

// --- 定数定義 ---

// --- 静的メンバ変数 ---
CFps* CFps::m_pInstance;			// インスタンス
DWORD CFps::m_dwCurrentTime;		// 現在時間
DWORD CFps::m_dwDeltaTime;		// 現在時間
DWORD CFps::m_dwLastTime;			// 最後に更新した時間
int CFps::m_nHitStopFrame = 0;		// ヒットストップ用
int CFps::m_dwSlowTime = 0;			// スロー時間回数

// コンストラクタ
CFps::CFps()
	:m_nSlowFramPerSec(30), m_dwExecLastTime(m_dwLastTime), m_bSlow(false), m_bUpdate(true)
{
}
// 引数付きコンストラクタ
CFps::CFps(int nSlowfps)
	: m_nSlowFramPerSec(30), m_dwExecLastTime(m_dwLastTime), m_bSlow(false), m_bUpdate(true)
{
	SetSlow(nSlowfps);
}
// デストラクタ
CFps::~CFps()
{
}
// 更新
void CFps::Update()
{
	// フラグが立っていなければ設定されたスロー時間を渡す
	if (!m_bSlow)
	{
		if (m_nSlowFramPerSec < FPS)
		{
			m_nSlowFramPerSec = m_nSlowFramPerSec * 0.9f + FPS * 0.1f;
		}
	}
	// ヒットストップ回数が0より上の時
	if (m_nHitStopFrame > 0)
	{
		--m_nHitStopFrame;		// ヒットストップ回数を減らす
		m_bUpdate = false;		// 更新しない判定を返す
		return;
	}
	// 設定された速度で更新
	if ((m_dwCurrentTime - m_dwExecLastTime) >= (DWORD)(1000 / m_nSlowFramPerSec))
	{
		// スローならば回数を減らす
		if (m_bSlow)
		{
			--m_dwSlowTime;			// 回数を減らす
			if (m_dwSlowTime <= 0)
			{
				m_dwSlowTime = 0;
				m_bSlow = false;
			}
		}
		// 最終更新時間を更新
		m_dwDeltaTime = (m_dwCurrentTime - m_dwExecLastTime) / 1000; // 現在時間と前回の更新時間の差を取る 1fの時間を求める
		m_dwExecLastTime = m_dwCurrentTime;
		m_bUpdate = true;
		return;
	}
	// 更新しない
	m_bUpdate = false;
}
// 更新してもいいか確認
bool CFps::IsUpdate()
{
	return m_bUpdate;
}
// スロー開始
void CFps::StartSlow(const int nSlowfps)
{
	m_bSlow = true;
	SetSlow(nSlowfps);
}
// スロー終了
void CFps::SlowEnd()
{
	m_bSlow = false;
	// メインのフレームと合わせる
	m_dwExecLastTime = m_dwLastTime;
}
// スロー時間設定
void CFps::SetSlow(const int nSlowfps)
{
	// 60より上なら修正
	if (nSlowfps > FPS)		
	{
		m_nSlowFramPerSec = FPS;
		return;
	}
	m_nSlowFramPerSec = nSlowfps;
}
// スロー時間設定
void CFps::SetSlow(const int nSlowfps, const int nTime)
{
	// 秒で決めたいため、60をかける
	m_dwSlowTime = nTime * 60;

	// 60より上なら修正
	if (nSlowfps > FPS)		
	{
		m_nSlowFramPerSec = FPS;
		return;
	}
	m_nSlowFramPerSec = nSlowfps;
}
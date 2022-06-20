//=========================================================
//作成:2022/04/21
// fps、時間制御
//=========================================================

//--- インクルードガード
#ifndef __FPS_H__
#define __FPS_H__

//--- 定数定義
#define FPS			(60)
#define MAIN_FPS	CFps::Get()

// TODO: 仮
using DWORD = float;

//--- クラス定義
class CFps
{
private:
	//--- 静的メンバ変数
	static CFps* m_pInstance;
	static DWORD m_dwCurrentTime;	// 現在時間
	static DWORD m_dwDeltaTime;		// デルタタイム
	static DWORD m_dwLastTime;		// 更新最後時間
	static int m_nHitStopFrame;		// ヒットストップ回数格納
	static int m_dwSlowTime;

	//--- メンバ変数
	int m_nSlowFramPerSec;			// 一秒の分割数
	DWORD m_dwExecLastTime;			// 静的でない最後時間
	bool m_bSlow;					// スロー開始フラグ
	bool m_bUpdate;
public:
	CFps();
	CFps(const int nSlowfps);
	~CFps();

	void Update();
	bool IsUpdate();
	void StartSlow(const int nSlowfps);
	void SlowEnd();
	void SetSlow(const int nSlowfps);
	void SetSlow(const int nSlowfps, const int nTime);
	bool IsSlow() { return m_bSlow; };

	// fpsメイン
	static DWORD GetTime() { return m_dwCurrentTime; }
	static DWORD DelataTime() { return m_dwDeltaTime; }
	static void SetCurrentTime(const DWORD currentTime) { m_dwCurrentTime = currentTime;};
	static void SetLastTime(const DWORD lastTime) { m_dwLastTime = lastTime; };
	static void SetHitStop(const int cnt) { if (m_nHitStopFrame <= 0) { m_nHitStopFrame = cnt; } };

	// シングルトン
	void Start() { m_pInstance = new CFps(); };
	void End() { delete m_pInstance; };
	CFps* Get() { return m_pInstance; };
};

#endif
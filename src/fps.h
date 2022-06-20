//=========================================================
//�쐬:2022/04/21
// fps�A���Ԑ���
//=========================================================

//--- �C���N���[�h�K�[�h
#ifndef __FPS_H__
#define __FPS_H__

//--- �萔��`
#define FPS			(60)
#define MAIN_FPS	CFps::Get()

// TODO: ��
using DWORD = float;

//--- �N���X��`
class CFps
{
private:
	//--- �ÓI�����o�ϐ�
	static CFps* m_pInstance;
	static DWORD m_dwCurrentTime;	// ���ݎ���
	static DWORD m_dwDeltaTime;		// �f���^�^�C��
	static DWORD m_dwLastTime;		// �X�V�Ō㎞��
	static int m_nHitStopFrame;		// �q�b�g�X�g�b�v�񐔊i�[
	static int m_dwSlowTime;

	//--- �����o�ϐ�
	int m_nSlowFramPerSec;			// ��b�̕�����
	DWORD m_dwExecLastTime;			// �ÓI�łȂ��Ō㎞��
	bool m_bSlow;					// �X���[�J�n�t���O
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

	// fps���C��
	static DWORD GetTime() { return m_dwCurrentTime; }
	static DWORD DelataTime() { return m_dwDeltaTime; }
	static void SetCurrentTime(const DWORD currentTime) { m_dwCurrentTime = currentTime;};
	static void SetLastTime(const DWORD lastTime) { m_dwLastTime = lastTime; };
	static void SetHitStop(const int cnt) { if (m_nHitStopFrame <= 0) { m_nHitStopFrame = cnt; } };

	// �V���O���g��
	void Start() { m_pInstance = new CFps(); };
	void End() { delete m_pInstance; };
	CFps* Get() { return m_pInstance; };
};

#endif
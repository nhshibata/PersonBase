//=========================================================
//�쐬:2022/04/19 (�Ηj��)
// ���C���[�׽ : ���i�׽
//=========================================================
#ifndef __LAYER_H__
#define __LAYER_H__

class CLayer
{
public:
	//--- �񋓑̒�`
	enum E_Layer	// ���C���[�𑝂₷
	{
		BG,			// �w�i
		DEFAULT,	// �f�t�H���g
		UI,			// UI
		FOG,		// �O�i(�t�F�[�h��)
	};
private:
	E_Layer m_eLayer;
public:
	CLayer():m_eLayer(DEFAULT){};
	CLayer(E_Layer layer):m_eLayer(layer){};
	~CLayer() {};
	E_Layer GetLayer() { return m_eLayer; };
	void SetLayer(E_Layer layer) { m_eLayer = layer; };
};

#endif // !__LAYER_H__

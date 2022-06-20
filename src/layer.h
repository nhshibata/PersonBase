//=========================================================
//作成:2022/04/19 (火曜日)
// レイヤーｸﾗｽ : 部品ｸﾗｽ
//=========================================================
#ifndef __LAYER_H__
#define __LAYER_H__

class CLayer
{
public:
	//--- 列挙体定義
	enum E_Layer	// レイヤーを増やす
	{
		BG,			// 背景
		DEFAULT,	// デフォルト
		UI,			// UI
		FOG,		// 前景(フェード等)
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

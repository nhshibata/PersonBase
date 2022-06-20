//=========================================================
//作成:2022/04/21
// プレイヤークラス
// 
//=========================================================

//--- インクルードガード
#ifndef __PLAYER_H__
#define __PLAYER_H__

//--- インクルード部
#include "component.h"


//--- クラス定義
class CPlayer : public CComponent
{
private:
	//const std::string CLASS_NAME = "player";
public:
	//--- ﾒﾝﾊﾞ関数
	CPlayer();
	CPlayer(CGameObject* owner);
	~CPlayer();

	void Init();				// 初期化 他コンポーネントの取得などを行う
	void Update();				// 更新
	void LateUpdate();			// 遅い更新

	// セッター・ゲッター
};

#endif // !__PLAYER_H__

//=========================================================
//作成:2022/04/20 (水曜日)
// コリジョンｸﾗｽ(当たり判定 ) : 基底ｸﾗｽ
//=========================================================
//--- インクルードガード
#ifndef __COLLISION_H__
#define __COLLISION_H__

//--- インクルード部
#include "component.h"
//#include "tag.h"

//--- クラス定義
class CCollision : public CComponent
{
protected:
	//--- ﾒﾝﾊﾞ変数
	CTransform* m_pTransform;	// ownerのTransformへのポインタ(関数で取得する無駄を省く)
	XMFLOAT3 m_vOldPos;			// 衝突があった場合、元に戻す座標
	
	CTag::E_Tag m_HitSubjectTag;	// フレームごとに初期化する
	bool m_bIsTrigger;				// 当たった時の動作(trueですり抜け)

	std::list<CGameObject*> m_pEnterList;
	std::list<CGameObject*> m_pStayList;
public:
	//const std::string CLASS_NAME = "collision";
	//virtual std::string GetName() { return  CLASS_NAME; };				// 実装
	
	//--- ﾒﾝﾊﾞ関数
private:
	void ColObjectUpdate();
protected:
	void HitResponse(CCollision* col);
public:
	//--- ﾒﾝﾊﾞ関数
	CCollision();
	CCollision(CGameObject* owner, bool trigger = false);
	~CCollision();
	void Init();
	void Update();

	//--- セッター・ゲッター
	CTag::E_Tag GetColTag() {return m_HitSubjectTag;};
	bool IsTrigger() { return m_bIsTrigger; };

	void SetColTag(CTag::E_Tag tag) { tag = m_HitSubjectTag; };
	void SetTrigger(bool is) { m_bIsTrigger = is; };
	
	virtual bool HitCheckPtr(CCollision* col) { return false; };		// コリジョンｸﾗｽを引き数にとって、当たり判定を行う
};

#endif // !__COLLISION_H__


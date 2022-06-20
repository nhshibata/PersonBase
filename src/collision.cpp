//=========================================================
//作成:2022/04/20 (水曜日)
// コリジョンｸﾗｽ(当たり判定 ) : 基底ｸﾗｽ
// 球とボックスの当たり判定は分けた方がいいかも?
//=========================================================

//--- インクルード部
#include "collision.h"
#include "scene.h"

// コンストラクタ
CCollision::CCollision() 
	:m_bIsTrigger(false), m_pTransform(nullptr), m_vOldPos(0,0,0),m_HitSubjectTag(CTag::DEFAULT),
	m_pEnterList(0), m_pStayList(0)
{
}
// 引数付きコンストラクタ
CCollision::CCollision(CGameObject* owner, bool trigger)
	:CComponent(owner), m_bIsTrigger(trigger), m_pTransform(nullptr), m_vOldPos(0, 0, 0), m_HitSubjectTag(CTag::DEFAULT),
	m_pEnterList(0),m_pStayList(0)
{
}
// デストラクタ
CCollision::~CCollision()
{

}
// 初期化
void CCollision::Init()
{
	m_pTransform = m_pOwner->GetTransform();
	// 過去座標
	m_vOldPos = m_pTransform->GetPos();
}
// 更新
void CCollision::Update()
{
	// タグが変更されているかもしれないので、初期化
	SetColTag(CTag::DEFAULT);

	// 接しているオブジェを区別
	// TODO: 離れたオブジェを判定するならこの時
	ColObjectUpdate();

	// 過去座標を更新
	m_vOldPos = m_pTransform->GetPos();

	// 当たり判定の要請
	CScene::Get()->SetColComponent(this);
}
// シーンから呼び出される当たった時の処理
void CCollision::HitResponse(CCollision* col)
{
	CGameObject* obj = col->GetOwner();
	std::list<CGameObject*>::iterator it = std::find(m_pEnterList.begin(), m_pEnterList.end(), obj);
	// トリガーがtrue / 衝突オブジェがtrueなら
	bool trigger = m_bIsTrigger | col->IsTrigger();

	// 衝突したオブジェクトのタグを保存
	SetColTag(obj->GetTagPtr()->GetTag());

	// 衝突リストに格納
	// エンターリストに格納していなければ、格納
	if (it == m_pEnterList.end())
	{
		// Enterリスト
		m_pEnterList.push_back(obj);
		if (!trigger)
		{
			// 元の座標を格納
			m_pTransform->SetPos(m_vOldPos);
			m_pOwner->OnCollisionEnter(obj);
		}
		else
		{
			m_pOwner->OnTriggerEnter(obj);
		}
	}
	// Stay
	if (std::find(m_pEnterList.begin(), m_pEnterList.end(), obj) == m_pEnterList.end())
	{
		if (!trigger)
		{
			// 元の座標を格納
			m_pTransform->SetPos(m_vOldPos);
			//
			m_pOwner->OnCollisionStay(obj);
		}
		else
		{
			m_pOwner->OnTriggerStay(obj);
		}
	}
}
void CCollision::ColObjectUpdate()
{
	std::list<CGameObject*>::iterator it;
	// EnterリストにStayオブジェがなければ除外
	for (it = m_pStayList.begin(); it != m_pStayList.end(); ++it)
	{
		if (std::find(m_pEnterList.begin(), m_pEnterList.end(), (*it)) == m_pEnterList.end())
		{
			it = m_pStayList.erase(it);
		}
	}
	// 格納していない時のみ処理
	if (m_pStayList.size() != 0)
	{
		// EnterリストからStayリストへ格納
		m_pStayList = m_pEnterList;
	}
	// 次の判定のため、クリア
	m_pEnterList.clear();
}

//
//// ベクトルの大きさを求める
//float VectorLength(XMFLOAT3 vector)
//{
//	return (vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
//}
//
//// ベクトルの内積を求める
//float VectorInner(XMFLOAT3 vec1, XMFLOAT3 vec2)
//{
//	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
//}
//
//// ベクトルの正規化
//XMFLOAT3 VectorNormalize(XMFLOAT3 vec)
//{
//	float l = (float)sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
//	XMFLOAT3 Normal;
//	Normal.x = vec.x / l;
//	Normal.y = vec.y / l;
//	Normal.z = vec.z / l;
//	return Normal;
//}
//// ベクトル同士の内積
//float VectorDot(XMFLOAT3 v1, XMFLOAT3 v2)
//{
//	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
//}
//// ベクトル同士の内積
//float VectorDotDegrees(XMFLOAT3 v1, XMFLOAT3 v2)
//{
//	return XMConvertToDegrees((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
//}
//// ベクトル同士の外積
//XMFLOAT3 VectorOuter(XMFLOAT3 vec1, XMFLOAT3 vec2)
//{
//	return XMFLOAT3((vec1.y * vec2.z) - (vec1.z * vec2.y),
//		(vec1.z * vec2.x) - (vec1.x * vec2.z),
//		(vec1.x * vec2.y) - (vec1.y * vec2.x));
//}
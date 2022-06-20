//=========================================================
//作成:2022/04/21
// プレイヤークラス
// 
//=========================================================

//--- インクルード部
#include "player.h"
#include "collision.h"

// コンストラクタ
CPlayer::CPlayer()
{
	// コンポーネントの追加 外部の方かも
	AddComponent(new CCollision());
}
// コンストラクタ
CPlayer::CPlayer(CGameObject* owner)
	:CComponent(owner)
{
	// タグの設定
	gameObject->SetTag(CTag::PLAYER);

	// コンポーネントの追加 外部の方かも
	AddComponent(new CCollision());
}
CPlayer::~CPlayer()
{

}
void CPlayer::Init()
{

}
void CPlayer::Update()
{

}
void CPlayer::LateUpdate()
{
}
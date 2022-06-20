//=========================================================
//作成:2022/04/19 (火曜日)
//タグ : 部品クラス
//=========================================================
#ifndef __TAG_H__
#define __TAG_H__

class CTag
{
public:
	//--- 列挙体定義
	enum E_Tag
	{
		DEFAULT,
		PLAYER,
		ENEMY,

	};
private:
	E_Tag m_eTag;
public:
	CTag() :m_eTag(DEFAULT){};
	CTag(E_Tag tag) :m_eTag(tag){};
	~CTag() {};
	E_Tag GetTag() { return m_eTag; }
	void SetTag(E_Tag tag) { m_eTag = tag; }
	bool Compare(E_Tag tag) { if (m_eTag == tag) { return true; } return false; }	// 指定のタグか確認
};

#endif  //__TAG_H__
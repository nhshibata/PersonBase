//=========================================================
//�쐬:2022/04/19 (�Ηj��)
//�^�O : ���i�N���X
//=========================================================
#ifndef __TAG_H__
#define __TAG_H__

class CTag
{
public:
	//--- �񋓑̒�`
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
	bool Compare(E_Tag tag) { if (m_eTag == tag) { return true; } return false; }	// �w��̃^�O���m�F
};

#endif  //__TAG_H__
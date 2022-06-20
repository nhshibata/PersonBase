//=========================================================
//�쐬:2022/04/19 (�Ηj��)
// �V�[���׽ : ���N���X
//=========================================================
#ifndef __SCENE_H__
#define __SCENE_H__

//--- �C���N���[�h��
#include "gameObject.h"
#include <vector>
#include <list>

//--- �萔��`
#define GAME Get()

//--- �O���Q��
class CCollision;
//--- �N���X��`
class CScene
{
private:
	//--- �ÓI�����o�ϐ�
	static CScene* m_pCurrentScene;
protected:
	//--- �Ē�`
	using GAMEOBJECT_VEC = std::vector<CGameObject*>;
	using COMPONENT_LIST = std::list<CComponent*>;
	using COLLISION_VEC = std::vector<CCollision*>;
protected:
	//--- �����o�ϐ�
	GAMEOBJECT_VEC m_pObjects;				// �Q�[���V�[�����Ƃ̃I�u�W�F�N�g
	COMPONENT_LIST m_pDrawComponent;		// �`�悷��R���|�[�l���g(�z��ł���A�\�[�g���邩���B���t���[����ɂ���)
	COLLISION_VEC m_pCollisionComponent;	// �����蔻��׽

	// TODO: �j�����Ȃ��I�u�W�F�N�g�p�̐ÓI�ϐ���p�ӂ��ׂ����H
	void CollisionCheck();
public:
	//--- ���ފ֐�
	CScene();
	virtual ~CScene();
	virtual void Init();
	virtual void Uninit();
	virtual void Update();
	virtual void FixedUpdate();
	virtual void Draw();

	//--- �Z�b�^�[�E�Q�b�^�[
	void SetGameObject(CGameObject* obj) { // �I�u�W�F�N�g�z����ɑ��݂��邩���� �Ō���ł���΁A�z����ɑ��݂��邽�߁A�i�[
		if(std::find(m_pObjects.begin(), m_pObjects.end(), obj) == m_pObjects.end())m_pObjects.push_back(obj); }
	void SetDrawComponent(CComponent* com) { m_pDrawComponent.push_back(com); }
	void SetColComponent(CCollision* com) { m_pCollisionComponent.push_back(com); }

	//--- �ÓI���ފ֐�
	static void SetScene(CScene* scene){ m_pCurrentScene = scene; };	// �V�[���̍X�V
	static CScene* Get() { return m_pCurrentScene; };					// ���݃V�[���̎擾
};

#endif // !__SCENE_H__

/*
�V�[���ōs������
�Q�[���I�u�W�F�N�g�N���X�̍X�V(����сA�e�R���|�[�l���g�̍X�V)
�I�u�W�F�N�g���m�̓����蔻��(GetComponent�Ŋm�F���s��)
�V�[���J�ڂ̏���
�Q�[���I�u�W�F�N�g��Draw��������n���ꂽ�`��̎��s

// �R���|�[�l���g�̔F���̂��߁A�����K����݂���B
// �� : �`�悷�邽�߂̃R���|�[�l���g�ɂ�Draw�A�����蔻��ɂ�Collision��t����

*/


//=========================================================
// �쐬:2022/04/19 (�Ηj��)
// �X�V:2022/04/19 �R���|�[�l���g�A�Q�[���I�u�W�F�N�g�A�V�[���Bunity���Q�l��tag��layer���`�B
// �X�V:2022/04/20 cpp�̎����Bcollision�Atransform�Acursor�Afps�쐬
// �X�V:2022/04/21 Factory�׽�Aplayer�׽�̎���
// 			!�ۑ�! �I�u�W�F�N�g�̃g�����X�t�H�[���̌��ߕ�(���W�A�p�x�A�傫��)�▼�O�A�ׂ����R���|�[�l���g�̒ǉ����ǂ��������邩
// 		�`��͂��邪�A���̑��̍X�V���������Ȃ��I�u�W�F�N�g�͂ǂ����邩?�X���[���̊e�X�V�͂ǂ����삷�邩?
// �X�V:2022/04/22 �����C���B
// �X�V:2022/04/24 �����蔻��X�V�B
//			!�ۑ�! UI�֘A�̕`�揇�̌��ߕ��B���݂�Component�ł͂Ȃ��A�h���׽DrawComponent���`���A�`�揇�����߂�ϐ���݂���B
// �X�V:2022/06/03 �ǉ��͂��Ă������̂́A�L�^�͎c���Ă��Ȃ��B���Ƃ�����������?
//			�\�z: UI�͂�͂�UI������`��˗���\��������@�������B�|�C���^�Ȃǂ�n�����C���[���ŕ��т����B
//			
//
// ���e:�R���|�[�l���g�w�����x�[�X�Ƃ����v���O�����B
// ��������Ɍl����̃Q�[���𐧍삷��B
// 
//=========================================================

// �g���t�H�[�}�b�g?�ɂ���ĈقȂ�?
#define _CRT_SECURE_NO_WARNINGS

//--- �C���N���[�h��
#include <stdio.h>
#include <Windows.h>

//--- ���C���G���g���[
int main()
{
	const int SORT_NUM = 5;

	char szNumber[SORT_NUM];
	int sortList[SORT_NUM];
	int randomNum = 0;
	bool result = false;

	scanf("%s", szNumber);

	// while
	do
	{
		// �z��̏�����
		for (int cnt = 0; cnt < SORT_NUM; ++cnt)
		{
			sortList[cnt] = -1;
		}

		// �����ɂ����͂��ꂽ�z�����ёւ���
		for (int cnt = 0; cnt < SORT_NUM; ++cnt)
		{
			do
			{
				// �󂫔z�񂪌�����܂ŌJ��Ԃ�
				randomNum = rand() % SORT_NUM;
				if (sortList[randomNum] != -1)	// -1�m�F
				{
					// �����R�[�h���琔���ɒ���
					sortList[randomNum] = szNumber[cnt] - '0';
					break;
				}
			} while (1);
		}

		// ���̌J��Ԃ��ňُ킪�Ȃ����true
		result = true;
		
		for (int cnt = 0; cnt < SORT_NUM - 1; ++cnt)
		{
			// ���������Ɋi�[����Ă��邱�Ƃ����҂��邽�߁A���̊i�[�������傫����Ύ��s
			if (sortList[cnt] > sortList[cnt + 1])
			{
				result = false;
				break;
			}
		}
	} while (!result);


	rewind(stdin);
	getchar();

	return 0;
}
//=========================================================
// 作成:2022/04/19 (火曜日)
// 更新:2022/04/19 コンポーネント、ゲームオブジェクト、シーン。unityを参考にtagとlayerを定義。
// 更新:2022/04/20 cppの実装。collision、transform、cursor、fps作成
// 更新:2022/04/21 Factoryｸﾗｽ、playerｸﾗｽの実装
// 			!課題! オブジェクトのトランスフォームの決め方(座標、角度、大きさ)や名前、細かいコンポーネントの追加をどう実装するか
// 		描画はするが、その他の更新をしたくないオブジェクトはどうするか?スロー時の各更新はどう操作するか?
// 更新:2022/04/22 少し修正。
// 更新:2022/04/24 当たり判定更新。
//			!課題! UI関連の描画順の決め方。現在のComponentではなく、派生ｸﾗｽDrawComponentを定義し、描画順を決める変数を設ける。
// 更新:2022/06/03 追加はしていたものの、記録は残していない。あともう少しかな?
//			構想: UIはやはりUI側から描画依頼を申請する方法を検討。ポインタなどを渡しレイヤー順で並びかえ。
//			
//
// 内容:コンポーネント指向をベースとしたプログラム。
// これを元に個人制作のゲームを制作する。
// 
//=========================================================

// 使うフォーマット?によって異なる?
#define _CRT_SECURE_NO_WARNINGS

//--- インクルード部
#include <stdio.h>
#include <Windows.h>

//--- メインエントリー
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
		// 配列の初期化
		for (int cnt = 0; cnt < SORT_NUM; ++cnt)
		{
			sortList[cnt] = -1;
		}

		// 乱数により入力された配列を並び替える
		for (int cnt = 0; cnt < SORT_NUM; ++cnt)
		{
			do
			{
				// 空き配列が見つかるまで繰り返す
				randomNum = rand() % SORT_NUM;
				if (sortList[randomNum] != -1)	// -1確認
				{
					// 文字コードから数字に直す
					sortList[randomNum] = szNumber[cnt] - '0';
					break;
				}
			} while (1);
		}

		// 下の繰り返しで異常がなければtrue
		result = true;
		
		for (int cnt = 0; cnt < SORT_NUM - 1; ++cnt)
		{
			// 小さい順に格納されていることを期待するため、次の格納数字より大きければ失敗
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
//=========================================================
// [main.h]
// 定数定義など、メインで行う処理の橋渡し
//=========================================================
#ifndef __MAIN_H__
#define __MAIN_H__

//FIXME:仮の構造体
class XMFLOAT3
{
public:
	float x;
	float y;
	float z;
	XMFLOAT3() {};
	XMFLOAT3(float x1, float y1, float z1)
	{
		x = x1; y = y1; z = z1;
	}
};

// マクロ定義
#define ADD_FLOAT3(pos, vel)		pos.x += vel.x; pos.y += vel.y; pos.z += vel.z
#define ADD_FLOAT3B(pos, vel)		pos.x + vel.x, pos.y + vel.y, pos.z + vel.z
#define MULTIPLY_FLOAT3(pos, vel)	pos.x *= vel.x; pos.y *= vel.y; pos.z *= vel.z
#define MULTIPLY_FLOAT3B(pos, vel)	pos.x * vel.x ,pos.y * vel.y, pos.z * vel.z

#endif // !__MAIN_H__


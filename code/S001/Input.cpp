#include "Input.h"
#include "DxLib.h"

//外部入力の状況を記憶する
static Input nowInput;

//初期化をする
int Input_Initialize()
{
	//初期設定
	//最初は入力を受け付けている状態
	nowInput.Available = 1;

	//最初は全て押下されていない状態
	for( int i = 0 ; i < NUMBER_OF_KEY_CODE ; i++ )
	{
		nowInput.KeyBuf[i] = 0;
	}

	//入力を受け付けているかどうかを返却
	//正しければ1
	return (nowInput.Available);
}

//外部入力の状況を表示
int Input_Draw( int CoordX , int CoordY , int Color )
{
	//描画する情報の数(行数)
	int RowCnt = 0;
	//可能かどうか
	DrawFormatString( CoordX , CoordY+16*RowCnt++ , Color , "Available:%d" , nowInput.Available );

	return (CoordY+16*RowCnt);
}

//セッタ
int Input_SetAvailable( bool newAvailable )
{
	nowInput.Available = newAvailable;

	return (nowInput.Available);
}


//ゲッタ
int Input_GetKeyState( int KeyCode )
{
	return (nowInput.KeyBuf[ KeyCode ]);
}

//外部入力の状況を更新
int Input_Update()
{
	//入力が可能かどうかを判別
	if( nowInput.Available == 0 )
	{
		return (0);	//0なら何もせず正常終了
	}

	//全てのキーの押下状態を取得
	if( GetHitKeyStateAll( nowInput.KeyBuf ) != 0 )
	{
		return (1);	//取得に失敗したら1を返却
	}
	else
	{
		return (0);	//正常終了として0を返却
	}
}

//終了する
int Input_Finalize()
{
	return (0);	//特にやることがない^^;
}
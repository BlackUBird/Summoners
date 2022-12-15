#ifndef INPUT_H
#define INPUT_H

#define NUMBER_OF_KEY_CODE (256)

//外部入力(キー入力)の状況を記憶するやつの構造体
typedef struct ts_Input
{
	bool Available;	//入力を受けつけている時は1
	char KeyBuf[ NUMBER_OF_KEY_CODE ];	//すべてのキーの押下状態を監視
} Input;

//初期化をする
int Input_Initialize();

//外部入力の状況を表示
int Input_Draw( int CoordX , int CoordY , int Color );

//セッタ
int Input_SetAvailable( bool newAvailable );

//ゲッタ
int Input_GetKeyState( int KeyCode );

//外部入力の状況を更新
int Input_Update();

//終了する
int Input_Finalize();

#endif
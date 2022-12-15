#include "DxLib.h"
#include "DX_Setup.h"

#define NUMBER_OF_RUNNER (1)
#define NAME_LENGTH (20)

#define MAP_HEIGHT (8)
#define MAP_WIDTH (10)

char KeyBuf[256];

// プログラムは WinMain から始まります
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
						LPSTR lpCmdLine, int nCmdShow )
{
	//セットアップ
	//スクリーン:640*480
	//カラービット数:32
	//表示モード:ウィンドウモード
	if( DX_Setup_Initialize( 640 , 480 , 32 , TRUE  ) != 0 )
	{
		return (-1);
	}

	//フォント
	int FontSize[] = { 16 , 32 };
	int FontThick[] = { 5 , 7 };
	char FontName[][FONT_NAME_MAX] =
	{
		"とりあえず" , 
		"とりあえず2"
	};
	//設定
	if( DX_Setup_Initialize_Font( 2 , FontName , FontSize , FontThick ) < 0 )
	{
		return (-1);
	}
	

	//初期化--------------------------------------
	//FPS設定を初期化
	FPS_Initialize( 30 );
	//入力
	Input_Initialize();

	//1フレームごとに行う処理を記述
	//ESCが押されたら終了
	while( DX_Setup_Update() == 0 && Input_GetKeyState( KEY_INPUT_ESCAPE ) == 0 )
	{

		//描画-----------------------------------------

		//FPS待ち
		FPS_Wait();
	}

	WaitKey() ;				// キー入力待ち


	DX_Setup_Finalize();
	//DxLib_End() ;				// ＤＸライブラリ使用の終了処理

	return 0 ;				// ソフトの終了 
}
#include "DX_Setup.h"
#include "DxLib.h"



//初期化処理
int DX_Setup_Initialize( int ScreenSizeX , int ScreenSizeY , int ScreenColorBitNum ,
						 int WindowMode )
{
	//設定、変更-------------------------------------------
	// ウインドウモードに変更
	if( ChangeWindowMode( WindowMode ) != DX_CHANGESCREEN_OK )
	{
		return -1;
	}
	// 画面モードの設定
	if( SetGraphMode( ScreenSizeX , ScreenSizeY , ScreenColorBitNum ) != DX_CHANGESCREEN_OK )
	{
		return -1;
	}
	// ＤＸライブラリ初期化処理
	if( DxLib_Init() == -1 )
	{
		return -1 ;			// エラーが起きたら直ちに終了
	}



	//情報を保持---------------------------------
	//スクリーン情報
	//画面サイズをセット
	initStatus.Screen.SizeX = ScreenSizeX;
	initStatus.Screen.SizeY = ScreenSizeY;
	//カラービット数をセット
	initStatus.Screen.ColorBitNum = ScreenColorBitNum;

	//ウィンドウ情報
	//ウィンドウモードをセット
	initStatus.Window.Mode = WindowMode;

	return 0;
}

//フォント設定
int DX_Setup_Initialize_Font( int FontNum ,
							  char FontName[ FONT_HUNDLE_MAX ][ FONT_NAME_MAX ] , 
							  int FontSize[] , 
							  int FontThick[] )
{
	//フォント情報
	initStatus.Font.Num = FontNum;	//フォントの数
	for( int i = 0 ; i < FontNum ; i++ )
	{
		initStatus.Font.Size[i] = FontSize[i];	//サイズ
		initStatus.Font.Thick[i] = FontThick[i];	//太さ
		//名前
		strcpy( initStatus.Font.Name[i] , FontName[i] );
		//ハンドル
		initStatus.Font.Hundle[i] = CreateFontToHandle( FontName[i] , FontSize[i] , FontThick[i] );
	}

	return (initStatus.Font.Num);
}

//描画処理
int DX_Setup_Draw( int CoordX , int CoordY , int Color )
{
	//表示する位置
	int x,y;
	//引数が負の値なら(0,0)
	if( CoordX < 0 || CoordY < 0 )
	{
		x = 0;
		y = 0;
	}
	else
	{
		x = CoordX;
		y = CoordY;
	}


	//描画-----------------------------------------------
	//描画する情報の数(行数)
	int RowCnt = 0;
	//スクリーン情報を描画
	DrawFormatString( x , y+16*RowCnt++ , Color , "ScreenSizeX=%d ScreenSizeY=%d" , initStatus.Screen.SizeX , initStatus.Screen.SizeY );
	DrawFormatString( x , y+16*RowCnt++ , Color , "ScreenColorBitNum=%d" , initStatus.Screen.ColorBitNum );
	//ウィンドウ情報
	DrawFormatString( x , y+16*RowCnt++ , Color , "WindowMode=%s" , initStatus.Window.Mode == TRUE ? "WindowMode" : "FullScreen" );
	//フォント情報
	DrawFormatString( x , y+16*RowCnt++ , Color , "FontNum=%d" , initStatus.Font.Num );
	for( int i = 0 ; i < initStatus.Font.Num ; i++ )
	{
		DrawFormatString( x , y+16*RowCnt++ , Color , "FontName=%s FontSize=%d FontThick=%d FontHundle=%d" , initStatus.Font.Name[i] , initStatus.Font.Size[i] , initStatus.Font.Thick[i] , initStatus.Font.Hundle[i] );
	}


	return (y+16*RowCnt);
}

//取得用
int DX_Setup_GetScreenSizeX()
{
	return (initStatus.Screen.SizeX);
}
int DX_Setup_GetScreenSizeY()
{
	return (initStatus.Screen.SizeY);
}
int DX_Setup_GetScreenColorBitNum()
{
	return (initStatus.Screen.ColorBitNum);
}

//更新処理
int DX_Setup_Update( void )
{
	int errNum = 0;	//エラーが起きた数
	errNum += ScreenFlip();	// 成功:0 失敗:-1
	errNum += ProcessMessage();	//成功:0 失敗:-1
	errNum += ClearDrawScreen();	//成功:0 失敗:-1
	errNum += Input_Update();	//成功:0 失敗:-1
	errNum += FPS_Update();	//成功:0 失敗:-1

	return (errNum);	//返却(正常なら0)
}

//終了処理
int DX_Setup_Finalize()
{
	DxLib_End();
	return 0;
}

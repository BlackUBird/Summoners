#ifndef DX_SETUP_H
#define DX_SETUP_H

#include "Input.h"
#include "FPS.h"

//フォント数の最大値
#define FONT_HUNDLE_MAX (16)
//フォント名の最長値
#define FONT_NAME_MAX (16)

//フォント情報
typedef struct ts_DXSS_Font
{
	int Num;	//登録されているフォントの数
	char Name[ FONT_HUNDLE_MAX ][ FONT_NAME_MAX ];	//名前
	int Hundle[ FONT_HUNDLE_MAX ];	//ハンドル
	int Size[ FONT_HUNDLE_MAX ];	//大きさ
	int Thick[ FONT_HUNDLE_MAX ];	//太さ
} DXSS_Font;

//スクリーン情報
typedef struct ts_DXSS_Screen
{
	int SizeX;	//横
	int SizeY;	//縦
	int ColorBitNum;	//カラービット数
} DXSS_Screen;

//ウィンドウ情報
typedef struct ts_DXSS_Window	
{
	int Mode;	//ウィンドウモード
} DXSS_Window;


//情報
typedef struct ts_DXSetupStatus
{
	DXSS_Screen Screen;	//スクリーン情報
	DXSS_Window Window;	//ウィンドウ情報
	DXSS_Font	Font;	//フォント情報
} DXSS;

//情報を保持
static DXSS initStatus;

//初期化処理
int DX_Setup_Initialize( int ScreenSizeX , int ScreenSizeY , int ScreenColorBitNum ,
						 int WindowMode );

//フォント設定
int DX_Setup_Initialize_Font( int FontNum ,
							  char FontName[ FONT_HUNDLE_MAX ][ FONT_NAME_MAX ] , 
							  int FontSize[] , 
							  int FontThick[] );

//描画処理
int DX_Setup_Draw( int CoordX , int CoordY ,int Color );

//取得用
int DX_Setup_GetScreenSizeX();
int DX_Setup_GetScreenSizeY();
int DX_Setup_GetScreenColorBitNum();

//更新処理
int DX_Setup_Update( void );

//終了処理
int DX_Setup_Finalize();

#endif
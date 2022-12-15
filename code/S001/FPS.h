#ifndef FPS_H
#define FPS_H

static int StartTime;	//測定開始時刻(基準となる時刻)
static int Count;	//カウンタ(フレーム数を記憶)
static float nowFPS;	//現在のFPS

static const int SampleNum = 60;	//平均をとるサンプル数

static int initFPS;	//設定したFPS

static int tookTime;
static int waitTime;

//初期化
int FPS_Initialize( int fps );

//更新
int FPS_Update();

//待機
int FPS_Wait();

//描画
int FPS_Draw( int CoordX , int CoordY , int Color );

//終了
int FPS_Finalize();

#endif
#include "FPS.h"
#include "DxLib.h"
#include <math.h>

//初期化
int FPS_Initialize( int fps )
{
	//FPSを設定
	initFPS = fps;

	return (initFPS);
}

//更新
int FPS_Update()
{
	//1フレーム目なら現在時刻を記憶
	if( Count == 0 )
	{
		StartTime = GetNowCount();
	}
	//"サンプル数"フレーム目なら平均を計算
	if( Count == SampleNum )
	{
		//現在時刻(ミリ秒)
		int time = GetNowCount();
		//現在のFPS
		nowFPS = 1000.0f / ((time-StartTime)/(float)SampleNum);
		
		//カウンタを0にする
		Count = 0;

		//測定開始時刻を更新
		StartTime = time;
	}

	//カウンタを1進める
	Count++;

	//今のカウンタの値を返す
	return (0);
}

//待機
int FPS_Wait()
{
	//かかった時間を計算
	tookTime = GetNowCount() - StartTime;
	//待つべき時間(かかるべき時間-かかった時間)を計算
	waitTime = Count * 1000 / initFPS - tookTime;
	//待つべき時間が0より大きければ待つ
	if( waitTime > 0 )
	{
		Sleep( waitTime );
	}

	return (waitTime);
}

//描画
int FPS_Draw( int CoordX , int CoordY , int Color )
{
	DrawFormatString( CoordX , CoordY , Color , "initFPS:%d waitTime:%d FPS:%.1f" , initFPS , waitTime , nowFPS );

	return (CoordY);
}

//終了
int FPSFinalize()
{
	return (1);
}
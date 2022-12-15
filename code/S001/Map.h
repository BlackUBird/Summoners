#ifndef MAP_H
#define MAP_H

#define MAP_NUM_MAX (2)

#define MAP_NAME_MAX (20)
#define MAP_SIZEX_MAX (20)
#define MAP_SIZEY_MAX (15)
#define MAP_CELL_SIZEX (32)
#define MAP_CELL_SIZEY (32)

//基礎ステータス
typedef struct ts_Attribute
{
	int State[ MAP_SIZEX_MAX ][ MAP_SIZEY_MAX ];	//各マスの状態
	float Skillpoint;	//スキル発動用コスト
} s_Attribute;

//基本的なステータス
typedef struct ts_Basic
{
	int PersonalNumber;	//識別番号
	char Name[ MAP_NAME_MAX ];	//名前
	int SizeX,SizeY;	//大きさ
} s_Basic;

//特殊効果
typedef struct ts_Special
{
} s_Special;

//作戦ステータス
typedef struct ts_Combat
{
	float NowCost;	//現在のコスト
	int ElapsedTurn;	//経過ターン数
	int NumberOfBases;	//拠点マスの数
	int NumberOfFriends;	//味方の数
	int NumberOfEnemies;	//敵の数
} s_Combat;

typedef struct ts_MapSatstus
{
	s_Basic Basic;	//基本情報
	s_Attribute InitAttribute;	//初期の状態
	s_Attribute NowAttribute;	//現在の状態
//	s_Combat Team1;	//チーム1の作戦ステータス
//	s_Combat Team2;	//チーム2の作戦ステータス
} s_MapStatus;

//マップの状態
static s_MapStatus InitMapStatus;
static s_MapStatus NowMapStatus;

//マップの初期状態を呼び出し
int Map_Call_InitState();

//初期化(呼び出し)
int Map_Initialize( int MapNumber );

//更新
int Map_Update();

//描画
int Map_Draw();
int Map_Draw_StatusAll();

//終了
int Map_Finalize();

#endif
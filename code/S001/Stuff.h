#ifndef STUFF_H
#define STUFF_H

//名前の長さ
#define NAME_LENGTH_MAX (20)

//できる事の最大数
#define SUGGESTION_MAX (32)

//個別情報
typedef struct ts_Personal
{
	char Name[ NAME_LENGTH_MAX ];	//名前
	int Number;	//番号
} Stuff_Personal;

//位置
typedef struct ts_Position
{
	int X,Y;	//座標
	int Direction;	//向き
} Stuff_Position;

//形
typedef struct ts_Shape
{
	int SizeX,SizeY;	//大きさ
	int GraphHundle;	//グラフィックのハンドル
} Stuff_Shape;

//できる事
typedef struct ts_Ability
{
	int Num;	//登録されているできる事の数
	int Suggestion;	//提案している、できる事の番号
} Stuff_Ability;

//状態異常
typedef struct ts_NegativeStatus
{
	//その状態の残りターン数を保持
	int Silence;	//能力無効化
	int Bind;	//バインド
	int Slow;	//足止め
	int CriticallyWounded;	//重症
	int Levitate;	//浮遊
	int Stun;	//スタン
	int Sleep;	//睡眠
	int Cold;	//寒冷
	int Freeze;	//凍結
	int BurningBreath;	//灼熱の息吹
} s_NegativeStatus;

//デバフ
typedef struct ts_DebuffNamed
{
	//効果値を保持
	//脆弱
} s_DebuffNamed;

//基礎ステータス
typedef struct ts_Attribute
{
	float HitPoint;	//残り体力
	float Attack;	//攻撃力
	float Deffence;	//防御力
	float Resist;	//術耐性
	float RedeploymentTurn;	//再配置ターン数
	float DeploymentPoint;	//配置コスト

	float SkillPoint;	//スキル用コストの初期or現在値
	
	int BattleStyle;	//攻撃方法
	
	int Block;	//ブロック可能数
	int Range;	//攻撃範囲(フィルタ番号)
	//攻撃範囲は15マス*15マスの正方形領域の中央にキャラを仮想的に置いた、というような配列を用意し、それをフィルタの様に使います

	int Speed;	//一度に進めるマスの数
} s_Attribute;

//ステータス
typedef struct ts_Status
{
	s_Attribute InitAttribute;	//初期値
	s_Attribute NowAttribute;	//現在値
} s_Status;

//「モノ」の型枠
typedef struct ts_Stuff
{
	Stuff_Personal Personal;	//個別情報
	Stuff_Position Position;	//位置
	Stuff_Shape	Shape;	//形
	Stuff_Ability Ability;	//できる事
} Stuff;

//初期化
int Stuff_Initialize();

//セット
//個別情報
int Stuff_Set_Personal_Name( char NewName[] );
int Stuff_Set_Personal_Number( int NewNumber );
//位置
int Stuff_Set_Position_XY( int NewX , int NewY );
int Stuff_Set_Direction( int NewDirection );
//形
int Stuff_Set_Shape_Size( int NewSizeX , int NewSizeY );
int Stuff_Set_Shape_GraphHundle( char* FileName );

//更新処理
//位置変え
int Stuff_Update_PositionX_Increment();
int Stuff_Update_PositionX_Decrement();
int Stuff_Update_PositionY_Increment();
int Stuff_Update_PositionY_Decrement();
//向き変え
int Stuff_Update_PositionDirection_Up();
int Stuff_Update_PositionDirection_Down();
int Stuff_Update_PositionDirection_Right();
int Stuff_Update_PositionDirection_Left();


#endif
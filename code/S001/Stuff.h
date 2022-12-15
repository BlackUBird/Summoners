#ifndef STUFF_H
#define STUFF_H

//���O�̒���
#define NAME_LENGTH_MAX (20)

//�ł��鎖�̍ő吔
#define SUGGESTION_MAX (32)

//�ʏ��
typedef struct ts_Personal
{
	char Name[ NAME_LENGTH_MAX ];	//���O
	int Number;	//�ԍ�
} Stuff_Personal;

//�ʒu
typedef struct ts_Position
{
	int X,Y;	//���W
	int Direction;	//����
} Stuff_Position;

//�`
typedef struct ts_Shape
{
	int SizeX,SizeY;	//�傫��
	int GraphHundle;	//�O���t�B�b�N�̃n���h��
} Stuff_Shape;

//�ł��鎖
typedef struct ts_Ability
{
	int Num;	//�o�^����Ă���ł��鎖�̐�
	int Suggestion;	//��Ă��Ă���A�ł��鎖�̔ԍ�
} Stuff_Ability;

//��Ԉُ�
typedef struct ts_NegativeStatus
{
	//���̏�Ԃ̎c��^�[������ێ�
	int Silence;	//�\�͖�����
	int Bind;	//�o�C���h
	int Slow;	//���~��
	int CriticallyWounded;	//�d��
	int Levitate;	//���V
	int Stun;	//�X�^��
	int Sleep;	//����
	int Cold;	//����
	int Freeze;	//����
	int BurningBreath;	//�ܔM�̑���
} s_NegativeStatus;

//�f�o�t
typedef struct ts_DebuffNamed
{
	//���ʒl��ێ�
	//�Ǝ�
} s_DebuffNamed;

//��b�X�e�[�^�X
typedef struct ts_Attribute
{
	float HitPoint;	//�c��̗�
	float Attack;	//�U����
	float Deffence;	//�h���
	float Resist;	//�p�ϐ�
	float RedeploymentTurn;	//�Ĕz�u�^�[����
	float DeploymentPoint;	//�z�u�R�X�g

	float SkillPoint;	//�X�L���p�R�X�g�̏���or���ݒl
	
	int BattleStyle;	//�U�����@
	
	int Block;	//�u���b�N�\��
	int Range;	//�U���͈�(�t�B���^�ԍ�)
	//�U���͈͂�15�}�X*15�}�X�̐����`�̈�̒����ɃL���������z�I�ɒu�����A�Ƃ����悤�Ȕz���p�ӂ��A������t�B���^�̗l�Ɏg���܂�

	int Speed;	//��x�ɐi�߂�}�X�̐�
} s_Attribute;

//�X�e�[�^�X
typedef struct ts_Status
{
	s_Attribute InitAttribute;	//�����l
	s_Attribute NowAttribute;	//���ݒl
} s_Status;

//�u���m�v�̌^�g
typedef struct ts_Stuff
{
	Stuff_Personal Personal;	//�ʏ��
	Stuff_Position Position;	//�ʒu
	Stuff_Shape	Shape;	//�`
	Stuff_Ability Ability;	//�ł��鎖
} Stuff;

//������
int Stuff_Initialize();

//�Z�b�g
//�ʏ��
int Stuff_Set_Personal_Name( char NewName[] );
int Stuff_Set_Personal_Number( int NewNumber );
//�ʒu
int Stuff_Set_Position_XY( int NewX , int NewY );
int Stuff_Set_Direction( int NewDirection );
//�`
int Stuff_Set_Shape_Size( int NewSizeX , int NewSizeY );
int Stuff_Set_Shape_GraphHundle( char* FileName );

//�X�V����
//�ʒu�ς�
int Stuff_Update_PositionX_Increment();
int Stuff_Update_PositionX_Decrement();
int Stuff_Update_PositionY_Increment();
int Stuff_Update_PositionY_Decrement();
//�����ς�
int Stuff_Update_PositionDirection_Up();
int Stuff_Update_PositionDirection_Down();
int Stuff_Update_PositionDirection_Right();
int Stuff_Update_PositionDirection_Left();


#endif
#ifndef MAP_H
#define MAP_H

#define MAP_NUM_MAX (2)

#define MAP_NAME_MAX (20)
#define MAP_SIZEX_MAX (20)
#define MAP_SIZEY_MAX (15)
#define MAP_CELL_SIZEX (32)
#define MAP_CELL_SIZEY (32)

//��b�X�e�[�^�X
typedef struct ts_Attribute
{
	int State[ MAP_SIZEX_MAX ][ MAP_SIZEY_MAX ];	//�e�}�X�̏��
	float Skillpoint;	//�X�L�������p�R�X�g
} s_Attribute;

//��{�I�ȃX�e�[�^�X
typedef struct ts_Basic
{
	int PersonalNumber;	//���ʔԍ�
	char Name[ MAP_NAME_MAX ];	//���O
	int SizeX,SizeY;	//�傫��
} s_Basic;

//�������
typedef struct ts_Special
{
} s_Special;

//���X�e�[�^�X
typedef struct ts_Combat
{
	float NowCost;	//���݂̃R�X�g
	int ElapsedTurn;	//�o�߃^�[����
	int NumberOfBases;	//���_�}�X�̐�
	int NumberOfFriends;	//�����̐�
	int NumberOfEnemies;	//�G�̐�
} s_Combat;

typedef struct ts_MapSatstus
{
	s_Basic Basic;	//��{���
	s_Attribute InitAttribute;	//�����̏��
	s_Attribute NowAttribute;	//���݂̏��
//	s_Combat Team1;	//�`�[��1�̍��X�e�[�^�X
//	s_Combat Team2;	//�`�[��2�̍��X�e�[�^�X
} s_MapStatus;

//�}�b�v�̏��
static s_MapStatus InitMapStatus;
static s_MapStatus NowMapStatus;

//�}�b�v�̏�����Ԃ��Ăяo��
int Map_Call_InitState();

//������(�Ăяo��)
int Map_Initialize( int MapNumber );

//�X�V
int Map_Update();

//�`��
int Map_Draw();
int Map_Draw_StatusAll();

//�I��
int Map_Finalize();

#endif
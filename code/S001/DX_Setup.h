#ifndef DX_SETUP_H
#define DX_SETUP_H

#include "Input.h"
#include "FPS.h"

//�t�H���g���̍ő�l
#define FONT_HUNDLE_MAX (16)
//�t�H���g���̍Œ��l
#define FONT_NAME_MAX (16)

//�t�H���g���
typedef struct ts_DXSS_Font
{
	int Num;	//�o�^����Ă���t�H���g�̐�
	char Name[ FONT_HUNDLE_MAX ][ FONT_NAME_MAX ];	//���O
	int Hundle[ FONT_HUNDLE_MAX ];	//�n���h��
	int Size[ FONT_HUNDLE_MAX ];	//�傫��
	int Thick[ FONT_HUNDLE_MAX ];	//����
} DXSS_Font;

//�X�N���[�����
typedef struct ts_DXSS_Screen
{
	int SizeX;	//��
	int SizeY;	//�c
	int ColorBitNum;	//�J���[�r�b�g��
} DXSS_Screen;

//�E�B���h�E���
typedef struct ts_DXSS_Window	
{
	int Mode;	//�E�B���h�E���[�h
} DXSS_Window;


//���
typedef struct ts_DXSetupStatus
{
	DXSS_Screen Screen;	//�X�N���[�����
	DXSS_Window Window;	//�E�B���h�E���
	DXSS_Font	Font;	//�t�H���g���
} DXSS;

//����ێ�
static DXSS initStatus;

//����������
int DX_Setup_Initialize( int ScreenSizeX , int ScreenSizeY , int ScreenColorBitNum ,
						 int WindowMode );

//�t�H���g�ݒ�
int DX_Setup_Initialize_Font( int FontNum ,
							  char FontName[ FONT_HUNDLE_MAX ][ FONT_NAME_MAX ] , 
							  int FontSize[] , 
							  int FontThick[] );

//�`�揈��
int DX_Setup_Draw( int CoordX , int CoordY ,int Color );

//�擾�p
int DX_Setup_GetScreenSizeX();
int DX_Setup_GetScreenSizeY();
int DX_Setup_GetScreenColorBitNum();

//�X�V����
int DX_Setup_Update( void );

//�I������
int DX_Setup_Finalize();

#endif
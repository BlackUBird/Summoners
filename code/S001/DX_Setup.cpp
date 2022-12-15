#include "DX_Setup.h"
#include "DxLib.h"



//����������
int DX_Setup_Initialize( int ScreenSizeX , int ScreenSizeY , int ScreenColorBitNum ,
						 int WindowMode )
{
	//�ݒ�A�ύX-------------------------------------------
	// �E�C���h�E���[�h�ɕύX
	if( ChangeWindowMode( WindowMode ) != DX_CHANGESCREEN_OK )
	{
		return -1;
	}
	// ��ʃ��[�h�̐ݒ�
	if( SetGraphMode( ScreenSizeX , ScreenSizeY , ScreenColorBitNum ) != DX_CHANGESCREEN_OK )
	{
		return -1;
	}
	// �c�w���C�u��������������
	if( DxLib_Init() == -1 )
	{
		return -1 ;			// �G���[���N�����璼���ɏI��
	}



	//����ێ�---------------------------------
	//�X�N���[�����
	//��ʃT�C�Y���Z�b�g
	initStatus.Screen.SizeX = ScreenSizeX;
	initStatus.Screen.SizeY = ScreenSizeY;
	//�J���[�r�b�g�����Z�b�g
	initStatus.Screen.ColorBitNum = ScreenColorBitNum;

	//�E�B���h�E���
	//�E�B���h�E���[�h���Z�b�g
	initStatus.Window.Mode = WindowMode;

	return 0;
}

//�t�H���g�ݒ�
int DX_Setup_Initialize_Font( int FontNum ,
							  char FontName[ FONT_HUNDLE_MAX ][ FONT_NAME_MAX ] , 
							  int FontSize[] , 
							  int FontThick[] )
{
	//�t�H���g���
	initStatus.Font.Num = FontNum;	//�t�H���g�̐�
	for( int i = 0 ; i < FontNum ; i++ )
	{
		initStatus.Font.Size[i] = FontSize[i];	//�T�C�Y
		initStatus.Font.Thick[i] = FontThick[i];	//����
		//���O
		strcpy( initStatus.Font.Name[i] , FontName[i] );
		//�n���h��
		initStatus.Font.Hundle[i] = CreateFontToHandle( FontName[i] , FontSize[i] , FontThick[i] );
	}

	return (initStatus.Font.Num);
}

//�`�揈��
int DX_Setup_Draw( int CoordX , int CoordY , int Color )
{
	//�\������ʒu
	int x,y;
	//���������̒l�Ȃ�(0,0)
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


	//�`��-----------------------------------------------
	//�`�悷����̐�(�s��)
	int RowCnt = 0;
	//�X�N���[������`��
	DrawFormatString( x , y+16*RowCnt++ , Color , "ScreenSizeX=%d ScreenSizeY=%d" , initStatus.Screen.SizeX , initStatus.Screen.SizeY );
	DrawFormatString( x , y+16*RowCnt++ , Color , "ScreenColorBitNum=%d" , initStatus.Screen.ColorBitNum );
	//�E�B���h�E���
	DrawFormatString( x , y+16*RowCnt++ , Color , "WindowMode=%s" , initStatus.Window.Mode == TRUE ? "WindowMode" : "FullScreen" );
	//�t�H���g���
	DrawFormatString( x , y+16*RowCnt++ , Color , "FontNum=%d" , initStatus.Font.Num );
	for( int i = 0 ; i < initStatus.Font.Num ; i++ )
	{
		DrawFormatString( x , y+16*RowCnt++ , Color , "FontName=%s FontSize=%d FontThick=%d FontHundle=%d" , initStatus.Font.Name[i] , initStatus.Font.Size[i] , initStatus.Font.Thick[i] , initStatus.Font.Hundle[i] );
	}


	return (y+16*RowCnt);
}

//�擾�p
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

//�X�V����
int DX_Setup_Update( void )
{
	int errNum = 0;	//�G���[���N������
	errNum += ScreenFlip();	// ����:0 ���s:-1
	errNum += ProcessMessage();	//����:0 ���s:-1
	errNum += ClearDrawScreen();	//����:0 ���s:-1
	errNum += Input_Update();	//����:0 ���s:-1
	errNum += FPS_Update();	//����:0 ���s:-1

	return (errNum);	//�ԋp(����Ȃ�0)
}

//�I������
int DX_Setup_Finalize()
{
	DxLib_End();
	return 0;
}

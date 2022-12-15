#include "DxLib.h"
#include "DX_Setup.h"

#define NUMBER_OF_RUNNER (1)
#define NAME_LENGTH (20)

#define MAP_HEIGHT (8)
#define MAP_WIDTH (10)

char KeyBuf[256];

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
						LPSTR lpCmdLine, int nCmdShow )
{
	//�Z�b�g�A�b�v
	//�X�N���[��:640*480
	//�J���[�r�b�g��:32
	//�\�����[�h:�E�B���h�E���[�h
	if( DX_Setup_Initialize( 640 , 480 , 32 , TRUE  ) != 0 )
	{
		return (-1);
	}

	//�t�H���g
	int FontSize[] = { 16 , 32 };
	int FontThick[] = { 5 , 7 };
	char FontName[][FONT_NAME_MAX] =
	{
		"�Ƃ肠����" , 
		"�Ƃ肠����2"
	};
	//�ݒ�
	if( DX_Setup_Initialize_Font( 2 , FontName , FontSize , FontThick ) < 0 )
	{
		return (-1);
	}
	

	//������--------------------------------------
	//FPS�ݒ��������
	FPS_Initialize( 30 );
	//����
	Input_Initialize();

	//1�t���[�����Ƃɍs���������L�q
	//ESC�������ꂽ��I��
	while( DX_Setup_Update() == 0 && Input_GetKeyState( KEY_INPUT_ESCAPE ) == 0 )
	{

		//�`��-----------------------------------------

		//FPS�҂�
		FPS_Wait();
	}

	WaitKey() ;				// �L�[���͑҂�


	DX_Setup_Finalize();
	//DxLib_End() ;				// �c�w���C�u�����g�p�̏I������

	return 0 ;				// �\�t�g�̏I�� 
}
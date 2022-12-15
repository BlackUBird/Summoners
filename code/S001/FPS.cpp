#include "FPS.h"
#include "DxLib.h"
#include <math.h>

//������
int FPS_Initialize( int fps )
{
	//FPS��ݒ�
	initFPS = fps;

	return (initFPS);
}

//�X�V
int FPS_Update()
{
	//1�t���[���ڂȂ猻�ݎ������L��
	if( Count == 0 )
	{
		StartTime = GetNowCount();
	}
	//"�T���v����"�t���[���ڂȂ畽�ς��v�Z
	if( Count == SampleNum )
	{
		//���ݎ���(�~���b)
		int time = GetNowCount();
		//���݂�FPS
		nowFPS = 1000.0f / ((time-StartTime)/(float)SampleNum);
		
		//�J�E���^��0�ɂ���
		Count = 0;

		//����J�n�������X�V
		StartTime = time;
	}

	//�J�E���^��1�i�߂�
	Count++;

	//���̃J�E���^�̒l��Ԃ�
	return (0);
}

//�ҋ@
int FPS_Wait()
{
	//�����������Ԃ��v�Z
	tookTime = GetNowCount() - StartTime;
	//�҂ׂ�����(������ׂ�����-������������)���v�Z
	waitTime = Count * 1000 / initFPS - tookTime;
	//�҂ׂ����Ԃ�0���傫����Α҂�
	if( waitTime > 0 )
	{
		Sleep( waitTime );
	}

	return (waitTime);
}

//�`��
int FPS_Draw( int CoordX , int CoordY , int Color )
{
	DrawFormatString( CoordX , CoordY , Color , "initFPS:%d waitTime:%d FPS:%.1f" , initFPS , waitTime , nowFPS );

	return (CoordY);
}

//�I��
int FPSFinalize()
{
	return (1);
}
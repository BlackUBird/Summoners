#ifndef FPS_H
#define FPS_H

static int StartTime;	//����J�n����(��ƂȂ鎞��)
static int Count;	//�J�E���^(�t���[�������L��)
static float nowFPS;	//���݂�FPS

static const int SampleNum = 60;	//���ς��Ƃ�T���v����

static int initFPS;	//�ݒ肵��FPS

static int tookTime;
static int waitTime;

//������
int FPS_Initialize( int fps );

//�X�V
int FPS_Update();

//�ҋ@
int FPS_Wait();

//�`��
int FPS_Draw( int CoordX , int CoordY , int Color );

//�I��
int FPS_Finalize();

#endif
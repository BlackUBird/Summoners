#include "Input.h"
#include "DxLib.h"

//�O�����͂̏󋵂��L������
static Input nowInput;

//������������
int Input_Initialize()
{
	//�����ݒ�
	//�ŏ��͓��͂��󂯕t���Ă�����
	nowInput.Available = 1;

	//�ŏ��͑S�ĉ�������Ă��Ȃ����
	for( int i = 0 ; i < NUMBER_OF_KEY_CODE ; i++ )
	{
		nowInput.KeyBuf[i] = 0;
	}

	//���͂��󂯕t���Ă��邩�ǂ�����ԋp
	//���������1
	return (nowInput.Available);
}

//�O�����͂̏󋵂�\��
int Input_Draw( int CoordX , int CoordY , int Color )
{
	//�`�悷����̐�(�s��)
	int RowCnt = 0;
	//�\���ǂ���
	DrawFormatString( CoordX , CoordY+16*RowCnt++ , Color , "Available:%d" , nowInput.Available );

	return (CoordY+16*RowCnt);
}

//�Z�b�^
int Input_SetAvailable( bool newAvailable )
{
	nowInput.Available = newAvailable;

	return (nowInput.Available);
}


//�Q�b�^
int Input_GetKeyState( int KeyCode )
{
	return (nowInput.KeyBuf[ KeyCode ]);
}

//�O�����͂̏󋵂��X�V
int Input_Update()
{
	//���͂��\���ǂ����𔻕�
	if( nowInput.Available == 0 )
	{
		return (0);	//0�Ȃ牽����������I��
	}

	//�S�ẴL�[�̉�����Ԃ��擾
	if( GetHitKeyStateAll( nowInput.KeyBuf ) != 0 )
	{
		return (1);	//�擾�Ɏ��s������1��ԋp
	}
	else
	{
		return (0);	//����I���Ƃ���0��ԋp
	}
}

//�I������
int Input_Finalize()
{
	return (0);	//���ɂ�邱�Ƃ��Ȃ�^^;
}
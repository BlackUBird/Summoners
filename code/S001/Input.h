#ifndef INPUT_H
#define INPUT_H

#define NUMBER_OF_KEY_CODE (256)

//�O������(�L�[����)�̏󋵂��L�������̍\����
typedef struct ts_Input
{
	bool Available;	//���͂��󂯂��Ă��鎞��1
	char KeyBuf[ NUMBER_OF_KEY_CODE ];	//���ׂẴL�[�̉�����Ԃ��Ď�
} Input;

//������������
int Input_Initialize();

//�O�����͂̏󋵂�\��
int Input_Draw( int CoordX , int CoordY , int Color );

//�Z�b�^
int Input_SetAvailable( bool newAvailable );

//�Q�b�^
int Input_GetKeyState( int KeyCode );

//�O�����͂̏󋵂��X�V
int Input_Update();

//�I������
int Input_Finalize();

#endif
#include <stdio.h>
/*
�I�u�W�F�N�g�̐����Ɣj��
C++�ł̓������m�ۂ�new/delete���g�����Ƃōs�����Ƃ��ł��܂��B
�܂��́A�������m�ۂ̂����ȑO�ɁA
�Ȃ��������m�ۂ��K�v�Ȃ̂��b���Ă����܂��B
*/
/*
�Ȃ��������m�ۂ��K�v�Ȃ̂�
�Q�[���Ɍ��炸�A���ׂẴA�v���P�[�V�����ɂ����āA
�c��ȃf�[�^�������A�v���P�[�V�����͂��̂��ׂẴf�[�^���A
��������ɓW�J���邱�Ƃ͂ł��܂���B
�Ȃ��Ȃ�A�������͗L��������ł��B
�������������ɂ���΁A�������m�ۂ��s���K�v�͂���܂���B
�������A�����I�Ƀ������������Ƃ������Ƃ͂Ȃ��̂ŁA
�������m�ۂ̋@�\�𗘗p���A
�����������̃^�C�~���O�ɕK�v�ȗʂ����g���A
�Ƃ������Ƃ��s�����Ƃ��ł���̂ŁA
�������m�ۂ̓������������ɂȂ�܂ł́A
�K�v�ȋZ�p�ɂȂ�܂��B

�����b�g�F
�L���ȃ��������A���̎��X�̕K�v�ȗʂ����g�����Ƃ��ł���B

�f�����b�g�F
�m�ۂ����������̉����Y���ƁA���������[�N���āA�o�O�̌����ɂȂ�B
���������������m�ۏ����͏d�����B
*/
/*
new
new�̏����̓�������K�v�ʊm�ۂ��A
���̊m�ۉ����������ǂ��ɂȂ邩�����A
�擪�̃A�h���X��Ԃ��Ă���鏈���ł��B

// newInt�̎w����(�������m�ۂ��ꂽ�ӏ�)�͖�������
int * newInt = new int;
// newInt�̎w����(�������m�ۂ��ꂽ�ӏ�)��0�ŏ�����
int * newInt = new int();
// newInt�̎w����(�������m�ۂ��ꂽ�ӏ�)��10�ŏ�����
int * newInt = new int(10);

��L�̂悤�ɁA
�������m�ۂ̂����͕�������B

// �z����m�ۂ���ꍇ
int * newArray = new int[1000]

// �������m�ۂɎ��s�������ǂ������肷��ꍇ
int * newArray2 = new (std::nothrow) int[1000]
{
	// �������s��
}

�����̕�(char��int��float�Ȃ�)�����łȂ��A
�����ō����class���A������񃁃����m�ۂł���B
class Vector3D
{
public:
	Vector3D()
	{
		x = y = z = 0;  // �ꊇ�œ����l�ŏ���������Ȃ炱���������������\
	}

private:
	float x;
	float y;
	float z;
};

Vector3D * pVec3d = new Vector3D();
*/
/*
int main()
{
	// newInt�̎w����(�������m�ۂ��ꂽ�ӏ�)�͖�������
	int* newInt = new int;

	// newInt�̎w����(�������m�ۂ��ꂽ�ӏ�)��0�ŏ�����
	int* newInt2 = new int();

	// newInt�̎w����(�������m�ۂ��ꂽ�ӏ�)��10�ŏ�����
	int* newInt3 = new int(10);

	printf("newInt1 = %d\n", *newInt);
	printf("newInt2 = %d\n", *newInt2);
	printf("newInt3 = %d\n", *newInt3);

	delete newInt3;
	newInt3 = nullptr;  // ���̌㏈���͂Ȃ��̂ŕK�v�Ȃ����ȕt���̈Ӗ��ŏ���
	delete newInt2;
	newInt2 = nullptr;
	delete newInt;
	newInt = nullptr;
}
*/
/*
delete
delete��new�Ƒ΂ɂȂ鏈���ŁA
�m�ۂ��Ă�������������������܂��B
new�Ń��������m�ۂ��Ă����ꍇ�A�K��delete�ŉ������K�v������܂��B

int * newInt = new int();
int * newArray = new int[100];

delete[] newArray;
newArray = nullptr;

delete newInt;
newInt = nullptr;

new�͂��낢��Ȋm�ۂ̂���������܂������A
delete�͔z�񂩂����łȂ�����2�p�^�[���ɂȂ�܂��B
delete��������̃|�C���^�ϐ���nullptr�����Ă����āA
���݂ǂ̃A�h���X���w���Ă��Ȃ�=�g�p���Ă��Ȃ��ϐ��A
�Ƃ������Ƃ𖾎����Ă����܂��傤�B
*/
/*
int main()
{
	int* newArray = new int[1000];
	for (int i = 0; i < 1000;i++)
	{
		newArray[i] = i;
		printf("%d\n", newArray[i]);
	}
}
*/
class Array
{
	// ���̒�������
public:
	Array()
	{
		newArray = nullptr;
	}
	int Get(int num)
	{
		array_number = newArray[num];
		if (0 >= check_newArray || check_newArray > 1000)
		{
			printf("�z��Q�ƊO\n");
		}
		return array_number;
	}
	void Set(int size1, int size2);
	void Create(int array_size);
	~Array()
	{
		delete[] newArray;
		newArray = nullptr;
	}
private:
	int* newArray;
	int check_newArray;
	int array_number;
};
int main()
{
	Array array;

	array.Create(1000);


	for (int i = 0; i < 1000; ++i)
	{
		array.Set(i, i);
	}

	for (int i = 0; i < 1000; ++i)
	{
		printf("num = %d\n", array.Get(i));
	}

	// �z��O�Q�Ƃ��悤�Ƃ����ۂ��m�F
	printf("num = %d\n", array.Get(-1));
	printf("num = %d\n", array.Get(1000));
}
void Array::Create(int array_size)
{
	check_newArray = array_size;
	newArray = new int[array_size];
}
void Array::Set(int size1, int size2)
{
	newArray[size1] = size2;
	if (0 >= check_newArray || check_newArray > 1000)
	{
		printf("�z��Q�ƊO\n");
	}
}
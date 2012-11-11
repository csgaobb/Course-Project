#include "que_Array.h"

qArray::qArray()
{
	front = rear = 0;
	size = 0;
}
qArray::~qArray()
{
}
void qArray::insert(char m)
{
	if (size < MAX-1) //����û������ʱ��
	{
		qArr[rear] = m;
		++rear;
		++size;
	}
	else
		cout << "����������ɾ��ʧ��" << endl;

}
void qArray::delete_p()
{
	if (size == 0)
		cout << "����Ϊ�գ�ɾ��ʧ��" << endl;
	else
	{
		qArr[front] = '\0';
		++front;
		--size;
	}
}
int qArray::judge()
{
	if (size == 0)
		return 1;
	else
		return 0;
}
void qArray::clean()
{
	for (int i = front; i < rear; i++) //�����е�Ԫ����Ϊ��
	{
		qArr[i] = '\0';
	}
	front = rear = 0;
	size = 0;
}
void qArray::print()
{
	for (int i = front; i < rear; i++)
	{
		cout << qArr[i] << "\t" ;
	}
	cout << endl;
}
void qArray::print_size()
{
	cout << "size :" << size << endl;
}
#include "que_Array.h"

int main()
{
	qArray a;
	cout << "��������Ҫ�������" << endl;
	int getNumber = 0;
	cin >> getNumber;
	cout << "��������ַ�" << endl;
	for (int i = 0; i < getNumber; i++)
	{
		char getChar = 0;
		cin >> getChar;
		a.insert(getChar);
	}
	cout << "��ʾ����Ԫ�ص����ݼ����д�С����:" << endl;
	a.print();
	a.print_size();
	a.delete_p();

	a.insert('m');
	a.insert('n');

	cout << "ɾ������Ԫ��֮��ʣ��ĸ���Ԫ�����£�" << endl;
	a.print();
	a.print_size();

	a.clean();
	cout << "��ն��к���е�Ԫ��" << endl;
	a.print();
	a.print_size();
	return 0;
}
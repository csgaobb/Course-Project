#include "list.h"

int main()
{
	INTLIST list(3); //��ʼ��10��Ԫ�أ��������������ڵĻ����Զ���չ
	cout << "--------���������ݵĸ���!-------" << endl;
	int getNum = 0;
	cin >> getNum;
	cout << "������" << getNum << "����������" << endl;
	for (int i = 0; i < getNum; i++)
	{
		int getInt = 0;
		cin >> getInt ;
		list.insert(getInt);
	}
	list.print();
			//������֤ɾ��ģ��Ĺ���
	cout << "----------������Ҫɾ����Ԫ��-------" << endl;
	int deleteNum=0;
	cin >> deleteNum ;
	if(list.remove(deleteNum))
		cout << "ɾ���ɹ�!" << endl;
	else
		cout << "ɾ��ʧ��!" << endl;
	list.print();
			//������֤����ģ��Ĺ���
	cout <<"---------����Ҫ��Ҫ���ҵ�Ԫ��--------"<< endl;
	int findNum = 0;
	cin >> findNum;
	if (list.find(findNum))
		cout << "�ҵ�Ҫ���ҵ�Ԫ��!" << endl;
	else
		cout << "û���ҵ�Ҫ���ҵ�Ԫ��!" << endl;
				//������֤���ҹ���ģ��
	cout << "---------������Ҫ��λ�ı������ݵ�λ��---------" << endl;
	int location = 0;
	cin >> location ;
	cout << "��λ�ô���Ӧ������ֵΪ:" << list.get(location) << endl;

	return 0;
}
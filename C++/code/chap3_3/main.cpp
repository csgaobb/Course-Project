#include "queue.h"

int main()
{
	cout << "-----------������ʵ���ַ����г���-----------\n" << endl;
	Queue qList;
	int getNum;
	cout <<"������Ҫ�������ݵĸ���" << endl;
	cin >> getNum;
	for (int i = 0; i < getNum; i++) //��֤�����������ȷ��
	{
		char getChar = NULL;
		cin >> getChar;
		qList.insert(getChar);
	}
	qList.print();//��ʾ�����Ľ��
	cout << ">>>>>>>>>>>ɾ������Ԫ�غ�>>>>>>>>>>" << endl;
	qList.delete_p();  //��֤ɾ������������ʾ���1
	qList.print();
	cout << "--------�ж϶����Ƿ�Ϊ�գ���Ϊ�վ������Ϣ���������-----" << endl;
	if (qList.judge())
		cout << "����Ϊ��" << endl;
 	qList.clean();  //clean������������������Ч��
	return 0;
}
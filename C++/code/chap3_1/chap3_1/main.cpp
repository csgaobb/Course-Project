#include "Set.h"
#include <iostream>
using namespace std;

int main()
{
	SET a(10);
	cout << "��ʼ����Ĵ�СΪ10��������10�����ݣ��Ժ�ʹ����Ҳ�����ٴη��䣬��̬��չ��" << endl;
	for (int i = 0; i < 10; i++) //���￴����ʹԽ����Ҳ���Գɹ����룬��Ϊinsert��ʵ�����·���
	{
		int getNumber = 0;
		cin >> getNumber;
		if (0 == a.insert(getNumber))
			cout << "����Ԫ���Ѿ����ڣ�����ʧ��" << endl;
	}
	a.print();
	cout << "����Ҫ����Ԫ��" << endl;
	int getNumber2 = -1;
	cin >> getNumber2 ;
	if (0 == a.insert(getNumber2))    
		cout << "����Ԫ���Ѿ����ڣ�����ʧ��" << endl;
	a.print();
	cout << "ɾ��ĳ�������Ԫ�أ�������һ����" << endl;
	int getNumber3 = 0;
	cin >> getNumber3;
	if (0 == a.remove(getNumber3))  
		cout << "û���ҵ���Ҫɾ����Ԫ��v��ɾ��ʧ��" << endl;   
	a.print();
	cout << "����ĳ�������Ԫ�أ������ھ����������Ϣ��������" << endl;
	int getNumber4 = 0;
	cin >> getNumber4;
	if (0 == a.has(getNumber4))
		cout << "û���ҵ�Ԫ��v������ʧ��" << endl;
	return 0;
}
#pragma warning(disable C4996)

#include <iostream>
#include "List.h"
#include <cstring>
using namespace std;

int main()
{
	cout << "---------ѧ���ɼ���¼����ϵͳ:-------------" << endl;
	cout << "\t\t 1.����һ��ѧ����¼" << endl;
	cout << "\t\t 2.��ѯѧ���ɼ�" << endl;
	cout << "\t\t 3.�޸�����" << endl;
	cout << "\t\t 4.�޸ĳɼ�" << endl;
	cout << "\t\t 5.�˳�" << endl;
	cout << "���������ѡ�1,2,3,4,5��������س�" << endl;
	int getChoice = 0;
	scanf("%d",&getChoice);
	char NAME[MAX];char PASSWORD[MAX];
	float ENG;float MATH; float PHYS;float CHEM;
	if(getChoice == 1){
		cout << "����������:";  cin >> NAME;
		cout << "����������:";  cin >>PASSWORD;
		cout << "������Ӣ��ɼ�:";  cin >> ENG;
		cout << "��������ѧ�ɼ�:";  cin >> MATH;
		cout << "����������ɼ�:"; cin >> PHYS;
		cout << "�����뻯ѧ�ɼ�:";  cin >> CHEM;
	}
	Student a(NAME, PASSWORD, ENG, MATH, PHYS, CHEM);
	cout << "please enter your password:" << endl;
	char Pssword[MAX];
	cin >> Pssword;
	if (!a.enterPsw(Pssword))
		a.print();
	return 0;
}
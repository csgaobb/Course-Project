#include <iostream>
#include <stdio.h>
using namespace std;

#define INCREMENT 10

class INTLIST{
	int *list;  //��̬������ڴ��ָ��
	int size;   //���Ա��ܹ���ŵ�Ԫ�ظ���
	int used;   //���Ա��Ѿ���ŵ�Ԫ�ظ���
public:
	INTLIST(int s);  //sΪ���Ա��ܹ���ŵ�Ԫ�ظ���
	int insert(int v);   //����Ԫ��v�ɹ�ʱ����1�����򷵻�0
	int remove(int v);  //ɾ��Ԫ��v�ɹ�ʱ����1�����򷵻�0
	int find(int v);   //����Ԫ��v�ɹ�ʱ����1�����򷵻�0
	int get(int v);   //ȡ��ĵ�k��Ԫ�ص�ֵ��Ϊ����ֵ
	void print();     //Ϊ�����������ڵ����ö��ӵġ�
	~INTLIST();
};

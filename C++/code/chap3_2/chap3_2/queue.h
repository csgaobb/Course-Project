#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct Node{
	char s;
	Node *next;
}Node;

class Queue
{
	Node *t;     //ͷָ�룬Ҳ�����Ǹ�������
	Node *tail; //βָ�룬ָʾ���һ��Ԫ��
	int size;  //���еĳ��ȣ���Ԫ�ظ���
public :
	Queue();
	~Queue(){}
	void insert(char s);  //��һ���ַ�s���뵽����β��
	void delete_p(); //ɾ�����еĶ���Ԫ��
	int judge(); //�ж�һ�������Ƿ�Ϊ�գ�Ϊ�շ���1�����򷵻�0
	void clean();  //��ն���
	void print();   //���Ժ͵��Դ�����
};

#define MAX 5
#include <iostream>

using namespace std;

class qArray
{
	char qArr[MAX];  //����һ������ַ�����,�����е�ʱ���СΪMAX-1
	int front;	//��ʾ����ͷ����λ��,ָ�����±��λ��
	int rear;	//��ʾ����β������һ��λ��
	int size ;   //���е�ʵ�ʳ���
public:
	qArray();
	~qArray();
	void insert(char m);  //��һ���ַ����뵽����β��,����ʧ�ܷ���1�����򷵻�0
	void delete_p(); //ɾ�����еĶ���Ԫ�أ�ɾ���ɹ�����0�����򷵻�1
	int judge(); //�ж�һ�������Ƿ�Ϊ�գ�Ϊ�շ���1�����򷵻�0
	void clean();  //��ն���,�൱����������������
	void print();   //���Ժ͵��Դ�����
	void print_size();	//��ʾ�������ȷ�����ڵ����á�
};
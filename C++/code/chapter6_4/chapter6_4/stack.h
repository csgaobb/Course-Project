#include <string>
#include <iostream>
using namespace std;

class STACK{
	const int max; //ջ�ܹ���ŵ����Ԫ�ظ���
	int top;		//ջ��Ԫ�ص�λ��,ָ��Ԫ�ص�����һ����Ԫ
	char *stk;		//ջ��ָ��
public:
	STACK(int max);
	~STACK();
	int push(char v);	//��vѹջ���ɹ�ʱ����1�����򷵻�0
	int pop(char &v);	//����ջ��Ԫ�أ��ɹ�����1�����򷵻�0
};
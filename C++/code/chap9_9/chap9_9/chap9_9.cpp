#include <iostream>
using namespace std;

class QUEUE{
	struct NODE{
		int value;
		NODE *next;
		NODE(int a,NODE *p){
			value = a;
			next = p;
		}
	}*head;
public:
	QUEUE();
	QUEUE(const QUEUE &);
	virtual operator int() const;	//���ض���Ԫ�ظ���
	virtual QUEUE &operator>>(const int &);	//�Ӷ���ȡһ��Ԫ��
	virtual QUEUE &operator<<(int);		//�������м���һ��Ԫ��
	virtual ~QUEUE();
	void print();
};

QUEUE::QUEUE(){
	head = 0;
}
QUEUE::QUEUE(const QUEUE &b){
	NODE *tmp = b.head; 
	int count = 0;	//�ڵ����
	while(tmp != NULL){
		count++;
		tmp = tmp ->next ;
	}
	tmp = b.head;	//ִ�������ʱָ����Ϊ��ʼλ�ã�����Ҫʹ��
	this->head = new NODE(tmp->value,NULL);	//������һ���ڵ�
	for(int i = 1; i < count; i++){
		NODE *newNode = new NODE(tmp->value,head);	//���򹹽����պ��γ�����
		head = newNode;
		tmp = tmp ->next;	//�βε��Ǹ������ϱ�����Ȼ�󴴽��µĽڵ�
	}
}

QUEUE::~QUEUE(){
	NODE *phead = this->head;
	while(phead !=NULL){
		NODE *tmp = phead->next;
		delete tmp;
		phead = tmp;
	}
}

QUEUE::operator int() const{	//���ض���Ԫ�ظ���
	NODE *tmp = this->head; 
	int count = 0;	//�ڵ����
	while(tmp != NULL){
		count++;
		tmp = tmp ->next ;
	}
	return count;	
}
QUEUE &QUEUE::operator>>(const int &b){	//�Ӷ���ȡһ��Ԫ��
	NODE *tmp = this->head;
	NODE *ptmp = NULL;
	while(tmp != NULL){
		ptmp = tmp;
		tmp = tmp->next;
	}
	*(int *)(&b) = tmp->value;	//���������򴴽��ģ�������Ҫ�����õ����һ�������������Ƚ��ȳ�����
	delete tmp;
	ptmp->next = NULL;//ȡ��һ��Ԫ�غ�ɾ������ڡ�
	return *this;
}
QUEUE &QUEUE::operator<<(int b){		//�������м���һ��Ԫ��
	NODE *newNode = new NODE(b,head);	//����һ���½ڵ㣬�����ڶ�����
	head = newNode;	//���ı�ͷ
	return *this;
}

void QUEUE::print(){
	NODE *tmp = head;
	while(tmp != NULL){
		cout << tmp->value << " ";
		tmp = tmp ->next;
	}
	cout << endl;
}
int main()
{
	QUEUE que;
	for(int i = 0; i < 5; i++)
		que << i;	//��������
	que.print();
	int num = que;	//ǿ������ת��
	cout << num << endl;
	return 0;
}




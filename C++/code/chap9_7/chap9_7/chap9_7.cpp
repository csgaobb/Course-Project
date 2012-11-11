#include <iostream>
using namespace  std;

class LIST{
	struct NODE{
		int value;
		NODE *next;
		NODE(int a,NODE *p){
			value = a;
			next = p;
		}
	}*head;
public:
	LIST();
	LIST(const LIST &);
	int find(int value) const;//����value���ҵ�����1�����򷵻�0
	int operator[](int k)const;	//ȡ��ĵ�k��Ԫ��
	virtual LIST operator+(const LIST&);	//��ĺϲ�����
	virtual LIST operator+(int value);	//����һ��Ԫ��
	virtual LIST operator-(int value);	//ɾ��һ��Ԫ��
	virtual LIST &operator+=(const LIST&);	//��ĺϲ�����
	virtual LIST &operator+=(int value);	//����һ��Ԫ��
	virtual LIST &operator-=(int value);	//ɾ��һ��Ԫ��
	virtual LIST &operator=(const LIST &);
	virtual ~LIST();
};
LIST::LIST():head(NULL){}
LIST::LIST(const LIST &b){
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

LIST::~LIST(){
	NODE *phead = this->head;
	while(phead !=NULL){
		NODE *tmp = phead->next;
		delete tmp;
		phead = tmp;
	}
}

int LIST::find(int value) const{
	NODE *tmp = this->head;
	int count = 0;
	while(tmp!=NULL){
		if(value == tmp->value)
			return 1;	//�ҵ�����1
		tmp = tmp->next;
	}
	return 0;	//û���ҵ�����0
}

int LIST::operator[](int k)const{
	NODE *tmp = this->head;
	for(int i = 0; i < k; i++){
		tmp = tmp ->next;
	}
	return tmp->value;
}

LIST LIST::operator+(const LIST& b){
	NODE *tmp = b.head;
	while(tmp != NULL){
		NODE *newNode = new NODE(tmp->value,head);	//����������������ֵͬ�Ľڵ�
		head = newNode;
		tmp = tmp ->next ;
	}
	return *this;
}

LIST LIST::operator+(int value)
{
	NODE *newNode = new NODE(value,NULL);//����һ���ڵ���ָ��Ϊ�յĽڵ㣬�������
	NODE *tmp = this->head;
	while(tmp!=NULL){
		tmp = tmp ->next;
	}
	tmp = newNode;
	return *this;
}
LIST LIST::operator-(int value){
	if(find(value)==0)
		return  *this;	//ɾ��ʧ�ܣ�û���ҵ���Ԫ��
	else{
		NODE *tmp = this->head;
		while(tmp->value != value)
			tmp = tmp->next;
		NODE *freep = tmp->next;
		delete(tmp);	//ɾ���Ǹ���Ԫ
		tmp = freep;	//ָ��ָ�����¸�
		return *this;
	}
}
LIST &LIST::operator+=(const LIST&b){
	*this = *this + b;
	return *this;
}

LIST &LIST::operator+=(int value){	//����һ��Ԫ��
	*this = *this + value;
	return *this;
}
LIST &LIST::operator-=(int value){	//ɾ��һ��Ԫ��
	*this = *this - value;
	return *this;
}
LIST &LIST::operator=(const LIST &b){	//��ֵ���������Ҫ�����ԭ����
	NODE *tmp = this->head->next;
	while(tmp !=NULL){
		NODE *freep = tmp;
		delete freep;
		tmp = tmp->next;
	}
	NODE *flagb = b.head;
	while(flagb!=NULL){
		NODE *newNode = new NODE(flagb->value,this->head);	//����������������ֵͬ�Ľڵ�
		this->head = newNode;
		flagb = flagb ->next ;
	}
	return *this;
}

int main(){
	return 0;
}




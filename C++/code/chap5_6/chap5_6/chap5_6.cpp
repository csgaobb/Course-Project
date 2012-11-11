#include <iostream>
using namespace std;
class SEQUENCE;
class TREE{		//��ʾһ���ڵ�,����ֵ��ָ��
	int item;
	TREE *left,*right;
	friend SEQUENCE;
public:
	TREE(int value,TREE *l,TREE *r);	//����һ����
	int getNode();			//���ؽڵ���
	int getNode(int *items);
};

TREE::TREE(int value,TREE *l,TREE *r){
	item = value;
	left = l;
	right = r;
}

int TREE::getNode(){	
	int l =0, r = 0;
	if(left != NULL)
		l = left-> getNode();
	if(right != NULL)
		r = right->getNode();
	return l+r+1;
}
int TREE::getNode(int *items){	//���ؽڵ���,������Ҫ�ݹ����
	int    n=0; 
	if(left)   n=left->getNode(items); 
	items[n++] = TREE::item; 
	if(right)   n= n + right->getNode(items); 
	return   n;
} 

class SEQUENCE{
	int *items;
	int size;
public:
	SEQUENCE(TREE &);
	void print();	//Ϊ�˱�����������˸����Դ��뺯��
};

SEQUENCE::SEQUENCE(TREE &b)
{
	int   m; 
	size=b.getNode();
	items=new int[size];	//��̬����һ������,������ֵ
	b.getNode(items);
}
void SEQUENCE::print(){
	for(int i = 0; i < size; i++)
		cout << items[i] << " ";
}
int main()
{
	TREE a(5,NULL,NULL);
	TREE b(0,NULL,NULL);
	TREE c(1,&b,&a);	//���������ӽڵ����
	SEQUENCE seq(c);
	seq.print();
	return 0;
}
#include <iostream>
using namespace std;

class TREE{ 
	int   item; 
	TREE   *left, *right;	//��������
public: 
	TREE(int *a, int b);
	friend void print(TREE *p);
}; 
void print(TREE *p);		//���Ժ�����ʵ��������۲��Ƿ���ȷ
TREE::TREE(int *a, int b){	//�ݹ鴴��������
	int   x = b / 2;
	item = a[x]; 
	if(x > 1)
		left = new TREE(a,x-1);
	else
		left = NULL;
	if(b > x + 1)
		right = new TREE(a+x+1,b-x-1);
	else
		right = NULL;
} 
void print(TREE *p){
	cout << p->item << " ";
	if( p->left!= NULL)
		print(p->left);
	if( p->right!=NULL)
		print(p->right);
}
int main(){ 
	int  s[]={1,2,3,4,5,6,7,8,9,10}; 
	TREE t(s, 10);
	print(&t);
	return 0;
} 

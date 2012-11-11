#include <iostream>
#include <string>
using namespace std;
const int MAX = 10;

class Item
{
public:
	void print();
	int insert(string s);
	int search(string s);
	int delete_item(int i);
	Item():stored(0){}
private:
	string a[MAX];  //����������
	int stored ;	//��־�Ѵ�ŵ��±�
};

int Item::insert(string s)
{
	if (stored== MAX-1)
		return 0;	//��������������ʧ��
	else{
		a[stored] = s;
		stored++;
		return 1;
	}
}
int Item::search(string s)
{
	for(int i = 0; i <= stored; i++)
	{
		if (s == a[i])
			return 1;  //�ҵ�
	}
	return 0;	//û���ҵ���string
}

int Item::delete_item(int i) //ɾ��ָ���±��item
{
	if(i > stored)
		return 0;	//û����ô����±�Ԫ�أ�ɾ��ʧ��
	else{
		for(int j = i; j <= stored; j++){
			a[j] = a[j+1];
		}
		return 1;
	}
}
void Item::print()
{
	for(int i = 0; i <= stored; i++)
		cout << a[i] << endl;
}
void main()
{
	Item a;
	a.insert("Hello,world");
	a.insert("Me!");
	a.insert("I Love C++");
	a.insert("just for test");
	a.print();
	if(a.search("sjife"))
		cout << "find" << endl;
	if(!a.search("Me!"))
		cout << "not found!" << endl;
	if(a.delete_item(2)){
		cout << "after deleting the item 3" << endl;
		a.print();
	}
}





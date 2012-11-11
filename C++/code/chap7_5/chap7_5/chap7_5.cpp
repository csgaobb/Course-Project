#include <iostream>
using namespace std;

class List;
class Abstrcat{
	int size;	//�������Ա�����
	int number;	//�������Ա�ǰԪ�ظ���
public:
	virtual int insert(int pinsert)=0;		//����ɹ��ɹ�����1�����򷵻�0
	virtual int delete_p(int pdelete)=0;	//ɾ���ɹ��ɹ�����1�����򷵻�0
	virtual int search(int psearch)=0;		//���ҵ�Ԫ�ط���1�����򷵻�0
	friend class List;	//����������Ϊ������Ԫ��ע��Ϳ��Է���˽�г�Ա
};

class List:public Abstrcat{
	int *pList;
public:
	List(int psize){
		pList = new int [psize];
		Abstrcat::size = psize;
		Abstrcat::number = 0;
	}
	~List(){
		if(!pList)
			return ;
		delete pList; 
	}
	int insert(int pinsert){
		if(Abstrcat::number==Abstrcat::size)	//��������������ʧ��
			return 0;
		else{
			pList[Abstrcat::number++] = pinsert;
			return 1;
		}
	}
	int delete_p(int pdelete){
		int mark = -1;	//��־ɾ��Ԫ������λ��
		for(int i = 0; i < Abstrcat::number;i++){
			if (pdelete == pList[i]){
				mark = i;
			}
		}
		if(-1 == mark)
			return 0; //ɾ��ʧ�ܣ�û���ҵ���Ԫ��
		else{
			for (int j = mark; j < Abstrcat::number-1;j++){
				pList[j] = pList[j+1];
			}
			Abstrcat::number--;
			return 1;
		}
		
	}
	int search(int psearch){
		for(int i = 0; i < Abstrcat::number;i++){
			if (psearch == pList[i]){
				return 1;	//�ҵ���Ԫ��
			}
		}
		return 0;
	}
	void print(){
		for(int i = 0; i < Abstrcat::number;i++){
			cout << pList[i] << " " ;
		}
		cout << endl;
	}
};

int main()
{
	List list(10);
	for (int i = 0; i < 10; i++)
		list.insert(i);			//ͨ��insert��������������Ԫ��
	cout << "����������ڵ����Ϣ���£�" << endl;
	list.print();
	if (1==list.search(5))
		cout << "�ҵ�Ԫ��5��" << endl;
	else
		cout << "û���ҵ�Ԫ��5��\n" << endl;
	cout << "ɾ��Ԫ�غ�......" << endl;
	if (0==list.delete_p(10))
		cout << "����ɾ������......ɾ��ʧ�ܣ�û��Ԫ��Ϊ10�Ľڵ�!" << endl;
	list.delete_p(5);
	cout << "ɾ��Ԫ��5��......." << endl;
	list.print();
}
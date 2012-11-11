#pragma warning(disable: 4996)
#include <iostream>
using namespace std;
const int MAX = 12;

class Clerk{
public:
	char name[MAX];	//����
	int ID;	//ְ����
	float salary;	//����
	int temp;	//�������ֲ�ͬԱ��
	char leader[MAX];	//�������Ա���ľ������𷢹��ʵ���
	virtual void print(){}
};

class TempClerk:public Clerk{
public:
	TempClerk(char *str,int bnum,char *lead=NULL,float sal=0){ //��ʱ��temp�ͳ�ʼ��Ϊ1
		temp = 1;
		strcpy(name,str);	//����
		ID = bnum;			//ְ����
		strcpy(leader,lead);	//ֱ������
		salary = sal;	
	}
	void print(){ cout << "I am a Temporary Clerk!" << endl;}
	~TempClerk(){}
};
class PermenClerk:public Clerk{
public:
	PermenClerk(char *str,int bnum,char *lead=NULL,float sal=0){	//����ʱ��temp�ͳ�ʼ��Ϊ0
		temp = 0;
		strcpy(name,str);	//����
		ID = bnum;			//ְ����
		strcpy(leader,lead);
		salary = sal;
	}
	void print(){ cout << "I am a stuff!" << endl;}
	~PermenClerk(){}
};
class Manager:public PermenClerk{	
public:
	int Maneger_flag;	//����ľ�����ϰ������
	Manager(char *str,int bnum,char *lead=NULL,float sal=NULL)
		:PermenClerk(str,bnum,lead,sal){ //��ͨ�ľ���������boss
			Maneger_flag = 1;			
	}
	void print(){cout << "I am a manager!" << endl;	} //��Ŀ����
	~Manager(){}
};

class Boss:public Manager{
public:
	Boss(char *str,int bnum,char *lead=NULL,float sal=NULL)
		:Manager(str,bnum,NULL,NULL){ //�ϰ���û�����ܺ͹��ʵ�
		Maneger_flag = 0;	//��־���ϰ�
	}
	void print(){   cout << "I am a Boss!" << endl;		}//�ϰ�
	~Boss(){}
};

int main()
{
	PermenClerk   a("Tom",0001,"Jerry",1000);
	TempClerk	  b("Jack",0002,"Jerry",800);
	Manager		c("Jerry",0003,"Boss",3000);
//	Boss		d("Boss",0,0,0);
	Clerk *newClerk = &a;
	newClerk->print();
	newClerk = &b;
	newClerk->print();
	newClerk = &c;
	newClerk->print();
	cout << "I am a Boss!" << endl;
}
#pragma warning(disable:4996) 

#include <iostream>
using namespace std;
const int MAX = 25;

class Base{
public:
	char name[MAX];
	int age;
	char social_Num[MAX];
	virtual void print(){}
	virtual void set_next(Base *p){}
	virtual Base *get_next(){ return NULL;}
};

class Student:public Base{
	char grad[MAX];
	double average_score;
public:
	Base *next;
	Student(char *name,int age1,char *social,char *grad,double average):next(NULL){
		strcpy(this->name,name);
		this->age = age1;
		strcpy(this->social_Num,social);
		strcpy(this->grad,grad);
		this->average_score = average;
	}
	void set_next(Base *p){		next = p;}
	Base *get_next(){	return this->next; }
	void print(){
		cout << "����: "<<this->name << "\t���䣺" << this->age << "\n��ᱣ�պ�:"
			<< this->social_Num << "\t�꼶:" << this->grad << "\t\tƽ���ɼ�:" << this->average_score << endl;
	}
};

class Clerk:public Base{
	double wage;
public:
	Base *next;
	Clerk(char *name,int age1,char *social,double wage1):next(NULL){
		strcpy(this->name,name);
		this->age = age1;
		strcpy(this->social_Num,social);
		this->wage = wage1;
	}
	void set_next(Base *p){		next = p;}
	Base *get_next(){	return this->next;}
	void print(){
		cout << "����: "<<this->name << "\t���䣺" << this->age << "\n��ᱣ�պ�:"
			<< this->social_Num << "\t����:" << this->wage  << endl;
	}
};

class Professer:public Base{
	double wage;
	char major[MAX];
public:
	Base *next;
	Professer(char *name,int age1,char *social,double wage1,char *major1):next(NULL){
		strcpy(this->name,name);
		this->age = age1;
		strcpy(this->social_Num,social);
		this->wage = wage1;
		strcpy(this->major,major1);
	}
	void set_next(Base *p){		next = p;}
	Base *get_next(){	return this->next;}
	void print(){
		cout << "����: "<<this->name << "\t���䣺" << this->age << "\n��ᱣ�պ�:"
			<< this->social_Num << "\t����:" << this->wage << "\t�о�����:" << this->major << endl;
	}
};

class List{//����������
	Base *head;
public:
	List(Base *p){
		head = p;
		p->set_next(NULL);	//������ڵ����next��ֵΪNULL
	}
	void insert(Base *p){
		p->set_next(head);	//�µĽڵ����ǰ��,���������ڵ�֮�����ϵ����ʹ����ͬһ���࣬Ҳ��������ָ��
		head = p;		//���ó�ʼ��ͷָ��
	}
	void delete_list(Base *p){ 
		Base *tmp = head;
		if(head == p){		//���ɾ����ǡ����ͷָ��(��ʼ��ʱ��û��ע����������������)
			head = p->get_next();
		}
		else{
			while(tmp->get_next()!= p){
				tmp = tmp->get_next();
			}
			Base *tmp2 = tmp->get_next()->get_next();
			delete tmp->get_next();		//ɾ���Ǹ��м�Ľڵ�
			tmp->set_next(tmp2);
		}
	}
	void print(){
		Base *ptmp = head;
		while(ptmp->get_next()!=NULL){
			ptmp->print();
			ptmp = ptmp->get_next();
		}
		ptmp->print();	//������һ������Ϊ��̽ڵ�ΪNULL���������⴦��
	}
};
//����ʵ�ֵ�������������������麯�������ԣ�������Ե���nextָ���print�麯�����ӽ�����Կ������Ǹ�����ָ��
//ʵ��ָ��ĵ�Ԫ������������ġ�nextָ�붼��Base *���͵ģ���������Ĳ���Base����Ϣ��������û������ˣ�,
//����ʵ��ָ������ͣ������������Clerk��
int main()
{
	Student student("jack",20,"132343","g1",87.8);
	Clerk clerk("Clerk",34,"23434",1000);
	Professer professer("Professor",50,"234356",10000,"computer");
	List aList(&student);
	cout << "��ʼ����ͨ�����뺯������������.......\n" << endl;
	aList.insert(&clerk);
	aList.insert(&professer);
	aList.print();
	cout << "\nɾ����������ڵ���Ϣ��........"<< endl;
	aList.delete_list(&professer);
	aList.print();
	cout << "\n���²��������Ϣ�ڵ㣬Ȼ��ɾ��ѧ���ڵ�...." << endl;
	aList.insert(&professer);
	aList.delete_list(&student);
	aList.print();
	return 0;
}


#include <iostream>
using namespace std;
class STATE;
class LIST{		//����STATE�仯��һ��ָ��
	LIST *next;
	char input;
	STATE *output;
	LIST(char in,STATE *out);	//˽�У�����STATE ʹ��
	~LIST();
	friend STATE;	//����Ϊ��Ԫ���Է���
};

class STATE{
	char *name;	//״̬��
	LIST *list;	//��������б�
	static STATE *error;	//�Զ�������
public:
	void enlist(char in,STATE *out);	//����list
	const STATE *next(char in)const;	//����inת�Ƶ���һ��״̬
	const STATE *start(char *)const;	//���������Զ���
	STATE(char *name);
	~STATE();
};

LIST::LIST(char in,STATE *out){   
	input=in;   
	output=out;   
	next=NULL;	//����һ��ָ������Ϊ�գ�����һ���ڵ��LIST  
}   
LIST::~LIST(){   
	if(this->next != NULL){
		delete this->next;
	}   
}   
STATE   *STATE::error = NULL;   
STATE::STATE(char *name):name(0),list(0){ 
	if(name==0){
		error = this;	//�����Զ�������
		return;   
	}   
	STATE::name=new char[strlen(name)+1];   
	strcpy(this->name,name);   
}  

void STATE::enlist(char in,STATE *out){	//����list   
	LIST *temp;   
	if(list==0){   
		list=new   LIST(in,   out);   
		return;   
	}   
	temp=new LIST(in,out);   
	temp->next=list;   
	list=temp;   
}   
const STATE *STATE::next(char in)const{	//����inת�Ƶ���һ��״̬   
	LIST *temp=list;   
	if(this==error)   
		return   error;   
	while(temp){   
		if(temp->input==in)   
			return   temp->output;   
		else   
			temp=temp->next;   
		return   error;  
	}
}   
const STATE *STATE::start(char *s)const{	//���������Զ���   
	const   STATE   *temp=this;   
	while(*s)   
		temp=temp->next(*s++);   
	return   temp;   
}   
STATE::~STATE(){   
	if(name){
		cout<<name<<"\n";  
		delete   name;  
		name=0;   
	}   
	if(list){
		delete   list;  
		list=0;  
	}   
}   
// ��M ��ʾ�� ��W ��ʾҰ�� B����     
// ��ʼ״̬Ϊ"BMMMYYY_" ��ֹ״̬Ϊ "_BMMMYYY"     
//���Ӷ������������֣��˵�������s �����˹���d Ұ�˵�������w ����Ұ�˹���t�˴���Ұ�˹���b 
int main( ){    
	char m[80];    
	STATE error(0);    
	STATE start("start");//BMMMYYY_    
	STATE MMMY_BYY("MMMY_BYY");//1    
	STATE MMYY_BMY("MMYY_BMY");//2    
	STATE BMMMYY_Y("BMMMYY_Y");//3    
	STATE MMM_BYYY("MMM_BYYY");//4    
	STATE BMMMY_YY("BMMMY_YY");//5    
	STATE MY_BMMYY("MY_BMMYY");//6    
	STATE BMMYY_MY("BMMYY_MY");//7    
	STATE YY_BMMMY("YY_BMMMY");//8    
	STATE BYYY_MMM("BYYY_MMM");//9    
	STATE Y_BMMMYY("Y_BMMMYY");//10    
	STATE BMY_MMYY("BMY_MMYY");//11    
	STATE BYY_MMMY("BYY_MMMY");//12    
	STATE stop("stop");//_BMMMYYY    
	start.enlist('t',&MMMY_BYY);    
	start.enlist('b',&MMYY_BMY);    
	MMMY_BYY.enlist('t',&start);    
	MMMY_BYY.enlist('w',&BMMMYY_Y);    
	MMYY_BMY.enlist('b',&start);    
	MMYY_BMY.enlist('s',&BMMMYY_Y);    
	BMMMYY_Y.enlist('w',&MMMY_BYY);    
	BMMMYY_Y.enlist('s',&MMYY_BMY);    
	BMMMYY_Y.enlist('t',&MMM_BYYY);    
	MMM_BYYY.enlist('t',&BMMMYY_Y);    
	MMM_BYYY.enlist('w',&BMMMY_YY);    
	BMMMY_YY.enlist('w',&MMM_BYYY);    
	BMMMY_YY.enlist('d',&MY_BMMYY);    
	MY_BMMYY.enlist('d',&BMMMY_YY);    
	MY_BMMYY.enlist('b',&BMMYY_MY);    
	BMMYY_MY.enlist('b',&MY_BMMYY);    
	BMMYY_MY.enlist('d',&YY_BMMMY);    
	YY_BMMMY.enlist('d',&BMMYY_MY);    
	YY_BMMMY.enlist('w',&BYYY_MMM);    
	BYYY_MMM.enlist('w',&YY_BMMMY);    
	BYYY_MMM.enlist('t',&Y_BMMMYY);    
	Y_BMMMYY.enlist('t',&BYYY_MMM);    
	Y_BMMMYY.enlist('s',&BMY_MMYY);    
	Y_BMMMYY.enlist('w',&BYY_MMMY);    
	BMY_MMYY.enlist('s',&Y_BMMMYY);    
	BMY_MMYY.enlist('b',&stop);    
	BYY_MMMY.enlist('w',&Y_BMMMYY);    
	BYY_MMMY.enlist('t',&stop);    
	cout<<"�˵�������s \t�����˹���d \nҰ�˵�������w \t����Ұ�˹���t\t�˴���Ұ�˹���b\n";    
	cout<<"������:\n";     
	cin>>m;    
	getchar();    
	if(start.start(m)==&stop) cout<<"���ӳɹ���\n";    
	else cout<<"����ʧ�ܣ�\n";    
	getchar();    
	return 1;    
}    

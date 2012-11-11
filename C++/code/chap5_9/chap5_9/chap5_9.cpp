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
void   main(   ){   
	STATE   start("WSGM_");   //��ʼ״̬
	STATE   stop("_WSGM");   
	STATE   error(0);   
	STATE   WG_SM("WG_SM");   //�˴��ǹ�ΪW��ʾ
	STATE   WGM_S("WGM_S");   //�˴��ݹ�ΪG��ʾ
	STATE   G_WSM("G_WSM");		//���Լ���ΪM��ʾ
	STATE   SGM_W("SGM_W");   
	STATE   W_SGM("W_SGM");   //��߶���ĸ���״̬��������Ӧ���ַ�����ʾ
	STATE   WSM_G("WSM_G");   //��ʾ���е���صı�ʾ��ͨ�������enlist
	STATE   S_WGM("S_WGM");   //���״̬��Ȼ��ʵ���Զ������л�
	STATE   SM_WG("SM_WG");   //��̬������״̬ת�����仯�л�
	start.enlist('S',   &WG_SM);   
	WG_SM.enlist('S',   &start);   
	WG_SM.enlist('M',   &WGM_S);   
	WGM_S.enlist('M',   &WG_SM);   
	WGM_S.enlist('W',   &G_WSM);   
	WGM_S.enlist('G',   &W_SGM);   
	G_WSM.enlist('W',   &WGM_S);   
	W_SGM.enlist('G',   &WGM_S);   
	G_WSM.enlist('S',   &SGM_W);   
	SGM_W.enlist('S',   &G_WSM);   
	SGM_W.enlist('G',   &S_WGM);   
	S_WGM.enlist('G',   &SGM_W);   
	W_SGM.enlist('S',   &WSM_G);   
	WSM_G.enlist('S',   &W_SGM);   
	WSM_G.enlist('W',   &S_WGM);   
	S_WGM.enlist('W',   &WSM_G);   
	S_WGM.enlist('M',   &SM_WG);   
	SM_WG.enlist('M',   &S_WGM);   
	SM_WG.enlist('S',   &stop);   
	stop.enlist('S',   &SM_WG);   
	if(start.start("SMWSGMSSS")==&stop)  //���ӳɹ�
		cout<<"OK";   
}   
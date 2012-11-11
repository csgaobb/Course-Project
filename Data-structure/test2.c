#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define ERROR  0
#define OK  1
#define OVERFLOW -2
#define queuesize 20
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild; //���Һ���ָ��
}BiTNode,*BiTree;
typedef struct Queue{
	 int front ,rear ;
     BiTree data[queuesize]; //ѭ������Ԫ������Ϊ����������ָ��
	 int count;
}Queue; //ѭ�����нṹ����

int CreateBiTree(BiTree * T) { //�����ľ���һ��BiTree���͵�ָ��,ͨ���޸�����main�е�T���޸ģ�Ȼ��ʹ��ָ������
  // �������������������н���ֵ��һ���ַ������ո��ַ���ʾ������
  // ������������ʾ�Ķ�����T��
  int ch;
  printf("������һ��������ֵ�����Ϊ�գ�������0��\n");
  scanf("%d",&ch);
  if (ch==0) (*T)= NULL;
  else {
    if (!(*T = (BiTNode *)malloc(sizeof(BiTNode))))  return ERROR;
    (*T)->data = ch;              // ���ɸ����
    CreateBiTree(&(*T)->lchild);   // ����������
    CreateBiTree(&(*T)->rchild);   // ����������
  }
  return OK;
} // CreateBiTree

int PreOrderTraverse(BiTree T) //�õݹ��㷨д�ı����������������������ͬʱ�������ֵ
{
	if(T!=NULL) 
	{
		printf("%d  ",T->data); 
		PreOrderTraverse(T->lchild); 
		PreOrderTraverse(T->rchild);
	} 
	return OK;
} 

int InorderTraverse(BiTree T)
{
	if(T!=NULL)
	{
		InorderTraverse(T->lchild);
		printf("%d ",T->data);
		InorderTraverse(T->rchild);
	}
	return OK;
}
int PreOrderTraverse2(BiTree T)  //�÷ǵݹ���㷨д�ı����������������������ͬʱ�������ֵ
{
   BiTree p,s[20];
   int top=0;
   p=T;
   while((p!=NULL)||(top>0))
   {
	   while(p!=NULL)
	   {
		   printf("%d ",p->data);
		   s[++top]=p;
		   p=p->lchild;
	   }
	   p=s[top--];
	   p=p->rchild;
   }
   return OK;
}

int get_all_node(BiTree T)  //����ܵĽ��ĸ���
{
   BiTree p,s[20];
   int num_node=0;
   int top=0;
   p=T;
   while((p!=NULL)||(top>0))
   {
	   while(p!=NULL)
	   {
		   num_node++;
		   s[++top]=p;
		   p=p->lchild;
	   }
	   p=s[top--];
	   p=p->rchild;
   }
   return num_node;
}

int get_node0_1(BiTree T)//���õݹ��㷨�õ���Ϊ0�Ľ��ĸ���
{
	int num1,num2;
	if(T==NULL)
		return 0;
	else
	{
        if((T->lchild==NULL)&&(T->rchild==NULL))
			return 1;
		else
		{
			num1=get_node0_1(T->lchild);
            num2=get_node0_1(T->rchild);
			return (num1+num2);
		}
	}
}
int get_node0_2(BiTree T) //���÷ǵݹ��㷨��ͬʱ���ò�α����ķ������õ���Ϊ0�Ľ��  
{
     Queue *q;
     BiTree p=T;
	 int num=0; 
	 q=(Queue *)malloc(sizeof(Queue));
	 q->front=0;
	 q->rear=0;
	 q->data[q->rear]=p;
	 q->rear++;
	 while(q->front < q->rear)
	 {
		 p=q->data[q->front];
		 q->front++;
		 if(p->lchild==NULL && p->rchild==NULL)
		 {
			 num++;
		 }
		 if(p->lchild!=NULL)
		 {
			 q->data[q->rear]=p->lchild;
			 q->rear++;
		 }
		 if(p->rchild!=NULL)
		 {
			 q->data[q->rear]=p->rchild;
			 q->rear++;
		 }
	 }
	return num;
}

int get_node1(BiTree T) //�����ܵĹ�ϵ�����Ϊ1�Ľ��ĸ���
{
	int num=get_all_node(T)-2*get_node0_1(T)+1;
	return num;
}
int get_node1_1(BiTree T)   //�ǵݹ��㷨��ͬʱ���ù�ϵ���Ϊ1�Ľ�㡣
{
	int num=get_all_node(T)-2*get_node0_2(T)+1;
	return num;
}
int get_node2(BiTree T) //���ö�Ϊ2�Ľ��������Ϊ0�Ľ������Ĺ�ϵ�õ�
{
	int num=get_node0_1(T)-1;
	return num;
}
int get_node2_1(BiTree T)   //�ǵݹ��㷨��ͬʱ���ù�ϵ���Ϊ2�Ľ�㡣
{
	int num=get_node0_2(T)-1;
	return num;
}
int get_node(BiTree T)
{
	int get;
   printf("��������Ҫ���ҵĽ��Ķ�\n");
   printf("1.��ѯ��Ϊ0�����н��ĸ���\n");
   printf("2.��ѯ��Ϊ1�����н��ĸ���\n");
   printf("3.��ѯ��Ϊ2�����н��ĸ���\n");
   scanf("%d",&get);
   switch(get){
   case 1:
	  printf("��Ϊ0�����н��ĸ�����%d\n",get_node0_1(T));
	  break;
   case 2:
	   printf("��Ϊ1�����н��ĸ�����%d\n",get_node1(T));
	   break;
   case 3:
	   printf("��Ϊ2�����н��ĸ�����%d\n",get_node2(T));
	   break;
   }
   return OK;
}
int get_node_1(BiTree T)        //���÷ǵݹ��㷨��ʵ��
{
	int get;
	printf("�������÷ǵݹ��㷨����ѯ\n");
   printf("��������Ҫ���ҵĽ��Ķ�\n");
   printf("1.��ѯ��Ϊ0�����н��ĸ���\n");
   printf("2.��ѯ��Ϊ1�����н��ĸ���\n");
   printf("3.��ѯ��Ϊ2�����н��ĸ���\n");
   scanf("%d",&get);
   switch(get){
   case 1:
	  printf("��Ϊ0�����н��ĸ�����%d\n",get_node0_2(T));
	  break;
   case 2:
	   printf("��Ϊ1�����н��ĸ�����%d\n",get_node1_1(T));
	   break;
   case 3:
	   printf("��Ϊ2�����н��ĸ�����%d\n",get_node2_1(T));
	   break;
   }
   return OK;
}
int LevelOrder(BiTree T)
{    Queue *q;
     BiTree p;
	 int flag=0;                      //����flagΪ���
	 q=(Queue *)malloc(sizeof(Queue));  //����ѭ�����пռ�
	 q->rear=q->front=q->count=0;      //��ѭ�����г�ʼ��Ϊ��
	 q->data[q->rear]=T;
	 q->count++;
	 q->rear=(q->rear+1)%queuesize;       //����������
	 while (q->count)                   //�����в�Ϊ�գ������²���
		 if(q->data[q->front]){            //������Ԫ�ز�Ϊ��ָ�룬�����²���
			 p=q->data[q->front];           //ȡ����Ԫ��*p
			 printf("%d ",p->data);        //��ӡ*p������������Ϣ
			 ++flag;
			 q->front=(q->front+1)%queuesize;
			 q->count--;       //����Ԫ�س���
			 if (q->count==queuesize)//������Ϊ���������ӡ������Ϣ���˳������ִ��
				 printf("the queue full!\n");
			 else{            //�����в�������*p��������ָ�����
				 q->count++;q->data[q->rear]=p->lchild;
				 q->rear=(q->rear+1)%queuesize;
			 }                        //enf of if
			 if (q->count==queuesize)        //������Ϊ���������ӡ������Ϣ���˳������ִ��
				 printf("the queue full!\n");
			 else{                      //�����в�������*p�����Һ���ָ�����
				 q->count++;q->data[q->rear]=p->rchild;
				 q->rear=(q->rear+1)%queuesize;
			 }                              //end of if
		 }                                //end of if 
		 else{                          //������Ԫ��Ϊ��ָ�룬����ָ�����
			 q->front=(q->front+1)%queuesize;
			 q->count--;
		 }
		 printf("\n");
		 return OK;
}      //end of LevelOrder

int height(BiTree T)
{
	BiTree p=T;
	int a,b;
	if(p==NULL)
		return 0;
	else{
	   if((p->lchild==NULL)&&(p->rchild==NULL))
		    return 1;
    else{
		  a=height(p->rchild);
	      b=height(p->lchild);
		  if(a>b)   return (a+1);
		  else    return (b+1);
		  }
	}
}

int judge(BiTree T)   //���õݹ��㷨��ʵ���ж��Ƿ�Ϊ��ȫ������
{
      if(T ==NULL)  
          return   0;  
      if(T->lchild == NULL && T->rchild== NULL)  
          return   1;   
      if(T->lchild  == NULL  && T->rchild != NULL||T->lchild!=NULL &&T->rchild==NULL)  
          return   0;  
      return   judge(T->lchild) & judge(T->rchild);  

}

int exchange(BiTree T)
{
     BiTree p=T;
	 int exch;
     if(p==NULL)
	     return OK;
	 else
	 {
		 if(p->lchild!=NULL && p->rchild!=NULL)
		 {
             exch=p->lchild->data;
			 p->lchild->data=p->rchild->data;
			 p->rchild->data=exch;
			 exchange(p->lchild);
			 exchange(p->rchild);
		 }
		 else
		 {
			 if(p->lchild==NULL)
				 exchange(p->rchild);
			 else
				 exchange(p->lchild);
		 }
		 return OK;
	 }
}

void copy_TERM(const char *filename,BiTree T)
{
	FILE *fp;
	BiTree p=T,s[20];
	int top=0;
	if((fp=fopen(filename,"w"))==NULL)
	{
		printf("can't open file\n");
		exit(-1);
	}
   while((p!=NULL)||(top>0))
   {
	   while(p!=NULL)
	   {
		   putw(p->data,fp);
		   s[++top]=p;
		   p=p->lchild;
	   }
	   p=s[top--];
	   p=p->rchild;
   }
   fclose(fp);
}
void type(const char *filename,BiTree T)
{
	 FILE *fp;
	 BiTree p=T,s[20];
	 int top=0;
	 if((fp=fopen(filename,"r"))==NULL)
	 {
		 printf("can't open file\n");
		 exit(-1);
	 }		 
	while((p!=NULL)||(top>0))
	{
	   while(p!=NULL)
	   {  
		   printf("%d ",getw(fp));
		   s[++top]=p;
		   p=p->lchild;
	   }
	   p=s[top--];
	   p=p->rchild;
    }
	 fclose(fp);
}

void main()
{
	BiTree T;         //����һ��ָ��BiTNode����ָ��
	int choice;
	do{
	printf("\n");
	printf("��ѡ�������\n");
	printf("1.��������Ĵ�������һ�Ŷ�����\n");
	printf("2.�ݹ��㷨ʵ�ֶ������������������������ֵ\n");
    printf("3.�÷ǵݹ��㷨ʵ�ֶ������ı�������������ֵ\n");
	printf("4.��ȷֱ�Ϊ0��1��2�Ľ�����Ŀ���ݹ��㷨ʵ�֣�\n");
	printf("5.��ȷֱ�Ϊ0��1��2�Ľ�����Ŀ���ǵݹ��㷨ʵ�֣�\n");
	printf("6.����α���������\n");
	printf("7.��������ĸ߶�(���)\n");
	printf("8.�ж��Ƿ�Ϊ��ȫ�����������\"Yes!\"��\"No!\"\n");
	printf("9.����ÿ��������������,������������ķ�ʽ���\n");
	printf("10.�Խ�������������Ķ��������������\n");
    printf("11.���浽�ļ�\n");
	printf("12.���ļ��ж�ȡ�����\n");
	printf("13.�˳�\n");
	scanf("%d",&choice);
	switch(choice){
	case 1:
		CreateBiTree(&T);   //����������
		break;
    case 2:
		PreOrderTraverse(T); //���õݹ��㷨�����������������ֵ
		break;
	case 3:
		PreOrderTraverse2(T);//���÷ǵݹ��㷨�����������������ֵ
		break;
	case 4:
		get_node(T); //���õݹ��㷨�õ��ĸ������ĸ���
		break;
	case 5:
		get_node_1(T);  //���÷ǵݹ��㷨�õ��ĸ������ĸ���
		break;
	case 6:
		LevelOrder(T);
		break;
	case 7:
		printf("�������ĸ߶�Ϊ%d\n",height(T));
		break;
	case 8:
		if(judge(T)==0)
			printf("No!\n");
		else
			printf("Yes!\n");
		break;
    case 9:
         exchange(T);
		 PreOrderTraverse(T);
		 break;
	case 10:
         InorderTraverse(T);
		 break;
	case 11:
		copy_TERM("d:\\aaa.dat",T);
		break;
	case 12:
		type("d:\\aaa.dat",T);
		break;
	}	
	}while(choice!=13);	
}
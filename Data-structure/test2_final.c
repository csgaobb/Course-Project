#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
#define ERROR     0
#define OK        1
#define OVERFLOW  -2
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

int Create_List(LinkList L,int length)
{//����һ������ͷ���Ĵ�СΪn���ĵ�����
	int i;                   
	LinkList p, tail; //����һ��Ҫ��ǰ�棬��������
	    tail=L;
	for(i=0;i<length;i++)
	{
        p=(LinkList)malloc(sizeof(LNode));
		printf("������%d������\n",length);
		scanf("%d",&p->data);
		p->next=NULL;
        tail->next=p;
		tail=tail->next;
	}
       return OK;
}

int display_all(LinkList L,int length) //�����ڳ��ȣ�����ȴ���������Ⱥ��������⡣
{//��ʾ���е�����Ԫ��
	int i;
	printf("���Ա��ȫ������Ԫ�����£�\n");
	for(i=0;i<length-1;i++)
	{
		printf("%d ",L->next->data);
		L=L->next;
	}
	printf("\n");
	return OK;
}

int length_L(LinkList L) //������
{//������Ա�ĳ���
	int length=0;
	LinkList p=L;
	while(p!=NULL)
	{
		++length;
		p=p->next;
	}
	return length;
}

int ListInsert(LinkList L,int i ,int *e)
{//����Ԫ��
	LinkList p=L,s;
	int j=0;
	while(p&&j<i-1)
	{
		p=p->next;
		++j;
	}
     if(!p||j>i-1) return ERROR;
	 s=(LinkList)malloc(sizeof(LNode));
	 s->data=*e;
	 s->next=p->next;
     p->next=s;
	 return OK;
}
int ListDelet(LinkList L, int i) 
{//ɾ��ָ��λ�õĽ��
	LinkList p=L,q;
	int j=0;
	while(p->next&&j<i-1)  //Ѱ�ҵ�i-1�����
	{
		p=p->next;
		++j;
	}
    if(!(p->next)||j>i-1) return ERROR;
    q=p->next; p->next=q->next;
    free(q);
	return OK;
}
int Destroy_L(LinkList L)   //���������һ�����⣬�����ͷ���free���Ļ��ͻ����
                            //��Ϊͷ��㲻���Լ�����ģ�����ϵͳ����ģ����������У������޷��ͷ�
{
     LinkList head=L,p;
	 p=head;
	 if (head)
		 p = head->next ;
	 head = head->next ;
	 while(head!=NULL)
	 {
		 p=head;
		 head=head->next;
		 free(p);
	 }
	 return OK;
}
int ClearList(LinkList L)
{//���Ա��ÿ�
	L->next=NULL;  //��ͷ���ָ������ΪNULL
	return OK;
}
int max_num(LinkList L)
{
	LinkList p=L->next;
	int max=0;
	while(p!=NULL)
	{
		if(max<=p->data)
			max=p->data;
		p=p->next;
	}
	return max;
}

float aver_num(LinkList L)  //ע�⺯������Ҫ�ͱ���ͬ���������׳���
{ //�������Ԫ�ص�ƽ��ֵ
    LinkList p=L->next;
	float average;
	int sum=0;
	int length=length_L(L);
	while(p!=NULL)
	{
		sum+=p->data;
		p=p->next;
	}
	average=(float)sum/(length-1);
	return average;
}

void main()
{
	int i,get,length,e;
	LNode L;           //����ͷ���L
	L.next=NULL;
	do{
		printf("\n");
		printf("1.��������Ԫ�أ����Ƚ��ȳ���ʽ����������\n");
        printf("2.���ٵ�����\n");
	    printf("3.���Ա��ÿ�\n");
	    printf("4.�����Ա���\n");
	    printf("5.�ڵ�i������Ԫ��ǰ�����µ�Ԫ��\n");
	    printf("6. ɾ����i��Ԫ��\n");
	    printf("7.��ʾ���Ա��е�ȫ��Ԫ��\n");
        printf("8.�����Ԫ�ص�ֵ��ƽ��ֵ\n");
		printf("9.�˳�\n");
	    printf("��������ѡ��Ĳ������\n");
	    scanf("%d",&get);
	    switch(get){
	         case 1:
		            printf("����������Ԫ�صĸ���\n");
		             scanf("%d",&length);
                    Create_List(&L,length);
			        break;
             case 2:
                     Destroy_L(&L);
					 break;
			 case 3:
                     ClearList(&L);
					 break;
			 case 4:
				 length=length_L(&L);
                 printf("�����������ĳ���(��ͷ���)Ϊ%d\n",length);
				 break;
			 case 5:
				 printf("��ֱ�������Ҫ�������ݵ�Ԫ�ص�λ��(��i��Ԫ��֮ǰ)��ֵ(����)\n");
				 scanf("%d,%d",&i,&e);
                 ListInsert(&L,i,&e);
				 break;
			 case 6:
				 printf("��ֱ�������Ҫɾ�����ݵ�Ԫ�ص�λ��(��i��Ԫ��)\n");
				 scanf("%d",&i);
                 ListDelet(&L,i);
				 break;
			 case 7:
				   length=length_L(&L);
                   display_all(&L,length);
					break;
			 case 8:
				   printf("���Ա��е����Ԫ����%d\n",max_num(&L));
                   printf("���Ա�������Ԫ�ص�ƽ��ֵ%f\n",aver_num(&L));
				    break;
			 case 9:
				 break;
		}
	}while(get!=9);
            
}

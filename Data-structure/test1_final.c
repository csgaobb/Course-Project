#include<stdio.h>
#include<malloc.h>
#include <conio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 10
#define LISTINCREMENT 10
#define ERROR     0
#define OK        1
#define OVERFLOW  -2

typedef struct{
   int *elem;
   int length;
   int listsize;
   }SqList;

int InitList_Sq(SqList *L) //�����д��ݲ�����������ָ��L,�������ܶ���ָ���Ԫ�ظı䡣
{ 
  int i;
  L->elem=(int *)malloc(LIST_INIT_SIZE*sizeof(int));
  if(!L->elem)  exit(OVERFLOW);
  L->length =10;
  L->listsize = LIST_INIT_SIZE; //�����ʼ�Ŀռ�
  for(i=0;i<L->length;i++)
  {
      L->elem[i]=i;
  }
  return OK;
}//InitList_Sq

int get_length(SqList *L)
{
	return L->length;
}

int destroy(SqList *L)
{
	L->length=0;
	return OK;
}

int ListInsert_Sq(SqList *L,int i, int e)
{ //��˳���L�еĵ�i��λ��֮ǰ�����µ�Ԫ��e��
	//i�ĺϷ�ֵΪ1<=i<=ListLength_Sq(L)+1;
	int *newbase,*q,*p;
	if(i<1||i>L->length+1) return ERROR;
	if(L->length>=L->listsize){// ��ǰ�Ĵ洢�ռ����������ӷ���
		 newbase = ( int *)realloc(L->elem,( L->listsize +LISTINCREMENT)*sizeof(int));
		 if(!newbase) exit(OVERFLOW) ; //�洢�ռ����ʧ��
		 L->elem = newbase;
		 L->listsize+=LISTINCREMENT;	 
   }
   q=&(L->elem[i-1]);
   for(p=&(L->elem[L->length-1]);p>=q;--p)  *(p+1)=*p;
                                       //����λ�ü�֮���Ԫ������            
   *q=e;
   ++L->length;
   return OK;
}//ListInsert_Sq;

int ListDelete_Sq(SqList *L, int i, int e) {  
  // ��˳�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ��
  // i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)��
  int *p, *q;
  if (i<1 || i>L->length) return ERROR;  // iֵ���Ϸ�
  p = &(L->elem[i-1]);                   // pΪ��ɾ��Ԫ�ص�λ��
  e = *p;                               // ��ɾ��Ԫ�ص�ֵ����e
  q = L->elem+L->length-1;                // ��βԪ�ص�λ��
  for (++p; p<=q; ++p) *(p-1) = *p;     // ��ɾ��Ԫ��֮���Ԫ������
  --L->length;                           // ����1
  return OK;
} // ListDelete_Sq

int display_all(SqList *L)
{
	int i;
	for(i=0;i<L->length;i++)
	{
		printf("%d",L->elem[i]);
		printf(" ");
	}
	return OK;
}
int main()
{
	SqList L;
	int get,e=0;
	int i,num;
    InitList_Sq(&L);
	printf("���ݵĳ�ʼ���Ѿ����ã�ֱ�ӿ��Թ۲죬����ʹ�÷�����ʵ�鱨��\n");
	do{
	printf("��������Ҫ���еĲ������\n");
	printf("1.���Ա��ÿ�\n");
	printf("2.�����Ա���\n");
	printf("3.����Ԫ�صĲ������\n");
	printf("4.����Ԫ�ص�ɾ������\n");
	printf("5.��ʾ���Ա��е�ȫ��Ԫ��\n");
	printf("6.�˳�\n");
	scanf("%d",&get);
	switch(get)
	{
	case 1: 
          destroy(&L);//��˳����ÿգ�ֻ��Ҫ���䳤������
		  break;
	case 2:
          printf("�����Ա�ĳ�����%d\n",get_length(&L)); //��ȡ���Ա�ĳ���
		  break;
	case 3:
		  //��ָ����λ���ϲ���ָ��������Ԫ��
		  printf("��������Ҫ�����Ԫ�ص�λ�ã����ڵ�i��Ԫ��֮ǰ���룩�Լ�����Ԫ��(�м��Զ��ŷֿ�)\n");
		  scanf("%d,%d",&i,&num);
		  ListInsert_Sq(&L,i,num); 
		  printf("�µ����Ա���\n");
		  display_all(&L);
		  break;
	case 4:
		//ɾ��ָ��λ�õ�����Ԫ��
		  printf("��������Ҫɾ����Ԫ�ص�λ�ã���ɾ����i��Ԫ�أ�\n");
		  scanf("%d",&i);
          ListDelete_Sq(&L,i,e);
		  printf("�µ����Ա���\n");
		  display_all(&L);
		  break;
	case 5:
		//��ʾ���Ա������Ԫ��
		  display_all(&L);
		  printf("\n");
		  break;
	case 6:
		//�˳�����
		  break;
	}
	}while(get!=6);
    return OK;
}

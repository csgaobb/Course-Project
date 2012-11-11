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
  L->listsize = LIST_INIT_SIZE;
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

int ListInsert_Sq(Sqlist &L,int i, int e)
{ //��˳���L�еĵ�i��λ��֮ǰ�����µ�Ԫ��e��
	//i�ĺϷ�ֵΪ1<=i<=ListLength_Sq(L)+1;
	if(i<1||i>L.length+1) return ERROR;
	if(L.length>=L.listsize){// ��ǰ�Ĵ洢�ռ����������ӷ���
		 newbase = ( int *)realloc(L.elem,( L.listsize +LISTINCREMENT)*sizeof(int));
		 if(!newbase) exit(OVERFLOW) ; //�洢�ռ����ʧ��
		 L.elem = newbase;
		 L.listsize+=LISTINCREMENT;	 
   }
   q=&(L.elem[i-1]);
   for(p=&(L.elem[L.length-1]);p>=q;--p)  *(p+1)=*p;
                                       //����λ�ü�֮���Ԫ������            
   *q=e;
   ++L.length;
   return OK;
}//ListInsert_Sq;

int ListDelete_Sq(SqList &L, int i, int &e) {  // �㷨2.5
  // ��˳�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ��
  // i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)��
  int *p, *q;
  if (i<1 || i>L.length) return ERROR;  // iֵ���Ϸ�
  p = &(L.elem[i-1]);                   // pΪ��ɾ��Ԫ�ص�λ��
  e = *p;                               // ��ɾ��Ԫ�ص�ֵ����e
  q = L.elem+L.length-1;                // ��βԪ�ص�λ��
  for (++p; p<=q; ++p) *(p-1) = *p;     // ��ɾ��Ԫ��֮���Ԫ������
  --L.length;                           // ����1
  return OK;
} // ListDelete_Sq

int main()
{
	int i;
	SqList L;
	int get,e;
    InitList_Sq(&L);
	printf("��������Ҫ���еĲ������\n");
	printf("1.���Ա��ÿ�\n");
	printf("2.�����Ա���\n");
	printf("3.����Ԫ�صĲ������\n");
	printf("4.����Ԫ�ص�ɾ������\n");
	printf("5.��ʾ���Ա��е�ȫ��Ԫ��\n");
	scanf("%d",&get);
	switch(get)
	{
	case 1: 
          destroy(*L);
	case 2:
          get_length(*L);
	case 3:
		  ListInsert_Sq(*L,5,10);
		  printf("");
	case 4:
          ListDelete_Sq(*L,5,&e);
	}
    return OK;
}

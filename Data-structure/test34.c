#include<malloc.h>
#include <conio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ERROR     0
#define OK        1
#define OVERFLOW  -2

typedef struct{
   int *elem;
   int length;
   int listsize;
   }SqList;
   
int InitList_Sq(SqList L) //�����д��ݲ�������L������������ָ��&L��
{  /*����һ���յ����Ա�L*/
  L.elem=(int *)malloc(LIST_INIT_SIZE*sizeof(int));
  if(!L.elem)  exit(OVERFLOW);
  L.length = 0;
  L.listsize = LIST_INIT_SIZE;
  return OK;
}//InitList_Sq

/*
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

int LocateElem_Sq(SqList L, int e,
        Status (*compare)(ElemType, ElemType)) {  // �㷨2.6
  // ��˳�����Ա�L�в��ҵ�1��ֵ��e����compare()��Ԫ�ص�λ��
  // ���ҵ����򷵻�����L�е�λ�򣬷��򷵻�0��
  int i;
  ElemType *p;
  i = 1;        // i�ĳ�ֵΪ��1��Ԫ�ص�λ��
  p = L.elem;   // p�ĳ�ֵΪ��1��Ԫ�صĴ洢λ��
  while (i <= L.length && !(*compare)(*p++, e)) 
    ++i;
  if (i <= L.length) return i;
  else return 0;
} // LocateElem_Sq
*/
int main()
{
	SqList L;
    InitList_Sq(L);
    system("pause");
    return OK;
}

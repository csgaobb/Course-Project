#include "Set.h"
#include <iostream>
using namespace std;

SET::SET(int card):set(0),card(0),used(0)
{
	set = (int *)malloc(card * sizeof(int));
	this->card = card;
	this->used = 0;
}

SET::~SET()
{
	free(set);
}

int SET::size()
{
	return used;
}

int SET::insert(int v)
{
	for (int i = 0; i < used; i++)
	{
		if (v == set[i])  //����Ԫ���Ѿ�����,����ʧ��
		{
		/*	cout << "����Ԫ���Ѿ����ڣ�����ʧ��" << endl;*/
			return 0;
		}
	}
	if (card == 0) //������������Ҫ���·���
	{
		set = (int *)realloc(set,(used + INCRESEMENT)*sizeof(int));
		card = INCRESEMENT; //���¸�ֵ�ܹ���ŵ�Ԫ�ظ���
		set[used] = v;
		--card;   //ÿ�β����ʣ����ܹ���Ÿ�������
		++used;	  //ÿ�β�����Ѿ���ŵĸ�������
		return 1;
	}
	else
	{
		set[used] = v;
		--card;   //ÿ�β����ʣ����ܹ���Ÿ�������
		++used;   //ÿ�β�����Ѿ���ŵĸ�������
		return 1;
	}
}

int SET::remove(int v)
{
	int mark = -1; //����ҵ�Ԫ�ص�λ��
	for (int i = 0; i < used; i++)
	{
		if (v == set[i])
		{
			mark = i;
			break;
		}
	}
	if (-1 == mark) //û���ҵ���Ҫɾ����Ԫ�أ�����
	{
	/*	cout << "û���ҵ���Ҫɾ����Ԫ��v��ɾ��ʧ��" << endl;*/
		return 0;
	}
	else
	{
		for (int i = mark; i < used - 1; i++)
		{
			set[i] = set[i+1];
		}
		--used;  //ɾ��һ��Ԫ�غ��Ѵ洢�ռ����
		++card;  //ɾ��һ��Ԫ�غ���ÿռ�����
		return 1;
	}
}
int SET::has(int v)
{
	for (int i = 0; i < used; i++)
	{
		if (v == set[i])
		{
			cout << "�ҵ�Ԫ��v�����ڵ�λ����" << i+1 << endl; //λ�����±��1
			return 1;
		}
	}
	//cout << "û���ҵ�Ԫ��v������ʧ��" << endl;
	return 0;
}

void SET::print()
{
	cout << "�Ѵ��Ԫ�ظ���Ϊ��" << size() << endl;
	for (int i = 0; i < used; i++)
	{
		cout << set[i] << "  ";
	}
	cout << endl;
}

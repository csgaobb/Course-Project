#include "queue.h"

Queue::Queue()
{
	t = tail = (Node *)malloc(sizeof(Node)); //��ʼ����ͷ
	t->next = tail->next = NULL;
	t->s = tail->s = NULL;
	size = 0;   //��ʼ����ʱ��sizeҲΪ0��û�в�������
}

void Queue::insert(char m)
{
	if (size == 0)
	{
		t->s = tail->s = m;
		++size;
	}
	else if (size == 1)  //�����ڵ�Ļ���Ҫ����ͷ�ڵ������֮��Ĺ�ϵ
	{
		Node *p = (Node *)malloc(sizeof(Node));
		p->s = m;
		t->next = p;
		tail = p;
		p->next = NULL;
		++size;
	}
	else //�����ڵ����ϵĻ�ֱ����tail���������ȥ
	{
		Node *p = (Node *)malloc(sizeof(Node));
		p->s = m;
		tail -> next = p;
		tail = p;  //��ʼȱ����һ�䣬��ôtail�Ͳ��ƶ���
		p->next = NULL;
		++size;
	}
}
void Queue::delete_p()
{
	if (size == 1) //ֻ��һ������
	{
		free(t);
		--size;		//��СΪ0.
	}
	else
	{
		Node *delet = t; //�ݴ�ԭ���ı�ͷָ�����ɾ��
	    t = t -> next ;
		free(delet);
		--size;
	}
}
int Queue::judge()
{
	if (size == 0)  //û�������ݾ��ǿյ�
		return 1;
	else
		return 0;
}
void Queue::clean()
{
	if (size == 1) //����ֻ��һ���ڵ��ʱ����Ҫ���⴦��
		free(t);
	else
	{
		for (int i = 0; i < size; i++)
		{
			Node *tmp = t; //�ݴ�������Ǹ�ָ��
			t = t -> next;
			free(tmp);	
		}
	}
}
void Queue::print()
{
	Node *tmp = t;
	cout << "�����ܵĳ�����:\t"<<size << endl;
	for (int i = 0; i < size ;i++)
	{
		cout << "i = " << i << "\t" << tmp->s << endl;
		tmp = tmp->next;
	}
}
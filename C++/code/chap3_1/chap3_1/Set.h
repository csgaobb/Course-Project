#define  INCRESEMENT 10

class SET{
	int *set;  //set���ڴ�ż���Ԫ��
	int card;   //cardΪ�㹻��ŵ�Ԫ�ظ���
	int used;   //usedΪ�Ѿ���ŵ�Ԫ�ظ���
public:
	SET(int card);  //cardΪ�ܹ���ŵĸ���
	~SET();
	int size();       //���ؼ����Ѿ���ŵ�Ԫ�ظ���
	int insert(int v);  //����v�ɹ��󷵻�1�����򷵻�0
	int remove(int v);  //ɾ��v�ɹ�ʱ����1�����򷵻�0
	int has(int v);     //Ԫ��v���ڷ���1�����򷵻�0��
	void print();   //�����������Ԫ�أ����ڼ������õģ������ڵ��ԡ�
};

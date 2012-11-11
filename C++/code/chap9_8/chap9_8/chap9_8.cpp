#include <iostream>
using namespace std;
const int MAX = 23;

class SET{
	int *elem;			//��ż���Ԫ�صĶ�̬�ڴ�
	int count,total;	//ĿǰԪ�ظ��������Ԫ�ظ���
public:
	SET(int total);
	SET(const SET&);
	int find(int val) const;
	int full() const;
	int empty() const;
	virtual SET operator +(const SET&);
	virtual SET operator -(const SET &)const;        //���ϵĲ
	virtual SET operator *(const SET &)const;         //���ϵĽ��� 
	virtual SET &operator <<(int value);             //����һ��Ԫ�� 
	virtual SET &operator >>(int value);             //ɾ��һ��Ԫ�� 
	virtual SET &operator +=(const SET &);         //���ϵĲ��� 
	virtual SET &operator -=(const SET &);           //���ϵĲ 
	virtual SET &operator *=(const SET &);         //���ϵĽ��� 
	virtual SET &operator  <<=(int value);            //����һ��Ԫ�� 
	virtual SET &operator  >>=(int value);            //ɾ��һ��Ԫ�� 
	virtual SET &operator   =(const   SET   &); 
	virtual ~SET(); 
	void print();
}; 
SET::SET(int total){
	this->total = total;
	elem = new int[total];
	count = 0;
}
SET::SET(const SET& b){
	this->total = b.total;//��ʼ������
	count = b.count;
	elem = new int[total]; //�����ڴ�ռ�
	for(int i = 0; i < count; i++){
		elem[i] = b.elem[i];	//��ֵ
	}
}
SET::~SET(){
	if(elem){
		delete elem;//�ͷ��ڴ��
	}
}
int SET::find(int val) const{
	for(int i=0; i < count; i++){
		if(val == elem[i])
			return 1;	//�ҵ�
	}
	return 0;	//δ�ҵ�
}
int SET::full() const{
	return (int)(count == total);
}
int SET::empty() const{
	return (int)(count==0);
}

SET SET::operator +(const SET& b){
	for(int i =0; i <b.count; i++){
		if(find(b.elem[i])==0){ //�ҵ���Ԫ�أ�����ɾ��
			 elem[count++] = b.elem[i];	//�Ӻ��濪ʼ��ֵ���
			}
		}
	return *this;
}
SET SET::operator -(const SET &b)const{      //���ϵĲ
	for(int i =0; i <b.count; i++){
		if(find(b.elem[i])){//�ҵ���Ԫ�أ�����ɾ��
			int j;
			for ( j= 0; elem[j]!= b.elem[i]; j++){}
			for(int k = j ; j < this->count-1; j++){
					elem[k] = elem[k++];	//ɾ����ǰ��һλ
				}
			}
		}
	return *this;
}
SET   SET::operator *(const SET & b)const{         //���ϵĽ���
	int a[MAX],count =0;
	for(int i = 0; i < this->count; i++)
	{
		for (int j = 0; j < b.count; j++)
		{
			if(elem[i]==b.elem[j])
				a[count++]=elem[i];	//���漯����ͬ��Ԫ���Ա�����
		}
	}
	SET *newSet = new SET(MAX);
	for (int i = 0; i <count; i++)
	{
		newSet->elem[i] = a[i];
	}
	return *this;
}
SET  &SET::operator  <<(int value){             //����һ��Ԫ�� 
	if(find(value) == 0)
		this->elem[count++] = value;
	return *this;
}
SET   &SET::operator >>(int value){	//ɾ��һ��Ԫ��
	int ptest = -1;	//��־λ��ɾ����value��λ��
	for(int i = 0; i < this->count; i++)
	{
		if(elem[i]==value){
			ptest = i; break;
		}		
	}
	for (int i = ptest; i < count; i++)
	{
		this->elem[i] = elem[i++];	//�ƶ�����Ԫ��
	}
	count--;
	return *this;
}
SET  &SET::operator +=(const SET &b){         //���ϵĲ���
	for(int i = 0; i<b.count; i++){
		if(find(b.elem[i])==0){     //���ڱ��������У�ֱ�����
			elem[count++] = b.elem[i];
		}
	}
	return *this;
}

SET   &SET::operator -=(const SET &b){          //���ϵĲ 
	*this = *this - b;		//�����Ѿ�д�õĲ����
	return *this;
}
SET   &SET::operator *=(const SET &b){        //���ϵĽ��� 
	*this = *this * b;
	return *this;	//ͬ��
}
SET   &SET::operator  <<=(int value){            //����һ��Ԫ�� 
	*this = *this << value;
	return *this;
}
SET   &SET::operator  >>=(int value){            //ɾ��һ��Ԫ�� 
	*this = *this >> value;
	return *this;
}
SET &SET::operator =(const  SET  &b){
	for(int i = 0; i < count; i++){
		elem[i] = 0;
	}
	for(int j = 0; j < b.count; j++){
		elem[j] = b.elem[j];
	}
	return *this;
}

void SET::print(){
	for (int i = 0; i < count; i++)
	{
		cout << elem[i] << " ";
	}
	cout << endl;
}
int main()	//���Դ���
{	
	SET a(10);	//����һ��SET����
	for(int i = 0; i < 5; i++)
		a << i;		//����һ��Ԫ��
	a.print();
	a>>4;	//ɾ��ֵΪ4�Ľڵ�
	a.print();
	if(a.find(2))	//��֤find����
		cout << "found!" << endl;
	if(a.full())	//��֤full����
		cout << "full!" << endl;
	if(a.empty())	//��֤empty����
		cout << "empty!" << endl;
	SET b(10);
	for(int i = 0; i < 6; i++)
		b << i;		//����Ԫ�أ���ʵ���ǳ�ʼ���������,Ϊ�����Ԫ��
	const SET c(b);	//���ÿ������캯��
	b = a + c;
	b.print();
	b = a - c;
	b.print();
	b = a * c;
	b.print();
	b += c;
	b.print();
	b -= c;
	b.print();
	b *= c;
	b.print();

	return 0;
}





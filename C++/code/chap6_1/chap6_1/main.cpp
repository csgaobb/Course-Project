#include <iostream>
#include <math.h>
using namespace std;

const double PI = 3.14159;

class LOCATION
{
public:
	int x,y;
	LOCATION(int x1,int y1):x(x1),y(y1) { }
	void move(int x,int y);		
};

void LOCATION::move(int x1,int y1) //�βν�����ʾ�ƶ����� 
{
	x += x1;
	y += y1;
}

class POINT:public LOCATION
{
public:
	POINT(int x1,int y1):LOCATION(x1,y1){ }
	void move(int x1,int y1) { 
		LOCATION::move(x1,y1);
		cout << "�ƶ��󣬵������Ϊ:x= " << this->x << " \t y= " << this->y<< endl; 
	}
	void draw(){	
		cout << "�ѻ���һ����!\t" << "����Ϊ:x= " 
			<< this->x << " \t y= " << this->y<< endl;
	}	
};

class CIRCLE:public LOCATION
{
	int radius;    //ԲҪ����Щ���а뾶 
public:
	CIRCLE(int x,int y,int radius):LOCATION(x,y){ CIRCLE::radius = radius; }
	void move(int x,int y){
		LOCATION::move(x,y);
		cout << "�ƶ���Բ�ĵ�����Ϊ:x= " << this->x << " \t y= " << this->y<< endl;
	}
	void draw();	
};

void CIRCLE::draw()
{
	cout << "�ѻ���һ��Բ!\t" <<"Բ������Ϊ:x = " 
		<< this->x <<" \ty = "<< this->y 
		<< " \t�뾶Ϊ��" << this->radius << endl;
}

void main()
{
	POINT a(4,9);
	a.draw();
	cout << "�ƶ�(1,2)����֮��........" << endl;
	a.move(1,2);
	a.draw();
	cout << endl;
	CIRCLE b(4,3,3);
	b.draw();
	cout << "�ƶ�(4,9)����֮��........" << endl;
	b.move(4,9);
	b.draw();
}
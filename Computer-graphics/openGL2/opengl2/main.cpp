/************************************************************************/
/*		KOCH���ߣ�C++/OpenGLʵ��(��ֱ��Ϊ��ʼͼ��)                      */
/*      ���ߣ�����              2009��11��3��                        ****/
/************************************************************************/
#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <math.h>
#define PI 3.1415926
using namespace std;

struct Point
{
	float x;
	float y;
};

static vector<Point> count;
static int m = 0; //��������
float line ;

void first_state(vector<Point> &count)	//��ʼ�����ֻ��������
{
	Point first = {-1.0f,0.0f},end = {1.0f,0.0f};
	line = sqrt( pow(first.x - end.x,2) + pow(first.y - end.y,2) );
	count.push_back(first);
	count.push_back(end);
}

void Draw_pic(vector<Point> &count)
{
	
	for (vector<Point>::size_type i = 0; i != (count.size()-1) ; i++)
	{
		glBegin(GL_LINES);	
			glVertex2f(count[i].x, count[i].y);
			glVertex2f(count[i+1].x, count[i+1].y);
		glEnd();
	}
	cout << count.size() << endl;

}
void Calculate_point(vector<Point> &count)
{
	vector<Point> new_count;
	float pline = line /(float) pow((float)3,(int)m) ;
	vector<Point>::size_type i;
	for ( i= 0; i != (count.size() - 1); i++ )
	{
		Point p1 , p2 , pmid;
		p1.x = count[i].x + (count[i+1].x - count[i].x) / 3;
		p1.y = count[i].y + (count[i+1].y - count[i].y) / 3;
		p2.x = count[i+1].x - (count[i+1].x - count[i].x) / 3;
		p2.y = count[i+1].y - (count[i+1].y - count[i].y) / 3;
		//mark  count[i+1].x < count[i].x����²�����
		double alpha = 0.0;
		if (count[i+1].y >= count[i].y)
		{
			alpha = atan((double) (count[i+1].y - count[i].y) / (count[i+1].x - count[i].x) );
			if (count[i+1].x > count[i].x)
			{	
				pmid.x = p1.x + pline * cos(alpha + PI / 3);
				pmid.y = p1.y + pline * sin(alpha + PI / 3);
			}
			else
			{
				pmid.x = p1.x - pline * cos(alpha + PI / 3);
				pmid.y = p1.y - pline * sin(alpha + PI / 3);
			}
		}
		else
		{
			alpha = atan((double) (count[i].y - count[i+1].y) / (count[i+1].x - count[i].x) );
			if (count[i+1].x > count[i].x)
			{
				pmid.x = p2.x - pline * cos(alpha + PI / 3);
				pmid.y = p2.y + pline * sin(alpha + PI / 3);
			}
			else
			{
				pmid.x = p2.x + pline * cos(alpha + PI / 3);
				pmid.y = p2.y - pline * sin(alpha + PI / 3);
			}
		}
		new_count.push_back(count[i]);
		new_count.push_back(p1);
		new_count.push_back(pmid);
		new_count.push_back(p2);
	}
	new_count.push_back(count[i]);
	count.clear();
	count = new_count; //֮ǰҪ���
}
void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	switch (m)
	{
		case 0:
			{
				Draw_pic(count);
			}
				break;
		case 1: 
			{
				Draw_pic(count);
			}
			break;
		case 2:
			{
				Draw_pic(count);
			}
			break;
		case 3:
			Draw_pic(count);
			break;
		case 4:
			Draw_pic(count);
			break;
		case 5:
			Draw_pic(count);
			break;
		case 6:
			Draw_pic(count);
			break;
		case 7:
			Draw_pic(count);
			break;
		case 8:
			Draw_pic(count);
			break;
		case 9:
			Draw_pic(count);
			break;
		case 10:
			Draw_pic(count);
			break;
		default:
			break;
	}
	glFlush();
}

void Keyboard(unsigned char key,int x,int y)   
{
	if (key == ' ')
	{
		++m;
		Calculate_point(count);
	}
	glutPostRedisplay();
}


int main(int argc, char *argv[])
{
	first_state(count);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("��һ��OpenGL����");
	glutDisplayFunc(&myDisplay);
	glutKeyboardFunc(Keyboard);     //������Ӧ�ص�����
	glutMainLoop();
	return 0;
}


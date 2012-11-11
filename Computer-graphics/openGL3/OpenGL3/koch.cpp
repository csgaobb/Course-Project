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

static vector<Point> count1,count2,count3;
const Point first = {-0.5f,0.1f},end = {0.5f,0.1f},second = {0.0f,-0.766f};
static int m = 0; //��������
float line ;

void first_state(vector<Point> &count1,vector<Point> &count2,vector<Point> &count3)	//��ʼ�����ֻ��������
{
	line = sqrt( pow(first.x - end.x,2) + pow(first.y - end.y,2) );
	count1.push_back(first);
	count1.push_back(end);
	count2.push_back(end);
	count2.push_back(second);
	count3.push_back(second);
	count3.push_back(first);
}

void Draw_pic(vector<Point> &count1)
{

	for (vector<Point>::size_type i = 0; i != (count1.size()-1) ; i++)
	{
		glBegin(GL_LINES);	
		glVertex2f(count1[i].x, count1[i].y);
		glVertex2f(count1[i+1].x, count1[i+1].y);
		glEnd();
	}
	for (vector<Point>::size_type i = 0; i != (count2.size()-1) ; i++)
	{
		glBegin(GL_LINES);	
		glVertex2f(count2[i].x, count2[i].y);
		glVertex2f(count2[i+1].x, count2[i+1].y);
		glEnd();
	}
	for (vector<Point>::size_type i = 0; i != (count3.size()-1) ; i++)
	{
		glBegin(GL_LINES);	
		glVertex2f(count3[i].x, count3[i].y);
		glVertex2f(count3[i+1].x, count3[i+1].y);
		glEnd();
	}

}
void Calculate_point(vector<Point> &count1)
{
	vector<Point> new_count;
	float pline = line /(float) pow((float)3,(int)m) ;
	vector<Point>::size_type i;
	for ( i= 0; i != (count1.size() - 1); i++ )
	{
		Point p1 , p2 , pmid;
		p1.x = count1[i].x + (count1[i+1].x - count1[i].x) / 3;
		p1.y = count1[i].y + (count1[i+1].y - count1[i].y) / 3;
		p2.x = count1[i+1].x - (count1[i+1].x - count1[i].x) / 3;
		p2.y = count1[i+1].y - (count1[i+1].y - count1[i].y) / 3;
		//mark  count[i+1].x < count[i].x����²�����
		double alpha = 0.0;
		if (count1[i+1].y >= count1[i].y)
		{
			alpha = atan((double) (count1[i+1].y - count1[i].y) / (count1[i+1].x - count1[i].x) );
			if (count1[i+1].x > count1[i].x)
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
			alpha = atan((double) (count1[i].y - count1[i+1].y) / (count1[i+1].x - count1[i].x) );
			if (count1[i+1].x > count1[i].x)
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
		new_count.push_back(count1[i]);
		new_count.push_back(p1);
		new_count.push_back(pmid);
		new_count.push_back(p2);
	}
	new_count.push_back(count1[i]);
	count1.clear();
	count1 = new_count; //֮ǰҪ���
	//for (i = 0; i != count1.size(); i++)
	//{
	//	Point temp;
	//	temp.x = new_count[i].x -first.x;
	//	temp.y = new_count[i].y - first.y;
	//	temp.x = temp.x * cos(PI/3) - temp.y * sin (PI/ 3);
	//	temp.y = temp.x * sin(PI/3) - temp.y * cos (PI/ 3);
	//	temp.x = temp.x + first.x;
	//	temp.y = temp.y + first.y;
	//	count2.clear();
	//	count2.push_back(temp);
	//}
}
void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	switch (m)
	{
	case 0:
		{
			Draw_pic(count1);
			Draw_pic(count2);
			Draw_pic(count3);
		}
		break;
	case 1: 
		{
			Draw_pic(count1);
			Draw_pic(count2);
			Draw_pic(count3);
		}
		break;
	case 2:
		{
			Draw_pic(count1);
			Draw_pic(count2);
			Draw_pic(count3);
		}
		break;
	case 3:
		{
			Draw_pic(count1);
			Draw_pic(count2);
			Draw_pic(count3);
		}
		
		break;
	case 4:
		{
			Draw_pic(count1);
			Draw_pic(count2);
			Draw_pic(count3);
		}
		break;
	case 5:
		{
			Draw_pic(count1);
			Draw_pic(count2);
			Draw_pic(count3);
		}
		break;
	case 6:
		{
			Draw_pic(count1);
			Draw_pic(count2);
			Draw_pic(count3);
		}
		
		break;
	case 7:
		{
			Draw_pic(count1);
			Draw_pic(count2);
			Draw_pic(count3);
		}
		break;
	case 8:
		{
			Draw_pic(count1);
			Draw_pic(count2);
			Draw_pic(count3);
		}
	
		break;
	case 9:
		{
			Draw_pic(count1);
			Draw_pic(count2);
			Draw_pic(count3);
		}
		
		break;
	case 10:
		{
			Draw_pic(count1);
			Draw_pic(count2);
			Draw_pic(count3);
		}
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
		Calculate_point(count1);
		Calculate_point(count2);
		Calculate_point(count3);
	}
	glutPostRedisplay();
}


int main(int argc, char *argv[])
{
	first_state(count1,count2,count3);
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


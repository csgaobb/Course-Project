#include "GaborFilter.h"
#include "BIF.h"
#pragma comment(lib,"TOOL.lib")

#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
using namespace std;

#define pi 3.1415926

#pragma  warning(disable:4305)
//function GaborFeatureAll  = bif2(ImgData,ImgSize,m_nScale)
//void bif2(double **ImgData,int dim1,int num1,double *ImgSize,int m_nScale,vector<vector<double> > outputGaborFeatureAll)
//mexFunction���ü򵥵İ汾(ImgData,ImgSize,Scale);
//DLL���÷�ʽ��outputGaborFeature = bif2(ImgData,ImgSize,m_nScale);


//DLL���÷�ʽ��outputGaborFeature = BIF::BifTransform(ImgData,ImgSize,m_nScale),���ж���һά�ġ�

void ReadFileDouble(char *s,double *ImgData)//��ȡ�ļ����ݣ���ΪҪ����ͼ������
{
	int i = 0;
	FILE *fp;
	char buf[1024];
	if( (fp = fopen(s,"r")) == NULL )
	{
		printf("ERROR! Open the file failed!\n");
		exit(0);
	}
	while(!feof(fp))
	{
		
		fgets(buf,1024,fp);
		double result =  atof(buf);
		ImgData[i++] = result;	
	}
	
// 	for(int k = 0; k < i-1; k++)
// 	{
// 		printf("%f\n",ImgData[k]);
// 	}
// 	printf("%d\n",i-1);
	fclose(fp);		
	
}

void WriteFileDouble(double *data, int size,char *s)//�������ɵ��ļ����ݣ���ΪҪ�������ɵ�����
{
	int i = 0;
	FILE *fp = fopen(s,"w");
	if(fp == NULL)
		fprintf(fp,"error!");
	while(i < size)
	{
		fprintf(fp,"%lf\n",data[i]);
		i++;
	}
	fclose(fp);
}


void BIF_32()
{
	int Width = 32;
	int Height = 32;
	int WidHei = Width * Height;
	int m_nScale = 16;
	double ImgSize[2] = {Width,Height};
	const int DIM = 10000;
	
	double *ImgData = new double [WidHei];
	int dim = WidHei;
	
	BIF mybif(ImgSize,m_nScale);
	int outputSize= 0;
	
	ReadFileDouble("data_32.txt",ImgData);		//����ߴ�Ϊ32ʱ���VC��ʽͼ������
	
	double *outputGabor = new double [DIM];
	mybif.BifTransform(ImgData,dim,outputGabor,outputSize);
	
	WriteFileDouble(outputGabor,outputSize,"RealResult_32.txt");//���������VC��ʽ������ͼ����
	
	double *RealGabor  = new double [outputSize];	
	mybif.DataConverse(outputGabor,RealGabor);
	
	WriteFileDouble(RealGabor,outputSize,"TransformResult_32.txt");//����ת�ú�MATLAB��ʽ������ͼ����
	
	delete []outputGabor;
	delete []RealGabor;
//	delete []ImgData;

}


void BIF_64()
{
	////�����Ƕ�64x64�ߴ�ʱ�����Ĳ��ԡ�
	int Width = 64;
	int Height = 64;
	int WidHei = Width * Height;
	int m_nScale = 16;
	double ImgSize[2] = {Width,Height};
	const int DIM = 10000;
	
	double *ImgData = new double [WidHei];
	int dim = WidHei;
	
	BIF mybif(ImgSize,m_nScale);
	int outputSize= 0;
	
	ReadFileDouble("data_64.txt",ImgData);		//����ߴ�Ϊ32ʱ���VC��ʽͼ������
	
	double *outputGabor = new double [DIM];
	mybif.BifTransform(ImgData,dim,outputGabor,outputSize);
	
	WriteFileDouble(outputGabor,outputSize,"RealResult_64.txt");//���������VC��ʽ������ͼ����
	
	double *RealGabor  = new double [outputSize];	
	mybif.DataConverse(outputGabor,RealGabor);
	
	WriteFileDouble(RealGabor,outputSize,"TransformResult_64.txt");//����ת�ú�MATLAB��ʽ������ͼ����
	
	delete []outputGabor;
	delete []RealGabor;
//	delete []ImgData;
}


int main()
{	
//	BIF_32();	//����β���û������!
	
	BIF_64();	//����β���Ҳû������!

	return 0;
}




























// BIF.h: interface for the BIF class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BIF_H__1EA4CCDD_FC46_4C43_8DA4_FE68785D00EB__INCLUDED_)
#define AFX_BIF_H__1EA4CCDD_FC46_4C43_8DA4_FE68785D00EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000





class BIF  
{
public:
	void DataConverse(double *inputGabor,double *outputGabor);
	int pos_buffer[8];
	int TempDim[8];
	int pos_num[8];//16���߶�Ҫ����8��ѭ��
	double * pos_all;

	static void segmentimage(double *ImgData,double *ImgSize,double *Pos,double *output_newImgData,int *output_pos);
//	static void imgblockindex(double *ImgSize,double *Pos,double *blockSize,double *gapSize,double *output_newImgData,int *output_pos,double *output_pos_all);
	static void imgblockindex(double *ImgSize,double *blockSize,double *gapSize,double *output_pos_all);
	int dim;			//ָʾһ��ͼƬ�ж��ٸ�Ԫ�أ�Ҳ��������(1024*94��)���������1024
	int newdim;
	double * InputImgData;//����ָ�룬ָ��ͼ��Ԫ��ָ�룬��Ϊһ����Ա��
	int numGabor;
	int HeiWid;
	int Height;
	int Width;
	const int SxSy;
	void BifTransform(double *ImgData, int ImgDataSize,double *outputGaborFeature,int &size);
	int Scale;
	int m_nOrientation;
	int kernelsize[2];
	BIF();
	BIF(double *ImgSize, int m_nScale);
	virtual ~BIF();

};

#endif // !defined(AFX_BIF_H__1EA4CCDD_FC46_4C43_8DA4_FE68785D00EB__INCLUDED_)

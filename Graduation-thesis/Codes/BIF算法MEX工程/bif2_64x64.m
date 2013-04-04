function GaborFeatureAll  = bif2(ImgData,ImgSize,m_nScale)
%��ͼ����ȡ����������Gabor����
% Input��
%       Img: ͼ������ݣ�Ϊ��hei��wid��num�������ݣ�ͼ�����ݵ����з�ʽҪ�������ȴ洢�ķ�ʽ
%       ImgSize�� ͼ��ĳߴ磬width = ImgSize(1);height = ImgSize(2);
%       sigma: �����й�ʽ2��sigma
%       kernelsize:
% Output:
%       GaborFeature����ȡ�������Gabor������Ϊ��hei��wid��40��1��������
% Notes:
%       �ο����ף�Laurenz Wiskott, Jean-Marc Fellous,Norbert Kruger, and Christoph von der Malsburg,
%               "Face Recognition by Elastic Bunch Graph Matching"
% * ��ǰ�汾��1.0
% * ��    �ߣ������
% * ������ڣ�2010��03��29��

%%����ע�ǣ�m_nOrientation = 8;�̶��˷��򣬶��߶����������趨Ϊ5��16
%%����ֻ�����ⶨ��һ��������GaborFeature_temp����ǰ����޹أ������clear���ˡ������޸ĵ�֮ǰ���ɵ�����

%%%�µ���⣺test.m�Ĺ��ܣ�
%%����ÿһ��ͼƬ(cross��1��num=94)��������һ��GaborExtraction_Scale16����ȡ����������reshapeΪ1024*
%%128�Ĵ�С�ͳߴ硣
%������mybif�����뺯�����ڷ��ֹ��ܣ������������Ĺ������ǣ�ÿһ��ͼƬ��ÿ�ζ��趨һ��filtersize��Ȼ������ȡ����
%����ÿ�ζ����뵽����У���󷵻ء�
%��bif2�㷨�������壩��ͬ��������ÿ��ͼƬ�����ڳߴ����ȡ������Ȼ��Ƚ����ֵ��Ȼ�������Ĵ������Ŵ�������
%�����������ɵ���1576*94�Ĵ�С�ͳߴ磬��ǰ��Ĳ�ͬ����Ϊ����ͬ����
%%%%���˵����mybif�����dll(mexGaborExtraction_Scale16)��������ͬ�ģ����ǽ�����ȡ�������ѡ�(���ڱȽϷ��־���)
%



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%�˴��������64x64ά�ȣ�Ϊ�ˣ����Ǹ�blocksize�����32x32����1��������ÿһ��ѭ����ԭ���Ļ����ϼ�1
%ԭ���Ǽ�2,���ڼ�3. gap = cross_scale + 3;% 64x64ʱ����Ҫ������blocksize�Ĵ�С��Ϊ���ټ�1



[dim, num] = size(ImgData);%%num��ʾͼ�����������dim��ʾ����32*32=1024(����������������)
if nargin<4 %nargin��ʾ��������ĸ���,��������������С��4��
    kernelsize = [32 32];
end
if nargin<3 %��������������С��3�����˾�û��ִ�У�
    sigma = 2;
    m_nScale = 5;
end
m_nOrientation = 8;
width = ImgSize(1);%%ImgSize��ָʾ��ͼ��Ĵ�С������32*32�����Էֱ���ȡ�����Ϳ�
height = ImgSize(2);
heiwid = height * width;
numGabor = m_nScale * m_nOrientation;%%Gabor�������ǳ߶Ⱥͷ���ĳ˻���������5*8����Ŀ��40����

SxSy = 32;
newdim = numGabor * dim;
% newImgData = zeros(newdim,num);

for cross_num = 1 : 1%num   %%�������ÿһ��ͼƬ�����д���num��ʾͼƬ����94�š�
    ImgData_temp = ImgData(:,cross_num );  %%�����ǲ���ÿһ�У�Ҳ����һ����ͼƬȡ��������Ϊ������ΪͼƬ����ÿһ�б�ʾһ��ͼƬ��
   
    for cross_scale = 1 : m_nScale/2 %%����Scale���κ���������֮��Ƚ������ֵ��ÿһ��Scale���д�����forѭ����һ��������ġ�
        filtersize = cross_scale *4+1;%%%%%����ע�⣺�������ú��ĵ�ʱ����ó߶�Ϊcross_scale��������VC���������Ϊ��̬�仯�ͳ����ˡ�//ps:����mybif˵�������̶�ʱ���ǿ��Ե�,������ͬ��
        [GaborReal,GaborConj]= KernelCreate1(filtersize,filtersize,cross_scale,m_nOrientation,2*pi,2*pi,0.7888*pi,sqrt(2));
        Gabor = GaborReal  + 1i * GaborConj;
        GaborFeature_odd  = GaborExtraction1(ImgData_temp, ImgSize, Gabor,filtersize,filtersize);%%GaborFeature_odd==8192*1(32*32*8)
        filtersize = cross_scale *4+3;
        [GaborReal,GaborConj]= KernelCreate1(filtersize,filtersize,cross_scale,m_nOrientation,2*pi,2*pi,0.7888*pi,sqrt(2));
        Gabor = GaborReal  + 1i * GaborConj;
        GaborFeature_even  = GaborExtraction1(ImgData_temp, ImgSize, Gabor,filtersize,filtersize);%%GaborFeature_even==8192*1
        GaborFeature = max(GaborFeature_even,GaborFeature_odd);%%GaborFeature=8192*1��max��ʾ������������ȡ����ÿһ���еĽϴ�ֵ���һ���µ����顣
   
        clear GaborFeature_even GaborFeature_odd GaborReal GaborConj;
    
        GaborFeature = reshape(GaborFeature,dim,size(GaborFeature,1)/dim);%%����8192*1�仯Ϊ1024*8�����´���size(X,1)�������
        %gap = cross_scale + 1;% ͬ�����е�gap��ʼ�㲻ͬ��
        %gap = cross_scale + 2;% ͬ�����е�gap��ʼ�㲻ͬ��
        gap = cross_scale + 3;% 64x64ʱ����Ҫ������blocksize�Ĵ�С��Ϊ���ټ�1
        sub_width = gap * 2;
        sub_height = sub_width;
        sub_heiwid = sub_height * sub_width;
        pos_all = imageblockindex(sub_width,sub_height, gap,width, height);%%��һ������imageblockindex��Ҫ�Լ�д
        dim_pos = length(pos_all);
        GaborFeature_temp = zeros(dim_pos/sub_width/sub_height, size(GaborFeature,2));
        for cross_block = 1 : dim_pos/sub_width/sub_height;
            index_begin = (cross_block - 1) * sub_heiwid +1;
            index_end = cross_block * sub_heiwid;
            index = pos_all(index_begin: index_end);%%�ڶ�������pos_all��Ҫ�Լ�д
            GaborFeature_temp(cross_block,:) = std(GaborFeature(index,:));    %%�˴����ǽ���std����,��ʾȡ����index����Ϊ������GaborFeature���У�    
        end
        clear index index_begin index_end pos_all;
        GaborFeature_temp = reshape(GaborFeature_temp, dim_pos/sub_width/sub_height *size(GaborFeature_temp,2),1);%���׶��ˣ��Ǵ��п�ʼ�ۻ��ġ����ȵ�һ�У�Ȼ��ڶ���������Ϊһ�У�
        
        if cross_num == 1 && cross_scale == 1;%��һ��ִ�е�ʱ������е�����ط����Ժ�Ͳ��ᡣ��Ϊ���߶��Ǳ仯�ģ����Ǵ�1��ʼ��(�϶���ִ��)
           newDim = length(GaborFeature_temp);%newDim = 648,m_nScale = 16
           GaborFeatureAll = zeros(newDim * m_nScale/4,num); %2592*94��ô���GaborFeatureAll
           index_end_GaborFeatureAll= 0;      
        end
        index_begin_GaborFeatureAll =  index_end_GaborFeatureAll + 1;
        index_end_GaborFeatureAll =  index_begin_GaborFeatureAll + dim_pos/sub_width/sub_height *size(GaborFeature,2)-1;
        GaborFeatureAll(index_begin_GaborFeatureAll:index_end_GaborFeatureAll, cross_num) = GaborFeature_temp;
        clear GaborFeature_temp GaborFeature;
    end  
    if cross_num == 1 
           GaborFeatureAll(index_end_GaborFeatureAll+1:end,:) = [] ; %��һ�δ�����ʼ��ʱ�����һ��ͼ���ʱ�򣩵�ʱ�򣬽������������ΪΪ0��������2592��������Ϊ1576��
    end
    index_end_GaborFeatureAll = 0;
    %     GaborFeature = GaborExtraction1(ImgData_temp, ImgSize, Gabor,5,5);
    %     GaborFeature = reshape(GaborFeature, dim, numGabor);
    %     GaborFeature_even = GaborFeature(:,1:2:end);
    %     GaborFeature_odd = GaborFeature(:,2:2:end);
end
return;

function  pos_all = imageblockindex(sub_width,sub_height, gap,width, height)
sub_heiwid = sub_height * sub_width;
index = 0 ;ImgSize = [height width] ;
ImgData = zeros(width*height,1);
pos_all = zeros(sub_width*sub_height*height/gap*width/gap,1);
for cross_x = 1:gap:width-sub_width+1
    for cross_y = 1: gap : height-sub_height+1
        index= index +1;
        Pos = [cross_x cross_y sub_height sub_width] ; % ÿ��ѭ���ж���cross_x,cross_y�б仯����sub_height,sub_width���䡣���Ե���segmentimag��ͬ��
        [newImgData, pos] = segmentimage(ImgData,ImgSize,Pos); %ÿһ��ѭ���ж�Ҫ���õ�segmentimage��������ÿ�εĲ���Pos���Ǳ仯�ġ�
        index_begin = (index - 1) * sub_heiwid +1;
        index_end = index * sub_heiwid;
        pos_all(index_begin:index_end)  = pos ;
    end
end
dim_pos = index_end;
pos_all(dim_pos+1:end)= [] ;
clear index_begin  index_end pos newImgData index;
return;

function GaborFeature  = GaborExtraction1(Img,ImgSize,gaborK,KernelWidth,KernelHeight)
%��ͼ����ȡ��Gabor���� ��
% Input��
%       Img: ͼ������ݣ�Ϊ��hei��wid��1�������ݣ�ͼ�����ݵ����з�ʽҪ�������ȴ洢�ķ�ʽ
%       ImgSize�� ͼ��ĳߴ磬width = ImgSize(2);height = ImgSize(1);
%       gaborK: gabor��,��numGabor��dim��
% Output:
%       GaborFeature����ȡ�������Gabor������Ϊ��hei��wid��40��1��������

%Notes:
%       40��Gabor���˲�����˳�����ȷ����߶�.

% * ��ǰ�汾��1.0
% * ��    �ߣ������
% * ������ڣ�2009��12��21��

width = ImgSize(1);
height = ImgSize(2);
heiwid = height * width;
numGabor = size(gaborK,2); %�õ������е�ֵ�����е�ֵ�أ�25*8�õ�����8(�ڶ�������)
Img = reshape(Img, height, width);
GaborFeature = zeros(heiwid*numGabor,1);
for k = 1 : numGabor
    idx = heiwid*(k-1);
    eachK = reshape(gaborK(:,k), KernelHeight, KernelWidth); %ѡ��ÿһ�У�numbGabor��������ÿһ�е����ݽ���reshapeΪ���ĵĸߺͿ�
    GaborFeature_temp = gaborwavelets(Img, eachK);%%����ֵΪ32*32
    GaborFeature(idx+1 : idx+heiwid, 1) = reshape(GaborFeature_temp,heiwid,1); %%�ѵõ���ÿһ��32*32չ��Ϊһά��1024����Ȼ���ڸ�ֵΪһά��GaborFeature�С�
end
return;

%%imgΪ32*32��GΪ5*5
function Gaborout  = gaborwavelets(img, G)
% ����gaborwaveletskernelcreat�����ľ���˼���ͼ���GaborС��
% Input:
%       img: ͼ�����ݣ�Ϊ[width, height]�ľ���
%       G: gaborwaveletskernelcreat�����ľ����
% Output:
%
% Notes:
%       �ο����ף�Laurenz Wiskott, Jean-Marc Fellous,Norbert Kruger, and Christoph von der Malsburg,
%               "Face Recognition by Elastic Bunch Graph Matching"
% * ��ǰ�汾��1.0
% * ��    �ߣ������
% * ������ڣ�2009��12��21��

if isa(img,'double')~=1
    img = im2double(img);
end
%%Imgabout,Regabout,Gaborout����32*32
Imgabout = conv2(img,double(imag(G)), 'same');
Regabout = conv2(img,double(real(G)), 'same');
% Imgabout = conv2(img,double(imag(G)), 'full');
% Regabout = conv2(img,double(real(G)), 'full');
Gaborout = sqrt(Imgabout.*Imgabout + Regabout.*Regabout);
return;

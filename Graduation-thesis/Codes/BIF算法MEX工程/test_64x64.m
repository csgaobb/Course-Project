%���ļ����ڲ���64x64�ߴ��ͼ���VC��MATLAB����ľ��ȡ�
%
%
%
height = 64;
width = 64;
heiwid = 64 * 64;
index = zeros(1, heiwid);
ImgSize = [64,64];

for cross_h = 1: height
    for cross_w =  1 : width
        index((cross_w-1)*height + cross_h) = (cross_h-1)* width +  cross_w;
    end
end
% num = size(ImgData,2);
for cross =5 :5%num
      ImgData_temp = ImgData(:,cross );
      GaborFeature_bif  = bif2_64x64(ImgData_temp,ImgSize,16);
    ImgData_temp(index) = ImgData_temp;%MATLAB����ת��VC�����ݣ���Ϊ֮ǰ�����ImgData��MATLAB�ġ�����
    %c1= b1(index,:);%����MATLAB��VC����ͼ��ı�ʾ��ͬ��һ��������һ������������֮ǰ��Ҫת���¡�   
    %%mexGaborExtractionΪScaleΪ16���������Ϊ������õ�reshape���Ǳ�Ϊ1024*128=131072
    %%ע�⣬���������������һά�ģ������洦���ʱ���������ά�ģ�������dll����֮��Ҫ������MATLAB���ı�����
    tic;
    GaborFeature_temp1 = BIF_Scale16_neat(ImgData_temp,ImgSize,16);%�˴����õ���dll�ļ�������16*8�ķ���߶�
    %GaborFeature_temp  = BIF_Scale16(ImgData_temp,ImgSize,16);
    toc;
   %GaborFeature_temp = reshape(GaborFeature_temp, heiwid, 128);%16*8����(��Ϊ1024*128)
   % GaborFeature_temp = GaborFeature_temp (index,:);%1024*128

end
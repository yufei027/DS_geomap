
#include "CGeoPoint.h"
///-----����ͼ��ģʽ��-----
#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
///----------------------

///  ---C++��ȡ�ļ�ͷ�ļ�------
#include <iostream>
#include <fstream>
#include <sstream>

///---C���Զ�ȡ�ļ�ͷ�ļ�----
#include <stdio.h>
#include <errno.h>
using namespace std;

#define isTextMode  0
#define WIDTH 600
#define HEIGHT 800

#define Fx(x) (x - 72.0 ) / (136.0 -72.0 ) *  WIDTH
#define Fy(y) HEIGHT - (y - 4.0 ) / (54.0 -4.0 ) *  HEIGHT

void main()
{
	CGeoPoint pts[350];
	int size=0;
	if( !isTextMode )
	{
		initgraph(HEIGHT, WIDTH);	// ������ͼ���ڣ���СΪ HEIGHT x WIDTH ����
		setcolor(RGB(255, 0, 0));
	}
	/////////// ------ C++���ȡ�ļ� ---------------
	/*
	ifstream file("D:\\ʵϰ����\\chnCities.txt",ios_base::in);  //�����ļ��������ļ���д
	if (  !file.is_open() ) {    //�ļ���ʧ�ܣ������Ϣ���˳�
		std::cerr << "�ļ���ʧ�ܣ�" << std::endl;
		return;
	}
	std::string line;  //������ʱ��ȡ����

	while ( std::getline(file, line) ) {    //��ȡ���ݲ�Ϊ�գ���ɺ�������
		//std::cout << line << std::endl;
		istringstream istrStream(line);    //�����ַ������������Դ��ַ����ж�ȡ����
		istrStream >> pts[size].id >> pts[size].x >> pts[size].y >> pts[size].chnName;
		
		Sleep(20);
		if (isTextMode)
			std::cout << "C++  id=" << pts[size].id << "   x=" << pts[size].x << "  y=" << pts[size].y << "   chnName=" << pts[size].chnName << std::endl;
		else
			circle(Fx(pts[size].x), Fy(pts[size].y), 2);
		size++;
		//std::cout << line << std::endl;
	}
	file.close(); //�ļ����ر�
	//*/

	////////// ----------  C���Զ��ļ���  ---------------
	///*
	FILE* fp;   //�����ļ�ָ��
	errno_t err;
	err = fopen_s(&fp, "D:\\ʵϰ����\\chnCities.txt", "r");  //���ļ����ļ�����·����"r"-�򿪷�ʽ��ֻ��
	if (err) { //�ж��Ƿ�������������˳�
		printf("�ļ���ʧ�ܣ�");
		return;  //����ֵΪ��
	}

	while ( !feof(fp) )   //�ж��ļ���ȡ�Ƿ����
	{
		fscanf_s(fp, "%d", &pts[size].id);  //�����ȡ��
		fscanf_s(fp, "%lf", &pts[size].x);
		fscanf_s(fp, "%lf", &pts[size].y);
		fscanf_s(fp, "%s",pts[size].chnName, 40);   //�ַ�������Ҫȡ��ַ������
		//std::cout << "C   id=" << pts[size].id << "   x=" << pts[size].x << "  y=" << pts[size].y << "   chnName=" << pts[size].chnName << std::endl;
		Sleep(20);
		if (isTextMode)
			std::cout << "C  id=" << pts[size].id << "   x=" << pts[size].x << "  y=" << pts[size].y << "   chnName=" << pts[size].chnName << std::endl;
		else
			circle(Fx(pts[size].x), Fy(pts[size].y), 2);
		size++;
	}
	fclose(fp); //�ر��ļ�

	//*/
	
	if (!isTextMode)
	{
		_getch();				// �����������
		closegraph();			// �رջ�ͼ����
	}
}
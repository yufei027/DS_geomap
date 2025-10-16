
#include "CGeoPoint.h"
///-----引入图形模式库-----
#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
///----------------------

///  ---C++读取文件头文件------
#include <iostream>
#include <fstream>
#include <sstream>

///---C语言读取文件头文件----
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
		initgraph(HEIGHT, WIDTH);	// 创建绘图窗口，大小为 HEIGHT x WIDTH 像素
		setcolor(RGB(255, 0, 0));
	}
	/////////// ------ C++版读取文件 ---------------
	/*
	ifstream file("D:\\实习数据\\chnCities.txt",ios_base::in);  //创建文件流，打开文件读写
	if (  !file.is_open() ) {    //文件打开失败，输出信息并退出
		std::cerr << "文件打开失败！" << std::endl;
		return;
	}
	std::string line;  //构建临时存取对象

	while ( std::getline(file, line) ) {    //读取数据不为空，完成后续处理
		//std::cout << line << std::endl;
		istringstream istrStream(line);    //构建字符串数据流，以从字符串中读取数据
		istrStream >> pts[size].id >> pts[size].x >> pts[size].y >> pts[size].chnName;
		
		Sleep(20);
		if (isTextMode)
			std::cout << "C++  id=" << pts[size].id << "   x=" << pts[size].x << "  y=" << pts[size].y << "   chnName=" << pts[size].chnName << std::endl;
		else
			circle(Fx(pts[size].x), Fy(pts[size].y), 2);
		size++;
		//std::cout << line << std::endl;
	}
	file.close(); //文件流关闭
	//*/

	////////// ----------  C语言读文件版  ---------------
	///*
	FILE* fp;   //定义文件指针
	errno_t err;
	err = fopen_s(&fp, "D:\\实习数据\\chnCities.txt", "r");  //打开文件，文件名带路径，"r"-打开方式，只读
	if (err) { //判断是否打开正常，否则退出
		printf("文件打开失败！");
		return;  //返回值为空
	}

	while ( !feof(fp) )   //判断文件读取是否到最后
	{
		fscanf_s(fp, "%d", &pts[size].id);  //逐个读取数
		fscanf_s(fp, "%lf", &pts[size].x);
		fscanf_s(fp, "%lf", &pts[size].y);
		fscanf_s(fp, "%s",pts[size].chnName, 40);   //字符串不需要取地址！！！
		//std::cout << "C   id=" << pts[size].id << "   x=" << pts[size].x << "  y=" << pts[size].y << "   chnName=" << pts[size].chnName << std::endl;
		Sleep(20);
		if (isTextMode)
			std::cout << "C  id=" << pts[size].id << "   x=" << pts[size].x << "  y=" << pts[size].y << "   chnName=" << pts[size].chnName << std::endl;
		else
			circle(Fx(pts[size].x), Fy(pts[size].y), 2);
		size++;
	}
	fclose(fp); //关闭文件

	//*/
	
	if (!isTextMode)
	{
		_getch();				// 按任意键继续
		closegraph();			// 关闭绘图窗口
	}
}
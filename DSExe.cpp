#include <iostream>
#include <fstream>
#include <sstream>
#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include "CGeoLayer.h"
#include "CGeoPoint.h"

using namespace std;


int main()
{
	int size = 350;
	CGeoLayer layer;

	layer.ReadData("E:\\GIS实习\\实习数据\\chnCities.txt");
	// layer.Search();
	layer.PrintLayer();
	layer.DrawLayer();

}
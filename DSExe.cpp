#include <iostream>
#include <fstream>
#include <sstream>
#include <graphics.h>
#include <conio.h>
#include "CGeoLayer.h"
#include "CGeoPoint.h"
#include "CWebMercator.h"
using namespace std;




int main()
{
	CGeoLayer layer;
	CWebMercator mercator;
	CViewPort view;

	string chinaBoundaryL = "E:\\GIS实习\\实习数据\\数据结构\\chinaBoundaryL.mif";
	string chnCities = "E:\\GIS实习\\实习数据\\数据结构\\chnCities.txt";

	layer.ReadData(chnCities);
	// TODO:这个mercator是不是不用传入实例，应该是传入一个类别，选用不同的投影方法，如果没有就默认。
	layer.DrawLayer(&view, &mercator);

	
	layer.PrintLayer();


	return 0;
}

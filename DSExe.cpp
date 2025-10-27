#include <iostream>
#include <fstream>
#include <sstream>
#include <graphics.h>
#include <conio.h>
#include "CGeoLayer.h"
#include "CGeoPoint.h"
#include "CProjMercator.h"
using namespace std;




int main()
{
	CGeoLayer layer;
	CProjMercator mercator;
	CViewPort view;

	string chinaBoundaryL = "E:\\GIS实习\\实习数据\\chinaBoundaryL.mif";
	string chnCities = "E:\\GIS实习\\实习数据\\chnCities.txt";

	layer.ReadData(chinaBoundaryL);
	layer.DrawLayer(&view, &mercator);

	// layer.Search();
	layer.PrintLayer();


	return 0;
}
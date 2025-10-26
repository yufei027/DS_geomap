#include <iostream>
#include <fstream>
#include <sstream>
#include <graphics.h>
#include <conio.h>
#include "CGeoLayer.h"
#include "CGeoPoint.h"
using namespace std;




int main()
{
	CGeoLayer layer;

	string chinaBoundaryL = "E:\\GIS实习\\实习数据\\chinaBoundaryL.mif";
	string chnCities = "E:\\GIS实习\\实习数据\\chnCities.txt";

	layer.ReadData(chinaBoundaryL);
	layer.DrawLayer();

	// layer.Search();
	layer.PrintLayer();

}
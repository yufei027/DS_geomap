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

	string chinaBoundaryL = "E:\\GISʵϰ\\ʵϰ����\\chinaBoundaryL.mif";
	string chnCities = "E:\\GISʵϰ\\ʵϰ����\\chnCities.txt";

	layer.ReadData(chinaBoundaryL);
	layer.DrawLayer();

	// layer.Search();
	layer.PrintLayer();

}
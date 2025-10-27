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

	string chinaBoundaryL = "E:\\GISʵϰ\\ʵϰ����\\chinaBoundaryL.mif";
	string chnCities = "E:\\GISʵϰ\\ʵϰ����\\chnCities.txt";

	layer.ReadData(chinaBoundaryL);
	layer.DrawLayer(&view, &mercator);

	// layer.Search();
	layer.PrintLayer();


	return 0;
}
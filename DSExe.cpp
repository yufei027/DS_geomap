#include <iostream>
#include <fstream>
#include <sstream>
#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include "CGeoLayer.h"
#include "CGeoPoint.h"

using namespace std;


int main()
{
	int size = 350;
	CGeoLayer layer;

	layer.ReadData("E:\\GISʵϰ\\ʵϰ����\\chnCities.txt");
	// layer.Search();
	layer.PrintLayer();
	layer.DrawLayer();

}
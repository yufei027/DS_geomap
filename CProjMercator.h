#pragma once
#include "CMapProj.h"
class CProjMercator : public CMapProj
{
public:

	double R;      // 地球半径
	double lon0;   // 中心经线（单位：度）

	CProjMercator(double radius = 6378137.0, double centralLon = 0.0)
		: R(radius), lon0(centralLon) {}
	~CProjMercator();

	CPoint1 Project(double lon, double lat) const override;


};


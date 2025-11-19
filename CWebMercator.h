#pragma once
#include "CMapProj.h"
class CWebMercator : public CMapProj
{
public:

	const double R = 6378137.0;      // 地球半径
	const double lon0 = 0;   // 中心经线（单位：度）


	CPoint1 Project(double lon, double lat) const override;
};


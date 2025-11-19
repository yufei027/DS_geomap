#pragma once
#include "CPoint1.h"
#include <cmath>
class CMapProj {
public:

	virtual CPoint1 Project(double lon, double lat) const = 0;

	CMapProj();
	virtual ~CMapProj();
};

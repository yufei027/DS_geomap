
#define _USE_MATH_DEFINES
#include <cmath>
#include "CProjMercator.h"
CPoint1 CProjMercator::Project(double lon, double lat) const
{
    double radLon = lon * M_PI / 180.0;
    double radLat = lat * M_PI / 180.0;
    double x = R * (radLon - lon0 * M_PI / 180.0);
    double y = R * std::log(std::tan(M_PI / 4.0 + radLat / 2.0));
	return CPoint1(x, y);
}

CProjMercator::~CProjMercator()
{
}

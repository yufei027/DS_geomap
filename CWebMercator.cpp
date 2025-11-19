#define _USE_MATH_DEFINES
#include <cmath>
#include "CWebMercator.h"
CPoint1 CWebMercator::Project(double lon, double lat) const
{
    // 限制纬度范围，避免 tan() 无穷大
    if (lat > 85.05112878) lat = 85.05112878;
    if (lat < -85.05112878) lat = -85.05112878;

    double radLon = (lon - lon0) * M_PI / 180.0;
    double radLat = lat * M_PI / 180.0;

    double x = R * radLon;
    double y = R * std::log(std::tan(M_PI / 4.0 + radLat / 2.0));
	return CPoint1(x, y);
}

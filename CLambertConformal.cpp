#define _USE_MATH_DEFINES
#include <cmath>
#include "CLambertConformal.h"

CLambertConformal::CLambertConformal(double centerLon, double standardLat1, 
	double standardLat2, double originLat)
	: lon0(centerLon), lat1(standardLat1), lat2(standardLat2), lat0(originLat)
{
	double radLat1 = lat1 * M_PI / 180.0;
	double radLat2 = lat2 * M_PI / 180.0;
	double radLat0 = lat0 * M_PI / 180.0;

	// 计算圆锥常数 n
	if (fabs(lat1 - lat2) < 1e-10) {
		// 如果两个标准纬线相同，使用单标准纬线公式
		n = sin(radLat1);
	} else {
		// 双标准纬线公式
		double m1 = cos(radLat1) / sqrt(1 - e2 * sin(radLat1) * sin(radLat1));
		double m2 = cos(radLat2) / sqrt(1 - e2 * sin(radLat2) * sin(radLat2));
		
		double t1 = tan(M_PI / 4.0 - radLat1 / 2.0) / 
			pow((1 - e * sin(radLat1)) / (1 + e * sin(radLat1)), e / 2.0);
		double t2 = tan(M_PI / 4.0 - radLat2 / 2.0) / 
			pow((1 - e * sin(radLat2)) / (1 + e * sin(radLat2)), e / 2.0);
		
		n = (log(m1) - log(m2)) / (log(t1) - log(t2));
	}

	// 计算比例因子 F
	double t0 = tan(M_PI / 4.0 - radLat0 / 2.0) / 
		pow((1 - e * sin(radLat0)) / (1 + e * sin(radLat0)), e / 2.0);
	double m0 = cos(radLat0) / sqrt(1 - e2 * sin(radLat0) * sin(radLat0));
	F = m0 / (n * pow(t0, n));

	// 计算原点处的投影半径
	rho0 = R * F * pow(t0, n);
}

CPoint1 CLambertConformal::Project(double lon, double lat) const
{
	double radLon = (lon - lon0) * M_PI / 180.0;
	double radLat = lat * M_PI / 180.0;

	// 计算 t（等量纬度）
	double t = tan(M_PI / 4.0 - radLat / 2.0) / 
		pow((1 - e * sin(radLat)) / (1 + e * sin(radLat)), e / 2.0);

	// 计算投影半径
	double rho = R * F * pow(t, n);

	// 计算坐标
	double theta = n * radLon;
	double x = rho * sin(theta);
	double y = rho0 - rho * cos(theta);

	return CPoint1(x, y);
}
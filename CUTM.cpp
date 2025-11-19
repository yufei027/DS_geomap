#define _USE_MATH_DEFINES
#include <cmath>
#include "CUTM.h"

CUTM::CUTM(int zone, double centralMeridian, double originLat)
	: lat0(originLat)
{
	// 如果指定了带号，计算对应的中央经线
	if (zone > 0 && zone <= 60) {
		lon0 = -180.0 + (zone - 1) * 6.0 + 3.0;  // UTM带号对应的中央经线
	} else {
		lon0 = centralMeridian;
	}

	// 预计算辅助常数
	e1 = (1 - sqrt(1 - e2)) / (1 + sqrt(1 - e2));
	e2_e4 = e2 * (1.0 / 3.0 + 31.0 * e2 / 180.0);
	e3 = 3.0 * e2 / 8.0 + 3.0 * e2 * e2 / 32.0;
	e4 = 15.0 * e2 * e2 / 256.0;

	// 计算基准纬度处的子午线弧长
	M0 = CalculateM0(lat0);
}

double CUTM::CalculateM0(double lat) const
{
	return CalculateM(lat);
}

double CUTM::CalculateM(double lat) const
{
	double radLat = lat * M_PI / 180.0;
	
	double m = R * ((1 - e2 / 4.0 - 3.0 * e2 * e2 / 64.0 - 5.0 * e2 * e2 * e2 / 256.0) * radLat
		- (3.0 * e2 / 8.0 + 3.0 * e2 * e2 / 32.0 + 45.0 * e2 * e2 * e2 / 1024.0) * sin(2.0 * radLat)
		+ (15.0 * e2 * e2 / 256.0 + 45.0 * e2 * e2 * e2 / 1024.0) * sin(4.0 * radLat)
		- (35.0 * e2 * e2 * e2 / 3072.0) * sin(6.0 * radLat));
	
	return m;
}

CPoint1 CUTM::Project(double lon, double lat) const
{
	double radLon = (lon - lon0) * M_PI / 180.0;
	double radLat = lat * M_PI / 180.0;

	// 计算辅助量
	double N = R / sqrt(1 - e2 * sin(radLat) * sin(radLat));  // 卯酉圈半径
	double T = tan(radLat) * tan(radLat);
	double C = e2 / (1 - e2) * cos(radLat) * cos(radLat);
	double A = cos(radLat) * radLon;

	// 计算子午线弧长
	double M = CalculateM(lat);

	// 计算投影坐标
	double x = k0 * N * (A + (1 - T + C) * A * A * A / 6.0
		+ (5 - 18 * T + T * T + 72 * C - 58) * A * A * A * A * A / 120.0);

	double y = k0 * (M - M0 + N * tan(radLat) * (A * A / 2.0
		+ (5 - T + 9 * C + 4 * C * C) * A * A * A * A / 24.0
		+ (61 - 58 * T + T * T + 600 * C - 330) * A * A * A * A * A * A / 720.0));

	return CPoint1(x, y);
}

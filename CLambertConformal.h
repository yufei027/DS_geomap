#pragma once
#include "CMapProj.h"

// 兰勃特等角圆锥投影（Lambert Conformal Conic）
// 适合中纬度地区，常用于美国、中国等地区的地图
// 特点：等角投影，形状保持良好，适合东西向延伸的地区
class CLambertConformal : public CMapProj
{
public:
	const double R = 6378137.0;      // 地球半径（米，WGS84椭球）
	const double e = 0.08181919;     // 第一偏心率（WGS84）
	const double e2 = 0.00669438;    // 第一偏心率平方（WGS84）
	
	double lon0;                     // 中心经线（度）
	double lat1;                     // 第一标准纬线（度）
	double lat2;                     // 第二标准纬线（度）
	double lat0;                     // 投影原点纬度（度）

	// 计算出的参数
	double n;                        // 圆锥常数
	double F;                        // 比例因子
	double rho0;                     // 原点处的投影半径

	// 构造函数，设置标准纬线和中心参数
	// 默认参数适合中国地区：中心经线105度，标准纬线25度和47度
	CLambertConformal(double centerLon = 105.0, double standardLat1 = 25.0, 
		double standardLat2 = 47.0, double originLat = 35.0);

	CPoint1 Project(double lon, double lat) const override;
};
#pragma once
#include "CMapProj.h"

// 横轴墨卡托投影（UTM - Universal Transverse Mercator）
// 适用于南北向延伸的地区，常用于大比例尺地图
// UTM将地球分为60个投影带，每个带6度经度
class CUTM : public CMapProj
{
public:
	const double R = 6378137.0;      // 地球半径（米，WGS84椭球）
	const double k0 = 0.9996;        // 中央经线比例因子（UTM标准）
	const double e2 = 0.00669438;    // 第一偏心率平方（WGS84）
	const double e = 0.08181919;     // 第一偏心率（WGS84）
	
	double lon0;                     // 中央经线（度）
	double lat0;                     // 基准纬度（度，通常为0）

	// 预计算的常数
	double M0;                       // 基准纬度处的子午线弧长
	double e1, e2_e4, e3, e4;        // 辅助常数

	// 构造函数
	// zone: UTM带号（1-60），或者直接指定中央经线
	// 如果zone为0，则使用指定的centralMeridian作为中央经线
	CUTM(int zone = 0, double centralMeridian = 0.0, double originLat = 0.0);

	CPoint1 Project(double lon, double lat) const override;
	
private:
	// 计算基准纬度处的子午线弧长
	double CalculateM0(double lat) const;
	
	// 计算子午线弧长
	double CalculateM(double lat) const;
};

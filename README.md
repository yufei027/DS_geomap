# Simple GISData Structure Visualization 



---

## 项目简介

一个基于 C++ 的 GIS 数据结构和可视化小工具，使用EasyX图形库。支持地理数据的存取、查询、排序和可视化。

### 数据管理
- **多格式数据读取**：支持 `.txt` 和 `.mif` 格式的地理数据文件
- **地理要素支持**：点（Point）和折线（Polyline）两种基础地理要素类型
- **数据组织**：链表、二叉树、数组等多种数据结构存储方案

### 地图投影
- **Web Mercator 投影**：支持 Web 地图常用的墨卡托投影
- **兰勃特等角圆锥投影（Lambert Conformal Conic）**：适合中纬度地区，等角投影，形状保持良好
- **横轴墨卡托投影（UTM）**：适用于南北向延伸的地区，常用于大比例尺地图
- **坐标转换**：地理坐标与投影坐标之间的无缝转换

---

## 项目结构

```
DS_geomap/
│
├── 核心类文件
│   ├── CGeoLayer.h/cpp          # 地理图层管理类
│   ├── CGeoObject.h/cpp          # 地理对象基类
│   ├── CGeoPoint.h/cpp           # 点要素类
│   ├── CGeoPolyline.h/cpp        # 折线要素类
│   ├── CPoint1.h/cpp             # 点坐标类
│   │
├── 投影与视图
│   ├── CMapProj.h/cpp            # 地图投影基类
│   ├── CWebMercator.h/cpp        # Web 墨卡托投影实现
│   ├── CLambertConformal.h/cpp   # 兰勃特等角圆锥投影实现
│   ├── CUTM.h/cpp                # 横轴墨卡托投影（UTM）实现
│   ├── CViewPort.h/cpp           # 视口管理类
│   │
├── 数据结构
│   └── GeoLinkedList.h           # 链表和二叉树节点模板
│
├── 主程序
│   └── DSExe.cpp                 # 程序入口
│
└── 项目文件
    ├── DS_geomap.vcxproj          # Visual Studio 项目文件
    ├── DS_geomap.vcxproj.filters  # 项目过滤器文件
    ├── DS_geomap.sln              # Visual Studio 解决方案文件
    └── README.md                  # 项目说明文档
```

### 核心类说明

| 类名 | 功能描述 |
|------|---------|
| `CGeoLayer` | 地理图层管理，负责数据读取、存储、查询和可视化 |
| `CGeoObject` | 地理对象抽象基类，定义地理要素的通用接口 |
| `CGeoPoint` | 点要素类，表示地理空间中的点对象 |
| `CGeoPolyline` | 折线要素类，表示由多个点组成的折线对象 |
| `CMapProj` | 地图投影抽象基类，定义投影转换接口 |
| `CWebMercator` | Web 墨卡托投影实现类，适用于全球范围的Web地图 |
| `CLambertConformal` | 兰勃特等角圆锥投影实现类，适合中纬度地区（默认参数适合中国） |
| `CUTM` | 横轴墨卡托投影（UTM）实现类，支持UTM带号或自定义中央经线 |
| `CViewPort` | 视口管理类，处理坐标转换和图形渲染 |


### 安装步骤

1. **克隆项目**
   ```bash
   git clone <repository-url>
   cd DS_geomap
   ```

2. **安装 EasyX 图形库**
   - 访问 [EasyX 官网](https://easyx.cn/) 下载安装包
   - 运行安装程序，选择对应的 Visual Studio 版本
   - 确保 EasyX 已正确安装到 Visual Studio 中

3. **打开项目**
   - 使用 Visual Studio 打开 `DS_geomap.sln` 解决方案文件
   - 或直接打开 `DS_geomap.vcxproj` 项目文件

### 数据文件格式

#### 文本格式 (.txt)
每行包含一个点的信息，格式为：
```
ID X坐标 Y坐标 名称
```

示例：
```
1 116.3974 39.9093 北京
2 121.4737 31.2304 上海
```

#### MIF 格式 (.mif)
支持 MapInfo Interchange Format 标准格式，包含折线（Pline）数据。

---

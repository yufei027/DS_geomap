#pragma once
#include <algorithm>
#include <graphics.h>  // EasyX ͼ�κ���
#include <conio.h>     // _getch() ����
class CViewPort
{
protected:
    double xmin = DBL_MAX, xmax = -DBL_MAX, ymin = DBL_MAX, ymax = -DBL_MAX;
    int width = 800, height = 600;

public:
	int lineColor = RGB(255, 0, 0);

    // ͶӰ���� -> ��Ļ����
    int Fx(double x) const {
        return static_cast<int>((x - xmin) / (xmax - xmin) * width);
    }
    int Fy(double y) const {
        return static_cast<int>(height - (y - ymin) / (ymax - ymin) * height);
    }

    void UpdExtent(double x, double y) {
        xmin = std::min<double>(xmin, x);
        xmax = std::max<double>(xmax, x);
        ymin = std::min<double>(ymin, y);
        ymax = std::max<double>(ymax, y);
    }

    // =================== ��װ��ͼ���� ===================
    void BeginDraw(int lineColor) {
        initgraph(width, height);
        setcolor(lineColor);
    }

    void EndDraw() {
        _getch();
        closegraph();
    }
};


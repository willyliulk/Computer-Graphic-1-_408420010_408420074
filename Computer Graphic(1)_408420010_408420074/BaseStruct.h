#pragma once
#include "framework.h"

class MyPoint
{
public:
	CPoint point;
	COLORREF color;
	int Tpye;
	MyPoint()
	{
		color = RGB(0, 0, 255);
		point = (0, 0);
		Tpye = 0; //系統點總類 0:點 1:圓點
	}
};


class MyLine
{
public:
	CPoint StartPnt, EndPnt, Prepoint;
	COLORREF color;
	int LineWidth;
	MyLine()
	{
		color = RGB(255, 0, 0);
		StartPnt = (0, 0);
		LineWidth = 3;
	}
	void draw(CDC &dc, COLORREF Lcolor, COLORREF fcolor, int Lwidth, BOOL Filled = false)
	{
		CPen pen(PS_SOLID, Lwidth, Lcolor);//建立畫筆物件
		CPen *oldPen = dc.SelectObject(&pen);//設定DC物件使用pen物件
		dc.MoveTo(StartPnt);//移至直線起點
		dc.LineTo(EndPnt);//移至直線終點
		dc.SelectObject(oldPen);//還原選取的畫筆物件
	}
	void draw2(CDC &dc)
	{
		CPen pen(PS_SOLID, LineWidth, color);//建立畫筆物件
		CPen *oldPen = dc.SelectObject(&pen);//設定DC物件使用pen物件
		dc.MoveTo(StartPnt);//移至直線起點
		dc.LineTo(EndPnt);//移至直線終點
		dc.SelectObject(oldPen);//還原選取的畫筆物件
	}
	void drawDashDot(CDC &dc, COLORREF Lcolor, COLORREF fcolor, int Lwidth, BOOL Filled = false)
	{
		CPen Center_Line_Pen(PS_DASHDOT, Lwidth, Lcolor);//建立畫筆物件
		CPen *oldPen = dc.SelectObject(&Center_Line_Pen);//設定DC物件使用pen物件
		dc.MoveTo(StartPnt);//移至直線起點
		dc.LineTo(EndPnt);//移至直線終點
		dc.SelectObject(oldPen);//還原選取的畫筆物件
	}
};
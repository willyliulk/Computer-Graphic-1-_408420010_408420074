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
		Tpye = 0; //�t���I�`�� 0:�I 1:���I
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
		CPen pen(PS_SOLID, Lwidth, Lcolor);//�إߵe������
		CPen *oldPen = dc.SelectObject(&pen);//�]�wDC����ϥ�pen����
		dc.MoveTo(StartPnt);//���ܪ��u�_�I
		dc.LineTo(EndPnt);//���ܪ��u���I
		dc.SelectObject(oldPen);//�٭������e������
	}
	void draw2(CDC &dc)
	{
		CPen pen(PS_SOLID, LineWidth, color);//�إߵe������
		CPen *oldPen = dc.SelectObject(&pen);//�]�wDC����ϥ�pen����
		dc.MoveTo(StartPnt);//���ܪ��u�_�I
		dc.LineTo(EndPnt);//���ܪ��u���I
		dc.SelectObject(oldPen);//�٭������e������
	}
	void drawDashDot(CDC &dc, COLORREF Lcolor, COLORREF fcolor, int Lwidth, BOOL Filled = false)
	{
		CPen Center_Line_Pen(PS_DASHDOT, Lwidth, Lcolor);//�إߵe������
		CPen *oldPen = dc.SelectObject(&Center_Line_Pen);//�]�wDC����ϥ�pen����
		dc.MoveTo(StartPnt);//���ܪ��u�_�I
		dc.LineTo(EndPnt);//���ܪ��u���I
		dc.SelectObject(oldPen);//�٭������e������
	}
};
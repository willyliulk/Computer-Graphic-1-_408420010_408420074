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
	MyLine()
	{
		color = RGB(255, 0, 0);
		StartPnt = (0, 0);
	}
};
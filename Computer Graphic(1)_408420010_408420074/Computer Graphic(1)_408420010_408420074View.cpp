
// Computer Graphic(1)_408420010_408420074View.cpp: CComputerGraphic1408420010408420074View 類別的實作
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以定義在實作預覽、縮圖和搜尋篩選條件處理常式的
// ATL 專案中，並允許與該專案共用文件程式碼。
#ifndef SHARED_HANDLERS
#include "Computer Graphic(1)_408420010_408420074.h"
#endif

#include "Computer Graphic(1)_408420010_408420074Doc.h"
#include "Computer Graphic(1)_408420010_408420074View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CComputerGraphic1408420010408420074View

IMPLEMENT_DYNCREATE(CComputerGraphic1408420010408420074View, CView)

BEGIN_MESSAGE_MAP(CComputerGraphic1408420010408420074View, CView)
	ON_COMMAND(ID_DRAW_POINT, &CComputerGraphic1408420010408420074View::OnDrawPoint)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_DRAW_LINE, &CComputerGraphic1408420010408420074View::OnDrawLine)
	ON_COMMAND(ID_DRAW_DOTLINE, &CComputerGraphic1408420010408420074View::OnDrawDotline)
	ON_COMMAND(ID_DRAW_ELLIPSE, &CComputerGraphic1408420010408420074View::OnDrawEllipse)
	ON_COMMAND(ID_COLOR_MANUALCOLOR, &CComputerGraphic1408420010408420074View::OnColorManualcolor)
	ON_COMMAND(ID_COLOR_FILLCOLOR, &CComputerGraphic1408420010408420074View::OnColorFillcolor)
	ON_COMMAND(ID_DRAW_RECTANGLE, &CComputerGraphic1408420010408420074View::OnDrawRectangle)
END_MESSAGE_MAP()

// CComputerGraphic1408420010408420074View 建構/解構

CComputerGraphic1408420010408420074View::CComputerGraphic1408420010408420074View() noexcept
{
	// TODO: 在此加入建構程式碼
	LineWidth = 10;
	color = RGB(255, 0, 0);
	fcolor = RGB(0, 0, 255);
}

CComputerGraphic1408420010408420074View::~CComputerGraphic1408420010408420074View()
{
}

BOOL CComputerGraphic1408420010408420074View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此經由修改 CREATESTRUCT cs 
	// 達到修改視窗類別或樣式的目的

	return CView::PreCreateWindow(cs);
}

// CComputerGraphic1408420010408420074View 繪圖

void CComputerGraphic1408420010408420074View::OnDraw(CDC* pDC)
{
	CComputerGraphic1408420010408420074Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此加入原生資料的描繪程式碼

	int Pnum = pDoc->pArray.GetSize();
	for (int i = 0; i < Pnum; i++) {
		if (pDoc->pArray[i].Tpye == 0)
		{
			pDC->SetPixel(pDoc->pArray[i].point, pDoc->pArray[i].color);
		}
		else
		{
			pDC->Ellipse(pDoc->pArray[i].point.x - 3, pDoc->pArray[i].point.y - 3, pDoc->pArray[i].point.x + 3, pDoc->pArray[i].point.y + 3);
		}
	}

	int Lnum = pDoc->lArray.GetCount();
	for (int i = 0; i < Lnum; i++)
	{
		if ((pDoc->lArray.GetAt(i).Type) == 0)
		{
			CPen pen(PS_SOLID, 2, pDoc->lArray.GetAt(i).color);
			CPen *oldPen = pDC->SelectObject(&pen);
			pDoc->lArray.GetAt(i).draw2(*pDC);
		}
		else if ((pDoc->lArray.GetAt(i).Type) == 1)
		{
			CPen pen(PS_DASHDOT, 1, pDoc->lArray.GetAt(i).color);
			CPen *oldPen = pDC->SelectObject(&pen);
			pDoc->lArray.GetAt(i).drawDashDot(*pDC);
		}
		int a = pDoc->lArray.GetAt(i).Type;
		CString s;
		s.Format(_T("%d"), (pDoc->lArray.GetAt(i).Type));
		pDC->TextOut(200, 50+20*i, s);
	}

	int Enum = pDoc->EArray.GetCount();
	for (int i = 0; i < Enum; i++)
	{
		CPen pen(PS_SOLID, 2, pDoc->EArray.GetAt(i).color);
		CPen *oldPen = pDC->SelectObject(&pen);
		if (TempEllipse.Filled)
		{
			// m_newbrush.CreateSolidBrush(fcolor);
			CBrush m_newbrush;
			m_newbrush.CreateHatchBrush(HS_FDIAGONAL, fcolor);
			pDC->SelectObject(&m_newbrush);
		}
		pDoc->EArray.GetAt(i).draw2(*pDC);
	}

	int Rnum = pDoc->RArray.GetCount();
	for (int i = 0; i < Rnum; i++)
	{
		CPen pen(PS_SOLID, 2, pDoc->RArray.GetAt(i).color);
		CPen *oldPen = pDC->SelectObject(&pen);
		if (TempRect.Filled)
		{
			// m_newbrush.CreateSolidBrush(fcolor);
			CBrush m_newbrush;
			m_newbrush.CreateHatchBrush(HS_FDIAGONAL, fcolor);
			pDC->SelectObject(&m_newbrush);
		}
		pDoc->RArray.GetAt(i).draw2(*pDC);
	}
}


// CComputerGraphic1408420010408420074View 診斷

#ifdef _DEBUG
void CComputerGraphic1408420010408420074View::AssertValid() const
{
	CView::AssertValid();
}

void CComputerGraphic1408420010408420074View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CComputerGraphic1408420010408420074Doc* CComputerGraphic1408420010408420074View::GetDocument() const // 內嵌非偵錯版本
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CComputerGraphic1408420010408420074Doc)));
	return (CComputerGraphic1408420010408420074Doc*)m_pDocument;
}
#endif //_DEBUG


// CComputerGraphic1408420010408420074View 訊息處理常式


void CComputerGraphic1408420010408420074View::OnDrawPoint()
{
	// TODO: 在此加入您的命令處理常式程式碼
	CComputerGraphic1408420010408420074Doc *doc = (CComputerGraphic1408420010408420074Doc *)GetDocument();
	doc->shapeNum = 0;
	doc->Obj_Color = RGB(0, 0, 255);
	doc->P_Type = 0;
}


void CComputerGraphic1408420010408420074View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值
	CView::OnLButtonDown(nFlags, point);
	SetCapture();
	CComputerGraphic1408420010408420074Doc *doc = (CComputerGraphic1408420010408420074Doc *)GetDocument();
	doc->Obj_Color = color;
	if (doc->shapeNum == 1)//draw line start
	{
		if (doc->L_Type == 0) {//for solid line
			TempLine.StartPnt = point;
			TempLine.EndPnt = point; //設定新物件座標點
			TempLine.color = doc->Obj_Color;
			TempLine.LineWidth = LineWidth;
			TempLine.Type = 0;
		}
		else if (doc->L_Type == 1) {//for dot line
			TempLine.StartPnt = point;
			TempLine.EndPnt = point; //設定新物件座標點
			TempLine.color = doc->Obj_Color;
			TempLine.LineWidth = LineWidth;
			TempLine.Type = 1;
		}
	}
	else if (doc->shapeNum == 2)//draw ellipse start
	{
		TempEllipse.StartPnt = point;
		TempEllipse.EndPnt = point; //設定新物件座標點
		TempEllipse.color = doc->Obj_Color;
		TempEllipse.fcolor = fcolor;
		TempEllipse.LineWidth = LineWidth;
	}
	else if (doc->shapeNum == 3)//draw erct start
	{
		TempRect.StartPnt = point;
		TempRect.EndPnt = point; //設定新物件座標點
		TempRect.color = doc->Obj_Color;
		TempRect.fcolor = fcolor;
		TempRect.LineWidth = LineWidth;
	}
}


void CComputerGraphic1408420010408420074View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值
	CView::OnMouseMove(nFlags, point);
	MyPoint temppoint;
	CComputerGraphic1408420010408420074Doc *doc = (CComputerGraphic1408420010408420074Doc *)GetDocument();
	if (this == GetCapture())
	{
		CClientDC aDC(this);
		if (doc->shapeNum == 0) //for point
		{
			if (doc->P_Type == 0)
			{
				aDC.SetPixel(point, doc->Obj_Color);
			}
			else
			{
				temppoint.point = point;
				temppoint.color = doc->Obj_Color;
				temppoint.Tpye = doc->P_Type;
				doc->pArray.Add(temppoint);
			}
		}
		else if (doc->shapeNum == 1)//for line
		{
			aDC.SetROP2(R2_NOTXORPEN); //設定繪圖模式 R2_NOT R2_NOTXORPEN 
			if (doc->L_Type == 0) {//for solid line
				TempLine.draw2(aDC); //清除上一筆
				TempLine.EndPnt = point; //設定新物件座標點
				TempLine.draw2(aDC); //再畫出新形狀物
				TempLine.Type = 0;
			}
			else if (doc->L_Type == 1) {//for dot line
				TempLine.drawDashDot(aDC); //清除上一筆
				TempLine.EndPnt = point; //設定新物件座標點
				TempLine.drawDashDot(aDC); //再畫出新形狀物
				TempLine.Type = 1;
			}
		}
		else if (doc->shapeNum == 2)//for ellipse
		{
			aDC.SetROP2(R2_NOTXORPEN); //設定繪圖模式 R2_NOT R2_NOTXORPEN 
			TempEllipse.draw2(aDC); //清除上一筆
			TempEllipse.EndPnt = point; //設定新物件座標點
			TempEllipse.draw2(aDC); //再畫出新形狀物
		}
		else if (doc->shapeNum == 3)//for rect
		{
			aDC.SetROP2(R2_NOTXORPEN); //設定繪圖模式 R2_NOT R2_NOTXORPEN 
			TempRect.draw2(aDC); //清除上一筆
			TempRect.EndPnt = point; //設定新物件座標點
			TempRect.draw2(aDC); //再畫出新形狀物
		}
	}
}


void CComputerGraphic1408420010408420074View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值

	CView::OnLButtonUp(nFlags, point);
	ReleaseCapture();
	CComputerGraphic1408420010408420074Doc *doc = (CComputerGraphic1408420010408420074Doc *)GetDocument();
	CClientDC aDC(this);
	if (doc->shapeNum == 0) {//draw point end
		//already done in mouseOnMove
	}
	else if (doc->shapeNum == 1)//draw line end
	{
		if (doc->L_Type == 0) {//for solid line
			TempLine.EndPnt = point;
			TempLine.draw2(aDC);
			
			doc->lArray.Add(TempLine);
		}
		else if (doc->L_Type == 1)//for dot line
		{
			TempLine.EndPnt = point;
			TempLine.drawDashDot(aDC);
			
			doc->lArray.Add(TempLine);
		}

	}
	else if (doc->shapeNum == 2)//draw ellipse end
	{
		if (TempEllipse.Filled)
		{
			// m_newbrush.CreateSolidBrush(fcolor);
			CBrush m_newbrush;
			m_newbrush.CreateHatchBrush(HS_FDIAGONAL, fcolor);
			aDC.SelectObject(&m_newbrush);
		}
		TempEllipse.EndPnt = point;
		TempEllipse.draw2(aDC);
		doc->EArray.Add(TempEllipse);
	}
	else if (doc->shapeNum == 3)//draw rect end
	{
		if (TempEllipse.Filled)
		{
			// m_newbrush.CreateSolidBrush(fcolor);
			CBrush m_newbrush;
			m_newbrush.CreateHatchBrush(HS_FDIAGONAL, fcolor);
			aDC.SelectObject(&m_newbrush);
		}
		TempRect.EndPnt = point;
		TempRect.draw2(aDC);
		doc->RArray.Add(TempRect);
	}
}


void CComputerGraphic1408420010408420074View::OnDrawLine()
{
	// TODO: 在此加入您的命令處理常式程式碼
	CComputerGraphic1408420010408420074Doc *doc = GetDocument();
	doc->shapeNum = 1;
	doc->L_Type = 0;
}


void CComputerGraphic1408420010408420074View::OnDrawDotline()
{
	// TODO: 在此加入您的命令處理常式程式碼
	CComputerGraphic1408420010408420074Doc *doc = GetDocument();
	doc->shapeNum = 1;
	doc->L_Type = 1;
}


void CComputerGraphic1408420010408420074View::OnDrawEllipse()
{
	// TODO: 在此加入您的命令處理常式程式碼
	CComputerGraphic1408420010408420074Doc *doc = GetDocument();
	doc->shapeNum = 2;
}


void CComputerGraphic1408420010408420074View::OnColorManualcolor()
{
	// TODO: 在此加入您的命令處理常式程式碼
	CColorDialog dlgColor(color);
	if (dlgColor.DoModal() == IDOK)
	{
		color = dlgColor.GetColor();
	}
}


void CComputerGraphic1408420010408420074View::OnColorFillcolor()
{
	// TODO: 在此加入您的命令處理常式程式碼
	CColorDialog dlgColor(color);
	if (dlgColor.DoModal() == IDOK)
	{
		fcolor = dlgColor.GetColor();
	}
}


void CComputerGraphic1408420010408420074View::OnDrawRectangle()
{
	// TODO: 在此加入您的命令處理常式程式碼
	CComputerGraphic1408420010408420074Doc *doc = GetDocument();
	doc->shapeNum = 3;
}


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
END_MESSAGE_MAP()

// CComputerGraphic1408420010408420074View 建構/解構

CComputerGraphic1408420010408420074View::CComputerGraphic1408420010408420074View() noexcept
{
	// TODO: 在此加入建構程式碼
	LineWidth = 10;
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
			pDC->Ellipse(pDoc->pArray[i].point.x - 3, pDoc->pArray[i].point.y - 3, pDoc->pArray[i].point.x + 3,pDoc->pArray[i].point.y + 3);
		}
	}
	int Lnum = pDoc->lArray.GetCount();
	for(int i = 0; i < Lnum; i++)
	{
		CPen pen(PS_SOLID, 2, pDoc->lArray.GetAt(i).color);
		CPen *oldPen = pDC->SelectObject(&pen);
		pDC->MoveTo(pDoc->lArray.GetAt(i).StartPnt);
		pDC->LineTo(pDoc->lArray.GetAt(i).EndPnt);
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
	if (doc->shapeNum == 1)
	{
		TempLine.StartPnt = point;
		TempLine.color = doc->Obj_Color;
		TempLine.LineWidth = LineWidth;
		
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
}


void CComputerGraphic1408420010408420074View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值

	CView::OnLButtonUp(nFlags, point);
	ReleaseCapture();
	CComputerGraphic1408420010408420074Doc *doc = (CComputerGraphic1408420010408420074Doc *)GetDocument();
	if(doc->shapeNum == 1)
	{
		CClientDC aDC(this);
		TempLine.EndPnt = point;
		TempLine.draw2(aDC);
		doc->lArray.Add(TempLine);

	}
}


void CComputerGraphic1408420010408420074View::OnDrawLine()
{
	// TODO: 在此加入您的命令處理常式程式碼
	CComputerGraphic1408420010408420074Doc *doc = GetDocument();
	doc->shapeNum = 1;
}


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
END_MESSAGE_MAP()

// CComputerGraphic1408420010408420074View 建構/解構

CComputerGraphic1408420010408420074View::CComputerGraphic1408420010408420074View() noexcept
{
	// TODO: 在此加入建構程式碼

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

void CComputerGraphic1408420010408420074View::OnDraw(CDC* /*pDC*/)
{
	CComputerGraphic1408420010408420074Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此加入原生資料的描繪程式碼
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

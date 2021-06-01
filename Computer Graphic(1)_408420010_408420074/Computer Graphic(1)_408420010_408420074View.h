
// Computer Graphic(1)_408420010_408420074View.h: CComputerGraphic1408420010408420074View 類別的介面
//

#pragma once


class CComputerGraphic1408420010408420074View : public CView
{
protected: // 僅從序列化建立
	CComputerGraphic1408420010408420074View() noexcept;
	DECLARE_DYNCREATE(CComputerGraphic1408420010408420074View)

// 屬性
public:
	CComputerGraphic1408420010408420074Doc* GetDocument() const;
	MyLine TempLine;
	int LineWidth;
	MyEllipse TempEllipse;
	MyRect TempRect;
	COLORREF color = RGB(255, 0, 0);
	COLORREF fcolor = RGB(0, 0, 255);

// 作業
public:

// 覆寫
public:
	virtual void OnDraw(CDC* pDC);  // 覆寫以描繪此檢視
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 程式碼實作
public:
	virtual ~CComputerGraphic1408420010408420074View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 產生的訊息對應函式
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawPoint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnDrawLine();
	afx_msg void OnDrawDotline();
	afx_msg void OnDrawEllipse();
	afx_msg void OnColorManualcolor();
	afx_msg void OnColorFillcolor();
	afx_msg void OnDrawRectangle();
	afx_msg void OnColorRed();
	afx_msg void OnColorGreen();
	afx_msg void OnColorBlue();
};

#ifndef _DEBUG  // 對 Computer Graphic(1)_408420010_408420074View.cpp 中的版本進行偵錯
inline CComputerGraphic1408420010408420074Doc* CComputerGraphic1408420010408420074View::GetDocument() const
   { return reinterpret_cast<CComputerGraphic1408420010408420074Doc*>(m_pDocument); }
#endif


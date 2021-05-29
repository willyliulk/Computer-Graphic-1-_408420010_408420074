
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
};

#ifndef _DEBUG  // 對 Computer Graphic(1)_408420010_408420074View.cpp 中的版本進行偵錯
inline CComputerGraphic1408420010408420074Doc* CComputerGraphic1408420010408420074View::GetDocument() const
   { return reinterpret_cast<CComputerGraphic1408420010408420074Doc*>(m_pDocument); }
#endif


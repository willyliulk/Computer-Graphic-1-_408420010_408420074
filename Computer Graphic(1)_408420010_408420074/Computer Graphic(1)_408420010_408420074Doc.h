
// Computer Graphic(1)_408420010_408420074Doc.h: CComputerGraphic1408420010408420074Doc 類別的介面
//


#pragma once
#include "BaseStruct.h"

class CComputerGraphic1408420010408420074Doc : public CDocument
{
protected: // 僅從序列化建立
	CComputerGraphic1408420010408420074Doc() noexcept;
	DECLARE_DYNCREATE(CComputerGraphic1408420010408420074Doc)

// 屬性
public:
	CArray <MyPoint, MyPoint &> pArray;
	CArray <MyLine, MyLine &> lArray;
	int shapeNum;
	COLORREF Obj_Color;
	int P_Type;
	void RemoveAll() 
	{
		pArray.RemoveAll();
		lArray.RemoveAll();
	}

// 作業
public:

// 覆寫
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 程式碼實作
public:
	virtual ~CComputerGraphic1408420010408420074Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 產生的訊息對應函式
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 為搜尋處理常式設定搜尋內容的 Helper 函式
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};

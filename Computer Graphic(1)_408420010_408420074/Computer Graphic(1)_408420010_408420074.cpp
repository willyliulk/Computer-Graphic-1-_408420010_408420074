﻿
// Computer Graphic(1)_408420010_408420074.cpp: 定義應用程式的類別表現方式。
//

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "Computer Graphic(1)_408420010_408420074.h"
#include "MainFrm.h"

#include "Computer Graphic(1)_408420010_408420074Doc.h"
#include "Computer Graphic(1)_408420010_408420074View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CComputerGraphic1408420010408420074App

BEGIN_MESSAGE_MAP(CComputerGraphic1408420010408420074App, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CComputerGraphic1408420010408420074App::OnAppAbout)
	// 依據文件命令的標準檔案
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
END_MESSAGE_MAP()


// CComputerGraphic1408420010408420074App 建構

CComputerGraphic1408420010408420074App::CComputerGraphic1408420010408420074App() noexcept
{
	// TODO: 以唯一的 ID 字串取代下面的應用程式 ID 字串; 建議的
	// 字串格式為 CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("ComputerGraphic1408420010408420074.AppID.NoVersion"));

	// TODO: 在此加入建構程式碼，
	// 將所有重要的初始設定加入 InitInstance 中
}

// 唯一一個 CComputerGraphic1408420010408420074App 物件

CComputerGraphic1408420010408420074App theApp;


// CComputerGraphic1408420010408420074App 初始化

BOOL CComputerGraphic1408420010408420074App::InitInstance()
{
	CWinApp::InitInstance();


	EnableTaskbarInteraction(FALSE);

	// 需要有 AfxInitRichEdit2() 才能使用 RichEdit 控制項
	// AfxInitRichEdit2();

	// 標準初始設定
	// 如果您不使用這些功能並且想減少
	// 最後完成的可執行檔大小，您可以
	// 從下列程式碼移除不需要的初始化常式，
	// 變更儲存設定值的登錄機碼
	// TODO: 您應該適度修改此字串
	// (例如，公司名稱或組織名稱)
	SetRegistryKey(_T("本機 AppWizard 所產生的應用程式"));
	LoadStdProfileSettings(4);  // 載入標準 INI 檔選項 (包含 MRU)


	// 登錄應用程式的文件範本。文件範本負責在文件、
	// 框架視窗與檢視間進行連接
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CComputerGraphic1408420010408420074Doc),
		RUNTIME_CLASS(CMainFrame),       // 主 SDI 框架視窗
		RUNTIME_CLASS(CComputerGraphic1408420010408420074View));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// 剖析標準 Shell 命令、DDE、檔案開啟舊檔的命令列
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// 在命令列中指定的分派命令。如果已使用 
	// /RegServer、/Register、/Unregserver 或 /Unregister 啟動應用程式，將傳回 FALSE。
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// 僅初始化一個視窗，所以顯示並更新該視窗
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

// CComputerGraphic1408420010408420074App 訊息處理常式


// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg() noexcept;

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// 執行對話方塊的應用程式命令
void CComputerGraphic1408420010408420074App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CComputerGraphic1408420010408420074App 訊息處理常式




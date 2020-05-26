
// exp14-1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "exp14-1.h"
#include "exp14-1Dlg.h"
#include "afxdialogex.h"
#include "Popdlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cexp141Dlg 对话框



Cexp141Dlg::Cexp141Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EXP141_DIALOG, pParent)
	, a(0)
	, b(0)
	, c(0)
	, x1(0)
	, y1(0)
	, z1(0)
	, x2(0)
	, y2(0)
	, z2(0)
	, x3(0)
	, y3(0)
	, z3(0)
	, x4(0)
	, y4(0)
	, z4(0)
	, x5(0)
	, z5(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cexp141Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
	DDX_Text(pDX, IDC_EDIT2, b);
	DDX_Text(pDX, IDC_EDIT3, c);
	DDX_Text(pDX, IDC_EDIT4, x1);
	DDX_Text(pDX, IDC_EDIT5, y1);
	DDX_Text(pDX, IDC_EDIT6, z1);
	DDX_Text(pDX, IDC_EDIT7, x2);
	DDX_Text(pDX, IDC_EDIT8, y2);
	DDX_Text(pDX, IDC_EDIT9, z2);
	DDX_Text(pDX, IDC_EDIT10, x3);
	DDX_Text(pDX, IDC_EDIT11, y3);
	DDX_Text(pDX, IDC_EDIT12, z3);
	DDX_Text(pDX, IDC_EDIT13, x4);
	DDX_Text(pDX, IDC_EDIT15, z4);
	DDX_Text(pDX, IDC_EDIT16, x5);
	DDX_Text(pDX, IDC_EDIT18, z5);
}

BEGIN_MESSAGE_MAP(Cexp141Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &Cexp141Dlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT3, &Cexp141Dlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON1, &Cexp141Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cexp141Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Cexp141Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Cexp141Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &Cexp141Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &Cexp141Dlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// Cexp141Dlg 消息处理程序

BOOL Cexp141Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Cexp141Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cexp141Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Cexp141Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cexp141Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Cexp141Dlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

}


void Cexp141Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	c = a + b;
	UpdateData(false);
}


void Cexp141Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	z1 = x1 - y1;
	UpdateData(false);
}


void Cexp141Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	z2 = x2 * y2;
	UpdateData(false);
}


void Cexp141Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	if (y3 == 0)
	{
		Popdlg dlg;
		int r = dlg.DoModal();
	}
	else z3 =(double) (x3 / y3);
	UpdateData(false);
}


void Cexp141Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	if (x4 < 0)
	{
		Popdlg dlg0;
		int r = dlg0.DoModal();
	}
	else
	{
		z4 = sqrt(x4);
	}
	UpdateData(false);
}


void Cexp141Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	if (x5 == 0)
	{
		Popdlg dlg0;
		int r = dlg0.DoModal();
	}
	else
	{
		z5 = (double)(1.0/x5);
	}
	UpdateData(false);
}


// exp14-1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "exp14-1.h"
#include "exp14-1Dlg.h"
#include "afxdialogex.h"
#include "Popdlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// Cexp141Dlg �Ի���



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


// Cexp141Dlg ��Ϣ�������

BOOL Cexp141Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Cexp141Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Cexp141Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cexp141Dlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Cexp141Dlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������

}


void Cexp141Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(true);
	c = a + b;
	UpdateData(false);
}


void Cexp141Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(true);
	z1 = x1 - y1;
	UpdateData(false);
}


void Cexp141Dlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(true);
	z2 = x2 * y2;
	UpdateData(false);
}


void Cexp141Dlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

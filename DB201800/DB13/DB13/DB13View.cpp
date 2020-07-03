
// DB13View.cpp : CDB13View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DB13.h"
#endif

#include "DB13Set.h"
#include "DB13Doc.h"
#include "DB13View.h"
#include "ADD_DLG.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB13View

IMPLEMENT_DYNCREATE(CDB13View, CRecordView)

BEGIN_MESSAGE_MAP(CDB13View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON2, &CDB13View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDB13View::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CDB13View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDB13View 构造/析构

CDB13View::CDB13View()
	: CRecordView(IDD_DB13_FORM)
	, ss(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CDB13View::~CDB13View()
{
}

void CDB13View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
}

BOOL CDB13View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CDB13View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DB13Set;
	CRecordView::OnInitialUpdate();

}


// CDB13View 诊断

#ifdef _DEBUG
void CDB13View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDB13View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDB13Doc* CDB13View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDB13Doc)));
	return (CDB13Doc*)m_pDocument;
}
#endif //_DEBUG


// CDB13View 数据库支持
CRecordset* CDB13View::OnGetRecordset()
{
	return m_pSet;
}



// CDB13View 消息处理程序


void CDB13View::OnBnClickedButton2() //修改
{
	// TODO: 在此添加控件通知处理程序代码
	ADD_DLG adddlg;
	int r = adddlg.DoModal();
	if (r == IDOK)
	{
		long ii = adddlg.i;
		m_pSet->Edit();
		m_pSet->m_ID = ii;
		m_pSet->Update();
		UpdateData(false);
	}
}


void CDB13View::OnBnClickedButton3() //删除
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
	{
		m_pSet->MoveFirst();
		UpdateData(false);
	}
}


void CDB13View::OnBnClickedButton1() //增加
{
	// TODO: 在此添加控件通知处理程序代码
	ADD_DLG adddlg;
	int r = adddlg.DoModal();
	if (r == IDOK)
	{
		long ii = adddlg.i;
		m_pSet->AddNew();
		m_pSet->m_ID = ii;
		m_pSet->Update();
		UpdateData(false);
	}
}

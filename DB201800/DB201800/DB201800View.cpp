
// DB201800View.cpp : CDB201800View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DB201800.h"
#endif

#include "DB201800Set.h"
#include "DB201800Doc.h"
#include "DB201800View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB201800View

IMPLEMENT_DYNCREATE(CDB201800View, CRecordView)

BEGIN_MESSAGE_MAP(CDB201800View, CRecordView)
END_MESSAGE_MAP()

// CDB201800View 构造/析构

CDB201800View::CDB201800View()
	: CRecordView(IDD_DB201800_FORM)
	, ID(0)
	, name(_T(""))
	, number(0)
	, age(0)
	, phoneNum(0)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CDB201800View::~CDB201800View()
{
}

void CDB201800View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column4);
}

BOOL CDB201800View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CDB201800View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DB201800Set;
	CRecordView::OnInitialUpdate();

}


// CDB201800View 诊断

#ifdef _DEBUG
void CDB201800View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDB201800View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDB201800Doc* CDB201800View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDB201800Doc)));
	return (CDB201800Doc*)m_pDocument;
}
#endif //_DEBUG


// CDB201800View 数据库支持
CRecordset* CDB201800View::OnGetRecordset()
{
	return m_pSet;
}



// CDB201800View 消息处理程序

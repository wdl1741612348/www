
// DB002View.cpp : CDB002View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DB002.h"
#endif

#include "DB002Set.h"
#include "DB002Doc.h"
#include "DB002View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB002View

IMPLEMENT_DYNCREATE(CDB002View, CRecordView)

BEGIN_MESSAGE_MAP(CDB002View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CDB002View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CDB002View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CDB002View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CDB002View::OnRecordLast)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CDB002View 构造/析构

CDB002View::CDB002View()
	: CRecordView(IDD_DB002_FORM)
	, s(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("D:\\数据源\\");
}

CDB002View::~CDB002View()
{
}

void CDB002View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
}

BOOL CDB002View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CDB002View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DB002Set;
	CRecordView::OnInitialUpdate();
//	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
}


// CDB002View 诊断

#ifdef _DEBUG
void CDB002View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDB002View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDB002Doc* CDB002View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDB002Doc)));
	return (CDB002Doc*)m_pDocument;
}
#endif //_DEBUG


// CDB002View 数据库支持
CRecordset* CDB002View::OnGetRecordset()
{
	return m_pSet;
}



// CDB002View 消息处理程序


void CDB002View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	GetDlgItemText(IDC_EDIT1, f);
	filename = path + f;
	draw_pic(filename);
	InvalidateRect(cr);
}


void CDB002View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
	{
		m_pSet->MoveFirst();
	}UpdateData(false);

	GetDlgItemText(IDC_EDIT1, f);
	filename = path + f;

	draw_pic(filename);
	InvalidateRect(cr);
}


void CDB002View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
	{
		m_pSet->MoveLast();
	}UpdateData(false);

	GetDlgItemText(IDC_EDIT1, f);
	filename = path + f;

	draw_pic(filename);
	InvalidateRect(cr);
}


void CDB002View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);

	GetDlgItemText(IDC_EDIT1, f);
	filename = path + f;

	draw_pic(filename);
	InvalidateRect(cr);
}

void CDB002View::draw_pic(CString file)
{
//	CImage img;
	img.Load(file);
//	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
//	CRect cr;
//	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
	float cr_ratio = 1.0*cr.Width() / cr.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();

	if (cr_ratio > img_ratio)
	{
		h = cr.Height();
		w = img_ratio*h;
		sx = (cr.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = cr.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (cr.Height() - h) / 2;
	}
//	pDC->SetStretchBltMode(HALFTONE);
//	img.Draw(pDC->m_hDC, sx, sy, w, h);
//	ReleaseDC(pDC);
}



void CDB002View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	CImage img;
	img.Load(filename);
    pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}

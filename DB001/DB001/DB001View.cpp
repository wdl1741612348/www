
// DB001View.cpp : CDB001View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DB001.h"
#endif

#include "DB001Set.h"
#include "DB001Doc.h"
#include "DB001View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB001View

IMPLEMENT_DYNCREATE(CDB001View, CRecordView)

BEGIN_MESSAGE_MAP(CDB001View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CDB001View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CDB001View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CDB001View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CDB001View::OnRecordLast)
//	ON_WM_PAINT()
END_MESSAGE_MAP()

// CDB001View 构造/析构

CDB001View::CDB001View()
	: CRecordView(IDD_DB001_FORM)
	, s(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("D:\\数据源\\");
	
}

CDB001View::~CDB001View()
{
}

void CDB001View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
}

BOOL CDB001View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CDB001View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DB001Set;
	CRecordView::OnInitialUpdate();
}


// CDB001View 诊断

#ifdef _DEBUG
void CDB001View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDB001View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDB001Doc* CDB001View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDB001Doc)));
	return (CDB001Doc*)m_pDocument;
}
#endif //_DEBUG


// CDB001View 数据库支持
CRecordset* CDB001View::OnGetRecordset()
{
	return m_pSet;
}



// CDB001View 消息处理程序


void CDB001View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);

	CString filename,s;
	GetDlgItemText(IDC_EDIT1,s);
	filename = path + s;

	draw_pic(filename);

}


void CDB001View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
	{
		m_pSet->MoveFirst();
	}UpdateData(false);

	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;

	draw_pic(filename);
}


void CDB001View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
	{
		m_pSet->MoveLast();
	}UpdateData(false);

	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;

	draw_pic(filename);
}


void CDB001View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;

	draw_pic(filename);
}

void CDB001View::draw_pic(CString file)
{
	CImage img;
	img.Load(file);
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();

	if (rect_ratio > img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC,sx,sy,w,h);
	ReleaseDC(pDC);
}



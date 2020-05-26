
// DB0505-3View.cpp : CDB05053View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DB0505-3.h"
#endif

#include "DB0505-3Set.h"
#include "DB0505-3Doc.h"
#include "DB0505-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB05053View

IMPLEMENT_DYNCREATE(CDB05053View, CRecordView)

BEGIN_MESSAGE_MAP(CDB05053View, CRecordView)
END_MESSAGE_MAP()

// CDB05053View 构造/析构

CDB05053View::CDB05053View()
	: CRecordView(IDD_DB05053_FORM)
	, name(_T(""))
	, number(0)
	, age(0)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
}

CDB05053View::~CDB05053View()
{
}

void CDB05053View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column3);
	Invalidate();
}

BOOL CDB05053View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CDB05053View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DB05053Set;
	CRecordView::OnInitialUpdate();

}


// CDB05053View 诊断

#ifdef _DEBUG
void CDB05053View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDB05053View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDB05053Doc* CDB05053View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDB05053Doc)));
	return (CDB05053Doc*)m_pDocument;
}
#endif //_DEBUG


// CDB05053View 数据库支持
CRecordset* CDB05053View::OnGetRecordset()
{
	return m_pSet;
}



// CDB05053View 消息处理程序

void CDB05053View::foo(CImage &img, int &sx, int &sy, int &w, int &h)
{
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
	float cr_ratio = 1.0*cr.Width() / cr.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (cr_ratio > img_ratio)
	{
		h = cr.Height()*1.0;
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
}


void CDB05053View::OnDraw(CDC* pDC)
{
	// TODO: 在此添加专用代码和/或调用基类
	CString s;
	m_pSet->GetFieldValue(short(3), s);//从记录集当前记录，读取第3个字段值，放入s中 
	CImage img;
	img.Load(s);

	int sx, sy, w, h;
	foo(img, sx, sy, w, h);

	pDC = GetDlgItem(IDC_STATIC)->GetDC();//GetDC()取得与图片控件所对应的设备环境
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}

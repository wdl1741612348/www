
// exp14-2-4View.cpp : Cexp1424View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp14-2-4.h"
#endif

#include "exp14-2-4Doc.h"
#include "exp14-2-4View.h"
#include "Mydlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp1424View

IMPLEMENT_DYNCREATE(Cexp1424View, CView)

BEGIN_MESSAGE_MAP(Cexp1424View, CView)
	ON_COMMAND(ID_Popout, &Cexp1424View::OnPopout)
END_MESSAGE_MAP()

// Cexp1424View 构造/析构

Cexp1424View::Cexp1424View()
{
	// TODO: 在此处添加构造代码
	cr.left = 200;
	cr.right = 500;
	cr.top = 200;
	cr.bottom = 400;
}

Cexp1424View::~Cexp1424View()
{
}

BOOL Cexp1424View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp1424View 绘制

void Cexp1424View::OnDraw(CDC* pDC)
{
	Cexp1424Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Ellipse(cr);
}


// Cexp1424View 诊断

#ifdef _DEBUG
void Cexp1424View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp1424View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp1424Doc* Cexp1424View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp1424Doc)));
	return (Cexp1424Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp1424View 消息处理程序


void Cexp1424View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	Mydlg dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		CClientDC dc(this);
		int color = RGB(dlg.a,dlg.b,dlg.c);
		CBrush newBrush(color);
		CBrush *oldBrush= dc.SelectObject(&newBrush);
		dc.Ellipse(cr);
		GetDC()->SelectObject(oldBrush);
	}
}

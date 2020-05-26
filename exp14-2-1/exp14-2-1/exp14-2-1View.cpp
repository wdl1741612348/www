
// exp14-2-1View.cpp : Cexp1421View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp14-2-1.h"
#endif

#include "exp14-2-1Doc.h"
#include "exp14-2-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp1421View

IMPLEMENT_DYNCREATE(Cexp1421View, CView)

BEGIN_MESSAGE_MAP(Cexp1421View, CView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// Cexp1421View 构造/析构

Cexp1421View::Cexp1421View()
{
	// TODO: 在此处添加构造代码
	cr.bottom =300 ; cr.right = 300;
	cr.top = 100; cr.left = 150;
	set = false;
}

Cexp1421View::~Cexp1421View()
{
}

BOOL Cexp1421View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp1421View 绘制

void Cexp1421View::OnDraw(CDC* pDC)
{
	Cexp1421Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Ellipse(cr);
}


// Cexp1421View 诊断

#ifdef _DEBUG
void Cexp1421View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp1421View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp1421Doc* Cexp1421View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp1421Doc)));
	return (Cexp1421Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp1421View 消息处理程序

void Cexp1421View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = true;
	a = point.y - cr.top;
	b = cr.bottom - point.y;
	c = point.x - cr.left;
	d = cr.right - point.x;
	CView::OnLButtonDown(nFlags, point);
}


void Cexp1421View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (set)
	{
		cr.top = point.y - a;
		cr.bottom = point.y + b;
		cr.left = point.x - c;
		cr.right = point.x + d;
	}
    Invalidate();
	CView::OnMouseMove(nFlags, point);
}





void Cexp1421View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = false;
	CView::OnLButtonUp(nFlags, point);
}

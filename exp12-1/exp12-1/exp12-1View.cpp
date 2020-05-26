
// exp12-1View.cpp : Cexp121View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp12-1.h"
#endif

#include "exp12-1Doc.h"
#include "exp12-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp121View

IMPLEMENT_DYNCREATE(Cexp121View, CView)

BEGIN_MESSAGE_MAP(Cexp121View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Cexp121View 构造/析构

Cexp121View::Cexp121View()
{
	// TODO: 在此处添加构造代码
	N = 0;
	cr.top = 100; cr.left = 100;
	cr.bottom = 200; cr.right = 300;
}

Cexp121View::~Cexp121View()
{
}

BOOL Cexp121View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp121View 绘制

void Cexp121View::OnDraw(CDC* pDC)
{
	Cexp121Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(cr);
}


// Cexp121View 诊断

#ifdef _DEBUG
void Cexp121View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp121View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp121Doc* Cexp121View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp121Doc)));
	return (Cexp121Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp121View 消息处理程序


void Cexp121View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	N = 1;
	a=cr.bottom - point.y; b= point.y - cr.top;
	c= point.x - cr.left; d=cr.right - point.x ;

	CView::OnLButtonDown(nFlags, point);
}


void Cexp121View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	N = 0;
	cr.bottom = point.y + a; cr.top = point.y - b;
	cr.left = point.x - c; cr.right = point.x + d;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void Cexp121View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (N == 1)
	{
		cr.bottom = point.y + 50; cr.top = point.y - 50;
		cr.left = point.x - 100; cr.right = point.x + 100;
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}

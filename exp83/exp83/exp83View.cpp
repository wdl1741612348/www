
// exp83View.cpp : Cexp83View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp83.h"
#endif

#include "exp83Doc.h"
#include "exp83View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp83View

IMPLEMENT_DYNCREATE(Cexp83View, CView)

BEGIN_MESSAGE_MAP(Cexp83View, CView)
	ON_COMMAND(ID_DRAWLINE, &Cexp83View::OnDrawline)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_DRAWRECTANGLE, &Cexp83View::OnDrawrectangle)
	ON_COMMAND(ID_DRAWCIRCLE, &Cexp83View::OnDrawcircle)
END_MESSAGE_MAP()

// Cexp83View 构造/析构

Cexp83View::Cexp83View()
{
	// TODO: 在此处添加构造代码

}

Cexp83View::~Cexp83View()
{
}

BOOL Cexp83View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp83View 绘制

void Cexp83View::OnDraw(CDC* pDC)
{
	Cexp83Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (k == 1)
	{
		pDC->MoveTo(a.x, a.y);
		pDC->LineTo(b.x, b.y);
	}
	if (k == 2)
	{
		CRect m_cr;
		m_cr.left = a.x;
		m_cr.top = a.y;
		m_cr.right = b.x;
		m_cr.bottom = b.y;
		pDC->Rectangle(m_cr);
	}
	if (k == 3)
	{
		CRect cr;
		cr.left = a.x;
		cr.top = a.y;
		cr.right = b.x;
		cr.bottom = b.y;
		pDC->Ellipse(cr);
	}

}


// Cexp83View 诊断

#ifdef _DEBUG
void Cexp83View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp83View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp83Doc* Cexp83View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp83Doc)));
	return (Cexp83Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp83View 消息处理程序


void Cexp83View::OnDrawline()
{
	// TODO: 在此添加命令处理程序代码
	k = 1;
}


void Cexp83View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
    	a.x = point.x;
		a.y = point.y;

	CView::OnLButtonDown(nFlags, point);
}



void Cexp83View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	b.x= point.x;
	b.y = point.y;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void Cexp83View::OnDrawrectangle()
{
	k = 2;
	// TODO: 在此添加命令处理程序代码
}


void Cexp83View::OnDrawcircle()
{
	k = 3;
	// TODO: 在此添加命令处理程序代码
}

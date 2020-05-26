
// exp14-2-3View.cpp : Cexp1423View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp14-2-3.h"
#endif

#include "exp14-2-3Doc.h"
#include "exp14-2-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp1423View

IMPLEMENT_DYNCREATE(Cexp1423View, CView)

BEGIN_MESSAGE_MAP(Cexp1423View, CView)
//	ON_WM_MBUTTONDOWN()
ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp1423View 构造/析构

Cexp1423View::Cexp1423View()
{
	// TODO: 在此处添加构造代码
	cr.left = 200;
	cr.top = 200;
	cr.bottom = 500;
	cr.right = 400;
}

Cexp1423View::~Cexp1423View()
{
}

BOOL Cexp1423View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp1423View 绘制

void Cexp1423View::OnDraw(CDC* pDC)
{
	Cexp1423Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Ellipse(cr);
}


// Cexp1423View 诊断

#ifdef _DEBUG
void Cexp1423View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp1423View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp1423Doc* Cexp1423View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp1423Doc)));
	return (Cexp1423Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp1423View 消息处理程序




void Cexp1423View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (point.x<cr.right && point.x>cr.left && point.y<cr.bottom &&point.y>cr.top)
	{
		GetDC()->Rectangle(cr);
		Invalidate(false);
	}
	CView::OnLButtonDown(nFlags, point);
}

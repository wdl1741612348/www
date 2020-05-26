
// exp61View.cpp : Cexp61View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp61.h"
#endif

#include "exp61Doc.h"
#include "exp61View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp61View

IMPLEMENT_DYNCREATE(Cexp61View, CView)

BEGIN_MESSAGE_MAP(Cexp61View, CView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// Cexp61View 构造/析构

Cexp61View::Cexp61View()
{
	// TODO: 在此处添加构造代码

}

Cexp61View::~Cexp61View()
{
}

BOOL Cexp61View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp61View 绘制

void Cexp61View::OnDraw(CDC* pDC)
{
	Cexp61Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->TextOutW(50, 70, pDoc->s2);
	pDC->TextOutW(50, 50, pDoc->s1);
	// TODO: 在此处为本机数据添加绘制代码

}


// Cexp61View 诊断

#ifdef _DEBUG
void Cexp61View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp61View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp61Doc* Cexp61View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp61Doc)));
	return (Cexp61Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp61View 消息处理程序


void Cexp61View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cexp61Doc* pDoc = GetDocument();
	pDoc->i++;
	CView::OnMouseMove(nFlags, point);
}


void Cexp61View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cexp61Doc* pDoc = GetDocument();
	pDoc->a_point=point;
	CView::OnLButtonDown(nFlags, point);
}


void Cexp61View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cexp61Doc* pDoc = GetDocument();
	CClientDC dc(this);
	pDoc->b_point=point;
	int x;
	pDoc->s1.Format(_T("MouseMove发生了%d 次"), pDoc->i);	
	x = (pDoc->b_point.x - pDoc->a_point.x) / pDoc->i;
	pDoc->s2.Format(_T("横向移动%d个像素发生一次"), x);	
	pDoc->i = 0;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);

}


// exp43View.cpp : Cexp43View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp43.h"
#endif

#include "exp43Doc.h"
#include "exp43View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp43View

IMPLEMENT_DYNCREATE(Cexp43View, CView)

BEGIN_MESSAGE_MAP(Cexp43View, CView)
//	ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp43View 构造/析构

Cexp43View::Cexp43View()
{
	// TODO: 在此处添加构造代码
	CRect a(50, 50, 300, 200);
	CRect b(50, 250, 400, 550);
	CRect c(600, 150, 1000, 500);
}

Cexp43View::~Cexp43View()
{
}

BOOL Cexp43View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp43View 绘制

void Cexp43View::OnDraw(CDC* pDC)
{
	Cexp43Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->a);
	pDC->Rectangle(pDoc->b);
	pDC->Rectangle(pDoc->c);
}


// Cexp43View 诊断

#ifdef _DEBUG
void Cexp43View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp43View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp43Doc* Cexp43View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp43Doc)));
	return (Cexp43Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp43View 消息处理程序
void Cexp43View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cexp43Doc* pDoc = GetDocument();
	CClientDC dc(this);

	if (point.x >pDoc->a.left && point.x<pDoc->a.right && point.y>pDoc->a.top && point.y < pDoc->a.bottom)
	{
		pDoc->r1 = rand() % 50 + 5;
		CString s1;
		s1.Format(_T("%d"), pDoc->r1);
		dc.TextOutW(80, 80, s1);
	}
	else if (point.x > pDoc->b.left && point.x<pDoc->b.right && point.y>pDoc->b.top && point.y < pDoc->b.bottom)
	{
		pDoc->r2 = rand() % 50 + 5;
		CString s2;
	s2.Format(_T("%d"), pDoc->r2);
		dc.TextOutW(250, 350, s2);
	}
	else if (point.x > pDoc->c.left && point.x<pDoc->c.right && point.y>pDoc->c.top && point.y < pDoc->c.bottom)
	{
	CString s3;
	s3.Format(_T("%d"), pDoc->r1 + pDoc->r2);
		dc.TextOutW(800, 350, s3);
	}
	else
	{
		CString s4 = _T("点击无效");
		dc.TextOutW(point.x,point.y,s4);
	}
	CView::OnLButtonDown(nFlags, point);
}
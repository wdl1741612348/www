
// exp62View.cpp : Cexp62View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp62.h"
#endif

#include "exp62Doc.h"
#include "exp62View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp62View

IMPLEMENT_DYNCREATE(Cexp62View, CView)

BEGIN_MESSAGE_MAP(Cexp62View, CView)
	ON_WM_KEYDOWN()
//	ON_WM_CHAR()
ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp62View 构造/析构

Cexp62View::Cexp62View()
{
	// TODO: 在此处添加构造代码
	i = 0;
}

Cexp62View::~Cexp62View()
{
}

BOOL Cexp62View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp62View 绘制

void Cexp62View::OnDraw(CDC* pDC)
{
	Cexp62Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect clientRec;
	int a, b;
	GetClientRect(&clientRec);
	if (i == 0)
	{
		a = (clientRec.right - clientRec.left) / 2;
		b = (clientRec.bottom - clientRec.top) / 2;

		pDoc->cr.left = a - 100;
		pDoc->cr.top = b - 50;
		pDoc->cr.right = a + 100;
		pDoc->cr.bottom = b + 50;
	}
	pDC->Rectangle(pDoc->cr);
	// TODO: 在此处为本机数据添加绘制代码
}


// Cexp62View 诊断

#ifdef _DEBUG
void Cexp62View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp62View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp62Doc* Cexp62View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp62Doc)));
	return (Cexp62Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp62View 消息处理程序


void Cexp62View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cexp62Doc* pDoc = GetDocument();
	i = 1;
	switch(nChar)
	{
	case VK_LEFT:
		pDoc->cr.left -= 20;
		pDoc->cr.right -= 20;
		break;
	case VK_RIGHT:
		pDoc->cr.left+= 20;
		pDoc->cr.right += 20;
		break;
	case VK_DOWN:
		pDoc->cr.top += 10;
		pDoc->cr.bottom += 10;
		break;
	case VK_UP:
		pDoc->cr.top -= 10;
		pDoc->cr.bottom -= 10;
		break;
	case VK_HOME:
		pDoc->cr.top += 10;
		pDoc->cr.left += 10;
		break;
	case VK_END:
		pDoc->cr.bottom -= 10;
		pDoc->cr.right -= 10;
		break;
	}
	
	CClientDC dc(this);
	dc.Rectangle(pDoc->cr);
	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}



void Cexp62View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	i = 0;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}

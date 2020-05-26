
// ecp72View.cpp : Cecp72View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ecp72.h"
#endif

#include "ecp72Doc.h"
#include "ecp72View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cecp72View

IMPLEMENT_DYNCREATE(Cecp72View, CView)

BEGIN_MESSAGE_MAP(Cecp72View, CView)
	ON_COMMAND(ID_DRAWCIRCLE, &Cecp72View::OnDrawcircle)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Cecp72View 构造/析构

Cecp72View::Cecp72View()
{
	// TODO: 在此处添加构造代码
	set = true;
	N = 0;
	red = 0; green = 0; blue = 0;
}

Cecp72View::~Cecp72View()
{
}

BOOL Cecp72View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cecp72View 绘制

void Cecp72View::OnDraw(CDC* pDC)
{
	Cecp72Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (set)
	{
		SetTimer(0, rand() % 400 + 100, NULL);
		set = false;
	}
	if (N == 1)
	{
		color = RGB(red,green,blue);
		CBrush newBrush(color);
		CBrush *oldBrush = pDC->SelectObject(&newBrush);
		pDC->Ellipse(pDoc->cr);
		pDC->SelectObject(oldBrush);
		red += 32;
		green += 16;
		blue += 8;
	}
}


// Cecp72View 诊断

#ifdef _DEBUG
void Cecp72View::AssertValid() const
{
	CView::AssertValid();
}

void Cecp72View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cecp72Doc* Cecp72View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cecp72Doc)));
	return (Cecp72Doc*)m_pDocument;
}
#endif //_DEBUG


// Cecp72View 消息处理程序


void Cecp72View::OnDrawcircle()
{
	// TODO: 在此添加命令处理程序代码
	Cecp72Doc* pDoc = GetDocument();
	CRect clientRec;
	int a, b;  N = 1;
	GetClientRect(&clientRec);
	a = (clientRec.right - clientRec.left) / 2;
	b = (clientRec.bottom - clientRec.top) / 2;
	pDoc->cr.left = a - 50;
	pDoc->cr.top = b - 50;
	pDoc->cr.right = a + 50;
	pDoc->cr.bottom = b + 50;

    CClientDC dc(this);
	CBrush newBrush(color);
	CBrush *oldBrush = dc.SelectObject(&newBrush);
	dc.Ellipse(pDoc->cr);
	dc.SelectObject(oldBrush);
	red += 32;
	green += 16;
	blue += 8;
}


void Cecp72View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cecp72Doc* pDoc = GetDocument();
	pDoc->cr.top -= 10;
	pDoc->cr.left -= 10;
	pDoc->cr.right += 10;
	pDoc->cr.bottom += 10;
	Invalidate();
	CView::OnTimer(nIDEvent);
}

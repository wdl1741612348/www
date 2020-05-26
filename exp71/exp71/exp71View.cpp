
// exp71View.cpp : Cexp71View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp71.h"
#endif

#include "exp71Doc.h"
#include "exp71View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp71View

IMPLEMENT_DYNCREATE(Cexp71View, CView)

BEGIN_MESSAGE_MAP(Cexp71View, CView)
	ON_COMMAND(ID_DRAWCIRCLE, &Cexp71View::OnDrawcircle)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Cexp71View 构造/析构

Cexp71View::Cexp71View()
{
	// TODO: 在此处添加构造代码
	set = true;
	N = 0;

}

Cexp71View::~Cexp71View()
{
}

BOOL Cexp71View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp71View 绘制

void Cexp71View::OnDraw(CDC* pDC)
{
	Cexp71Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (set)
	{
		SetTimer(0, rand() % 400 + 100, NULL);
		set = false;
	}
	if(N==1)
	pDC->Ellipse(pDoc->cr);
}


// Cexp71View 诊断

#ifdef _DEBUG
void Cexp71View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp71View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp71Doc* Cexp71View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp71Doc)));
	return (Cexp71Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp71View 消息处理程序


void Cexp71View::OnDrawcircle()
{
	// TODO: 在此添加命令处理程序代码
	Cexp71Doc* pDoc = GetDocument();
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
	dc.Ellipse(pDoc->cr);
	

}


void Cexp71View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cexp71Doc* pDoc = GetDocument();
	pDoc->cr.top -= 10;
	pDoc->cr.left -= 10;
	pDoc->cr.right += 10;
	pDoc->cr.bottom += 10;
	Invalidate();
	CView::OnTimer(nIDEvent);
}


// exp101View.cpp : Cexp101View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp101.h"
#endif

#include "exp101Doc.h"
#include "exp101View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp101View

IMPLEMENT_DYNCREATE(Cexp101View, CView)

BEGIN_MESSAGE_MAP(Cexp101View, CView)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// Cexp101View 构造/析构

Cexp101View::Cexp101View()
{
	// TODO: 在此处添加构造代码
	a = 5;
	b = 50;
}

Cexp101View::~Cexp101View()
{
}

BOOL Cexp101View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp101View 绘制

void Cexp101View::OnDraw(CDC* pDC)
{
	Cexp101Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect m_cr;
	GetClientRect(&m_cr);
	// TODO: 在此处为本机数据添加绘制代码
	CRect cr(0,40,m_cr.right,80);
	pDC->Rectangle(cr);
	pDC->TextOutW(a, b, s);
}


// Cexp101View 诊断

#ifdef _DEBUG
void Cexp101View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp101View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp101Doc* Cexp101View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp101Doc)));
	return (Cexp101Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp101View 消息处理程序


void Cexp101View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值	
	s.Format(s + _T("%c"), nChar);
	Invalidate();

	CView::OnChar(nChar, nRepCnt, nFlags);
}

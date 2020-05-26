
// exp22View.cpp : Cexp22View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp22.h"
#endif

#include "exp22Doc.h"
#include "exp22View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp22View

IMPLEMENT_DYNCREATE(Cexp22View, CView)

BEGIN_MESSAGE_MAP(Cexp22View, CView)
END_MESSAGE_MAP()

// Cexp22View 构造/析构

Cexp22View::Cexp22View()
{
	// TODO: 在此处添加构造代码
}

Cexp22View::~Cexp22View()
{
}

BOOL Cexp22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp22View 绘制

void Cexp22View::OnDraw(CDC* pDC)
{
	Cexp22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	int b = pDoc->a;
	CString s1 = pDoc->s;
	CString s2;
	s2.Format(s1+_T("    %d"),b);
	pDC->TextOutW(100, 200, s2);
}


// Cexp22View 诊断

#ifdef _DEBUG
void Cexp22View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp22Doc* Cexp22View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp22Doc)));
	return (Cexp22Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp22View 消息处理程序

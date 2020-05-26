
// exp17-1View.cpp : Cexp171View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp17-1.h"
#endif

#include "exp17-1Doc.h"
#include "exp17-1View.h"
#include"win32.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp171View

IMPLEMENT_DYNCREATE(Cexp171View, CView)

BEGIN_MESSAGE_MAP(Cexp171View, CView)
END_MESSAGE_MAP()

// Cexp171View 构造/析构

Cexp171View::Cexp171View()
{
	// TODO: 在此处添加构造代码

}

Cexp171View::~Cexp171View()
{
}

BOOL Cexp171View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp171View 绘制

void Cexp171View::OnDraw(CDC* pDC)
{
	Cexp171Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString p;
	p.Format(_T("%d"),factorial(5));
	pDC->TextOutW(200,200,p);
}


// Cexp171View 诊断

#ifdef _DEBUG
void Cexp171View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp171View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp171Doc* Cexp171View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp171Doc)));
	return (Cexp171Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp171View 消息处理程序

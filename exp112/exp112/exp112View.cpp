
// exp112View.cpp : Cexp112View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp112.h"
#endif

#include "exp112Doc.h"
#include "exp112View.h"
#include "MyDlg0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp112View

IMPLEMENT_DYNCREATE(Cexp112View, CView)

BEGIN_MESSAGE_MAP(Cexp112View, CView)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// Cexp112View 构造/析构

Cexp112View::Cexp112View()
{
	// TODO: 在此处添加构造代码

}

Cexp112View::~Cexp112View()
{
}

BOOL Cexp112View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp112View 绘制

void Cexp112View::OnDraw(CDC* /*pDC*/)
{
	Cexp112Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Cexp112View 诊断

#ifdef _DEBUG
void Cexp112View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp112View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp112Doc* Cexp112View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp112Doc)));
	return (Cexp112Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp112View 消息处理程序


void Cexp112View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	MyDlg0 dlg;
	int r = dlg.DoModal();

	if (r == IDOK)
	{

	}

	CView::OnLButtonDblClk(nFlags, point);
}

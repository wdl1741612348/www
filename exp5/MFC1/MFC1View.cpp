
// MFC1View.cpp : CMFC1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC1.h"
#endif

#include "MFC1Doc.h"
#include "MFC1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC1View

IMPLEMENT_DYNCREATE(CMFC1View, CView)

BEGIN_MESSAGE_MAP(CMFC1View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
//	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFC1View 构造/析构

CMFC1View::CMFC1View()
{
	// TODO: 在此处添加构造代码

}

CMFC1View::~CMFC1View()
{
}

BOOL CMFC1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC1View 绘制

void CMFC1View::OnDraw(CDC* pDC)
{
	CMFC1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDC->Rectangle(pDoc->m_tagRec);

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC1View 诊断

#ifdef _DEBUG
void CMFC1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC1Doc* CMFC1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC1Doc)));
	return (CMFC1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC1View 消息处理程序


void CMFC1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC1Doc*pDoc = GetDocument();

		pDoc->m_tagRec.left = point.x;
	    pDoc->m_tagRec.top = point.y;

	CView::OnLButtonDown(nFlags, point);

}


void CMFC1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC1Doc*pDoc = GetDocument();

	pDoc->m_tagRec.right= point.x;
	pDoc->m_tagRec.bottom = point.y;
	CClientDC dc(this);
	dc.Rectangle(pDoc->m_tagRec);
	CView::OnLButtonUp(nFlags, point);
}





void CMFC1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CString s;
	s.Format(_T("X=%d  Y=%d  "), point.x, point.y);
	dc.TextOutW(50, 50, s);
	CView::OnMouseMove(nFlags, point);
}

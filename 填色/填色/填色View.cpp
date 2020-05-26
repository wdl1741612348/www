
// 填色View.cpp : C填色View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "填色.h"
#endif

#include "填色Doc.h"
#include "填色View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C填色View

IMPLEMENT_DYNCREATE(C填色View, CView)

BEGIN_MESSAGE_MAP(C填色View, CView)
END_MESSAGE_MAP()

// C填色View 构造/析构

C填色View::C填色View()
{
	// TODO: 在此处添加构造代码

}

C填色View::~C填色View()
{
}

BOOL C填色View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C填色View 绘制

void C填色View::OnDraw(CDC* pDC)
{
	C填色Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect cr;
	this->GetClientRect(&cr);
	int color = RGB(220,230,200);
	CBrush newBrush(color);
	CBrush *oldBrush = pDC->SelectObject(&newBrush);
	pDC->Ellipse(cr);
	pDC->SelectObject(oldBrush);
}


// C填色View 诊断

#ifdef _DEBUG
void C填色View::AssertValid() const
{
	CView::AssertValid();
}

void C填色View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C填色Doc* C填色View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C填色Doc)));
	return (C填色Doc*)m_pDocument;
}
#endif //_DEBUG


// C填色View 消息处理程序

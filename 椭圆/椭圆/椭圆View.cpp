
// 椭圆View.cpp : C椭圆View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "椭圆.h"
#endif

#include "椭圆Doc.h"
#include "椭圆View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C椭圆View

IMPLEMENT_DYNCREATE(C椭圆View, CView)

BEGIN_MESSAGE_MAP(C椭圆View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C椭圆View 构造/析构

C椭圆View::C椭圆View()
{
	// TODO: 在此处添加构造代码

}

C椭圆View::~C椭圆View()
{
}

BOOL C椭圆View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C椭圆View 绘制

void C椭圆View::OnDraw(CDC* /*pDC*/)
{
	C椭圆Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: 在此处为本机数据添加绘制代码

}


// C椭圆View 诊断

#ifdef _DEBUG
void C椭圆View::AssertValid() const
{
	CView::AssertValid();
}

void C椭圆View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C椭圆Doc* C椭圆View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C椭圆Doc)));
	return (C椭圆Doc*)m_pDocument;
}
#endif //_DEBUG


// C椭圆View 消息处理程序


void C椭圆View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect cr;
	this->GetClientRect(&cr);   //视图类的成员函数
	CClientDC dc(this);  //构造一个客户区dc，带有参数（与视图客户区相关联）,this是视图类的指针
	dc.Ellipse(cr);
	CView::OnLButtonDown(nFlags, point);
}


// exp81View.cpp : Cexp81View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp81.h"
#endif

#include "exp81Doc.h"
#include "exp81View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp81View

IMPLEMENT_DYNCREATE(Cexp81View, CView)

BEGIN_MESSAGE_MAP(Cexp81View, CView)
	ON_COMMAND(ID_SHOWNAME, &Cexp81View::OnShowname)
END_MESSAGE_MAP()

// Cexp81View 构造/析构

Cexp81View::Cexp81View()
{
	// TODO: 在此处添加构造代码

}

Cexp81View::~Cexp81View()
{
}

BOOL Cexp81View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp81View 绘制

void Cexp81View::OnDraw(CDC* /*pDC*/)
{
	Cexp81Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Cexp81View 诊断

#ifdef _DEBUG
void Cexp81View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp81View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp81Doc* Cexp81View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp81Doc)));
	return (Cexp81Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp81View 消息处理程序


void Cexp81View::OnShowname()
{
	// TODO: 在此添加命令处理程序代码
	CString s;
	s = _T("吴东林");
	CClientDC dc(this);
	dc.TextOutW(50,50,s);
}

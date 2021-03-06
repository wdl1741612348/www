
// exp111View.cpp : Cexp111View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp111.h"
#endif

#include "exp111Doc.h"
#include "exp111View.h"
#include "MyDlgO.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp111View

IMPLEMENT_DYNCREATE(Cexp111View, CView)

BEGIN_MESSAGE_MAP(Cexp111View, CView)
	ON_COMMAND(ID_POPOUT, &Cexp111View::OnPopout)
END_MESSAGE_MAP()

// Cexp111View 构造/析构

Cexp111View::Cexp111View()
{
	// TODO: 在此处添加构造代码

}

Cexp111View::~Cexp111View()
{
}

BOOL Cexp111View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp111View 绘制

void Cexp111View::OnDraw(CDC* /*pDC*/)
{
	Cexp111Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Cexp111View 诊断

#ifdef _DEBUG
void Cexp111View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp111View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp111Doc* Cexp111View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp111Doc)));
	return (Cexp111Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp111View 消息处理程序


void Cexp111View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	MyDlgO dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		CClientDC dc(this);
		CString s = _T("你已退出对话框");
		dc.TextOutW(200,300,s);
	}
}

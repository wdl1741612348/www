
// exp12-4View.cpp : Cexp124View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp12-4.h"
#endif

#include "exp12-4Doc.h"
#include "exp12-4View.h"
#include "Mydlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp124View

IMPLEMENT_DYNCREATE(Cexp124View, CView)

BEGIN_MESSAGE_MAP(Cexp124View, CView)
	ON_COMMAND(ID_POPUP, &Cexp124View::OnPopup)
END_MESSAGE_MAP()

// Cexp124View 构造/析构

Cexp124View::Cexp124View()
{
	// TODO: 在此处添加构造代码

}

Cexp124View::~Cexp124View()
{
}

BOOL Cexp124View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp124View 绘制

void Cexp124View::OnDraw(CDC* /*pDC*/)
{
	Cexp124Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Cexp124View 诊断

#ifdef _DEBUG
void Cexp124View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp124View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp124Doc* Cexp124View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp124Doc)));
	return (Cexp124Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp124View 消息处理程序


void Cexp124View::OnPopup()
{
	// TODO: 在此添加命令处理程序代码
	Mydlg dlg;
	dlg.DoModal();
}


// exp12-2View.cpp : Cexp122View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp12-2.h"
#endif

#include "exp12-2Doc.h"
#include "exp12-2View.h"
#include "Calculator.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp122View

IMPLEMENT_DYNCREATE(Cexp122View, CView)

BEGIN_MESSAGE_MAP(Cexp122View, CView)
	ON_COMMAND(ID_POPUP, &Cexp122View::OnPopup)
END_MESSAGE_MAP()

// Cexp122View 构造/析构

Cexp122View::Cexp122View()
{
	// TODO: 在此处添加构造代码

}

Cexp122View::~Cexp122View()
{
}

BOOL Cexp122View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp122View 绘制

void Cexp122View::OnDraw(CDC* /*pDC*/)
{
	Cexp122Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Cexp122View 诊断

#ifdef _DEBUG
void Cexp122View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp122View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp122Doc* Cexp122View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp122Doc)));
	return (Cexp122Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp122View 消息处理程序


void Cexp122View::OnPopup()
{
	// TODO: 在此添加命令处理程序代码
	Calculator dlg;
	int r = dlg.DoModal();
}

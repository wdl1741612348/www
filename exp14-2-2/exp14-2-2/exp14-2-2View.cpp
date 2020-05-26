
// exp14-2-2View.cpp : Cexp1422View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp14-2-2.h"
#endif

#include "exp14-2-2Doc.h"
#include "exp14-2-2View.h"
#include "Mydlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp1422View

IMPLEMENT_DYNCREATE(Cexp1422View, CView)

BEGIN_MESSAGE_MAP(Cexp1422View, CView)
	ON_COMMAND(ID_Popout, &Cexp1422View::OnPopout)
END_MESSAGE_MAP()

// Cexp1422View 构造/析构

Cexp1422View::Cexp1422View()
{
	// TODO: 在此处添加构造代码

}

Cexp1422View::~Cexp1422View()
{
}

BOOL Cexp1422View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp1422View 绘制

void Cexp1422View::OnDraw(CDC* /*pDC*/)
{
	Cexp1422Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Cexp1422View 诊断

#ifdef _DEBUG
void Cexp1422View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp1422View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp1422Doc* Cexp1422View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp1422Doc)));
	return (Cexp1422Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp1422View 消息处理程序


void Cexp1422View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	Mydlg dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		cr.left = dlg.p_lx;
		cr.top = dlg.p_ly;
		cr.bottom = dlg.p_ry;
		cr.right = dlg.p_rx;
		GetDC()->Ellipse(cr);
	}

}

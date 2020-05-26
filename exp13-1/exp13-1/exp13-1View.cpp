
// exp13-1View.cpp : Cexp131View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp13-1.h"
#endif

#include "exp13-1Doc.h"
#include "exp13-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp131View

IMPLEMENT_DYNCREATE(Cexp131View, CView)

BEGIN_MESSAGE_MAP(Cexp131View, CView)
	ON_COMMAND(ID_FILE_OPEN, &Cexp131View::OnFileOpen)
END_MESSAGE_MAP()

// Cexp131View 构造/析构

Cexp131View::Cexp131View()
{
	// TODO: 在此处添加构造代码

}

Cexp131View::~Cexp131View()
{
}

BOOL Cexp131View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp131View 绘制

void Cexp131View::OnDraw(CDC* /*pDC*/)
{
	Cexp131Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Cexp131View 诊断

#ifdef _DEBUG
void Cexp131View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp131View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp131Doc* Cexp131View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp131Doc)));
	return (Cexp131Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp131View 消息处理程序


void Cexp131View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		CString filename = cfd.GetFileName();
		GetDC()->TextOutW(200,100,filename);
	}
}

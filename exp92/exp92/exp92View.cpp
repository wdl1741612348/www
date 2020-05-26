
// exp92View.cpp : Cexp92View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp92.h"
#endif

#include "exp92Doc.h"
#include "exp92View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp92View

IMPLEMENT_DYNCREATE(Cexp92View, CView)

BEGIN_MESSAGE_MAP(Cexp92View, CView)
	ON_COMMAND(ID_FILE_OPEN, &Cexp92View::OnFileOpen)
END_MESSAGE_MAP()

// Cexp92View 构造/析构

Cexp92View::Cexp92View()
{
	// TODO: 在此处添加构造代码
	i = 0;
}

Cexp92View::~Cexp92View()
{
}

BOOL Cexp92View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp92View 绘制

void Cexp92View::OnDraw(CDC* pDC)
{
	Cexp92Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (i == 1)
	{
		img.Draw(pDC->m_hDC, sx, sy, img.GetWidth(), img.GetHeight());
		pDC->TextOutW(50, 50, filename);
	}
}


// Cexp92View 诊断

#ifdef _DEBUG
void Cexp92View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp92View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp92Doc* Cexp92View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp92Doc)));
	return (Cexp92Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp92View 消息处理程序


void Cexp92View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);  
	int r = cfd.DoModal();  
	CClientDC dc(this);
	i = 1;
	if (r == IDOK)  
	{
		filename = cfd.GetPathName(); 
		img.Load(filename);  
		CRect rect;
		GetClientRect(&rect);

		sx = (rect.Width() - img.GetWidth()) / 2;
		sy = (rect.Height() - img.GetHeight()) / 2;

		Invalidate();
	}
}

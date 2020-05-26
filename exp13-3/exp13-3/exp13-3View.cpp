
// exp13-3View.cpp : Cexp133View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp13-3.h"
#endif

#include "exp13-3Doc.h"
#include "exp13-3View.h"
#include "MyDlg00.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp133View

IMPLEMENT_DYNCREATE(Cexp133View, CView)

BEGIN_MESSAGE_MAP(Cexp133View, CView)
	ON_COMMAND(ID_POPOUT, &Cexp133View::OnPopout)
	ON_COMMAND(ID_FILE_OPEN, &Cexp133View::OnFileOpen)
END_MESSAGE_MAP()

// Cexp133View 构造/析构

Cexp133View::Cexp133View()
{
	// TODO: 在此处添加构造代码

}

Cexp133View::~Cexp133View()
{
}

BOOL Cexp133View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp133View 绘制

void Cexp133View::OnDraw(CDC* /*pDC*/)
{
	Cexp133Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Cexp133View 诊断

#ifdef _DEBUG
void Cexp133View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp133View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp133Doc* Cexp133View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp133Doc)));
	return (Cexp133Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp133View 消息处理程序


void Cexp133View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg00 dlg;
//	dlg.Lbox.AddString(s);
	dlg.ss = s;
	int r = dlg.DoModal();
}


void Cexp133View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog fdlg(true);
	int r=fdlg.DoModal();
	if (r == IDOK)
	{
		s = fdlg.GetFileName();
	}
}


// exp13-2View.cpp : Cexp132View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp13-2.h"
#endif

#include "exp13-2Doc.h"
#include "exp13-2View.h"
#include "MyDlg0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp132View

IMPLEMENT_DYNCREATE(Cexp132View, CView)

BEGIN_MESSAGE_MAP(Cexp132View, CView)
	ON_COMMAND(ID_POPUP, &Cexp132View::OnPopup)
	ON_COMMAND(ID_FILE_OPEN, &Cexp132View::OnFileOpen)
END_MESSAGE_MAP()

// Cexp132View 构造/析构

Cexp132View::Cexp132View()
{
	// TODO: 在此处添加构造代码

}

Cexp132View::~Cexp132View()
{
}

BOOL Cexp132View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp132View 绘制

void Cexp132View::OnDraw(CDC* /*pDC*/)
{
	Cexp132Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Cexp132View 诊断

#ifdef _DEBUG
void Cexp132View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp132View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp132Doc* Cexp132View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp132Doc)));
	return (Cexp132Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp132View 消息处理程序


void Cexp132View::OnPopup()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg0 dlg;	
	dlg.s = filename;
	int r=dlg.DoModal();
}


void Cexp132View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog fdlg(true);
	int r = fdlg.DoModal();
	if (r == IDOK)
	{
		filename = fdlg.GetFileName();
		GetDC()->TextOutW(100,200,filename);
	}
}

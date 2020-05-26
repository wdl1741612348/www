
// exp15-2View.cpp : Cexp152View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp15-2.h"
#endif
#include "Mydlg.h"
#include <fstream>
#include<string>
#include<stdlib.h>
using namespace std;

#include "exp15-2Doc.h"
#include "exp15-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp152View

IMPLEMENT_DYNCREATE(Cexp152View, CView)

BEGIN_MESSAGE_MAP(Cexp152View, CView)
	ON_COMMAND(ID_FILE_OPEN, &Cexp152View::OnFileOpen)
END_MESSAGE_MAP()

// Cexp152View 构造/析构

Cexp152View::Cexp152View()
{
	// TODO: 在此处添加构造代码

}

Cexp152View::~Cexp152View()
{
}

BOOL Cexp152View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp152View 绘制

void Cexp152View::OnDraw(CDC* /*pDC*/)
{
	Cexp152Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Cexp152View 诊断

#ifdef _DEBUG
void Cexp152View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp152View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp152Doc* Cexp152View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp152Doc)));
	return (Cexp152Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp152View 消息处理程序

void Cexp152View::foo(CImage &img, int &sx, int &sy, int &w, int &h)
{
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
	float cr_ratio = 1.0*cr.Width() / cr.Height();
	float img_ratio= 1.0*img.GetWidth() / img.GetHeight();
	if (cr_ratio > img_ratio)
	{
		h = cr.Height();
		w = img_ratio*h;
		sx = (cr_ratio - img_ratio) / 2;
		sy = 0;
	}
	else
	{
		w = cr.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (cr.Height() - h) / 2;

	}
}

void Cexp152View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	Mydlg dlg;
	string filename;
	CImage img;
	if (r == IDOK)
	{
		ifstream ifs(cfd.GetPathName());
        dlg.DoModal();
		while (ifs >> filename)
		{
			img.Load(CString(filename.c_str()));
			int sx, sy, w, h;
			foo(img,sx,sy,w,h);
			CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
			img.Draw(pDC->m_hDC,sx,sy,w,h);
			ReleaseDC(pDC);
		}

	}

	
} 

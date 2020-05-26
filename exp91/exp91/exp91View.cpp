
// exp91View.cpp : Cexp91View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp91.h"
#endif

#include "exp91Doc.h"
#include "exp91View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp91View

IMPLEMENT_DYNCREATE(Cexp91View, CView)

BEGIN_MESSAGE_MAP(Cexp91View, CView)
	ON_COMMAND(ID_FILE_OPEN, &Cexp91View::OnFileOpen)
END_MESSAGE_MAP()

// Cexp91View 构造/析构

Cexp91View::Cexp91View()
{
	// TODO: 在此处添加构造代码

}

Cexp91View::~Cexp91View()
{
}

BOOL Cexp91View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp91View 绘制

void Cexp91View::OnDraw(CDC* pDC)
{
	Cexp91Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

}


// Cexp91View 诊断

#ifdef _DEBUG
void Cexp91View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp91View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp91Doc* Cexp91View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp91Doc)));
	return (Cexp91Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp91View 消息处理程序


void Cexp91View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);  //ture为打开 , false为另存为
	int r = cfd.DoModal();  //domodal函数是弹出独立对话框，取得返回值给r
	CClientDC dc(this);

	if (r == IDOK)  //返回值为IDOK，表示点击“确定”退出
	{
		CString filename;
		filename = cfd.GetPathName(); //路径名
		CImage img;
		img.Load(filename);  //图片文件与CImage相关联
        int sx,sy;		
		CRect rect;
		GetClientRect(&rect);

		sx = (rect.Width() - img.GetWidth()) / 2;
		sy = (rect.Height() - img.GetHeight()) / 2;

		img.Draw(dc.m_hDC, sx, sy, img.GetWidth(), img.GetHeight());
		dc.TextOutW(50, 50, filename);

	}
}

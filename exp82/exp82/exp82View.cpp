
// exp82View.cpp : Cexp82View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp82.h"
#endif

#include "exp82Doc.h"
#include "exp82View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp82View

IMPLEMENT_DYNCREATE(Cexp82View, CView)

BEGIN_MESSAGE_MAP(Cexp82View, CView)
END_MESSAGE_MAP()

// Cexp82View 构造/析构

Cexp82View::Cexp82View()
{
	// TODO: 在此处添加构造代码
	BITMAP BM;
	m_Bitmap.LoadBitmapW(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;
}

Cexp82View::~Cexp82View()
{
}

BOOL Cexp82View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp82View 绘制

void Cexp82View::OnDraw(CDC* pDC)
{
	Cexp82Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);
}


// Cexp82View 诊断

#ifdef _DEBUG
void Cexp82View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp82View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp82Doc* Cexp82View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp82Doc)));
	return (Cexp82Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp82View 消息处理程序

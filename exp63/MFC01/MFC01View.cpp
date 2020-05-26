
// MFC01View.cpp : CMFC01View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC01.h"
#endif

#include "MFC01Doc.h"
#include "MFC01View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC01View

IMPLEMENT_DYNCREATE(CMFC01View, CView)

BEGIN_MESSAGE_MAP(CMFC01View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC01View 构造/析构

CMFC01View::CMFC01View()
{
	// TODO: 在此处添加构造代码
	set = true;
	N = 5;
	
	for (int i = 0; i < N; i++)
	{
		int t = (i + 1) * 200;  //每一个圆的左上角的位置
		CRect rect(t, 0, t + 80, 80);  //左上角的坐标，和右下角的坐标
		cr.Add(rect);
		K = 0;
	}

}

CMFC01View::~CMFC01View()
{
}

BOOL CMFC01View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC01View 绘制

void CMFC01View::OnDraw(CDC* pDC)
{
	CMFC01Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc)
		return;
	if (set)
	{
		for (int i = 0; i < N; i++)
		{
			SetTimer(i, rand() % 400 + 100, NULL); //第i个计时器；以毫秒计算，1000毫秒等于一秒；
		}
		set = false;
	}
	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < N; i++)
	{
		pDC->Ellipse(cr[i]);
	}
}


// CMFC01View 诊断

#ifdef _DEBUG
void CMFC01View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC01View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC01Doc* CMFC01View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC01Doc)));
	return (CMFC01Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC01View 消息处理程序


void CMFC01View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int i = nIDEvent; //表示是第几个计时器
	CRect m_cr;
	GetClientRect(&m_cr);
	if (cr[i].bottom < m_cr.bottom && K== 0)
	{
		cr[i].top += 10;
		cr[i].bottom += 10;
		Invalidate();
	}
	if (cr[i].bottom > m_cr.bottom || cr[i].bottom == m_cr.bottom)

		K = 1;

	if (cr[i].top > m_cr.top && K == 1)
	{
		cr[i].top -= 10;
		cr[i].bottom -= 10;
		Invalidate();
	}

	CView::OnTimer(nIDEvent);
}

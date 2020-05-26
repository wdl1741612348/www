
// exp12-1View.cpp : Cexp121View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp12-1.h"
#endif

#include "exp12-1Doc.h"
#include "exp12-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp121View

IMPLEMENT_DYNCREATE(Cexp121View, CView)

BEGIN_MESSAGE_MAP(Cexp121View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Cexp121View ����/����

Cexp121View::Cexp121View()
{
	// TODO: �ڴ˴���ӹ������
	N = 0;
	cr.top = 100; cr.left = 100;
	cr.bottom = 200; cr.right = 300;
}

Cexp121View::~Cexp121View()
{
}

BOOL Cexp121View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp121View ����

void Cexp121View::OnDraw(CDC* pDC)
{
	Cexp121Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(cr);
}


// Cexp121View ���

#ifdef _DEBUG
void Cexp121View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp121View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp121Doc* Cexp121View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp121Doc)));
	return (Cexp121Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp121View ��Ϣ�������


void Cexp121View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	N = 1;
	a=cr.bottom - point.y; b= point.y - cr.top;
	c= point.x - cr.left; d=cr.right - point.x ;

	CView::OnLButtonDown(nFlags, point);
}


void Cexp121View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	N = 0;
	cr.bottom = point.y + a; cr.top = point.y - b;
	cr.left = point.x - c; cr.right = point.x + d;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void Cexp121View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (N == 1)
	{
		cr.bottom = point.y + 50; cr.top = point.y - 50;
		cr.left = point.x - 100; cr.right = point.x + 100;
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}

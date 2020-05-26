
// exp14-2-1View.cpp : Cexp1421View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp14-2-1.h"
#endif

#include "exp14-2-1Doc.h"
#include "exp14-2-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp1421View

IMPLEMENT_DYNCREATE(Cexp1421View, CView)

BEGIN_MESSAGE_MAP(Cexp1421View, CView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// Cexp1421View ����/����

Cexp1421View::Cexp1421View()
{
	// TODO: �ڴ˴���ӹ������
	cr.bottom =300 ; cr.right = 300;
	cr.top = 100; cr.left = 150;
	set = false;
}

Cexp1421View::~Cexp1421View()
{
}

BOOL Cexp1421View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp1421View ����

void Cexp1421View::OnDraw(CDC* pDC)
{
	Cexp1421Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Ellipse(cr);
}


// Cexp1421View ���

#ifdef _DEBUG
void Cexp1421View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp1421View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp1421Doc* Cexp1421View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp1421Doc)));
	return (Cexp1421Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp1421View ��Ϣ�������

void Cexp1421View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set = true;
	a = point.y - cr.top;
	b = cr.bottom - point.y;
	c = point.x - cr.left;
	d = cr.right - point.x;
	CView::OnLButtonDown(nFlags, point);
}


void Cexp1421View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (set)
	{
		cr.top = point.y - a;
		cr.bottom = point.y + b;
		cr.left = point.x - c;
		cr.right = point.x + d;
	}
    Invalidate();
	CView::OnMouseMove(nFlags, point);
}





void Cexp1421View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set = false;
	CView::OnLButtonUp(nFlags, point);
}

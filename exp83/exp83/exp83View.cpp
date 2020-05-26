
// exp83View.cpp : Cexp83View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp83.h"
#endif

#include "exp83Doc.h"
#include "exp83View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp83View

IMPLEMENT_DYNCREATE(Cexp83View, CView)

BEGIN_MESSAGE_MAP(Cexp83View, CView)
	ON_COMMAND(ID_DRAWLINE, &Cexp83View::OnDrawline)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_DRAWRECTANGLE, &Cexp83View::OnDrawrectangle)
	ON_COMMAND(ID_DRAWCIRCLE, &Cexp83View::OnDrawcircle)
END_MESSAGE_MAP()

// Cexp83View ����/����

Cexp83View::Cexp83View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp83View::~Cexp83View()
{
}

BOOL Cexp83View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp83View ����

void Cexp83View::OnDraw(CDC* pDC)
{
	Cexp83Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (k == 1)
	{
		pDC->MoveTo(a.x, a.y);
		pDC->LineTo(b.x, b.y);
	}
	if (k == 2)
	{
		CRect m_cr;
		m_cr.left = a.x;
		m_cr.top = a.y;
		m_cr.right = b.x;
		m_cr.bottom = b.y;
		pDC->Rectangle(m_cr);
	}
	if (k == 3)
	{
		CRect cr;
		cr.left = a.x;
		cr.top = a.y;
		cr.right = b.x;
		cr.bottom = b.y;
		pDC->Ellipse(cr);
	}

}


// Cexp83View ���

#ifdef _DEBUG
void Cexp83View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp83View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp83Doc* Cexp83View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp83Doc)));
	return (Cexp83Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp83View ��Ϣ�������


void Cexp83View::OnDrawline()
{
	// TODO: �ڴ���������������
	k = 1;
}


void Cexp83View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    	a.x = point.x;
		a.y = point.y;

	CView::OnLButtonDown(nFlags, point);
}



void Cexp83View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	b.x= point.x;
	b.y = point.y;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void Cexp83View::OnDrawrectangle()
{
	k = 2;
	// TODO: �ڴ���������������
}


void Cexp83View::OnDrawcircle()
{
	k = 3;
	// TODO: �ڴ���������������
}

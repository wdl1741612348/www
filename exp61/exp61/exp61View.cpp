
// exp61View.cpp : Cexp61View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp61.h"
#endif

#include "exp61Doc.h"
#include "exp61View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp61View

IMPLEMENT_DYNCREATE(Cexp61View, CView)

BEGIN_MESSAGE_MAP(Cexp61View, CView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// Cexp61View ����/����

Cexp61View::Cexp61View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp61View::~Cexp61View()
{
}

BOOL Cexp61View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp61View ����

void Cexp61View::OnDraw(CDC* pDC)
{
	Cexp61Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->TextOutW(50, 70, pDoc->s2);
	pDC->TextOutW(50, 50, pDoc->s1);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

}


// Cexp61View ���

#ifdef _DEBUG
void Cexp61View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp61View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp61Doc* Cexp61View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp61Doc)));
	return (Cexp61Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp61View ��Ϣ�������


void Cexp61View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cexp61Doc* pDoc = GetDocument();
	pDoc->i++;
	CView::OnMouseMove(nFlags, point);
}


void Cexp61View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cexp61Doc* pDoc = GetDocument();
	pDoc->a_point=point;
	CView::OnLButtonDown(nFlags, point);
}


void Cexp61View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cexp61Doc* pDoc = GetDocument();
	CClientDC dc(this);
	pDoc->b_point=point;
	int x;
	pDoc->s1.Format(_T("MouseMove������%d ��"), pDoc->i);	
	x = (pDoc->b_point.x - pDoc->a_point.x) / pDoc->i;
	pDoc->s2.Format(_T("�����ƶ�%d�����ط���һ��"), x);	
	pDoc->i = 0;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);

}

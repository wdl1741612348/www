
// ecp72View.cpp : Cecp72View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ecp72.h"
#endif

#include "ecp72Doc.h"
#include "ecp72View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cecp72View

IMPLEMENT_DYNCREATE(Cecp72View, CView)

BEGIN_MESSAGE_MAP(Cecp72View, CView)
	ON_COMMAND(ID_DRAWCIRCLE, &Cecp72View::OnDrawcircle)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Cecp72View ����/����

Cecp72View::Cecp72View()
{
	// TODO: �ڴ˴���ӹ������
	set = true;
	N = 0;
	red = 0; green = 0; blue = 0;
}

Cecp72View::~Cecp72View()
{
}

BOOL Cecp72View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cecp72View ����

void Cecp72View::OnDraw(CDC* pDC)
{
	Cecp72Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (set)
	{
		SetTimer(0, rand() % 400 + 100, NULL);
		set = false;
	}
	if (N == 1)
	{
		color = RGB(red,green,blue);
		CBrush newBrush(color);
		CBrush *oldBrush = pDC->SelectObject(&newBrush);
		pDC->Ellipse(pDoc->cr);
		pDC->SelectObject(oldBrush);
		red += 32;
		green += 16;
		blue += 8;
	}
}


// Cecp72View ���

#ifdef _DEBUG
void Cecp72View::AssertValid() const
{
	CView::AssertValid();
}

void Cecp72View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cecp72Doc* Cecp72View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cecp72Doc)));
	return (Cecp72Doc*)m_pDocument;
}
#endif //_DEBUG


// Cecp72View ��Ϣ�������


void Cecp72View::OnDrawcircle()
{
	// TODO: �ڴ���������������
	Cecp72Doc* pDoc = GetDocument();
	CRect clientRec;
	int a, b;  N = 1;
	GetClientRect(&clientRec);
	a = (clientRec.right - clientRec.left) / 2;
	b = (clientRec.bottom - clientRec.top) / 2;
	pDoc->cr.left = a - 50;
	pDoc->cr.top = b - 50;
	pDoc->cr.right = a + 50;
	pDoc->cr.bottom = b + 50;

    CClientDC dc(this);
	CBrush newBrush(color);
	CBrush *oldBrush = dc.SelectObject(&newBrush);
	dc.Ellipse(pDoc->cr);
	dc.SelectObject(oldBrush);
	red += 32;
	green += 16;
	blue += 8;
}


void Cecp72View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cecp72Doc* pDoc = GetDocument();
	pDoc->cr.top -= 10;
	pDoc->cr.left -= 10;
	pDoc->cr.right += 10;
	pDoc->cr.bottom += 10;
	Invalidate();
	CView::OnTimer(nIDEvent);
}


// exp71View.cpp : Cexp71View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp71.h"
#endif

#include "exp71Doc.h"
#include "exp71View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp71View

IMPLEMENT_DYNCREATE(Cexp71View, CView)

BEGIN_MESSAGE_MAP(Cexp71View, CView)
	ON_COMMAND(ID_DRAWCIRCLE, &Cexp71View::OnDrawcircle)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Cexp71View ����/����

Cexp71View::Cexp71View()
{
	// TODO: �ڴ˴���ӹ������
	set = true;
	N = 0;

}

Cexp71View::~Cexp71View()
{
}

BOOL Cexp71View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp71View ����

void Cexp71View::OnDraw(CDC* pDC)
{
	Cexp71Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (set)
	{
		SetTimer(0, rand() % 400 + 100, NULL);
		set = false;
	}
	if(N==1)
	pDC->Ellipse(pDoc->cr);
}


// Cexp71View ���

#ifdef _DEBUG
void Cexp71View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp71View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp71Doc* Cexp71View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp71Doc)));
	return (Cexp71Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp71View ��Ϣ�������


void Cexp71View::OnDrawcircle()
{
	// TODO: �ڴ���������������
	Cexp71Doc* pDoc = GetDocument();
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
	dc.Ellipse(pDoc->cr);
	

}


void Cexp71View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cexp71Doc* pDoc = GetDocument();
	pDoc->cr.top -= 10;
	pDoc->cr.left -= 10;
	pDoc->cr.right += 10;
	pDoc->cr.bottom += 10;
	Invalidate();
	CView::OnTimer(nIDEvent);
}


// exp62View.cpp : Cexp62View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp62.h"
#endif

#include "exp62Doc.h"
#include "exp62View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp62View

IMPLEMENT_DYNCREATE(Cexp62View, CView)

BEGIN_MESSAGE_MAP(Cexp62View, CView)
	ON_WM_KEYDOWN()
//	ON_WM_CHAR()
ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp62View ����/����

Cexp62View::Cexp62View()
{
	// TODO: �ڴ˴���ӹ������
	i = 0;
}

Cexp62View::~Cexp62View()
{
}

BOOL Cexp62View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp62View ����

void Cexp62View::OnDraw(CDC* pDC)
{
	Cexp62Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect clientRec;
	int a, b;
	GetClientRect(&clientRec);
	if (i == 0)
	{
		a = (clientRec.right - clientRec.left) / 2;
		b = (clientRec.bottom - clientRec.top) / 2;

		pDoc->cr.left = a - 100;
		pDoc->cr.top = b - 50;
		pDoc->cr.right = a + 100;
		pDoc->cr.bottom = b + 50;
	}
	pDC->Rectangle(pDoc->cr);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp62View ���

#ifdef _DEBUG
void Cexp62View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp62View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp62Doc* Cexp62View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp62Doc)));
	return (Cexp62Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp62View ��Ϣ�������


void Cexp62View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cexp62Doc* pDoc = GetDocument();
	i = 1;
	switch(nChar)
	{
	case VK_LEFT:
		pDoc->cr.left -= 20;
		pDoc->cr.right -= 20;
		break;
	case VK_RIGHT:
		pDoc->cr.left+= 20;
		pDoc->cr.right += 20;
		break;
	case VK_DOWN:
		pDoc->cr.top += 10;
		pDoc->cr.bottom += 10;
		break;
	case VK_UP:
		pDoc->cr.top -= 10;
		pDoc->cr.bottom -= 10;
		break;
	case VK_HOME:
		pDoc->cr.top += 10;
		pDoc->cr.left += 10;
		break;
	case VK_END:
		pDoc->cr.bottom -= 10;
		pDoc->cr.right -= 10;
		break;
	}
	
	CClientDC dc(this);
	dc.Rectangle(pDoc->cr);
	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}



void Cexp62View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	i = 0;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}

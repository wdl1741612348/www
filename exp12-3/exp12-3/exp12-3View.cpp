
// exp12-3View.cpp : Cexp123View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp12-3.h"
#endif

#include "exp12-3Doc.h"
#include "exp12-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp123View

IMPLEMENT_DYNCREATE(Cexp123View, CView)

BEGIN_MESSAGE_MAP(Cexp123View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Cexp123View ����/����

Cexp123View::Cexp123View()
{
	// TODO: �ڴ˴���ӹ������
	N = 0;
	set1 = false;
	set2 = false;
}

Cexp123View::~Cexp123View()
{
}

BOOL Cexp123View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp123View ����

void Cexp123View::OnDraw(CDC* pDC)
{
	Cexp123Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	GetClientRect(&rect);

	SetTimer(1,600,NULL);
	if (N == 0)
	{
		cr.top = (rect.bottom - rect.top) / 2 - 50;
		cr.left = 0;
		cr.bottom = (rect.bottom - rect.top) / 2 + 50;
		cr.right = 100;
		N = 1;
	}

	if (set2)
	{
		KillTimer (1);
		SetTimer(2,600,NULL);
	}
	pDC->Ellipse(&cr);
}


// Cexp123View ���

#ifdef _DEBUG
void Cexp123View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp123View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp123Doc* Cexp123View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp123Doc)));
	return (Cexp123Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp123View ��Ϣ�������


void Cexp123View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set1 = true;

	CView::OnLButtonDown(nFlags, point);
}


void Cexp123View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set1 = false;
	CView::OnLButtonDblClk(nFlags, point);
}


void Cexp123View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch (nIDEvent)
	{
	case 1:
		if (set1)
		{
			if (cr.right <= rect.right)
			{
				cr.left += 50;
				cr.right += 50;
			}
			else  set2 = true;

		}break;
	case 2:
		if (set1)
		{

				cr.left -= 50;
				cr.right -= 50;

		}break;
	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}

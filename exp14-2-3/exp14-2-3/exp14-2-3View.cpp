
// exp14-2-3View.cpp : Cexp1423View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp14-2-3.h"
#endif

#include "exp14-2-3Doc.h"
#include "exp14-2-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp1423View

IMPLEMENT_DYNCREATE(Cexp1423View, CView)

BEGIN_MESSAGE_MAP(Cexp1423View, CView)
//	ON_WM_MBUTTONDOWN()
ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp1423View ����/����

Cexp1423View::Cexp1423View()
{
	// TODO: �ڴ˴���ӹ������
	cr.left = 200;
	cr.top = 200;
	cr.bottom = 500;
	cr.right = 400;
}

Cexp1423View::~Cexp1423View()
{
}

BOOL Cexp1423View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp1423View ����

void Cexp1423View::OnDraw(CDC* pDC)
{
	Cexp1423Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Ellipse(cr);
}


// Cexp1423View ���

#ifdef _DEBUG
void Cexp1423View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp1423View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp1423Doc* Cexp1423View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp1423Doc)));
	return (Cexp1423Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp1423View ��Ϣ�������




void Cexp1423View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (point.x<cr.right && point.x>cr.left && point.y<cr.bottom &&point.y>cr.top)
	{
		GetDC()->Rectangle(cr);
		Invalidate(false);
	}
	CView::OnLButtonDown(nFlags, point);
}

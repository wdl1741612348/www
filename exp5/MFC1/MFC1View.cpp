
// MFC1View.cpp : CMFC1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC1.h"
#endif

#include "MFC1Doc.h"
#include "MFC1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC1View

IMPLEMENT_DYNCREATE(CMFC1View, CView)

BEGIN_MESSAGE_MAP(CMFC1View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
//	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFC1View ����/����

CMFC1View::CMFC1View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC1View::~CMFC1View()
{
}

BOOL CMFC1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC1View ����

void CMFC1View::OnDraw(CDC* pDC)
{
	CMFC1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDC->Rectangle(pDoc->m_tagRec);

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC1View ���

#ifdef _DEBUG
void CMFC1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC1Doc* CMFC1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC1Doc)));
	return (CMFC1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC1View ��Ϣ�������


void CMFC1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC1Doc*pDoc = GetDocument();

		pDoc->m_tagRec.left = point.x;
	    pDoc->m_tagRec.top = point.y;

	CView::OnLButtonDown(nFlags, point);

}


void CMFC1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC1Doc*pDoc = GetDocument();

	pDoc->m_tagRec.right= point.x;
	pDoc->m_tagRec.bottom = point.y;
	CClientDC dc(this);
	dc.Rectangle(pDoc->m_tagRec);
	CView::OnLButtonUp(nFlags, point);
}





void CMFC1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CString s;
	s.Format(_T("X=%d  Y=%d  "), point.x, point.y);
	dc.TextOutW(50, 50, s);
	CView::OnMouseMove(nFlags, point);
}


// exp23View.cpp : Cexp23View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp23.h"
#endif

#include "exp23Doc.h"
#include "exp23View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp23View

IMPLEMENT_DYNCREATE(Cexp23View, CView)

BEGIN_MESSAGE_MAP(Cexp23View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp23View ����/����

Cexp23View::Cexp23View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp23View::~Cexp23View()
{
}

BOOL Cexp23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp23View ����

void Cexp23View::OnDraw(CDC* /*pDC*/)
{
	Cexp23Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

}


// Cexp23View ���

#ifdef _DEBUG
void Cexp23View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp23View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp23Doc* Cexp23View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp23Doc)));
	return (Cexp23Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp23View ��Ϣ�������


void Cexp23View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cexp23Doc* pDoc = GetDocument();
	pDoc->count= pDoc->count+1;

	CView::OnLButtonDown(nFlags, point);
}


void Cexp23View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cexp23Doc* pDoc = GetDocument();
	CClientDC dc(this);
	CString s;
	s.Format(_T("���һ�������%d��"), pDoc->count);
	dc.TextOutW(200, 200, s);

	CView::OnRButtonDown(nFlags, point);
}

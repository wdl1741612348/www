
// exp101View.cpp : Cexp101View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp101.h"
#endif

#include "exp101Doc.h"
#include "exp101View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp101View

IMPLEMENT_DYNCREATE(Cexp101View, CView)

BEGIN_MESSAGE_MAP(Cexp101View, CView)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// Cexp101View ����/����

Cexp101View::Cexp101View()
{
	// TODO: �ڴ˴���ӹ������
	a = 5;
	b = 50;
}

Cexp101View::~Cexp101View()
{
}

BOOL Cexp101View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp101View ����

void Cexp101View::OnDraw(CDC* pDC)
{
	Cexp101Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect m_cr;
	GetClientRect(&m_cr);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CRect cr(0,40,m_cr.right,80);
	pDC->Rectangle(cr);
	pDC->TextOutW(a, b, s);
}


// Cexp101View ���

#ifdef _DEBUG
void Cexp101View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp101View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp101Doc* Cexp101View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp101Doc)));
	return (Cexp101Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp101View ��Ϣ�������


void Cexp101View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ	
	s.Format(s + _T("%c"), nChar);
	Invalidate();

	CView::OnChar(nChar, nRepCnt, nFlags);
}

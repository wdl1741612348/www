
// exp17-1View.cpp : Cexp171View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp17-1.h"
#endif

#include "exp17-1Doc.h"
#include "exp17-1View.h"
#include"win32.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp171View

IMPLEMENT_DYNCREATE(Cexp171View, CView)

BEGIN_MESSAGE_MAP(Cexp171View, CView)
END_MESSAGE_MAP()

// Cexp171View ����/����

Cexp171View::Cexp171View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp171View::~Cexp171View()
{
}

BOOL Cexp171View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp171View ����

void Cexp171View::OnDraw(CDC* pDC)
{
	Cexp171Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString p;
	p.Format(_T("%d"),factorial(5));
	pDC->TextOutW(200,200,p);
}


// Cexp171View ���

#ifdef _DEBUG
void Cexp171View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp171View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp171Doc* Cexp171View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp171Doc)));
	return (Cexp171Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp171View ��Ϣ�������

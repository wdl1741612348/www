
// exp31View.cpp : Cexp31View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp31.h"
#endif

#include "exp31Doc.h"
#include "exp31View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp31View

IMPLEMENT_DYNCREATE(Cexp31View, CView)

BEGIN_MESSAGE_MAP(Cexp31View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp31View ����/����

Cexp31View::Cexp31View()
{
	
	// TODO: �ڴ˴���ӹ������

}

Cexp31View::~Cexp31View()
{
}

BOOL Cexp31View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp31View ����

void Cexp31View::OnDraw(CDC* pDC)
{
	Cexp31Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Ellipse(cr);
}


// Cexp31View ���

#ifdef _DEBUG
void Cexp31View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp31View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp31Doc* Cexp31View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp31Doc)));
	return (Cexp31Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp31View ��Ϣ�������


void Cexp31View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	this->GetClientRect(&cr);
	this->Invalidate();
	
	CView::OnLButtonDown(nFlags, point);
}

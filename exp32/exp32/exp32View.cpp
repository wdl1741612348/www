
// exp32View.cpp : Cexp32View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp32.h"
#endif

#include "exp32Doc.h"
#include "exp32View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp32View

IMPLEMENT_DYNCREATE(Cexp32View, CView)

BEGIN_MESSAGE_MAP(Cexp32View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp32View ����/����

Cexp32View::Cexp32View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp32View::~Cexp32View()
{
}

BOOL Cexp32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp32View ����

void Cexp32View::OnDraw(CDC* pDC)
{
	Cexp32Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	for(int i=0;i<pDoc->ca.GetSize();i++)
	pDC->Ellipse(pDoc->ca.GetAt(i));
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp32View ���

#ifdef _DEBUG
void Cexp32View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp32View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp32Doc* Cexp32View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp32Doc)));
	return (Cexp32Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp32View ��Ϣ�������


void Cexp32View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int a= rand()%100 +50 ;
	int b = rand() %100 + 50;
	Cexp32Doc* pDoc = GetDocument();
	CRect cr(point.x-a, point.y-b, point.x+a, point.y+b);
	pDoc->ca.Add(cr);
	this->Invalidate();
	CView::OnLButtonDown(nFlags, point);
}

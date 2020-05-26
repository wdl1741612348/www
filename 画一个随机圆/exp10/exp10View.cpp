
// exp10View.cpp : Cexp10View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp10.h"
#endif

#include "exp10Doc.h"
#include "exp10View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp10View

IMPLEMENT_DYNCREATE(Cexp10View, CView)

BEGIN_MESSAGE_MAP(Cexp10View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp10View ����/����
COLORREF color;
int penwidth;
Cexp10View::Cexp10View()
{
	// TODO: �ڴ˴���ӹ������
	ca.SetSize(256);
}

Cexp10View::~Cexp10View()
{

}

BOOL Cexp10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp10View ����

void Cexp10View::OnDraw(CDC* pDC)
{
	Cexp10Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	for (int i = 0; i < ca.GetSize(); i++)
		pDC->Ellipse(ca.GetAt(i)); //ȡ�������еĵ�i��Ԫ��
	

}


// Cexp10View ���

#ifdef _DEBUG
void Cexp10View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp10Doc* Cexp10View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp10Doc)));
	return (Cexp10Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp10View ��Ϣ�������


void Cexp10View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    int r = rand() % (200 - 100) + 100;
	CRect cr(point.x - r, point.y - r, point.x + r, point.y + r);
	ca.Add(cr);
	this->Invalidate();//ǿ���ػ�
	//CClientDC dc(this);
	//dc.Ellipse(cr);
	
	CView::OnLButtonDown(nFlags, point);
}

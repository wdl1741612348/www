
// ��ɫView.cpp : C��ɫView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ɫ.h"
#endif

#include "��ɫDoc.h"
#include "��ɫView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ɫView

IMPLEMENT_DYNCREATE(C��ɫView, CView)

BEGIN_MESSAGE_MAP(C��ɫView, CView)
END_MESSAGE_MAP()

// C��ɫView ����/����

C��ɫView::C��ɫView()
{
	// TODO: �ڴ˴���ӹ������

}

C��ɫView::~C��ɫView()
{
}

BOOL C��ɫView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��ɫView ����

void C��ɫView::OnDraw(CDC* pDC)
{
	C��ɫDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CRect cr;
	this->GetClientRect(&cr);
	int color = RGB(220,230,200);
	CBrush newBrush(color);
	CBrush *oldBrush = pDC->SelectObject(&newBrush);
	pDC->Ellipse(cr);
	pDC->SelectObject(oldBrush);
}


// C��ɫView ���

#ifdef _DEBUG
void C��ɫView::AssertValid() const
{
	CView::AssertValid();
}

void C��ɫView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��ɫDoc* C��ɫView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ɫDoc)));
	return (C��ɫDoc*)m_pDocument;
}
#endif //_DEBUG


// C��ɫView ��Ϣ�������


// exp112View.cpp : Cexp112View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp112.h"
#endif

#include "exp112Doc.h"
#include "exp112View.h"
#include "MyDlg0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp112View

IMPLEMENT_DYNCREATE(Cexp112View, CView)

BEGIN_MESSAGE_MAP(Cexp112View, CView)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// Cexp112View ����/����

Cexp112View::Cexp112View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp112View::~Cexp112View()
{
}

BOOL Cexp112View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp112View ����

void Cexp112View::OnDraw(CDC* /*pDC*/)
{
	Cexp112Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp112View ���

#ifdef _DEBUG
void Cexp112View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp112View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp112Doc* Cexp112View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp112Doc)));
	return (Cexp112Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp112View ��Ϣ�������


void Cexp112View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	MyDlg0 dlg;
	int r = dlg.DoModal();

	if (r == IDOK)
	{

	}

	CView::OnLButtonDblClk(nFlags, point);
}

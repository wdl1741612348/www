
// exp14-2-4View.cpp : Cexp1424View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp14-2-4.h"
#endif

#include "exp14-2-4Doc.h"
#include "exp14-2-4View.h"
#include "Mydlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp1424View

IMPLEMENT_DYNCREATE(Cexp1424View, CView)

BEGIN_MESSAGE_MAP(Cexp1424View, CView)
	ON_COMMAND(ID_Popout, &Cexp1424View::OnPopout)
END_MESSAGE_MAP()

// Cexp1424View ����/����

Cexp1424View::Cexp1424View()
{
	// TODO: �ڴ˴���ӹ������
	cr.left = 200;
	cr.right = 500;
	cr.top = 200;
	cr.bottom = 400;
}

Cexp1424View::~Cexp1424View()
{
}

BOOL Cexp1424View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp1424View ����

void Cexp1424View::OnDraw(CDC* pDC)
{
	Cexp1424Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Ellipse(cr);
}


// Cexp1424View ���

#ifdef _DEBUG
void Cexp1424View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp1424View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp1424Doc* Cexp1424View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp1424Doc)));
	return (Cexp1424Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp1424View ��Ϣ�������


void Cexp1424View::OnPopout()
{
	// TODO: �ڴ���������������
	Mydlg dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		CClientDC dc(this);
		int color = RGB(dlg.a,dlg.b,dlg.c);
		CBrush newBrush(color);
		CBrush *oldBrush= dc.SelectObject(&newBrush);
		dc.Ellipse(cr);
		GetDC()->SelectObject(oldBrush);
	}
}

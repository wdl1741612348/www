
// exp14-2-2View.cpp : Cexp1422View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp14-2-2.h"
#endif

#include "exp14-2-2Doc.h"
#include "exp14-2-2View.h"
#include "Mydlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp1422View

IMPLEMENT_DYNCREATE(Cexp1422View, CView)

BEGIN_MESSAGE_MAP(Cexp1422View, CView)
	ON_COMMAND(ID_Popout, &Cexp1422View::OnPopout)
END_MESSAGE_MAP()

// Cexp1422View ����/����

Cexp1422View::Cexp1422View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp1422View::~Cexp1422View()
{
}

BOOL Cexp1422View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp1422View ����

void Cexp1422View::OnDraw(CDC* /*pDC*/)
{
	Cexp1422Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp1422View ���

#ifdef _DEBUG
void Cexp1422View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp1422View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp1422Doc* Cexp1422View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp1422Doc)));
	return (Cexp1422Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp1422View ��Ϣ�������


void Cexp1422View::OnPopout()
{
	// TODO: �ڴ���������������
	Mydlg dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		cr.left = dlg.p_lx;
		cr.top = dlg.p_ly;
		cr.bottom = dlg.p_ry;
		cr.right = dlg.p_rx;
		GetDC()->Ellipse(cr);
	}

}

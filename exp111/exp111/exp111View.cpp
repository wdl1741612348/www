
// exp111View.cpp : Cexp111View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp111.h"
#endif

#include "exp111Doc.h"
#include "exp111View.h"
#include "MyDlgO.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp111View

IMPLEMENT_DYNCREATE(Cexp111View, CView)

BEGIN_MESSAGE_MAP(Cexp111View, CView)
	ON_COMMAND(ID_POPOUT, &Cexp111View::OnPopout)
END_MESSAGE_MAP()

// Cexp111View ����/����

Cexp111View::Cexp111View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp111View::~Cexp111View()
{
}

BOOL Cexp111View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp111View ����

void Cexp111View::OnDraw(CDC* /*pDC*/)
{
	Cexp111Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp111View ���

#ifdef _DEBUG
void Cexp111View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp111View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp111Doc* Cexp111View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp111Doc)));
	return (Cexp111Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp111View ��Ϣ�������


void Cexp111View::OnPopout()
{
	// TODO: �ڴ���������������
	MyDlgO dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		CClientDC dc(this);
		CString s = _T("�����˳��Ի���");
		dc.TextOutW(200,300,s);
	}
}

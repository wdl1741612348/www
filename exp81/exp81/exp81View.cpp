
// exp81View.cpp : Cexp81View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp81.h"
#endif

#include "exp81Doc.h"
#include "exp81View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp81View

IMPLEMENT_DYNCREATE(Cexp81View, CView)

BEGIN_MESSAGE_MAP(Cexp81View, CView)
	ON_COMMAND(ID_SHOWNAME, &Cexp81View::OnShowname)
END_MESSAGE_MAP()

// Cexp81View ����/����

Cexp81View::Cexp81View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp81View::~Cexp81View()
{
}

BOOL Cexp81View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp81View ����

void Cexp81View::OnDraw(CDC* /*pDC*/)
{
	Cexp81Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp81View ���

#ifdef _DEBUG
void Cexp81View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp81View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp81Doc* Cexp81View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp81Doc)));
	return (Cexp81Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp81View ��Ϣ�������


void Cexp81View::OnShowname()
{
	// TODO: �ڴ���������������
	CString s;
	s = _T("�ⶫ��");
	CClientDC dc(this);
	dc.TextOutW(50,50,s);
}

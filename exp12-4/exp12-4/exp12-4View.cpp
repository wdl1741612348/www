
// exp12-4View.cpp : Cexp124View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp12-4.h"
#endif

#include "exp12-4Doc.h"
#include "exp12-4View.h"
#include "Mydlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp124View

IMPLEMENT_DYNCREATE(Cexp124View, CView)

BEGIN_MESSAGE_MAP(Cexp124View, CView)
	ON_COMMAND(ID_POPUP, &Cexp124View::OnPopup)
END_MESSAGE_MAP()

// Cexp124View ����/����

Cexp124View::Cexp124View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp124View::~Cexp124View()
{
}

BOOL Cexp124View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp124View ����

void Cexp124View::OnDraw(CDC* /*pDC*/)
{
	Cexp124Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp124View ���

#ifdef _DEBUG
void Cexp124View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp124View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp124Doc* Cexp124View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp124Doc)));
	return (Cexp124Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp124View ��Ϣ�������


void Cexp124View::OnPopup()
{
	// TODO: �ڴ���������������
	Mydlg dlg;
	dlg.DoModal();
}


// exp12-2View.cpp : Cexp122View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp12-2.h"
#endif

#include "exp12-2Doc.h"
#include "exp12-2View.h"
#include "Calculator.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp122View

IMPLEMENT_DYNCREATE(Cexp122View, CView)

BEGIN_MESSAGE_MAP(Cexp122View, CView)
	ON_COMMAND(ID_POPUP, &Cexp122View::OnPopup)
END_MESSAGE_MAP()

// Cexp122View ����/����

Cexp122View::Cexp122View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp122View::~Cexp122View()
{
}

BOOL Cexp122View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp122View ����

void Cexp122View::OnDraw(CDC* /*pDC*/)
{
	Cexp122Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp122View ���

#ifdef _DEBUG
void Cexp122View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp122View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp122Doc* Cexp122View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp122Doc)));
	return (Cexp122Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp122View ��Ϣ�������


void Cexp122View::OnPopup()
{
	// TODO: �ڴ���������������
	Calculator dlg;
	int r = dlg.DoModal();
}

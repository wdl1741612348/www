
// exp13-1View.cpp : Cexp131View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp13-1.h"
#endif

#include "exp13-1Doc.h"
#include "exp13-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp131View

IMPLEMENT_DYNCREATE(Cexp131View, CView)

BEGIN_MESSAGE_MAP(Cexp131View, CView)
	ON_COMMAND(ID_FILE_OPEN, &Cexp131View::OnFileOpen)
END_MESSAGE_MAP()

// Cexp131View ����/����

Cexp131View::Cexp131View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp131View::~Cexp131View()
{
}

BOOL Cexp131View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp131View ����

void Cexp131View::OnDraw(CDC* /*pDC*/)
{
	Cexp131Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp131View ���

#ifdef _DEBUG
void Cexp131View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp131View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp131Doc* Cexp131View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp131Doc)));
	return (Cexp131Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp131View ��Ϣ�������


void Cexp131View::OnFileOpen()
{
	// TODO: �ڴ���������������
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		CString filename = cfd.GetFileName();
		GetDC()->TextOutW(200,100,filename);
	}
}

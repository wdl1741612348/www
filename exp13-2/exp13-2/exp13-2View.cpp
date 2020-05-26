
// exp13-2View.cpp : Cexp132View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp13-2.h"
#endif

#include "exp13-2Doc.h"
#include "exp13-2View.h"
#include "MyDlg0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp132View

IMPLEMENT_DYNCREATE(Cexp132View, CView)

BEGIN_MESSAGE_MAP(Cexp132View, CView)
	ON_COMMAND(ID_POPUP, &Cexp132View::OnPopup)
	ON_COMMAND(ID_FILE_OPEN, &Cexp132View::OnFileOpen)
END_MESSAGE_MAP()

// Cexp132View ����/����

Cexp132View::Cexp132View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp132View::~Cexp132View()
{
}

BOOL Cexp132View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp132View ����

void Cexp132View::OnDraw(CDC* /*pDC*/)
{
	Cexp132Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp132View ���

#ifdef _DEBUG
void Cexp132View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp132View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp132Doc* Cexp132View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp132Doc)));
	return (Cexp132Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp132View ��Ϣ�������


void Cexp132View::OnPopup()
{
	// TODO: �ڴ���������������
	MyDlg0 dlg;	
	dlg.s = filename;
	int r=dlg.DoModal();
}


void Cexp132View::OnFileOpen()
{
	// TODO: �ڴ���������������
	CFileDialog fdlg(true);
	int r = fdlg.DoModal();
	if (r == IDOK)
	{
		filename = fdlg.GetFileName();
		GetDC()->TextOutW(100,200,filename);
	}
}

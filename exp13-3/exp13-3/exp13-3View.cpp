
// exp13-3View.cpp : Cexp133View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp13-3.h"
#endif

#include "exp13-3Doc.h"
#include "exp13-3View.h"
#include "MyDlg00.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp133View

IMPLEMENT_DYNCREATE(Cexp133View, CView)

BEGIN_MESSAGE_MAP(Cexp133View, CView)
	ON_COMMAND(ID_POPOUT, &Cexp133View::OnPopout)
	ON_COMMAND(ID_FILE_OPEN, &Cexp133View::OnFileOpen)
END_MESSAGE_MAP()

// Cexp133View ����/����

Cexp133View::Cexp133View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp133View::~Cexp133View()
{
}

BOOL Cexp133View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp133View ����

void Cexp133View::OnDraw(CDC* /*pDC*/)
{
	Cexp133Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp133View ���

#ifdef _DEBUG
void Cexp133View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp133View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp133Doc* Cexp133View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp133Doc)));
	return (Cexp133Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp133View ��Ϣ�������


void Cexp133View::OnPopout()
{
	// TODO: �ڴ���������������
	MyDlg00 dlg;
//	dlg.Lbox.AddString(s);
	dlg.ss = s;
	int r = dlg.DoModal();
}


void Cexp133View::OnFileOpen()
{
	// TODO: �ڴ���������������
	CFileDialog fdlg(true);
	int r=fdlg.DoModal();
	if (r == IDOK)
	{
		s = fdlg.GetFileName();
	}
}

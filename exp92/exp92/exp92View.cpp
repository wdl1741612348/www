
// exp92View.cpp : Cexp92View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp92.h"
#endif

#include "exp92Doc.h"
#include "exp92View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp92View

IMPLEMENT_DYNCREATE(Cexp92View, CView)

BEGIN_MESSAGE_MAP(Cexp92View, CView)
	ON_COMMAND(ID_FILE_OPEN, &Cexp92View::OnFileOpen)
END_MESSAGE_MAP()

// Cexp92View ����/����

Cexp92View::Cexp92View()
{
	// TODO: �ڴ˴���ӹ������
	i = 0;
}

Cexp92View::~Cexp92View()
{
}

BOOL Cexp92View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp92View ����

void Cexp92View::OnDraw(CDC* pDC)
{
	Cexp92Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (i == 1)
	{
		img.Draw(pDC->m_hDC, sx, sy, img.GetWidth(), img.GetHeight());
		pDC->TextOutW(50, 50, filename);
	}
}


// Cexp92View ���

#ifdef _DEBUG
void Cexp92View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp92View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp92Doc* Cexp92View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp92Doc)));
	return (Cexp92Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp92View ��Ϣ�������


void Cexp92View::OnFileOpen()
{
	// TODO: �ڴ���������������
	CFileDialog cfd(true);  
	int r = cfd.DoModal();  
	CClientDC dc(this);
	i = 1;
	if (r == IDOK)  
	{
		filename = cfd.GetPathName(); 
		img.Load(filename);  
		CRect rect;
		GetClientRect(&rect);

		sx = (rect.Width() - img.GetWidth()) / 2;
		sy = (rect.Height() - img.GetHeight()) / 2;

		Invalidate();
	}
}

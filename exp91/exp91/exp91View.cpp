
// exp91View.cpp : Cexp91View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp91.h"
#endif

#include "exp91Doc.h"
#include "exp91View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp91View

IMPLEMENT_DYNCREATE(Cexp91View, CView)

BEGIN_MESSAGE_MAP(Cexp91View, CView)
	ON_COMMAND(ID_FILE_OPEN, &Cexp91View::OnFileOpen)
END_MESSAGE_MAP()

// Cexp91View ����/����

Cexp91View::Cexp91View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp91View::~Cexp91View()
{
}

BOOL Cexp91View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp91View ����

void Cexp91View::OnDraw(CDC* pDC)
{
	Cexp91Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

}


// Cexp91View ���

#ifdef _DEBUG
void Cexp91View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp91View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp91Doc* Cexp91View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp91Doc)));
	return (Cexp91Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp91View ��Ϣ�������


void Cexp91View::OnFileOpen()
{
	// TODO: �ڴ���������������
	CFileDialog cfd(true);  //tureΪ�� , falseΪ���Ϊ
	int r = cfd.DoModal();  //domodal�����ǵ��������Ի���ȡ�÷���ֵ��r
	CClientDC dc(this);

	if (r == IDOK)  //����ֵΪIDOK����ʾ�����ȷ�����˳�
	{
		CString filename;
		filename = cfd.GetPathName(); //·����
		CImage img;
		img.Load(filename);  //ͼƬ�ļ���CImage�����
        int sx,sy;		
		CRect rect;
		GetClientRect(&rect);

		sx = (rect.Width() - img.GetWidth()) / 2;
		sy = (rect.Height() - img.GetHeight()) / 2;

		img.Draw(dc.m_hDC, sx, sy, img.GetWidth(), img.GetHeight());
		dc.TextOutW(50, 50, filename);

	}
}

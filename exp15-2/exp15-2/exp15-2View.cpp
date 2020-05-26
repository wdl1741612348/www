
// exp15-2View.cpp : Cexp152View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp15-2.h"
#endif
#include "Mydlg.h"
#include <fstream>
#include<string>
#include<stdlib.h>
using namespace std;

#include "exp15-2Doc.h"
#include "exp15-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp152View

IMPLEMENT_DYNCREATE(Cexp152View, CView)

BEGIN_MESSAGE_MAP(Cexp152View, CView)
	ON_COMMAND(ID_FILE_OPEN, &Cexp152View::OnFileOpen)
END_MESSAGE_MAP()

// Cexp152View ����/����

Cexp152View::Cexp152View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp152View::~Cexp152View()
{
}

BOOL Cexp152View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp152View ����

void Cexp152View::OnDraw(CDC* /*pDC*/)
{
	Cexp152Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp152View ���

#ifdef _DEBUG
void Cexp152View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp152View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp152Doc* Cexp152View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp152Doc)));
	return (Cexp152Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp152View ��Ϣ�������

void Cexp152View::foo(CImage &img, int &sx, int &sy, int &w, int &h)
{
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
	float cr_ratio = 1.0*cr.Width() / cr.Height();
	float img_ratio= 1.0*img.GetWidth() / img.GetHeight();
	if (cr_ratio > img_ratio)
	{
		h = cr.Height();
		w = img_ratio*h;
		sx = (cr_ratio - img_ratio) / 2;
		sy = 0;
	}
	else
	{
		w = cr.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (cr.Height() - h) / 2;

	}
}

void Cexp152View::OnFileOpen()
{
	// TODO: �ڴ���������������
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	Mydlg dlg;
	string filename;
	CImage img;
	if (r == IDOK)
	{
		ifstream ifs(cfd.GetPathName());
        dlg.DoModal();
		while (ifs >> filename)
		{
			img.Load(CString(filename.c_str()));
			int sx, sy, w, h;
			foo(img,sx,sy,w,h);
			CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
			img.Draw(pDC->m_hDC,sx,sy,w,h);
			ReleaseDC(pDC);
		}

	}

	
} 

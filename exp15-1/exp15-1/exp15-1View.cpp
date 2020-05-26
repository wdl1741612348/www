
// exp15-1View.cpp : Cexp151View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp15-1.h"
#endif

#include "exp15-1Doc.h"
#include "exp15-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include<fstream>
using namespace std;
// Cexp151View

IMPLEMENT_DYNCREATE(Cexp151View, CView)

BEGIN_MESSAGE_MAP(Cexp151View, CView)
	ON_COMMAND(ID_FILE_OPEN, &Cexp151View::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, &Cexp151View::OnFileSave)
END_MESSAGE_MAP()

// Cexp151View ����/����

Cexp151View::Cexp151View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp151View::~Cexp151View()
{
}

BOOL Cexp151View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp151View ����

void Cexp151View::OnDraw(CDC* /*pDC*/)
{
	Cexp151Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp151View ���

#ifdef _DEBUG
void Cexp151View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp151View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp151Doc* Cexp151View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp151Doc)));
	return (Cexp151Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp151View ��Ϣ�������


void Cexp151View::OnFileOpen()
{
	// TODO: �ڴ���������������
	CFileDialog cfd(true);  
	int r = cfd.DoModal();  
	CClientDC dc(this);
	if (r == IDOK)
	{
		
		filename = cfd.GetPathName(); //·����

	}
}


void Cexp151View::OnFileSave()
{
	// TODO: �ڴ���������������
	CFileDialog cfd(false);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		ofstream ofs(cfd.GetPathName());
		ofs << CT2A(filename.GetString())<<endl;
	}
}

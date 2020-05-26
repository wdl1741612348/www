
// DB0505-3View.cpp : CDB05053View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "DB0505-3.h"
#endif

#include "DB0505-3Set.h"
#include "DB0505-3Doc.h"
#include "DB0505-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB05053View

IMPLEMENT_DYNCREATE(CDB05053View, CRecordView)

BEGIN_MESSAGE_MAP(CDB05053View, CRecordView)
END_MESSAGE_MAP()

// CDB05053View ����/����

CDB05053View::CDB05053View()
	: CRecordView(IDD_DB05053_FORM)
	, name(_T(""))
	, number(0)
	, age(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
}

CDB05053View::~CDB05053View()
{
}

void CDB05053View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column3);
	Invalidate();
}

BOOL CDB05053View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CDB05053View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DB05053Set;
	CRecordView::OnInitialUpdate();

}


// CDB05053View ���

#ifdef _DEBUG
void CDB05053View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDB05053View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDB05053Doc* CDB05053View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDB05053Doc)));
	return (CDB05053Doc*)m_pDocument;
}
#endif //_DEBUG


// CDB05053View ���ݿ�֧��
CRecordset* CDB05053View::OnGetRecordset()
{
	return m_pSet;
}



// CDB05053View ��Ϣ�������

void CDB05053View::foo(CImage &img, int &sx, int &sy, int &w, int &h)
{
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
	float cr_ratio = 1.0*cr.Width() / cr.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (cr_ratio > img_ratio)
	{
		h = cr.Height()*1.0;
		w = img_ratio*h;
		sx = (cr.Width() - w) / 2;
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


void CDB05053View::OnDraw(CDC* pDC)
{
	// TODO: �ڴ����ר�ô����/����û���
	CString s;
	m_pSet->GetFieldValue(short(3), s);//�Ӽ�¼����ǰ��¼����ȡ��3���ֶ�ֵ������s�� 
	CImage img;
	img.Load(s);

	int sx, sy, w, h;
	foo(img, sx, sy, w, h);

	pDC = GetDlgItem(IDC_STATIC)->GetDC();//GetDC()ȡ����ͼƬ�ؼ�����Ӧ���豸����
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}

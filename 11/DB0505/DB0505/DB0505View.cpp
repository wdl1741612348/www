
// DB0505View.cpp : CDB0505View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "DB0505.h"
#endif

#include "DB0505Set.h"
#include "DB0505Doc.h"
#include "DB0505View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB0505View

IMPLEMENT_DYNCREATE(CDB0505View, CRecordView)

BEGIN_MESSAGE_MAP(CDB0505View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDB0505View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDB0505View ����/����

CDB0505View::CDB0505View()
	: CRecordView(IDD_DB0505_FORM)
	, name(_T(""))
	, number(0)
	, age(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CDB0505View::~CDB0505View()
{
}

void CDB0505View::DoDataExchange(CDataExchange* pDX)
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

BOOL CDB0505View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CDB0505View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DB0505Set;
	CRecordView::OnInitialUpdate();

}


// CDB0505View ���

#ifdef _DEBUG
void CDB0505View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDB0505View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDB0505Doc* CDB0505View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDB0505Doc)));
	return (CDB0505Doc*)m_pDocument;
}
#endif //_DEBUG


// CDB0505View ���ݿ�֧��
CRecordset* CDB0505View::OnGetRecordset()
{
	return m_pSet;
}

void CDB0505View::foo(CImage &img, int &sx, int &sy, int &w, int &h)
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

// CDB0505View ��Ϣ�������


void CDB0505View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString s;
	m_pSet->GetFieldValue(short(3), s);//�Ӽ�¼����ǰ��¼����ȡ��3���ֶ�ֵ������s�� 
	CImage img;
	img.Load(s);

	int sx, sy, w, h;
	foo(img, sx, sy, w, h);

	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();//GetDC()ȡ����ͼƬ�ؼ�����Ӧ���豸����
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC,sx,sy,w,h);
	ReleaseDC(pDC);

}


// DB002View.cpp : CDB002View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "DB002.h"
#endif

#include "DB002Set.h"
#include "DB002Doc.h"
#include "DB002View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB002View

IMPLEMENT_DYNCREATE(CDB002View, CRecordView)

BEGIN_MESSAGE_MAP(CDB002View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CDB002View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CDB002View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CDB002View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CDB002View::OnRecordLast)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CDB002View ����/����

CDB002View::CDB002View()
	: CRecordView(IDD_DB002_FORM)
	, s(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	path = _T("D:\\����Դ\\");
}

CDB002View::~CDB002View()
{
}

void CDB002View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
}

BOOL CDB002View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CDB002View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DB002Set;
	CRecordView::OnInitialUpdate();
//	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
}


// CDB002View ���

#ifdef _DEBUG
void CDB002View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDB002View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDB002Doc* CDB002View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDB002Doc)));
	return (CDB002Doc*)m_pDocument;
}
#endif //_DEBUG


// CDB002View ���ݿ�֧��
CRecordset* CDB002View::OnGetRecordset()
{
	return m_pSet;
}



// CDB002View ��Ϣ�������


void CDB002View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	GetDlgItemText(IDC_EDIT1, f);
	filename = path + f;
	draw_pic(filename);
	InvalidateRect(cr);
}


void CDB002View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
	{
		m_pSet->MoveFirst();
	}UpdateData(false);

	GetDlgItemText(IDC_EDIT1, f);
	filename = path + f;

	draw_pic(filename);
	InvalidateRect(cr);
}


void CDB002View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
	{
		m_pSet->MoveLast();
	}UpdateData(false);

	GetDlgItemText(IDC_EDIT1, f);
	filename = path + f;

	draw_pic(filename);
	InvalidateRect(cr);
}


void CDB002View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);

	GetDlgItemText(IDC_EDIT1, f);
	filename = path + f;

	draw_pic(filename);
	InvalidateRect(cr);
}

void CDB002View::draw_pic(CString file)
{
//	CImage img;
	img.Load(file);
//	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
//	CRect cr;
//	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);
	float cr_ratio = 1.0*cr.Width() / cr.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();

	if (cr_ratio > img_ratio)
	{
		h = cr.Height();
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
//	pDC->SetStretchBltMode(HALFTONE);
//	img.Draw(pDC->m_hDC, sx, sy, w, h);
//	ReleaseDC(pDC);
}



void CDB002View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	CImage img;
	img.Load(filename);
    pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}

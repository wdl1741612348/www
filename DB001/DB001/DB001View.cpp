
// DB001View.cpp : CDB001View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "DB001.h"
#endif

#include "DB001Set.h"
#include "DB001Doc.h"
#include "DB001View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB001View

IMPLEMENT_DYNCREATE(CDB001View, CRecordView)

BEGIN_MESSAGE_MAP(CDB001View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CDB001View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CDB001View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CDB001View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CDB001View::OnRecordLast)
//	ON_WM_PAINT()
END_MESSAGE_MAP()

// CDB001View ����/����

CDB001View::CDB001View()
	: CRecordView(IDD_DB001_FORM)
	, s(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	path = _T("D:\\����Դ\\");
	
}

CDB001View::~CDB001View()
{
}

void CDB001View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
}

BOOL CDB001View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CDB001View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DB001Set;
	CRecordView::OnInitialUpdate();
}


// CDB001View ���

#ifdef _DEBUG
void CDB001View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDB001View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDB001Doc* CDB001View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDB001Doc)));
	return (CDB001Doc*)m_pDocument;
}
#endif //_DEBUG


// CDB001View ���ݿ�֧��
CRecordset* CDB001View::OnGetRecordset()
{
	return m_pSet;
}



// CDB001View ��Ϣ�������


void CDB001View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);

	CString filename,s;
	GetDlgItemText(IDC_EDIT1,s);
	filename = path + s;

	draw_pic(filename);

}


void CDB001View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
	{
		m_pSet->MoveFirst();
	}UpdateData(false);

	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;

	draw_pic(filename);
}


void CDB001View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
	{
		m_pSet->MoveLast();
	}UpdateData(false);

	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;

	draw_pic(filename);
}


void CDB001View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;

	draw_pic(filename);
}

void CDB001View::draw_pic(CString file)
{
	CImage img;
	img.Load(file);
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();

	if (rect_ratio > img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC,sx,sy,w,h);
	ReleaseDC(pDC);
}



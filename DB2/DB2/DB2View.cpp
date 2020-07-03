
// DB2View.cpp : CDB2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "DB2.h"
#endif

#include "DB2Set.h"
#include "DB2Doc.h"
#include "DB2View.h"
#include "Mydlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB2View

IMPLEMENT_DYNCREATE(CDB2View, CRecordView)

BEGIN_MESSAGE_MAP(CDB2View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CDB2View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CDB2View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CDB2View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CDB2View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON1, &CDB2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDB2View ����/����

CDB2View::CDB2View()
	: CRecordView(IDD_DB2_FORM)
	, s(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CDB2View::~CDB2View()
{
}

void CDB2View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
}

BOOL CDB2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CDB2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DB2Set;
	CRecordView::OnInitialUpdate();

}


// CDB2View ���

#ifdef _DEBUG
void CDB2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDB2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDB2Doc* CDB2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDB2Doc)));
	return (CDB2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDB2View ���ݿ�֧��
CRecordset* CDB2View::OnGetRecordset()
{
	return m_pSet;
}



// CDB2View ��Ϣ�������


void CDB2View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);

	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;

	draw_pic(filename);
}


void CDB2View::OnRecordPrev()
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


void CDB2View::OnRecordNext()
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


void CDB2View::OnRecordLast()
{
	// TODO: �ڴ���������������
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;

	draw_pic(filename);
}

void CDB2View::draw_pic(CString file)
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
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}


void CDB2View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	Mydlg dlg;
	dlg.file1 = filename;
	dlg.DoModal();
}


// DB13View.cpp : CDB13View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "DB13.h"
#endif

#include "DB13Set.h"
#include "DB13Doc.h"
#include "DB13View.h"
#include "ADD_DLG.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB13View

IMPLEMENT_DYNCREATE(CDB13View, CRecordView)

BEGIN_MESSAGE_MAP(CDB13View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON2, &CDB13View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDB13View::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CDB13View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDB13View ����/����

CDB13View::CDB13View()
	: CRecordView(IDD_DB13_FORM)
	, ss(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CDB13View::~CDB13View()
{
}

void CDB13View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
}

BOOL CDB13View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CDB13View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DB13Set;
	CRecordView::OnInitialUpdate();

}


// CDB13View ���

#ifdef _DEBUG
void CDB13View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDB13View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDB13Doc* CDB13View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDB13Doc)));
	return (CDB13Doc*)m_pDocument;
}
#endif //_DEBUG


// CDB13View ���ݿ�֧��
CRecordset* CDB13View::OnGetRecordset()
{
	return m_pSet;
}



// CDB13View ��Ϣ�������


void CDB13View::OnBnClickedButton2() //�޸�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ADD_DLG adddlg;
	int r = adddlg.DoModal();
	if (r == IDOK)
	{
		long ii = adddlg.i;
		m_pSet->Edit();
		m_pSet->m_ID = ii;
		m_pSet->Update();
		UpdateData(false);
	}
}


void CDB13View::OnBnClickedButton3() //ɾ��
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
	{
		m_pSet->MoveFirst();
		UpdateData(false);
	}
}


void CDB13View::OnBnClickedButton1() //����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ADD_DLG adddlg;
	int r = adddlg.DoModal();
	if (r == IDOK)
	{
		long ii = adddlg.i;
		m_pSet->AddNew();
		m_pSet->m_ID = ii;
		m_pSet->Update();
		UpdateData(false);
	}
}

// Popdlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "exp14-1.h"
#include "Popdlg.h"
#include "afxdialogex.h"


// Popdlg �Ի���

IMPLEMENT_DYNAMIC(Popdlg, CDialogEx)

Popdlg::Popdlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, q(_T(""))
{

}

Popdlg::~Popdlg()
{
}

void Popdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, q);
}


BEGIN_MESSAGE_MAP(Popdlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &Popdlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// Popdlg ��Ϣ�������


void Popdlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


BOOL Popdlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	q = _T("�Ƿ�����");
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

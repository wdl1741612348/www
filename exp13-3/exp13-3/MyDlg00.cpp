// MyDlg00.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "exp13-3.h"
#include "MyDlg00.h"
#include "afxdialogex.h"


// MyDlg00 �Ի���

IMPLEMENT_DYNAMIC(MyDlg00, CDialogEx)

MyDlg00::MyDlg00(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, ss(_T(""))
{

}

MyDlg00::~MyDlg00()
{
}

void MyDlg00::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, Lbox);
	DDX_Text(pDX, IDC_EDIT1, ss);
}


BEGIN_MESSAGE_MAP(MyDlg00, CDialogEx)
END_MESSAGE_MAP()


// MyDlg00 ��Ϣ�������


BOOL MyDlg00::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	Lbox.AddString(ss);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

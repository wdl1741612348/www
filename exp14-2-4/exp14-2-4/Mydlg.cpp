// Mydlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "exp14-2-4.h"
#include "Mydlg.h"
#include "afxdialogex.h"


// Mydlg �Ի���

IMPLEMENT_DYNAMIC(Mydlg, CDialogEx)

Mydlg::Mydlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, a(0)
	, b(0)
	, c(0)
{

}

Mydlg::~Mydlg()
{
}

void Mydlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
	DDX_Text(pDX, IDC_EDIT2, b);
	DDX_Text(pDX, IDC_EDIT3, c);
}


BEGIN_MESSAGE_MAP(Mydlg, CDialogEx)
END_MESSAGE_MAP()


// Mydlg ��Ϣ�������

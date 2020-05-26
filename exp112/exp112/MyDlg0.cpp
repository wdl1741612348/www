// MyDlg0.cpp : 实现文件
//

#include "stdafx.h"
#include "exp112.h"
#include "MyDlg0.h"
#include "afxdialogex.h"


// MyDlg0 对话框

IMPLEMENT_DYNAMIC(MyDlg0, CDialogEx)

MyDlg0::MyDlg0(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, s1(_T(""))
	, s2(_T(""))
{

}

MyDlg0::~MyDlg0()
{
}

void MyDlg0::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s1);
	DDX_Text(pDX, IDC_EDIT2, s2);
}


BEGIN_MESSAGE_MAP(MyDlg0, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg0::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDlg0 消息处理程序


void MyDlg0::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	CString x, y;
	x = s1;
	y = s2;
	s1 = y;
	s2 = x;
	UpdateData(false);
}

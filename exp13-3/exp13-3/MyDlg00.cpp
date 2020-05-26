// MyDlg00.cpp : 实现文件
//

#include "stdafx.h"
#include "exp13-3.h"
#include "MyDlg00.h"
#include "afxdialogex.h"


// MyDlg00 对话框

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


// MyDlg00 消息处理程序


BOOL MyDlg00::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化
	Lbox.AddString(ss);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

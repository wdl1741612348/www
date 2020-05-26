// Popdlg.cpp : 实现文件
//

#include "stdafx.h"
#include "exp14-1.h"
#include "Popdlg.h"
#include "afxdialogex.h"


// Popdlg 对话框

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


// Popdlg 消息处理程序


void Popdlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


BOOL Popdlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	q = _T("非法输入");
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

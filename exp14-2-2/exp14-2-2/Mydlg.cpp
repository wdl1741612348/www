// Mydlg.cpp : 实现文件
//

#include "stdafx.h"
#include "exp14-2-2.h"
#include "Mydlg.h"
#include "afxdialogex.h"


// Mydlg 对话框

IMPLEMENT_DYNAMIC(Mydlg, CDialogEx)

Mydlg::Mydlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, p_lx(0)
	, p_ly(0)
	, p_rx(0)
	, p_ry(0)
{

}

Mydlg::~Mydlg()
{
}

void Mydlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, p_lx);
	DDX_Text(pDX, IDC_EDIT2, p_ly);
	DDX_Text(pDX, IDC_EDIT3, p_rx);
	DDX_Text(pDX, IDC_EDIT4, p_ry);
}


BEGIN_MESSAGE_MAP(Mydlg, CDialogEx)
END_MESSAGE_MAP()


// Mydlg 消息处理程序

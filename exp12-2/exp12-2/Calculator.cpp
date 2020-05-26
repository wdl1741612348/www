// Calculator.cpp : 实现文件
//

#include "stdafx.h"
#include "exp12-2.h"
#include "Calculator.h"
#include "afxdialogex.h"


// Calculator 对话框

IMPLEMENT_DYNAMIC(Calculator, CDialogEx)

Calculator::Calculator(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, x(0)
	, y(0)
	, z(0)
{

}

Calculator::~Calculator()
{
}

void Calculator::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
	DDX_Text(pDX, IDC_EDIT2, y);
	DDX_Text(pDX, IDC_EDIT3, z);
}


BEGIN_MESSAGE_MAP(Calculator, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Calculator::OnBnClickedButton1)
END_MESSAGE_MAP()


// Calculator 消息处理程序


void Calculator::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	int a = x;
	int b = y;
	z = a + b;
	UpdateData(false);
}

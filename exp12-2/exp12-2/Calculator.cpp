// Calculator.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "exp12-2.h"
#include "Calculator.h"
#include "afxdialogex.h"


// Calculator �Ի���

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


// Calculator ��Ϣ�������


void Calculator::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(true);
	int a = x;
	int b = y;
	z = a + b;
	UpdateData(false);
}

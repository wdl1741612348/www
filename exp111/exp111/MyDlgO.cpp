// MyDlgO.cpp : 实现文件
//

#include "stdafx.h"
#include "exp111.h"
#include "MyDlgO.h"
#include "afxdialogex.h"


// MyDlgO 对话框

IMPLEMENT_DYNAMIC(MyDlgO, CDialogEx)

MyDlgO::MyDlgO(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

MyDlgO::~MyDlgO()
{
}

void MyDlgO::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDlgO, CDialogEx)
END_MESSAGE_MAP()


// MyDlgO 消息处理程序

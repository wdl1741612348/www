#pragma once
#include "afxwin.h"


// MyDlg00 对话框

class MyDlg00 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg00)

public:
	MyDlg00(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDlg00();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox Lbox;
	virtual BOOL OnInitDialog();
	CString ss;
};

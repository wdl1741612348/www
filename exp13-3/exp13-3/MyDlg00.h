#pragma once
#include "afxwin.h"


// MyDlg00 �Ի���

class MyDlg00 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg00)

public:
	MyDlg00(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDlg00();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListBox Lbox;
	virtual BOOL OnInitDialog();
	CString ss;
};

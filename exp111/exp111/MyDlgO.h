#pragma once


// MyDlgO �Ի���

class MyDlgO : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlgO)

public:
	MyDlgO(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDlgO();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};

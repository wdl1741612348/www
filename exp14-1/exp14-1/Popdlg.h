#pragma once


// Popdlg �Ի���

class Popdlg : public CDialogEx
{
	DECLARE_DYNAMIC(Popdlg)

public:
	Popdlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Popdlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString q;
	afx_msg void OnEnChangeEdit1();
	virtual BOOL OnInitDialog();
};

#pragma once


// Calculator �Ի���

class Calculator : public CDialogEx
{
	DECLARE_DYNAMIC(Calculator)

public:
	Calculator(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Calculator();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int x;
	int y;
	int z;
	afx_msg void OnBnClickedButton1();
};

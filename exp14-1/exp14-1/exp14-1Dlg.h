
// exp14-1Dlg.h : ͷ�ļ�
//

#pragma once


// Cexp141Dlg �Ի���
class Cexp141Dlg : public CDialogEx
{
// ����
public:
	Cexp141Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXP141_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	double a;
	double b;
	double c;
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedButton1();
	double x1;
	double y1;
	double z1;
	afx_msg void OnBnClickedButton2();
	double x2;
	double y2;
	double z2;
	afx_msg void OnBnClickedButton3();
	double x3;
	double y3;
	double z3;
	afx_msg void OnBnClickedButton4();
	double x4;
	double y4;
	double z4;
	afx_msg void OnBnClickedButton5();
	double x5;
	double z5;
	afx_msg void OnBnClickedButton6();
};

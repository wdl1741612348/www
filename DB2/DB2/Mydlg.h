#pragma once


// Mydlg �Ի���

class Mydlg : public CDialogEx
{
	DECLARE_DYNAMIC(Mydlg)

public:
	Mydlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Mydlg();
	CString file1;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	void Mydlg::draw_pic(CString file);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};

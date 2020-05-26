#pragma once


// Popdlg 对话框

class Popdlg : public CDialogEx
{
	DECLARE_DYNAMIC(Popdlg)

public:
	Popdlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Popdlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString q;
	afx_msg void OnEnChangeEdit1();
	virtual BOOL OnInitDialog();
};

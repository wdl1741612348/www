#pragma once


// Mydlg 对话框

class Mydlg : public CDialogEx
{
	DECLARE_DYNAMIC(Mydlg)

public:
	Mydlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Mydlg();
	CString file1;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	void Mydlg::draw_pic(CString file);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};

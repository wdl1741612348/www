#pragma once


// MyDlgO 对话框

class MyDlgO : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlgO)

public:
	MyDlgO(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDlgO();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};

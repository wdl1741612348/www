
// DB13View.h : CDB13View 类的接口
//

#pragma once

class CDB13Set;

class CDB13View : public CRecordView
{
protected: // 仅从序列化创建
	CDB13View();
	DECLARE_DYNCREATE(CDB13View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DB13_FORM };
#endif
	CDB13Set* m_pSet;

// 特性
public:
	CDB13Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CDB13View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CString ss;
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // DB13View.cpp 中的调试版本
inline CDB13Doc* CDB13View::GetDocument() const
   { return reinterpret_cast<CDB13Doc*>(m_pDocument); }
#endif


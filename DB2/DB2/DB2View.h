
// DB2View.h : CDB2View 类的接口
//

#pragma once

class CDB2Set;

class CDB2View : public CRecordView
{
protected: // 仅从序列化创建
	CDB2View();
	DECLARE_DYNCREATE(CDB2View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DB2_FORM };
#endif
	CDB2Set* m_pSet;
	CString filename,path;


// 特性
public:
	CDB2Doc* GetDocument() const;

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
	virtual ~CDB2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString s;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	void CDB2View::draw_pic(CString file);
		afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // DB2View.cpp 中的调试版本
inline CDB2Doc* CDB2View::GetDocument() const
   { return reinterpret_cast<CDB2Doc*>(m_pDocument); }
#endif


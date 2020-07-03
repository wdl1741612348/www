
// DB002View.h : CDB002View 类的接口
//

#pragma once

class CDB002Set;

class CDB002View : public CRecordView
{
protected: // 仅从序列化创建
	CDB002View();
	DECLARE_DYNCREATE(CDB002View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DB002_FORM };
#endif
	CDB002Set* m_pSet;
	CString path;
// 特性
public:
	CDB002Doc* GetDocument() const;

// 操作
public:
	int sx, sy, w, h;
	CString filename, f;
	CRect cr;
	CImage img;
// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CDB002View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	void CDB002View::draw_pic(CString file);
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
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // DB002View.cpp 中的调试版本
inline CDB002Doc* CDB002View::GetDocument() const
   { return reinterpret_cast<CDB002Doc*>(m_pDocument); }
#endif


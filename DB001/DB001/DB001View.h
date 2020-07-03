
// DB001View.h : CDB001View 类的接口
//

#pragma once

class CDB001Set;

class CDB001View : public CRecordView
{
protected: // 仅从序列化创建
	CDB001View();
	DECLARE_DYNCREATE(CDB001View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DB001_FORM };
#endif
	CDB001Set* m_pSet;
	CString path;
// 特性
public:
	CDB001Doc* GetDocument() const;

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
	virtual ~CDB001View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	void CDB001View::draw_pic(CString file);
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
//	afx_msg void OnPaint();
};

#ifndef _DEBUG  // DB001View.cpp 中的调试版本
inline CDB001Doc* CDB001View::GetDocument() const
   { return reinterpret_cast<CDB001Doc*>(m_pDocument); }
#endif


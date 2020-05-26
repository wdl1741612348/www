
// DB0505-3View.h : CDB05053View 类的接口
//

#pragma once

class CDB05053Set;

class CDB05053View : public CRecordView
{
protected: // 仅从序列化创建
	CDB05053View();
	DECLARE_DYNCREATE(CDB05053View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DB05053_FORM };
#endif
	CDB05053Set* m_pSet;

// 特性
public:
	CDB05053Doc* GetDocument() const;

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
	virtual ~CDB05053View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	void CDB05053View::foo(CImage &img, int &sx, int &sy, int &w, int &h);
protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString name;
	double number;
	double age;
	virtual void OnDraw(CDC* /*pDC*/);
};

#ifndef _DEBUG  // DB0505-3View.cpp 中的调试版本
inline CDB05053Doc* CDB05053View::GetDocument() const
   { return reinterpret_cast<CDB05053Doc*>(m_pDocument); }
#endif


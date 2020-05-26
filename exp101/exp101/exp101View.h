
// exp101View.h : Cexp101View 类的接口
//

#pragma once


class Cexp101View : public CView
{
protected: // 仅从序列化创建
	Cexp101View();
	DECLARE_DYNCREATE(Cexp101View)

// 特性
public:
	Cexp101Doc* GetDocument() const;

// 操作
public:
	CString s;
	int a, b;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp101View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // exp101View.cpp 中的调试版本
inline Cexp101Doc* Cexp101View::GetDocument() const
   { return reinterpret_cast<Cexp101Doc*>(m_pDocument); }
#endif



// exp83View.h : Cexp83View 类的接口
//

#pragma once


class Cexp83View : public CView
{
protected: // 仅从序列化创建
	Cexp83View();
	DECLARE_DYNCREATE(Cexp83View)

// 特性
public:
	Cexp83Doc* GetDocument() const;

// 操作
public:
	int k;
	CPoint a, b;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp83View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawline();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnDrawrectangle();
	afx_msg void OnDrawcircle();
};

#ifndef _DEBUG  // exp83View.cpp 中的调试版本
inline Cexp83Doc* Cexp83View::GetDocument() const
   { return reinterpret_cast<Cexp83Doc*>(m_pDocument); }
#endif


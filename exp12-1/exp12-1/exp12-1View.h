
// exp12-1View.h : Cexp121View 类的接口
//

#pragma once


class Cexp121View : public CView
{
protected: // 仅从序列化创建
	Cexp121View();
	DECLARE_DYNCREATE(Cexp121View)

// 特性
public:
	Cexp121Doc* GetDocument() const;

// 操作
public:
	CRect cr;
	int N;
	int a, b, c, d;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp121View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp12-1View.cpp 中的调试版本
inline Cexp121Doc* Cexp121View::GetDocument() const
   { return reinterpret_cast<Cexp121Doc*>(m_pDocument); }
#endif


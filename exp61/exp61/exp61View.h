
// exp61View.h : Cexp61View 类的接口
//

#pragma once


class Cexp61View : public CView
{
protected: // 仅从序列化创建
	Cexp61View();
	DECLARE_DYNCREATE(Cexp61View)

// 特性
public:
	Cexp61Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp61View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp61View.cpp 中的调试版本
inline Cexp61Doc* Cexp61View::GetDocument() const
   { return reinterpret_cast<Cexp61Doc*>(m_pDocument); }
#endif



// exp14-2-1View.h : Cexp1421View 类的接口
//

#pragma once


class Cexp1421View : public CView
{
protected: // 仅从序列化创建
	Cexp1421View();
	DECLARE_DYNCREATE(Cexp1421View)

// 特性
public:
	Cexp1421Doc* GetDocument() const;

// 操作
public:
	CRect cr;
	int a, b, c, d;
	bool set;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp1421View();
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

#ifndef _DEBUG  // exp14-2-1View.cpp 中的调试版本
inline Cexp1421Doc* Cexp1421View::GetDocument() const
   { return reinterpret_cast<Cexp1421Doc*>(m_pDocument); }
#endif


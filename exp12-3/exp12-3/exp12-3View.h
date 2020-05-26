
// exp12-3View.h : Cexp123View 类的接口
//

#pragma once


class Cexp123View : public CView
{
protected: // 仅从序列化创建
	Cexp123View();
	DECLARE_DYNCREATE(Cexp123View)

// 特性
public:
	Cexp123Doc* GetDocument() const;

// 操作
public:
	CRect cr,rect;
	int N;
	bool set1,set2;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp123View();
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
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // exp12-3View.cpp 中的调试版本
inline Cexp123Doc* Cexp123View::GetDocument() const
   { return reinterpret_cast<Cexp123Doc*>(m_pDocument); }
#endif


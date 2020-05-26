
// exp112View.h : Cexp112View 类的接口
//

#pragma once


class Cexp112View : public CView
{
protected: // 仅从序列化创建
	Cexp112View();
	DECLARE_DYNCREATE(Cexp112View)

// 特性
public:
	Cexp112Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp112View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp112View.cpp 中的调试版本
inline Cexp112Doc* Cexp112View::GetDocument() const
   { return reinterpret_cast<Cexp112Doc*>(m_pDocument); }
#endif


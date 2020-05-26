
// exp14-2-3View.h : Cexp1423View 类的接口
//

#pragma once


class Cexp1423View : public CView
{
protected: // 仅从序列化创建
	Cexp1423View();
	DECLARE_DYNCREATE(Cexp1423View)

// 特性
public:
	Cexp1423Doc* GetDocument() const;

// 操作
public:
	CRect cr;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp1423View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp14-2-3View.cpp 中的调试版本
inline Cexp1423Doc* Cexp1423View::GetDocument() const
   { return reinterpret_cast<Cexp1423Doc*>(m_pDocument); }
#endif


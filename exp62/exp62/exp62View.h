
// exp62View.h : Cexp62View 类的接口
//

#pragma once


class Cexp62View : public CView
{
protected: // 仅从序列化创建
	Cexp62View();
	DECLARE_DYNCREATE(Cexp62View)

// 特性
public:
	Cexp62Doc* GetDocument() const;
	
// 操作
public:
    int i;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp62View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp62View.cpp 中的调试版本
inline Cexp62Doc* Cexp62View::GetDocument() const
   { return reinterpret_cast<Cexp62Doc*>(m_pDocument); }
#endif


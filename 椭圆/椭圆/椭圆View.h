
// 椭圆View.h : C椭圆View 类的接口
//

#pragma once


class C椭圆View : public CView
{
protected: // 仅从序列化创建
	C椭圆View();
	DECLARE_DYNCREATE(C椭圆View)

// 特性
public:
	C椭圆Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C椭圆View();
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
};

#ifndef _DEBUG  // 椭圆View.cpp 中的调试版本
inline C椭圆Doc* C椭圆View::GetDocument() const
   { return reinterpret_cast<C椭圆Doc*>(m_pDocument); }
#endif


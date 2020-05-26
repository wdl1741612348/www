
// exp17-1View.h : Cexp171View 类的接口
//

#pragma once


class Cexp171View : public CView
{
protected: // 仅从序列化创建
	Cexp171View();
	DECLARE_DYNCREATE(Cexp171View)

// 特性
public:
	Cexp171Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp171View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // exp17-1View.cpp 中的调试版本
inline Cexp171Doc* Cexp171View::GetDocument() const
   { return reinterpret_cast<Cexp171Doc*>(m_pDocument); }
#endif


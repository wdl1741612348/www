
// exp111View.h : Cexp111View 类的接口
//

#pragma once


class Cexp111View : public CView
{
protected: // 仅从序列化创建
	Cexp111View();
	DECLARE_DYNCREATE(Cexp111View)

// 特性
public:
	Cexp111Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp111View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopout();
};

#ifndef _DEBUG  // exp111View.cpp 中的调试版本
inline Cexp111Doc* Cexp111View::GetDocument() const
   { return reinterpret_cast<Cexp111Doc*>(m_pDocument); }
#endif


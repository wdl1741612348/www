
// exp13-1View.h : Cexp131View 类的接口
//

#pragma once


class Cexp131View : public CView
{
protected: // 仅从序列化创建
	Cexp131View();
	DECLARE_DYNCREATE(Cexp131View)

// 特性
public:
	Cexp131Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp131View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // exp13-1View.cpp 中的调试版本
inline Cexp131Doc* Cexp131View::GetDocument() const
   { return reinterpret_cast<Cexp131Doc*>(m_pDocument); }
#endif


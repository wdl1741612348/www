
// exp15-2View.h : Cexp152View 类的接口
//

#pragma once


class Cexp152View : public CView
{
protected: // 仅从序列化创建
	Cexp152View();
	DECLARE_DYNCREATE(Cexp152View)

// 特性
public:
	Cexp152Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp152View();
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
	afx_msg void foo(CImage &img, int &sx, int &sy, int &w, int &h);
};

#ifndef _DEBUG  // exp15-2View.cpp 中的调试版本
inline Cexp152Doc* Cexp152View::GetDocument() const
   { return reinterpret_cast<Cexp152Doc*>(m_pDocument); }
#endif


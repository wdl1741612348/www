
// exp71View.h : Cexp71View 类的接口
//

#pragma once


class Cexp71View : public CView
{
protected: // 仅从序列化创建
	Cexp71View();
	DECLARE_DYNCREATE(Cexp71View)

// 特性
public:
	Cexp71Doc* GetDocument() const;

// 操作
public:
	bool set;
	int N;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp71View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawcircle();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // exp71View.cpp 中的调试版本
inline Cexp71Doc* Cexp71View::GetDocument() const
   { return reinterpret_cast<Cexp71Doc*>(m_pDocument); }
#endif


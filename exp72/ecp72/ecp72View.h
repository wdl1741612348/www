
// ecp72View.h : Cecp72View 类的接口
//

#pragma once


class Cecp72View : public CView
{
protected: // 仅从序列化创建
	Cecp72View();
	DECLARE_DYNCREATE(Cecp72View)

// 特性
public:
	Cecp72Doc* GetDocument() const;

// 操作
public:
	bool set;
	int N;
	int color,red,green,blue;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cecp72View();
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

#ifndef _DEBUG  // ecp72View.cpp 中的调试版本
inline Cecp72Doc* Cecp72View::GetDocument() const
   { return reinterpret_cast<Cecp72Doc*>(m_pDocument); }
#endif


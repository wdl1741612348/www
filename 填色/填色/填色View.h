
// 填色View.h : C填色View 类的接口
//

#pragma once


class C填色View : public CView
{
protected: // 仅从序列化创建
	C填色View();
	DECLARE_DYNCREATE(C填色View)

// 特性
public:
	C填色Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C填色View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 填色View.cpp 中的调试版本
inline C填色Doc* C填色View::GetDocument() const
   { return reinterpret_cast<C填色Doc*>(m_pDocument); }
#endif


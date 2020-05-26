
// exp12-2View.h : Cexp122View 类的接口
//

#pragma once


class Cexp122View : public CView
{
protected: // 仅从序列化创建
	Cexp122View();
	DECLARE_DYNCREATE(Cexp122View)

// 特性
public:
	Cexp122Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp122View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopup();
};

#ifndef _DEBUG  // exp12-2View.cpp 中的调试版本
inline Cexp122Doc* Cexp122View::GetDocument() const
   { return reinterpret_cast<Cexp122Doc*>(m_pDocument); }
#endif


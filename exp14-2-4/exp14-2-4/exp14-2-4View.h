
// exp14-2-4View.h : Cexp1424View 类的接口
//

#pragma once


class Cexp1424View : public CView
{
protected: // 仅从序列化创建
	Cexp1424View();
	DECLARE_DYNCREATE(Cexp1424View)

// 特性
public:
	Cexp1424Doc* GetDocument() const;

// 操作
public:
	CRect cr;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp1424View();
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

#ifndef _DEBUG  // exp14-2-4View.cpp 中的调试版本
inline Cexp1424Doc* Cexp1424View::GetDocument() const
   { return reinterpret_cast<Cexp1424Doc*>(m_pDocument); }
#endif



// exp14-2-2View.h : Cexp1422View 类的接口
//

#pragma once


class Cexp1422View : public CView
{
protected: // 仅从序列化创建
	Cexp1422View();
	DECLARE_DYNCREATE(Cexp1422View)

// 特性
public:
	Cexp1422Doc* GetDocument() const;

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
	virtual ~Cexp1422View();
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

#ifndef _DEBUG  // exp14-2-2View.cpp 中的调试版本
inline Cexp1422Doc* Cexp1422View::GetDocument() const
   { return reinterpret_cast<Cexp1422Doc*>(m_pDocument); }
#endif


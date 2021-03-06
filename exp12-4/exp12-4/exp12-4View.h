
// exp12-4View.h : Cexp124View 类的接口
//

#pragma once


class Cexp124View : public CView
{
protected: // 仅从序列化创建
	Cexp124View();
	DECLARE_DYNCREATE(Cexp124View)

// 特性
public:
	Cexp124Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp124View();
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

#ifndef _DEBUG  // exp12-4View.cpp 中的调试版本
inline Cexp124Doc* Cexp124View::GetDocument() const
   { return reinterpret_cast<Cexp124Doc*>(m_pDocument); }
#endif


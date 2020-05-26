
// exp91View.h : Cexp91View 类的接口
//

#pragma once


class Cexp91View : public CView
{
protected: // 仅从序列化创建
	Cexp91View();
	DECLARE_DYNCREATE(Cexp91View)

// 特性
public:
	Cexp91Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp91View();
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

#ifndef _DEBUG  // exp91View.cpp 中的调试版本
inline Cexp91Doc* Cexp91View::GetDocument() const
   { return reinterpret_cast<Cexp91Doc*>(m_pDocument); }
#endif


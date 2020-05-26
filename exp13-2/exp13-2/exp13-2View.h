
// exp13-2View.h : Cexp132View 类的接口
//

#pragma once


class Cexp132View : public CView
{
protected: // 仅从序列化创建
	Cexp132View();
	DECLARE_DYNCREATE(Cexp132View)

// 特性
public:
	Cexp132Doc* GetDocument() const;

// 操作
public:
	CString filename;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp132View();
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
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // exp13-2View.cpp 中的调试版本
inline Cexp132Doc* Cexp132View::GetDocument() const
   { return reinterpret_cast<Cexp132Doc*>(m_pDocument); }
#endif


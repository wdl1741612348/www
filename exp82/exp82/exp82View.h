
// exp82View.h : Cexp82View 类的接口
//

#pragma once


class Cexp82View : public CView
{
protected: // 仅从序列化创建
	Cexp82View();
	DECLARE_DYNCREATE(Cexp82View)

// 特性
public:
	Cexp82Doc* GetDocument() const;

// 操作
public:
	CBitmap m_Bitmap;       //位图对象
	int m_nWidth;           //存储位图宽的数据成员
	int m_nHeight;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp82View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // exp82View.cpp 中的调试版本
inline Cexp82Doc* Cexp82View::GetDocument() const
   { return reinterpret_cast<Cexp82Doc*>(m_pDocument); }
#endif


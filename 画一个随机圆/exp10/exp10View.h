
// exp10View.h : Cexp10View ��Ľӿ�
//

#pragma once


class Cexp10View : public CView
{
protected: // �������л�����
	Cexp10View();
	DECLARE_DYNCREATE(Cexp10View)

// ����
public:
	Cexp10Doc* GetDocument() const;

// ����
public:
	CArray<CRect,CRect&> ca;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp10View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp10View.cpp �еĵ��԰汾
inline Cexp10Doc* Cexp10View::GetDocument() const
   { return reinterpret_cast<Cexp10Doc*>(m_pDocument); }
#endif


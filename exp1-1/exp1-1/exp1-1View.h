
// exp1-1View.h : Cexp11View ��Ľӿ�
//

#pragma once


class Cexp11View : public CView
{
protected: // �������л�����
	Cexp11View();
	DECLARE_DYNCREATE(Cexp11View)

// ����
public:
	Cexp11Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp11View();
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

#ifndef _DEBUG  // exp1-1View.cpp �еĵ��԰汾
inline Cexp11Doc* Cexp11View::GetDocument() const
   { return reinterpret_cast<Cexp11Doc*>(m_pDocument); }
#endif


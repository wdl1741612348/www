
// exp1View.h : Cexp1View ��Ľӿ�
//

#pragma once


class Cexp1View : public CView
{
protected: // �������л�����
	Cexp1View();
	DECLARE_DYNCREATE(Cexp1View)

// ����
public:
	Cexp1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp1View();
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

#ifndef _DEBUG  // exp1View.cpp �еĵ��԰汾
inline Cexp1Doc* Cexp1View::GetDocument() const
   { return reinterpret_cast<Cexp1Doc*>(m_pDocument); }
#endif


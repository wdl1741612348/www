
// exp12-1View.h : Cexp121View ��Ľӿ�
//

#pragma once


class Cexp121View : public CView
{
protected: // �������л�����
	Cexp121View();
	DECLARE_DYNCREATE(Cexp121View)

// ����
public:
	Cexp121Doc* GetDocument() const;

// ����
public:
	CRect cr;
	int N;
	int a, b, c, d;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp121View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp12-1View.cpp �еĵ��԰汾
inline Cexp121Doc* Cexp121View::GetDocument() const
   { return reinterpret_cast<Cexp121Doc*>(m_pDocument); }
#endif



// exp83View.h : Cexp83View ��Ľӿ�
//

#pragma once


class Cexp83View : public CView
{
protected: // �������л�����
	Cexp83View();
	DECLARE_DYNCREATE(Cexp83View)

// ����
public:
	Cexp83Doc* GetDocument() const;

// ����
public:
	int k;
	CPoint a, b;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp83View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawline();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnDrawrectangle();
	afx_msg void OnDrawcircle();
};

#ifndef _DEBUG  // exp83View.cpp �еĵ��԰汾
inline Cexp83Doc* Cexp83View::GetDocument() const
   { return reinterpret_cast<Cexp83Doc*>(m_pDocument); }
#endif


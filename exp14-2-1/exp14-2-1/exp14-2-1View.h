
// exp14-2-1View.h : Cexp1421View ��Ľӿ�
//

#pragma once


class Cexp1421View : public CView
{
protected: // �������л�����
	Cexp1421View();
	DECLARE_DYNCREATE(Cexp1421View)

// ����
public:
	Cexp1421Doc* GetDocument() const;

// ����
public:
	CRect cr;
	int a, b, c, d;
	bool set;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp1421View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp14-2-1View.cpp �еĵ��԰汾
inline Cexp1421Doc* Cexp1421View::GetDocument() const
   { return reinterpret_cast<Cexp1421Doc*>(m_pDocument); }
#endif


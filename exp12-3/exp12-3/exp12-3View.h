
// exp12-3View.h : Cexp123View ��Ľӿ�
//

#pragma once


class Cexp123View : public CView
{
protected: // �������л�����
	Cexp123View();
	DECLARE_DYNCREATE(Cexp123View)

// ����
public:
	Cexp123Doc* GetDocument() const;

// ����
public:
	CRect cr,rect;
	int N;
	bool set1,set2;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp123View();
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
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // exp12-3View.cpp �еĵ��԰汾
inline Cexp123Doc* Cexp123View::GetDocument() const
   { return reinterpret_cast<Cexp123Doc*>(m_pDocument); }
#endif


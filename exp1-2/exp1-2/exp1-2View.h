
// exp1-2View.h : Cexp12View ��Ľӿ�
//

#pragma once


class Cexp12View : public CView
{
protected: // �������л�����
	Cexp12View();
	DECLARE_DYNCREATE(Cexp12View)

// ����
public:
	Cexp12Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp12View();
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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp1-2View.cpp �еĵ��԰汾
inline Cexp12Doc* Cexp12View::GetDocument() const
   { return reinterpret_cast<Cexp12Doc*>(m_pDocument); }
#endif


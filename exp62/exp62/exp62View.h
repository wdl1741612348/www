
// exp62View.h : Cexp62View ��Ľӿ�
//

#pragma once


class Cexp62View : public CView
{
protected: // �������л�����
	Cexp62View();
	DECLARE_DYNCREATE(Cexp62View)

// ����
public:
	Cexp62Doc* GetDocument() const;
	
// ����
public:
    int i;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp62View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp62View.cpp �еĵ��԰汾
inline Cexp62Doc* Cexp62View::GetDocument() const
   { return reinterpret_cast<Cexp62Doc*>(m_pDocument); }
#endif


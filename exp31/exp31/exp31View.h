
// exp31View.h : Cexp31View ��Ľӿ�
//

#pragma once


class Cexp31View : public CView
{
protected: // �������л�����
	Cexp31View();
	DECLARE_DYNCREATE(Cexp31View)

// ����
public:
	Cexp31Doc* GetDocument() const;

// ����
public:
	CRect cr;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp31View();
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

#ifndef _DEBUG  // exp31View.cpp �еĵ��԰汾
inline Cexp31Doc* Cexp31View::GetDocument() const
   { return reinterpret_cast<Cexp31Doc*>(m_pDocument); }
#endif



// exp14-2-3View.h : Cexp1423View ��Ľӿ�
//

#pragma once


class Cexp1423View : public CView
{
protected: // �������л�����
	Cexp1423View();
	DECLARE_DYNCREATE(Cexp1423View)

// ����
public:
	Cexp1423Doc* GetDocument() const;

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
	virtual ~Cexp1423View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp14-2-3View.cpp �еĵ��԰汾
inline Cexp1423Doc* Cexp1423View::GetDocument() const
   { return reinterpret_cast<Cexp1423Doc*>(m_pDocument); }
#endif



// exp112View.h : Cexp112View ��Ľӿ�
//

#pragma once


class Cexp112View : public CView
{
protected: // �������л�����
	Cexp112View();
	DECLARE_DYNCREATE(Cexp112View)

// ����
public:
	Cexp112Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp112View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp112View.cpp �еĵ��԰汾
inline Cexp112Doc* Cexp112View::GetDocument() const
   { return reinterpret_cast<Cexp112Doc*>(m_pDocument); }
#endif


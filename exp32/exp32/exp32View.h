
// exp32View.h : Cexp32View ��Ľӿ�
//

#pragma once


class Cexp32View : public CView
{
protected: // �������л�����
	Cexp32View();
	DECLARE_DYNCREATE(Cexp32View)

// ����
public:
	Cexp32Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp32View();
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

#ifndef _DEBUG  // exp32View.cpp �еĵ��԰汾
inline Cexp32Doc* Cexp32View::GetDocument() const
   { return reinterpret_cast<Cexp32Doc*>(m_pDocument); }
#endif


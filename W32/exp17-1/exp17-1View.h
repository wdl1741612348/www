
// exp17-1View.h : Cexp171View ��Ľӿ�
//

#pragma once


class Cexp171View : public CView
{
protected: // �������л�����
	Cexp171View();
	DECLARE_DYNCREATE(Cexp171View)

// ����
public:
	Cexp171Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp171View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // exp17-1View.cpp �еĵ��԰汾
inline Cexp171Doc* Cexp171View::GetDocument() const
   { return reinterpret_cast<Cexp171Doc*>(m_pDocument); }
#endif


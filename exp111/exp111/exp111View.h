
// exp111View.h : Cexp111View ��Ľӿ�
//

#pragma once


class Cexp111View : public CView
{
protected: // �������л�����
	Cexp111View();
	DECLARE_DYNCREATE(Cexp111View)

// ����
public:
	Cexp111Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp111View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopout();
};

#ifndef _DEBUG  // exp111View.cpp �еĵ��԰汾
inline Cexp111Doc* Cexp111View::GetDocument() const
   { return reinterpret_cast<Cexp111Doc*>(m_pDocument); }
#endif


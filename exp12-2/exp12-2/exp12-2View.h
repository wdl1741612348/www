
// exp12-2View.h : Cexp122View ��Ľӿ�
//

#pragma once


class Cexp122View : public CView
{
protected: // �������л�����
	Cexp122View();
	DECLARE_DYNCREATE(Cexp122View)

// ����
public:
	Cexp122Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp122View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopup();
};

#ifndef _DEBUG  // exp12-2View.cpp �еĵ��԰汾
inline Cexp122Doc* Cexp122View::GetDocument() const
   { return reinterpret_cast<Cexp122Doc*>(m_pDocument); }
#endif


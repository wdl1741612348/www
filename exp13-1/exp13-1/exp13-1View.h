
// exp13-1View.h : Cexp131View ��Ľӿ�
//

#pragma once


class Cexp131View : public CView
{
protected: // �������л�����
	Cexp131View();
	DECLARE_DYNCREATE(Cexp131View)

// ����
public:
	Cexp131Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp131View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // exp13-1View.cpp �еĵ��԰汾
inline Cexp131Doc* Cexp131View::GetDocument() const
   { return reinterpret_cast<Cexp131Doc*>(m_pDocument); }
#endif

